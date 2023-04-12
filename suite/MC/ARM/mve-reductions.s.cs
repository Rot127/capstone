# CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_V8 | CS_MODE_MCLASS, None
0x82,0xee,0x07,0x0f = vabav.s8 r0, q1, q3
0x92,0xee,0x07,0x0f = vabav.s16 r0, q1, q3
0xa2,0xee,0x07,0x0f = vabav.s32 r0, q1, q3
0x82,0xfe,0x07,0x0f = vabav.u8 r0, q1, q3
0x92,0xfe,0x07,0x0f = vabav.u16 r0, q1, q3
0xa2,0xfe,0x07,0x0f = vabav.u32 r0, q1, q3
0xf5,0xee,0x00,0xef = vaddv.s16 lr, q0
0xf5,0xee,0x0c,0x0f = vaddv.s16 r0, q6
0xf5,0xee,0x20,0xef = vaddva.s16 lr, q0
0xc9,0xee,0x04,0x0f = vaddlv.s32 r0, r9, q2
0x89,0xfe,0x02,0x0f = vaddlv.u32 r0, r1, q1
0xe2,0xee,0x80,0xef = vminv.s8 lr, q0
0xe6,0xee,0x80,0xef = vminv.s16 lr, q0
0xea,0xee,0x84,0xef = vminv.s32 lr, q2
0xe2,0xfe,0x80,0x0f = vminv.u8 r0, q0
0xea,0xfe,0x86,0xaf = vminv.u32 r10, q3
0xe4,0xee,0x80,0x0f = vminav.s16 r0, q0
0xe0,0xee,0x82,0x0f = vminav.s8 r0, q1
0xe8,0xee,0x82,0xef = vminav.s32 lr, q1
0xe2,0xee,0x08,0xef = vmaxv.s8 lr, q4
0xe6,0xee,0x00,0xef = vmaxv.s16 lr, q0
0xea,0xee,0x02,0x1f = vmaxv.s32 r1, q1
0xe2,0xfe,0x08,0x0f = vmaxv.u8 r0, q4
0xe6,0xfe,0x02,0x0f = vmaxv.u16 r0, q1
0xea,0xfe,0x00,0x1f = vmaxv.u32 r1, q0
0xe0,0xee,0x0c,0xef = vmaxav.s8 lr, q6
0xe4,0xee,0x0c,0x0f = vmaxav.s16 r0, q6
0xe8,0xee,0x0e,0xaf = vmaxav.s32 r10, q7
0xf0,0xee,0x0e,0xee = vmlav.s16 lr, q0, q7
0xf1,0xee,0x08,0xee = vmlav.s32 lr, q0, q4
0xf0,0xfe,0x0e,0xee = vmlav.u16 lr, q0, q7
0xf1,0xfe,0x00,0xee = vmlav.u32 lr, q0, q0
0xf0,0xee,0x28,0xee = vmlava.s16 lr, q0, q4
0xf0,0xee,0x0e,0x1e = vmladavx.s16 r0, q0, q7
0xf0,0xee,0x2e,0xfe = vmladavax.s16 lr, q0, q7
0xf6,0xee,0x00,0xef = vmlav.s8 lr, q3, q0
0xf2,0xfe,0x0e,0xef = vmlav.u8 lr, q1, q7
0x8c,0xee,0x04,0xef = vrmlalvh.s32 lr, r1, q6, q2
0x8a,0xfe,0x04,0xef = vrmlalvh.u32 lr, r1, q5, q2
0x8a,0xfe,0x04,0xef = vrmlalvh.u32 lr, r1, q5, q2
0x86,0xee,0x20,0xff = vrmlaldavhax.s32 lr, r1, q3, q0
0xdc,0xfe,0x0b,0xee = vrmlsldavh.s32 lr, r11, q6, q5
0xf0,0xee,0x07,0xee = vmlsdav.s16 lr, q0, q3
0x8c,0xee,0x04,0xef = vrmlalvh.s32 lr, r1, q6, q2
0x8a,0xfe,0x04,0xef = vrmlalvh.u32 lr, r1, q5, q2
0x86,0xee,0x2c,0xef = vrmlalvha.s32 lr, r1, q3, q6
0x8e,0xfe,0x22,0xef = vrmlalvha.u32 lr, r1, q7, q1
0xf0,0xee,0x07,0xee = vmlsdav.s16 lr, q0, q3
0xf5,0xee,0x0d,0xee = vmlsdav.s32 lr, q2, q6
0xf2,0xee,0x29,0xfe = vmlsdavax.s16 lr, q1, q4
0xf0,0xee,0x0e,0xee = vmlav.s16 lr, q0, q7
0x88,0xee,0x02,0xee = vmlalv.s16 lr, r1, q4, q1
0xd9,0xee,0x02,0xee = vmlalv.s32 lr, r11, q4, q1
0x8f,0xee,0x0c,0x0e = vmlalv.s32 r0, r1, q7, q6
0xda,0xfe,0x08,0xee = vmlalv.u16 lr, r11, q5, q4
