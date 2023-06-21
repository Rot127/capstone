/* Capstone Disassembler Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013> */

#include <stdio.h>
#include <stdlib.h>

#include <capstone/capstone.h>
#include "cstool.h"

void print_insn_detail_aarch64(csh handle, cs_insn *ins)
{
	cs_aarch64 *aarch64;
	int i;
	cs_regs regs_read, regs_write;
	uint8_t regs_read_count, regs_write_count;
	uint8_t access;
	
	// detail can be NULL if SKIPDATA option is turned ON
	if (ins->detail == NULL)
		return;

	aarch64 = &(ins->detail->aarch64);
	if (aarch64->op_count)
		printf("\top_count: %u\n", aarch64->op_count);

	for (i = 0; i < aarch64->op_count; i++) {
		cs_aarch64_op *op = &(aarch64->operands[i]);
		switch(op->type) {
			default:
				break;
			case AArch64_OP_REG:
				printf("\t\toperands[%u].type: REG = %s\n", i, cs_reg_name(handle, op->reg));
				break;
			case AArch64_OP_IMM:
				printf("\t\toperands[%u].type: IMM = 0x%" PRIx64 "\n", i, op->imm);
				break;
			case AArch64_OP_FP:
#if defined(_KERNEL_MODE)
				// Issue #681: Windows kernel does not support formatting float point
				printf("\t\toperands[%u].type: FP = <float_point_unsupported>\n", i);
#else
				printf("\t\toperands[%u].type: FP = %f\n", i, op->fp);
#endif
				break;
			case AArch64_OP_MEM:
				printf("\t\toperands[%u].type: MEM\n", i);
				if (op->mem.base != AArch64_REG_INVALID)
					printf("\t\t\toperands[%u].mem.base: REG = %s\n", i, cs_reg_name(handle, op->mem.base));
				if (op->mem.index != AArch64_REG_INVALID)
					printf("\t\t\toperands[%u].mem.index: REG = %s\n", i, cs_reg_name(handle, op->mem.index));
				if (op->mem.disp != 0)
					printf("\t\t\toperands[%u].mem.disp: 0x%x\n", i, op->mem.disp);

				break;
			case AArch64_OP_SME_MATRIX:
				printf("\t\toperands[%u].type: SME_MATRIX\n", i);
				printf("\t\toperands[%u].sme.type: %d\n", i, op->sme.type);

				if (op->sme.tile != AArch64_REG_INVALID)
					printf("\t\toperands[%u].sme.tile: %s\n", i, cs_reg_name(handle, op->sme.tile));
				if (op->sme.slice_reg != AArch64_REG_INVALID)
					printf("\t\toperands[%u].sme.slice_reg: %s\n", i, cs_reg_name(handle, op->sme.slice_reg));
				if (op->sme.slice_offset != -1)
					printf("\t\toperands[%u].sme.slice_offset: %d\n", i, op->sme.slice_offset);
				if (op->sme.slice_reg != AArch64_REG_INVALID || op->sme.slice_offset != -1)
					printf("\t\toperands[%u].sme.is_vertical: %s\n", i, (op->sme.is_vertical ? "true" : "false"));
				break;
			case AArch64_OP_CIMM:
				printf("\t\toperands[%u].type: C-IMM = %u\n", i, (int)op->imm);
				break;
			case AArch64_OP_REG_MRS:
				printf("\t\toperands[%u].type: REG_MRS = 0x%x\n", i, op->reg);
				break;
			case AArch64_OP_REG_MSR:
				printf("\t\toperands[%u].type: REG_MSR = 0x%x\n", i, op->reg);
				break;
			case AArch64_OP_PSTATEIMM0_1:
				printf("\t\toperands[%u].type: PSTATE 0_1 = 0x%x\n", i, op->sysop.alias.pstateimm0_1);
				break;
			case AArch64_OP_PSTATEIMM0_15:
				printf("\t\toperands[%u].type: PSTATE 0_15 = 0x%x\n", i, op->sysop.alias.pstateimm0_15);
				break;
			case AArch64_OP_AT:
				printf("\t\toperands[%u].type: AT = 0x%x\n", i, op->sysop.alias.at);
				break;
			case AArch64_OP_PRFM:
				printf("\t\toperands[%u].type: PREFETCH = 0x%x\n", i, op->sysop.alias.prfm);
				break;
			case AArch64_OP_DB:
				printf("\t\toperands[%u].type: BARRIER = 0x%x\n", i, op->sysop.alias.db);
				break;
			// TODO Add the others.
			case AArch64_OP_SVCR:
				if(op->sysop.alias.svcr == AArch64_SVCR_SVCRSM)
					printf("\t\t\toperands[%u].svcr: BIT = SM\n", i);
				else if(op->sysop.alias.svcr == AArch64_SVCR_SVCRZA)
					printf("\t\t\toperands[%u].svcr: BIT = ZA\n", i);
				else if(op->sysop.alias.svcr == AArch64_SVCR_SVCRSMZA)
					printf("\t\t\toperands[%u].svcr: BIT = SM & ZA\n", i);
				break;
			// TODO Wait for https://github.com/capstone-engine/capstone/pull/2026#issuecomment-1575635261
			// Add SME
		}
		
		access = op->access;
		switch(access) {
			default:
				break;
			case CS_AC_READ:
				printf("\t\toperands[%u].access: READ\n", i);
				break;
			case CS_AC_WRITE:
				printf("\t\toperands[%u].access: WRITE\n", i);
				break;
			case CS_AC_READ | CS_AC_WRITE:
				printf("\t\toperands[%u].access: READ | WRITE\n", i);
				break;
		}
		
		if (op->shift.type != AArch64_SFT_INVALID &&
			op->shift.value)
			printf("\t\t\tShift: type = %u, value = %u\n",
				   op->shift.type, op->shift.value);

		if (op->ext != AArch64_EXT_INVALID)
			printf("\t\t\tExt: %u\n", op->ext);

		if (op->vas != AArch64Layout_Invalid)
			printf("\t\t\tVector Arrangement Specifier: 0x%x\n", op->vas);

		if (op->vector_index != -1)
			printf("\t\t\tVector Index: %u\n", op->vector_index);
	}

	if (aarch64->update_flags)
		printf("\tUpdate-flags: True\n");

	if (aarch64->writeback)
		printf("\tWrite-back: True\n");

	if (aarch64->cc)
		printf("\tCode-condition: %u\n", aarch64->cc);

	// Print out all registers accessed by this instruction (either implicit or explicit)
	if (!cs_regs_access(handle, ins,
						regs_read, &regs_read_count,
						regs_write, &regs_write_count)) {
		if (regs_read_count) {
			printf("\tRegisters read:");
			for(i = 0; i < regs_read_count; i++) {
				printf(" %s", cs_reg_name(handle, regs_read[i]));
			}
			printf("\n");
		}
		
		if (regs_write_count) {
			printf("\tRegisters modified:");
			for(i = 0; i < regs_write_count; i++) {
				printf(" %s", cs_reg_name(handle, regs_write[i]));
			}
			printf("\n");
		}
	}
}
