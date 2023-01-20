/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2019 */
/*    Rot127 <unisono@quyllur.org>, 2022-2023 */

#ifndef CS_ARM_DISASSEMBLER_EXTENSION_H
#define CS_ARM_DISASSEMBLER_EXTENSION_H

#include "ARMBaseInfo.h"
#include "ARMDisassembler.h"
#include "capstone/capstone.h"
#include "../../MathExtras.h"
#include "../../MCRegisterInfo.h"
#include "../../MCDisassembler.h"
#include "../../cs_priv.h"

bool ITBlock_push_back(ARM_ITBlock *it, char v);

bool ITBlock_instrInITBlock(ARM_ITBlock *it);

bool ITBlock_instrLastInITBlock(ARM_ITBlock *it);

unsigned ITBlock_getITCC(ARM_ITBlock *it);

void ITBlock_advanceITState(ARM_ITBlock *it);

void ITBlock_setITState(ARM_ITBlock *it, char Firstcond, char Mask);

bool Check(DecodeStatus *Out, DecodeStatus In);

inline bool isValidCoprocessorNumber(MCInst *Inst, unsigned Num);

inline bool ARM_isVpred(arm_op_type op);

inline bool isVPTOpcode(int Opc);

bool ARM_isCDECoproc(size_t Coproc, const MCInst *MI);

bool VPTBlock_push_back(ARM_VPTBlock *it, char v);

bool VPTBlock_instrInVPTBlock(ARM_VPTBlock *VPT);

unsigned VPTBlock_getVPTPred(ARM_VPTBlock *VPT);

void VPTBlock_advanceVPTState(ARM_VPTBlock *VPT);

void VPTBlock_setVPTState(ARM_VPTBlock *VPT, char Mask);

#endif // CS_ARM_DISASSEMBLER_EXTENSION_H
