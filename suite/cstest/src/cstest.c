// Copyright © 2024 Rot127 <unisono@quyllur.org>
// SPDX-License-Identifier: BSD-3

#define _XOPEN_SOURCE 500
#include <capstone/platform.h>
#include "test_run.h"
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>
#include <time.h>

// Pointer to the file list table
// Must be a thread local, because we cannot pass argumets to nftw.
// So the found test files can only be saved, very very annoyingly,
// to a global/thread-local mutable variable.
thread_local char ***test_files = NULL;
thread_local uint32_t file_count = 0;

static void help(const char *self)
{
	fprintf(stderr, "%s <test-file-dir>/<test-file.yml> ...\n", self);
}

static int handle_ftree_entry(const char *fpath, const struct stat *sb,
			      int typeflag, struct FTW *ftwbuf)
{
	if (typeflag != FTW_F) {
		return 0;
	}
	const char *suffix = strstr(fpath, ".yaml");
	if (!suffix || suffix - fpath != strlen(fpath) - 5) {
		// Misses the .yaml suffix.
		return 0;
	}

	file_count++;
	*test_files = realloc(*test_files, sizeof(char *) * file_count);
	if (!*test_files) {
		fprintf(stderr, "realloc failed\n");
		return -1;
	}
	test_files[0][file_count - 1] = strdup(fpath);
	return 0;
}

/// Parses the test file paths from the @argv array.
static void get_tfiles(int argc, const char **argv)
{
	for (size_t i = 1; i < argc; ++i) {
		if (nftw(argv[i], handle_ftree_entry, 20,
			 FTW_DEPTH | FTW_PHYS) == -1) {
			fprintf(stderr, "nftw failed.\n");
			return;
		}
	}
}

void print_test_run_stats(const TestRunStats *stats)
{
	printf("-----------------------------------------\n");
	printf("Test run statistics\n\n");
	printf("Errors: %" PRId32 "\n\n", stats->errors);
	printf("Test cases:\n");
	printf("\tTotal: %" PRId32 "\n", stats->total);
	printf("\tSuccessful: %" PRId32 "\n", stats->successful);
	printf("\tFailed: %" PRId32 "\n", stats->failed);
	printf("-----------------------------------------\n");
	printf("\n");
}

int main(int argc, const char **argv)
{
	if (argc < 2 || strcmp(argv[1], "-h") == 0 ||
	    strcmp(argv[1], "--help") == 0) {
		help(argv[0]);
		exit(EXIT_FAILURE);
	}
	test_files = malloc(sizeof(char **));
	*test_files = NULL;

	get_tfiles(argc, argv);
	if (!*test_files || file_count == 0) {
		fprintf(stderr, "Arguments are invalid. No files found.\n");
		exit(EXIT_FAILURE);
	}

	printf("Test files found: %" PRId32 "\n", file_count);
	TestRunStats stats = { 0 };
	TestRunResult res = cstest_run_tests(*test_files, file_count, &stats);

	print_test_run_stats(&stats);
	if (res == TRError) {
		fprintf(stderr, "An error occured.\n");
		exit(EXIT_FAILURE);
	} else if (res == TRSuccess) {
		printf("All tests succeeded.\n");
		exit(EXIT_SUCCESS);
	} else if (res == TRFailure) {
		fprintf(stderr, "Some tests failed.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Unhandled Test Run result\n");
	exit(EXIT_FAILURE);
}
