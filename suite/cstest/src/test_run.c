// Copyright © 2024 Rot127 <unisono@quyllur.org>
// SPDX-License-Identifier: BSD-3

#include "test_run.h"
#include "cyaml/cyaml.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include "test_case.h"
#include <capstone/capstone.h>
#include <stdbool.h>
#include <stdio.h>

static TestRunResult get_test_run_result(const TestRunStats *stats)
{
	if (stats->total != stats->successful + stats->failed) {
		fprintf(stderr,
			"Inconsistent statistics: total != successful + failed");
		return TRError;
	}

	if (stats->errors != 0) {
		return TRError;
	} else if (stats->failed != 0) {
		return TRFailure;
	}
	return TRSuccess;
}

/// Extract all test cases from the given test files.
static TestCase **parse_test_cases(char **test_files, uint32_t file_count,
				   TestRunStats *stats)
{
	TestCase **cases = NULL;
	stats->total = 0;

	for (size_t i = 0; i < file_count; ++i) {
		TestFile *test_file = NULL;
		cyaml_err_t err = cyaml_load_file(test_files[i], &cyaml_config,
						  &test_file_schema,
						  (cyaml_data_t **)&test_file,
						  NULL);
		if (err != CYAML_OK || !test_file) {
			fprintf(stderr, "Failed to parse test file '%s'\n",
				test_files[i]);
			fprintf(stderr, "Error: '%s'\n",
				!test_file && err == CYAML_OK ?
					"Empty file" :
					cyaml_strerror(err));
			stats->errors++;
			continue;
		}

		// Copy all test cases of a test file
		cases = realloc(cases, sizeof(TestCase *) * stats->total +
					       test_file->test_cases_count);
		for (size_t i = 0; i < test_file->test_cases_count; ++i) {
			cases[stats->total] =
				test_case_clone(&test_file->test_cases[i]);
			stats->total++;
		}
		err = cyaml_free(&cyaml_config, &test_file_schema, test_file,
				 0);
		if (err != CYAML_OK) {
			fprintf(stderr, "Error: '%s'\n", cyaml_strerror(err));
			stats->errors++;
			continue;
		}
	}

	return cases;
}

static int cstest_unit_test_setup(void **state)
{
	assert(state);
	UnitTestState *ustate = *state;
	assert(ustate->stats && ustate->tcase);
	// Setup cs handle
	cs_err err = cs_open(0, 0, ustate->handle);
	if (err != CS_ERR_OK) {
		char *tc_str = test_input_stringify(&ustate->tcase->input);
		fail_msg("cs_open() failed with: '%s'. TestInput: %s",
			 cs_strerror(err), tc_str);
		free(tc_str);
		return -1;
	}
	return 0;
}

static int cstest_unit_test_teardown(void **state)
{
	if (!state) {
		return 0;
	}
	UnitTestState *ustate = *state;
	if (ustate->handle) {
		cs_err err = cs_close(ustate->handle);
		if (err != CS_ERR_OK) {
			fail_msg("cs_close() failed with: '%s'.",
				 cs_strerror(err));
			return -1;
		}
	}
	return 0;
}

static void cstest_unit_test(void **state)
{
}

static void eval_test_cases(TestCase **test_cases, TestRunStats *stats)
{
	assert(test_cases);
	// CMocka's API does't allow to init a CMUnitTest with a partially initialzed state
	// (which is later initialized in the setup_test function).
	// So we do it manually here.
	struct CMUnitTest *utest_table =
		calloc(sizeof(UnitTestState), stats->total);

	for (size_t i = 0; i < stats->total; ++i) {
		UnitTestState *ut_state = calloc(sizeof(UnitTestState), 1);
		ut_state->tcase = test_cases[i];
		ut_state->stats = stats;

		utest_table[i].initial_state = ut_state;
		utest_table[i].setup_func = cstest_unit_test_setup;
		utest_table[i].teardown_func = cstest_unit_test_teardown;
		utest_table[i].test_func = cstest_unit_test;
	}
	// Use private function here, because the API takes only const tables.
	_cmocka_run_group_tests("All test cases", utest_table, stats->total,
				NULL, NULL);
}

/// Runs runs all valid tests in the given @test_files
/// and returns the result as well as statistics in @stats.
TestRunResult cstest_run_tests(char **test_files, uint32_t file_count,
			       TestRunStats *stats)
{
	TestCase **cases = parse_test_cases(test_files, file_count, stats);
	eval_test_cases(cases, stats);
	for (size_t i = 0; i < stats->total; ++i) {
		test_case_free(cases[i]);
	}

	return get_test_run_result(stats);
}
