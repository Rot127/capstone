/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2019 */

#ifndef CS_ARM_MAPPING_H
#define CS_ARM_MAPPING_H

#include "../../include/capstone/capstone.h"
#include "../../utils.h"
#include "ARMBaseInfo.h"

typedef enum {
#include "ARMGenCSOpGroup.inc"
} arm_op_group;

// return name of regiser in friendly string
const char *ARM_reg_name(csh handle, unsigned int reg);

void ARM_printer(MCInst *MI, SStream *O, void * /* MCRegisterInfo* */info);

// given internal insn id, return public instruction ID
void ARM_get_insn_id(cs_struct *h, cs_insn *insn, unsigned int id);

const char *ARM_insn_name(csh handle, unsigned int id);

const char *ARM_group_name(csh handle, unsigned int id);

// check if this insn is relative branch
bool ARM_rel_branch(cs_struct *h, unsigned int insn_id);

bool ARM_blx_to_arm_mode(cs_struct *h, unsigned int insn_id);

void ARM_reg_access(const cs_insn *insn, cs_regs regs_read,
					uint8_t *regs_read_count, cs_regs regs_write,
					uint8_t *regs_write_count);

const BankedReg *lookupBankedRegByEncoding(uint8_t encoding);

bool ARM_getInstruction(csh handle, const uint8_t *code, size_t code_len,
						MCInst *instr, uint16_t *size, uint64_t address,
						void *info);
void ARM_set_instr_map_data(MCInst *MI);

void ARM_init_mri(MCRegisterInfo *MRI);

// cs_detail related functions
void ARM_init_cs_detail(MCInst *MI);
void ARM_set_mem_access(MCInst *MI, bool status);
static inline void set_mem_access(MCInst *MI, bool status)
{
	ARM_set_mem_access(MI, status);
}
void ARM_add_cs_detail(MCInst *MI, int /* arm_op_group */ op_group,
					   va_list args);
static inline void add_cs_detail(MCInst *MI, int /* arm_op_group */ op_group,
								 ...)
{
	if (!MI->flat_insn->detail)
		return;
	va_list args;
	va_start(args, op_group);
	ARM_add_cs_detail(MI, op_group, args);
	va_end(args);
}

uint64_t ARM_get_op_val(MCInst *MI, unsigned OpNum);
const cs_op_type ARM_get_op_type(MCInst *MI, unsigned OpNum);
const cs_ac_type ARM_get_op_access(MCInst *MI, unsigned OpNum);

void ARM_set_detail_op_reg(MCInst *MI, unsigned OpNum, arm_reg Reg);
void ARM_set_detail_op_sysreg(MCInst *MI, arm_sysreg SysReg, bool IsOutReg);
void ARM_set_detail_op_imm(MCInst *MI, unsigned OpNum, arm_op_type ImmType,
						   int64_t Imm);
void ARM_set_detail_op_float(MCInst *MI, unsigned OpNum, uint64_t Imm);
void ARM_set_detail_op_mem(MCInst *MI, unsigned OpNum, bool is_index_reg,
						   int scale, int lshift, uint64_t Val);
void ARM_set_detail_op_mem_offset(MCInst *MI, unsigned OpNum, uint64_t Val,
								  bool subtracted);
void ARM_set_detail_op_neon_lane(MCInst *MI, unsigned OpNum);

void ARM_check_updates_flags(MCInst *MI);

#endif // CS_ARM_MAPPING_H
