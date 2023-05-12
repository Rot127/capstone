/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2015 */

#ifdef CAPSTONE_HAS_POWERPC

#include <stdio.h>	// debug
#include <string.h>

#include "../../cs_simple_types.h"
#include "../../Mapping.h"
#include "../../MCDisassembler.h"
#include "../../utils.h"

#include "PPCLinkage.h"
#include "PPCMapping.h"
#include "PPCMCTargetDesc.h"

#define GET_REGINFO_MC_DESC
#include "PPCGenRegisterInfo.inc"

void PPC_init_mri(MCRegisterInfo *MRI)
{
	MCRegisterInfo_InitMCRegisterInfo(
		MRI, PPCRegDesc, 289, 0, 0, PPCMCRegisterClasses, 103, 0, 0,
		PPCRegDiffLists, 0, PPCSubRegIdxLists, 57, PPCRegEncodingTable);
}

const char *PPC_reg_name(csh handle, unsigned int reg)
{
	return PPC_LLVM_getRegisterName(reg);
}

static const insn_map insns[] = {
	// dummy item
	{
		0, 0,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { 0 }, 0, 0
#endif
	},

#include "PPCGenCSMappingInsn.inc"
};

// given internal insn id, return public instruction info
void PPC_get_insn_id(cs_struct *h, cs_insn *insn, unsigned int id)
{
	int i;

	i = insn_find(insns, ARR_SIZE(insns), id, &h->insn_cache);
	if (i != 0) {
		insn->id = insns[i].mapid;

		if (h->detail) {
#ifndef CAPSTONE_DIET
			cs_struct handle;
			handle.detail = h->detail;

			memcpy(insn->detail->regs_read, insns[i].regs_use, sizeof(insns[i].regs_use));
			insn->detail->regs_read_count = (uint8_t)count_positive(insns[i].regs_use);

			memcpy(insn->detail->regs_write, insns[i].regs_mod, sizeof(insns[i].regs_mod));
			insn->detail->regs_write_count = (uint8_t)count_positive(insns[i].regs_mod);

			memcpy(insn->detail->groups, insns[i].groups, sizeof(insns[i].groups));
			insn->detail->groups_count = (uint8_t)count_positive8(insns[i].groups);

			if (insns[i].branch || insns[i].indirect_branch) {
				// this insn also belongs to JUMP group. add JUMP group
				insn->detail->groups[insn->detail->groups_count] = PPC_GRP_JUMP;
				insn->detail->groups_count++;
			}

			insn->detail->ppc.update_cr0 = cs_reg_write((csh)&handle, insn, PPC_REG_CR0);
#endif
		}
	}
}

static const char * const insn_name_maps[] = {
    NULL, // PPC_INS_BCT
#include "PPCGenCSMappingInsnName.inc"
};

const char *PPC_insn_name(csh handle, unsigned int id)
{
#ifndef CAPSTONE_DIET
	if (id >= PPC_INS_ENDING)
		return NULL;

	return insn_name_maps[id];
#else
	return NULL;
#endif
}

// map instruction name to public instruction ID
ppc_insn PPC_map_insn(const char *name)
{
	unsigned int i;

	for(i = 1; i < ARR_SIZE(insn_name_maps); i++) {
		if (!strcmp(name, insn_name_maps[i]))
			return i;
	}

	// not found
	return PPC_INS_INVALID;
}

#ifndef CAPSTONE_DIET
static const name_map group_name_maps[] = {
	// generic groups
	{ PPC_GRP_INVALID, NULL },
	{ PPC_GRP_JUMP,	"jump" },

	// architecture-specific groups
	#include "PPCGenCSFeatureName.inc"
};
#endif

const char *PPC_group_name(csh handle, unsigned int id)
{
#ifndef CAPSTONE_DIET
	return id2name(group_name_maps, ARR_SIZE(group_name_maps), id);
#else
	return NULL;
#endif
}

void PPC_printer(MCInst *MI, SStream *O, void * /* MCRegisterInfo* */info) {
	PPC_LLVM_printInst(MI, MI->address, "", O);
}

bool PPC_getInstruction(csh handle, const uint8_t *bytes, size_t bytes_len,
						MCInst *instr, uint16_t *size, uint64_t address,
						void *info) {
	DecodeStatus result = PPC_LLVM_getInstruction(handle, bytes, bytes_len, instr, size, address, info);
	return result != MCDisassembler_Fail;
}

// check if this insn is relative branch
bool PPC_abs_branch(cs_struct *h, unsigned int id)
{
	unsigned int i;
	// list all absolute branch instructions
	static const unsigned int insn_abs[] = {
		PPC_BA,
		PPC_BCCA,
		PPC_BCCLA,
		PPC_BDNZA,
		PPC_BDNZAm,
		PPC_BDNZAp,
		PPC_BDNZLA,
		PPC_BDNZLAm,
		PPC_BDNZLAp,
		PPC_BDZA,
		PPC_BDZAm,
		PPC_BDZAp,
		PPC_BDZLAm,
		PPC_BDZLAp,
		PPC_BLA,
		PPC_gBCA,
		PPC_gBCLA,
		PPC_BDZLA,
		0
	};

	// printf("opcode: %u\n", id);

	for (i = 0; insn_abs[i]; i++) {
		if (id == insn_abs[i]) {
			return true;
		}
	}

	// not found
	return false;
}

bool PPC_getFeatureBits(unsigned int mode, unsigned int feature) {
  if ((feature == PPC_FeatureQPX) && (mode & CS_MODE_QPX) == 0) {
    return false;
  } else if ((feature == PPC_FeatureSPE) && (mode & CS_MODE_SPE) == 0) {
    return false;
  } else if ((feature == PPC_FeatureBookE) && (mode & CS_MODE_BOOKE) == 0) {
    return false;
  }
	// TODO: CS_MODE_PS

	// No AIX support for now.
	if (feature == PPC_FeatureModernAIXAs)
		return false;

	// By default support everything
	return true;
}

static const map_insn_ops insn_operands[] = {
#include "PPCGenCSMappingInsnOp.inc"
};

static void add_cs_detail_general(MCInst *MI, ppc_op_group op_group,
								  unsigned OpNum) {
	if (!detail_is_set(MI))
		return;

	switch (op_group) {
	default:
		printf("General operand group %d not handled!\n", op_group);
		return;
	case PPC_OP_GROUP_Operand:
		if (doing_mem(MI)) {
			PPC_set_detail_op_mem(MI, OpNum, MCInst_getOpVal(MI, OpNum));
			break;
		}

		cs_op_type op_type = map_get_op_type(MI, OpNum);
		assert((op_type & CS_OP_MEM) == 0); // doing_mem should have been true.

		if (op_type == CS_OP_REG)
			PPC_set_detail_op_reg(MI, OpNum, MCInst_getOpVal(MI, OpNum));
		else if (op_type == CS_OP_IMM)
			PPC_set_detail_op_imm(MI, OpNum, MCInst_getOpVal(MI, OpNum));
		else
			assert(0 && "Operand type not handled.");
		break;
	case PPC_OP_GROUP_PredicateOperand:
	case PPC_OP_GROUP_MandatoryInvertedPredicateOperand:
	case PPC_OP_GROUP_ImmZeroOperand:
	case PPC_OP_GROUP_U1ImmOperand:
	case PPC_OP_GROUP_U2ImmOperand:
	case PPC_OP_GROUP_U3ImmOperand:
	case PPC_OP_GROUP_U4ImmOperand:
	case PPC_OP_GROUP_U5ImmOperand:
	case PPC_OP_GROUP_U6ImmOperand:
	case PPC_OP_GROUP_U7ImmOperand:
	case PPC_OP_GROUP_U8ImmOperand:
	case PPC_OP_GROUP_U10ImmOperand:
	case PPC_OP_GROUP_U12ImmOperand:
	case PPC_OP_GROUP_U16ImmOperand:
	case PPC_OP_GROUP_S5ImmOperand:
	case PPC_OP_GROUP_S16ImmOperand:
	case PPC_OP_GROUP_S34ImmOperand:
	case PPC_OP_GROUP_LdStmModeOperand:
	case PPC_OP_GROUP_MemRegReg:
	case PPC_OP_GROUP_MemRegImm:
	case PPC_OP_GROUP_MemRegImmHash:
	case PPC_OP_GROUP_MemRegImm34:
	case PPC_OP_GROUP_MemRegImm34PCRel:
	case PPC_OP_GROUP_BranchOperand:
	case PPC_OP_GROUP_AbsBranchOperand:
	case PPC_OP_GROUP_TLSCall:
	case PPC_OP_GROUP_crbitm:
	case PPC_OP_GROUP_ATBitsAsHint:
		printf("Operand group %d not implemented.\n", op_group);
		return;
	}
}

/// Fills cs_detail with the data of the operand.
/// Calls to this function should not be added by hand! Please checkout the
/// patch `AddCSDetail` of the CppTranslator.
void PPC_add_cs_detail(MCInst *MI, ppc_op_group op_group, va_list args)
{
	if (!detail_is_set(MI))
		return;

	switch (op_group) {
	default:
		printf("Operand group %d not handled!\n", op_group);
		return;
	case PPC_OP_GROUP_RegImmShift: {
		// ARM_AM_ShiftOpc shift_opc = va_arg(args, ARM_AM_ShiftOpc);
		// unsigned shift_imm = va_arg(args, unsigned);
		// add_cs_detail_RegImmShift(MI, shift_opc, shift_imm);
		return;
	}
	case PPC_OP_GROUP_LdStmModeOperand:
	case PPC_OP_GROUP_MandatoryInvertedPredicateOperand:
	case PPC_OP_GROUP_Operand:
	case PPC_OP_GROUP_MemRegReg:
	case PPC_OP_GROUP_U6ImmOperand:
	case PPC_OP_GROUP_U5ImmOperand:
	case PPC_OP_GROUP_MemRegImm:
	case PPC_OP_GROUP_S16ImmOperand:
	case PPC_OP_GROUP_U2ImmOperand:
	case PPC_OP_GROUP_U16ImmOperand:
	case PPC_OP_GROUP_BranchOperand:
	case PPC_OP_GROUP_AbsBranchOperand:
	case PPC_OP_GROUP_PredicateOperand:
	case PPC_OP_GROUP_U1ImmOperand:
	case PPC_OP_GROUP_TLSCall:
	case PPC_OP_GROUP_U3ImmOperand:
	case PPC_OP_GROUP_S5ImmOperand:
	case PPC_OP_GROUP_MemRegImmHash:
	case PPC_OP_GROUP_U4ImmOperand:
	case PPC_OP_GROUP_U10ImmOperand:
	case PPC_OP_GROUP_crbitm:
	case PPC_OP_GROUP_S34ImmOperand:
	case PPC_OP_GROUP_ImmZeroOperand:
	case PPC_OP_GROUP_MemRegImm34:
	case PPC_OP_GROUP_MemRegImm34PCRel:
	case PPC_OP_GROUP_U8ImmOperand:
	case PPC_OP_GROUP_U12ImmOperand:
	case PPC_OP_GROUP_U7ImmOperand:
	case PPC_OP_GROUP_ATBitsAsHint: {
		unsigned OpNum = va_arg(args, unsigned);
		add_cs_detail_general(MI, op_group, OpNum);
		return;
	}
	}
}

void PPC_set_detail_op_mem(MCInst *MI, unsigned OpNum, uint64_t Val)
{
	if (!detail_is_set(MI))
		return;

	assert(map_get_op_type(MI, OpNum) & CS_OP_MEM);
	cs_op_type secondary_type = map_get_op_type(MI, OpNum) & ~CS_OP_MEM;
	switch (secondary_type) {
	default:
		assert(0 && "Secondary type not supported yet.");
	case CS_OP_REG:
		PPC_get_detail_op(MI, 0)->mem.base = Val;
		if (MCInst_opIsTying(MI, OpNum))
			map_add_implicit_write(MI, MCInst_getOpVal(MI, OpNum));
		break;
	case CS_OP_IMM:
		PPC_get_detail_op(MI, 0)->mem.disp = Val;
		break;
	}

	PPC_get_detail_op(MI, 0)->type = PPC_OP_MEM;
	PPC_get_detail_op(MI, 0)->access = map_get_op_access(MI, OpNum);
}

/// Adds a register PPC operand at position OpNum and increases the op_count by
/// one.
void PPC_set_detail_op_reg(MCInst *MI, unsigned OpNum, ppc_reg Reg)
{
	if (!detail_is_set(MI))
		return;
	assert(!(map_get_op_type(MI, OpNum) & CS_OP_MEM));
	assert(map_get_op_type(MI, OpNum) == CS_OP_REG);

	PPC_get_detail_op(MI, 0)->type = PPC_OP_REG;
	PPC_get_detail_op(MI, 0)->reg = Reg;
	PPC_get_detail_op(MI, 0)->access = map_get_op_access(MI, OpNum);
	PPC_inc_op_count(MI);
}

/// Adds an immediate PPC operand at position OpNum and increases the op_count
/// by one.
void PPC_set_detail_op_imm(MCInst *MI, unsigned OpNum, int64_t Imm)
{
	if (!detail_is_set(MI))
		return;
	assert(!(map_get_op_type(MI, OpNum) & CS_OP_MEM));
	assert(map_get_op_type(MI, OpNum) == CS_OP_IMM);

	PPC_get_detail_op(MI, 0)->type = PPC_OP_IMM;
	PPC_get_detail_op(MI, 0)->imm = Imm;
	PPC_get_detail_op(MI, 0)->access = map_get_op_access(MI, OpNum);
	PPC_inc_op_count(MI);
}

#endif
