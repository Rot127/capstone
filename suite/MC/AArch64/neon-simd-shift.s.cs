# CS_ARCH_AARCH64, 0, None
0x20,0x04,0x0d,0x0f = sshr v0.8b, v1.8b, #3
0x20,0x04,0x1d,0x0f = sshr v0.4h, v1.4h, #3
0x20,0x04,0x3d,0x0f = sshr v0.2s, v1.2s, #3
0x20,0x04,0x0d,0x4f = sshr v0.16b, v1.16b, #3
0x20,0x04,0x1d,0x4f = sshr v0.8h, v1.8h, #3
0x20,0x04,0x3d,0x4f = sshr v0.4s, v1.4s, #3
0x20,0x04,0x7d,0x4f = sshr v0.2d, v1.2d, #3
0x20,0x04,0x0d,0x2f = ushr v0.8b, v1.8b, #3
0x20,0x04,0x1d,0x2f = ushr v0.4h, v1.4h, #3
0x20,0x04,0x3d,0x2f = ushr v0.2s, v1.2s, #3
0x20,0x04,0x0d,0x6f = ushr v0.16b, v1.16b, #3
0x20,0x04,0x1d,0x6f = ushr v0.8h, v1.8h, #3
0x20,0x04,0x3d,0x6f = ushr v0.4s, v1.4s, #3
0x20,0x04,0x7d,0x6f = ushr v0.2d, v1.2d, #3
0x20,0x14,0x0d,0x0f = ssra v0.8b, v1.8b, #3
0x20,0x14,0x1d,0x0f = ssra v0.4h, v1.4h, #3
0x20,0x14,0x3d,0x0f = ssra v0.2s, v1.2s, #3
0x20,0x14,0x0d,0x4f = ssra v0.16b, v1.16b, #3
0x20,0x14,0x1d,0x4f = ssra v0.8h, v1.8h, #3
0x20,0x14,0x3d,0x4f = ssra v0.4s, v1.4s, #3
0x20,0x14,0x7d,0x4f = ssra v0.2d, v1.2d, #3
0x20,0x14,0x0d,0x2f = usra v0.8b, v1.8b, #3
0x20,0x14,0x1d,0x2f = usra v0.4h, v1.4h, #3
0x20,0x14,0x3d,0x2f = usra v0.2s, v1.2s, #3
0x20,0x14,0x0d,0x6f = usra v0.16b, v1.16b, #3
0x20,0x14,0x1d,0x6f = usra v0.8h, v1.8h, #3
0x20,0x14,0x3d,0x6f = usra v0.4s, v1.4s, #3
0x20,0x14,0x7d,0x6f = usra v0.2d, v1.2d, #3
0x20,0x24,0x0d,0x0f = srshr v0.8b, v1.8b, #3
0x20,0x24,0x1d,0x0f = srshr v0.4h, v1.4h, #3
0x20,0x24,0x3d,0x0f = srshr v0.2s, v1.2s, #3
0x20,0x24,0x0d,0x4f = srshr v0.16b, v1.16b, #3
0x20,0x24,0x1d,0x4f = srshr v0.8h, v1.8h, #3
0x20,0x24,0x3d,0x4f = srshr v0.4s, v1.4s, #3
0x20,0x24,0x7d,0x4f = srshr v0.2d, v1.2d, #3
0x20,0x24,0x0d,0x2f = urshr v0.8b, v1.8b, #3
0x20,0x24,0x1d,0x2f = urshr v0.4h, v1.4h, #3
0x20,0x24,0x3d,0x2f = urshr v0.2s, v1.2s, #3
0x20,0x24,0x0d,0x6f = urshr v0.16b, v1.16b, #3
0x20,0x24,0x1d,0x6f = urshr v0.8h, v1.8h, #3
0x20,0x24,0x3d,0x6f = urshr v0.4s, v1.4s, #3
0x20,0x24,0x7d,0x6f = urshr v0.2d, v1.2d, #3
0x20,0x34,0x0d,0x0f = srsra v0.8b, v1.8b, #3
0x20,0x34,0x1d,0x0f = srsra v0.4h, v1.4h, #3
0x20,0x34,0x3d,0x0f = srsra v0.2s, v1.2s, #3
0x20,0x34,0x0d,0x4f = srsra v0.16b, v1.16b, #3
0x20,0x34,0x1d,0x4f = srsra v0.8h, v1.8h, #3
0x20,0x34,0x3d,0x4f = srsra v0.4s, v1.4s, #3
0x20,0x34,0x7d,0x4f = srsra v0.2d, v1.2d, #3
0x20,0x34,0x0d,0x2f = ursra v0.8b, v1.8b, #3
0x20,0x34,0x1d,0x2f = ursra v0.4h, v1.4h, #3
0x20,0x34,0x3d,0x2f = ursra v0.2s, v1.2s, #3
0x20,0x34,0x0d,0x6f = ursra v0.16b, v1.16b, #3
0x20,0x34,0x1d,0x6f = ursra v0.8h, v1.8h, #3
0x20,0x34,0x3d,0x6f = ursra v0.4s, v1.4s, #3
0x20,0x34,0x7d,0x6f = ursra v0.2d, v1.2d, #3
0x20,0x44,0x0d,0x2f = sri v0.8b, v1.8b, #3
0x20,0x44,0x1d,0x2f = sri v0.4h, v1.4h, #3
0x20,0x44,0x3d,0x2f = sri v0.2s, v1.2s, #3
0x20,0x44,0x0d,0x6f = sri v0.16b, v1.16b, #3
0x20,0x44,0x1d,0x6f = sri v0.8h, v1.8h, #3
0x20,0x44,0x3d,0x6f = sri v0.4s, v1.4s, #3
0x20,0x54,0x0b,0x2f = sli v0.8b, v1.8b, #3
0x20,0x54,0x13,0x2f = sli v0.4h, v1.4h, #3
0x20,0x54,0x23,0x2f = sli v0.2s, v1.2s, #3
0x20,0x54,0x0b,0x6f = sli v0.16b, v1.16b, #3
0x20,0x54,0x13,0x6f = sli v0.8h, v1.8h, #3
0x20,0x54,0x23,0x6f = sli v0.4s, v1.4s, #3
0x20,0x54,0x43,0x6f = sli v0.2d, v1.2d, #3
0x20,0x64,0x0b,0x2f = sqshlu v0.8b, v1.8b, #3
0x20,0x64,0x13,0x2f = sqshlu v0.4h, v1.4h, #3
0x20,0x64,0x23,0x2f = sqshlu v0.2s, v1.2s, #3
0x20,0x64,0x0b,0x6f = sqshlu v0.16b, v1.16b, #3
0x20,0x64,0x13,0x6f = sqshlu v0.8h, v1.8h, #3
0x20,0x64,0x23,0x6f = sqshlu v0.4s, v1.4s, #3
0x20,0x64,0x43,0x6f = sqshlu v0.2d, v1.2d, #3
0x20,0x74,0x0b,0x0f = sqshl v0.8b, v1.8b, #3
0x20,0x74,0x13,0x0f = sqshl v0.4h, v1.4h, #3
0x20,0x74,0x23,0x0f = sqshl v0.2s, v1.2s, #3
0x20,0x74,0x0b,0x4f = sqshl v0.16b, v1.16b, #3
0x20,0x74,0x13,0x4f = sqshl v0.8h, v1.8h, #3
0x20,0x74,0x23,0x4f = sqshl v0.4s, v1.4s, #3
0x20,0x74,0x43,0x4f = sqshl v0.2d, v1.2d, #3
0x20,0x74,0x0b,0x2f = uqshl v0.8b, v1.8b, #3
0x20,0x74,0x13,0x2f = uqshl v0.4h, v1.4h, #3
0x20,0x74,0x23,0x2f = uqshl v0.2s, v1.2s, #3
0x20,0x74,0x0b,0x6f = uqshl v0.16b, v1.16b, #3
0x20,0x74,0x13,0x6f = uqshl v0.8h, v1.8h, #3
0x20,0x74,0x23,0x6f = uqshl v0.4s, v1.4s, #3
0x20,0x74,0x43,0x6f = uqshl v0.2d, v1.2d, #3
0x20,0x84,0x0d,0x0f = shrn v0.8b, v1.8h, #3
0x20,0x84,0x1d,0x0f = shrn v0.4h, v1.4s, #3
0x20,0x84,0x3d,0x0f = shrn v0.2s, v1.2d, #3
0x20,0x84,0x0d,0x4f = shrn2 v0.16b, v1.8h, #3
0x20,0x84,0x1d,0x4f = shrn2 v0.8h, v1.4s, #3
0x20,0x84,0x3d,0x4f = shrn2 v0.4s, v1.2d, #3
0x20,0x84,0x0d,0x2f = sqshrun v0.8b, v1.8h, #3
0x20,0x84,0x1d,0x2f = sqshrun v0.4h, v1.4s, #3
0x20,0x84,0x3d,0x2f = sqshrun v0.2s, v1.2d, #3
0x20,0x84,0x0d,0x6f = sqshrun2 v0.16b, v1.8h, #3
0x20,0x84,0x1d,0x6f = sqshrun2 v0.8h, v1.4s, #3
0x20,0x84,0x3d,0x6f = sqshrun2 v0.4s, v1.2d, #3
0x20,0x8c,0x0d,0x0f = rshrn v0.8b, v1.8h, #3
0x20,0x8c,0x1d,0x0f = rshrn v0.4h, v1.4s, #3
0x20,0x8c,0x3d,0x0f = rshrn v0.2s, v1.2d, #3
0x20,0x8c,0x0d,0x4f = rshrn2 v0.16b, v1.8h, #3
0x20,0x8c,0x1d,0x4f = rshrn2 v0.8h, v1.4s, #3
0x20,0x8c,0x3d,0x4f = rshrn2 v0.4s, v1.2d, #3
0x20,0x8c,0x0d,0x2f = sqrshrun v0.8b, v1.8h, #3
0x20,0x8c,0x1d,0x2f = sqrshrun v0.4h, v1.4s, #3
0x20,0x8c,0x3d,0x2f = sqrshrun v0.2s, v1.2d, #3
0x20,0x8c,0x0d,0x6f = sqrshrun2 v0.16b, v1.8h, #3
0x20,0x8c,0x1d,0x6f = sqrshrun2 v0.8h, v1.4s, #3
0x20,0x8c,0x3d,0x6f = sqrshrun2 v0.4s, v1.2d, #3
0x20,0x94,0x0d,0x0f = sqshrn v0.8b, v1.8h, #3
0x20,0x94,0x1d,0x0f = sqshrn v0.4h, v1.4s, #3
0x20,0x94,0x3d,0x0f = sqshrn v0.2s, v1.2d, #3
0x20,0x94,0x0d,0x4f = sqshrn2 v0.16b, v1.8h, #3
0x20,0x94,0x1d,0x4f = sqshrn2 v0.8h, v1.4s, #3
0x20,0x94,0x3d,0x4f = sqshrn2 v0.4s, v1.2d, #3
0x20,0x94,0x0d,0x2f = uqshrn v0.8b, v1.8h, #3
0x20,0x94,0x1d,0x2f = uqshrn v0.4h, v1.4s, #3
0x20,0x94,0x3d,0x2f = uqshrn v0.2s, v1.2d, #3
0x20,0x94,0x0d,0x6f = uqshrn2 v0.16b, v1.8h, #3
0x20,0x94,0x1d,0x6f = uqshrn2 v0.8h, v1.4s, #3
0x20,0x94,0x3d,0x6f = uqshrn2 v0.4s, v1.2d, #3
0x20,0x9c,0x0d,0x0f = sqrshrn v0.8b, v1.8h, #3
0x20,0x9c,0x1d,0x0f = sqrshrn v0.4h, v1.4s, #3
0x20,0x9c,0x3d,0x0f = sqrshrn v0.2s, v1.2d, #3
0x20,0x9c,0x0d,0x4f = sqrshrn2 v0.16b, v1.8h, #3
0x20,0x9c,0x1d,0x4f = sqrshrn2 v0.8h, v1.4s, #3
0x20,0x9c,0x3d,0x4f = sqrshrn2 v0.4s, v1.2d, #3
0x20,0x9c,0x0d,0x2f = uqrshrn v0.8b, v1.8h, #3
0x20,0x9c,0x1d,0x2f = uqrshrn v0.4h, v1.4s, #3
0x20,0x9c,0x3d,0x2f = uqrshrn v0.2s, v1.2d, #3
0x20,0x9c,0x0d,0x6f = uqrshrn2 v0.16b, v1.8h, #3
0x20,0x9c,0x1d,0x6f = uqrshrn2 v0.8h, v1.4s, #3
0x20,0x9c,0x3d,0x6f = uqrshrn2 v0.4s, v1.2d, #3
0x20,0xe4,0x3d,0x0f = scvtf v0.2s, v1.2s, #3
0x20,0xe4,0x3d,0x4f = scvtf v0.4s, v1.4s, #3
0x20,0xe4,0x7d,0x4f = scvtf v0.2d, v1.2d, #3
0x20,0xe4,0x3d,0x2f = ucvtf v0.2s, v1.2s, #3
0x20,0xe4,0x3d,0x6f = ucvtf v0.4s, v1.4s, #3
0x20,0xe4,0x7d,0x6f = ucvtf v0.2d, v1.2d, #3
0x20,0xfc,0x3d,0x0f = fcvtzs v0.2s, v1.2s, #3
0x20,0xfc,0x3d,0x4f = fcvtzs v0.4s, v1.4s, #3
0x20,0xfc,0x7d,0x4f = fcvtzs v0.2d, v1.2d, #3
0x20,0xfc,0x3d,0x2f = fcvtzu v0.2s, v1.2s, #3
0x20,0xfc,0x3d,0x6f = fcvtzu v0.4s, v1.4s, #3
0x20,0xfc,0x7d,0x6f = fcvtzu v0.2d, v1.2d, #3
