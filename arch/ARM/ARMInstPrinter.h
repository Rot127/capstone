/* Capstone Disassembly Engine, http://www.capstone-engine.org */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2022, */
/*    Rot127 <unisono@quyllur.org> 2022-2023 */
/* Automatically translated source file from LLVM. */

/* LLVM-commit: 464bda7750a3ba9e23823fc707d7e7b6fc38438d */
/* LLVM-tag: llvmorg-16.0.2-5-g464bda7750a3 */

/* Only small edits allowed. */
/* For multiple similar edits, please create a Patch for the translator. */

/* Capstone's C++ file translator: */
/* https://github.com/capstone-engine/capstone/tree/next/suite/auto-sync */

//===- ARMInstPrinter.h - Convert ARM MCInst to assembly syntax -*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an ARM MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef CS_ARM_INSTPRINTER_H
#define CS_ARM_INSTPRINTER_H

#include <capstone/platform.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../MCInst.h"
#include "../../MCInstPrinter.h"
#include "../../MCRegisterInfo.h"
#include "../../SStream.h"
#include "../../utils.h"
#define CONCAT(a, b) CONCAT_(a, b)
#define CONCAT_(a, b) a##_##b

bool applyTargetSpecificCLOption(const char *Opt);
// Autogenerated by tblgen.
void printOperandAddr(MCInst *MI, uint64_t Address, unsigned OpNum, SStream *O);
void printSORegRegOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printSORegImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printAddrModeTBB(MCInst *MI, unsigned OpNum, SStream *O);
void printAddrModeTBH(MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode2Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printAM2PostIndexOp(MCInst *MI, unsigned OpNum, SStream *O);
void printAM2PreOrOffsetIndexOp(MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode2OffsetOperand(MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAddrMode3Operand(AlwaysPrintImm0)                         \
	void CONCAT(printAddrMode3Operand,                                         \
				AlwaysPrintImm0)(MCInst * MI, unsigned OpNum, SStream *O);
DECLARE_printAddrMode3Operand(false) DECLARE_printAddrMode3Operand(true)

	void printAddrMode3OffsetOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printAM3PreOrOffsetIndexOp(MCInst *MI, unsigned Op, SStream *O,
								bool AlwaysPrintImm0);
void printPostIdxImm8Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printPostIdxRegOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printPostIdxImm8s4Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printLdStmModeOperand(MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAddrMode5Operand(AlwaysPrintImm0)                         \
	void CONCAT(printAddrMode5Operand,                                         \
				AlwaysPrintImm0)(MCInst * MI, unsigned OpNum, SStream *O);
DECLARE_printAddrMode5Operand(false) DECLARE_printAddrMode5Operand(true)

#define DECLARE_printAddrMode5FP16Operand(AlwaysPrintImm0)                     \
	void CONCAT(printAddrMode5FP16Operand,                                     \
				AlwaysPrintImm0)(MCInst * MI, unsigned OpNum, SStream *O);
	DECLARE_printAddrMode5FP16Operand(false)

		void printAddrMode6Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode7Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode6OffsetOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printBitfieldInvMaskImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printMemBOption(MCInst *MI, unsigned OpNum, SStream *O);
void printInstSyncBOption(MCInst *MI, unsigned OpNum, SStream *O);
void printTraceSyncBOption(MCInst *MI, unsigned OpNum, SStream *O);
void printShiftImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printPKHLSLShiftImm(MCInst *MI, unsigned OpNum, SStream *O);
void printPKHASRShiftImm(MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAdrLabelOperand(scale)                                    \
	void CONCAT(printAdrLabelOperand, scale)(MCInst * MI, unsigned OpNum,      \
											 SStream *O);
DECLARE_printAdrLabelOperand(0) DECLARE_printAdrLabelOperand(2)

#define DEFINE_printAdrLabelOperandAddr(scale)                                 \
	static inline void CONCAT(printAdrLabelOperandAddr, scale)(                \
		MCInst * MI, uint64_t Address, unsigned OpNum, SStream *O)             \
	{                                                                          \
		CONCAT(printAdrLabelOperand, scale)(MI, OpNum, O);                     \
	}
	DEFINE_printAdrLabelOperandAddr(0) DEFINE_printAdrLabelOperandAddr(2)

		void printThumbS4ImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbSRImm(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbITMask(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeRROperand(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeImm5SOperand(MCInst *MI, unsigned OpNum, SStream *O,
									unsigned Scale);
void printThumbAddrModeImm5S1Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeImm5S2Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeImm5S4Operand(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeSPOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printT2SOOperand(MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAddrModeImm12Operand(AlwaysPrintImm0)                     \
	void CONCAT(printAddrModeImm12Operand,                                     \
				AlwaysPrintImm0)(MCInst * MI, unsigned OpNum, SStream *O);
DECLARE_printAddrModeImm12Operand(false) DECLARE_printAddrModeImm12Operand(true)

#define DECLARE_printT2AddrModeImm8Operand(AlwaysPrintImm0)                    \
	void CONCAT(printT2AddrModeImm8Operand,                                    \
				AlwaysPrintImm0)(MCInst * MI, unsigned OpNum, SStream *O);
	DECLARE_printT2AddrModeImm8Operand(true)
		DECLARE_printT2AddrModeImm8Operand(false)

#define DECLARE_printT2AddrModeImm8s4Operand(AlwaysPrintImm0)                  \
	void CONCAT(printT2AddrModeImm8s4Operand,                                  \
				AlwaysPrintImm0)(MCInst * MI, unsigned OpNum, SStream *O);
			DECLARE_printT2AddrModeImm8s4Operand(false)
				DECLARE_printT2AddrModeImm8s4Operand(true)

					void printT2AddrModeImm0_1020s4Operand(MCInst *MI,
														   unsigned OpNum,
														   SStream *O);
void printT2AddrModeImm8OffsetOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printT2AddrModeImm8s4OffsetOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printT2AddrModeSoRegOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printSetendOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printCPSIMod(MCInst *MI, unsigned OpNum, SStream *O);
void printCPSIFlag(MCInst *MI, unsigned OpNum, SStream *O);
void printMSRMaskOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printBankedRegOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printMandatoryPredicateOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printMandatoryRestrictedPredicateOperand(MCInst *MI, unsigned OpNum,
											  SStream *O);
void printMandatoryInvertedPredicateOperand(MCInst *MI, unsigned OpNum,
											SStream *O);
void printSBitModifierOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printRegisterList(MCInst *MI, unsigned OpNum, SStream *O);
void printNoHashImmediate(MCInst *MI, unsigned OpNum, SStream *O);
void printPImmediate(MCInst *MI, unsigned OpNum, SStream *O);
void printCImmediate(MCInst *MI, unsigned OpNum, SStream *O);
void printCoprocOptionImm(MCInst *MI, unsigned OpNum, SStream *O);
void printFPImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printVMOVModImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printImmPlusOneOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printRotImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printModImmOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printGPRPairOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printPCLabel(MCInst *MI, unsigned OpNum, SStream *O);
void printThumbLdrLabelOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printFBits16(MCInst *MI, unsigned OpNum, SStream *O);
void printFBits32(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorIndex(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListOne(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwo(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwoSpaced(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListThree(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFour(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListOneAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwoAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListThreeAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFourAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwoSpacedAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListThreeSpacedAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFourSpacedAllLanes(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListThreeSpaced(MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFourSpaced(MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printMVEVectorList(NumRegs)                                    \
	void CONCAT(printMVEVectorList, NumRegs)(MCInst * MI, unsigned OpNum,      \
											 SStream *O);
DECLARE_printMVEVectorList(2) DECLARE_printMVEVectorList(4)

#define DECLARE_printComplexRotationOp(Angle, Remainder)                       \
	void CONCAT(printComplexRotationOp, CONCAT(Angle, Remainder))(             \
		MCInst * MI, unsigned OpNum, SStream *O);
	DECLARE_printComplexRotationOp(90, 0)
		DECLARE_printComplexRotationOp(180, 90)

	// MVE
	void printVPTPredicateOperand(MCInst *MI, unsigned OpNum, SStream *O);
void printVPTMask(MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printMveAddrModeRQOperand(shift)                               \
	void CONCAT(printMveAddrModeRQOperand, shift)(MCInst * MI, unsigned OpNum, \
												  SStream *O);
DECLARE_printMveAddrModeRQOperand(0) DECLARE_printMveAddrModeRQOperand(3)
	DECLARE_printMveAddrModeRQOperand(1) DECLARE_printMveAddrModeRQOperand(2)

		void printMveSaturateOp(MCInst *MI, unsigned OpNum, SStream *O);

unsigned translateShiftImm(unsigned imm);

#endif // CS_ARM_INSTPRINTER_H
