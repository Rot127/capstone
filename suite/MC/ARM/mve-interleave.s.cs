# CS_ARCH_ARM, CS_MODE_THUMB, None
0x9d,0xfc,0x00,0x1e = vld20.8 {q0, q1}, [sp]
0x90,0xfc,0x00,0x1e = vld20.8 {q0, q1}, [r0]
0xb0,0xfc,0x00,0x1e = vld20.8 {q0, q1}, [r0]!
0x9b,0xfc,0x00,0x1e = vld20.8 {q0, q1}, [r11]
0xb0,0xfc,0x00,0xbe = vld20.8 {q5, q6}, [r0]!
0x90,0xfc,0x20,0x1e = vld21.8 {q0, q1}, [r0]
0xb0,0xfc,0x20,0x7e = vld21.8 {q3, q4}, [r0]!
0x90,0xfc,0x80,0x1e = vld20.16 {q0, q1}, [r0]
0xb0,0xfc,0x80,0x1e = vld20.16 {q0, q1}, [r0]!
0x9b,0xfc,0x80,0x1e = vld20.16 {q0, q1}, [r11]
0xb0,0xfc,0x80,0xbe = vld20.16 {q5, q6}, [r0]!
0x90,0xfc,0xa0,0x1e = vld21.16 {q0, q1}, [r0]
0xb0,0xfc,0xa0,0x7e = vld21.16 {q3, q4}, [r0]!
0x90,0xfc,0x00,0x1f = vld20.32 {q0, q1}, [r0]
0xb0,0xfc,0x00,0x1f = vld20.32 {q0, q1}, [r0]!
0x9b,0xfc,0x00,0x1f = vld20.32 {q0, q1}, [r11]
0xb0,0xfc,0x00,0xbf = vld20.32 {q5, q6}, [r0]!
0x90,0xfc,0x20,0x1f = vld21.32 {q0, q1}, [r0]
0xb0,0xfc,0x20,0x7f = vld21.32 {q3, q4}, [r0]!
0x80,0xfc,0x00,0x1e = vst20.8 {q0, q1}, [r0]
0xa0,0xfc,0x00,0x1e = vst20.8 {q0, q1}, [r0]!
0x8b,0xfc,0x00,0x1e = vst20.8 {q0, q1}, [r11]
0xa0,0xfc,0x00,0xbe = vst20.8 {q5, q6}, [r0]!
0x80,0xfc,0x20,0x1e = vst21.8 {q0, q1}, [r0]
0xa0,0xfc,0x20,0x7e = vst21.8 {q3, q4}, [r0]!
0x80,0xfc,0x80,0x1e = vst20.16 {q0, q1}, [r0]
0xa0,0xfc,0x80,0x1e = vst20.16 {q0, q1}, [r0]!
0x8b,0xfc,0x80,0x1e = vst20.16 {q0, q1}, [r11]
0xa0,0xfc,0x80,0xbe = vst20.16 {q5, q6}, [r0]!
0x80,0xfc,0xa0,0x1e = vst21.16 {q0, q1}, [r0]
0xa0,0xfc,0xa0,0x7e = vst21.16 {q3, q4}, [r0]!
0x80,0xfc,0x00,0x1f = vst20.32 {q0, q1}, [r0]
0xa0,0xfc,0x00,0x1f = vst20.32 {q0, q1}, [r0]!
0x8b,0xfc,0x00,0x1f = vst20.32 {q0, q1}, [r11]
0xa0,0xfc,0x00,0xbf = vst20.32 {q5, q6}, [r0]!
0x80,0xfc,0x20,0x1f = vst21.32 {q0, q1}, [r0]
0xa0,0xfc,0x20,0x7f = vst21.32 {q3, q4}, [r0]!
0x90,0xfc,0x01,0x1e = vld40.8 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x01,0x1e = vld40.8 {q0, q1, q2, q3}, [r0]!
0x9b,0xfc,0x01,0x1e = vld40.8 {q0, q1, q2, q3}, [r11]
0xb0,0xfc,0x01,0x7e = vld40.8 {q3, q4, q5, q6}, [r0]!
0x90,0xfc,0x21,0x1e = vld41.8 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x21,0x9e = vld41.8 {q4, q5, q6, q7}, [r0]!
0x90,0xfc,0x41,0x1e = vld42.8 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x41,0x1e = vld42.8 {q0, q1, q2, q3}, [r0]!
0x90,0xfc,0x61,0x1e = vld43.8 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x61,0x9e = vld43.8 {q4, q5, q6, q7}, [r0]!
0x90,0xfc,0x81,0x1e = vld40.16 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x81,0x1e = vld40.16 {q0, q1, q2, q3}, [r0]!
0x9b,0xfc,0x81,0x1e = vld40.16 {q0, q1, q2, q3}, [r11]
0xb0,0xfc,0x81,0x7e = vld40.16 {q3, q4, q5, q6}, [r0]!
0x90,0xfc,0xa1,0x1e = vld41.16 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0xa1,0x9e = vld41.16 {q4, q5, q6, q7}, [r0]!
0x90,0xfc,0xc1,0x1e = vld42.16 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0xc1,0x1e = vld42.16 {q0, q1, q2, q3}, [r0]!
0x90,0xfc,0xe1,0x1e = vld43.16 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0xe1,0x9e = vld43.16 {q4, q5, q6, q7}, [r0]!
0x90,0xfc,0x01,0x1f = vld40.32 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x01,0x1f = vld40.32 {q0, q1, q2, q3}, [r0]!
0x9b,0xfc,0x01,0x1f = vld40.32 {q0, q1, q2, q3}, [r11]
0xb0,0xfc,0x01,0x7f = vld40.32 {q3, q4, q5, q6}, [r0]!
0x90,0xfc,0x21,0x1f = vld41.32 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x21,0x9f = vld41.32 {q4, q5, q6, q7}, [r0]!
0x90,0xfc,0x41,0x1f = vld42.32 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x41,0x1f = vld42.32 {q0, q1, q2, q3}, [r0]!
0x90,0xfc,0x61,0x1f = vld43.32 {q0, q1, q2, q3}, [r0]
0xb0,0xfc,0x61,0x9f = vld43.32 {q4, q5, q6, q7}, [r0]!
