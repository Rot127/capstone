# CS_ARCH_ARM, CS_MODE_THUMB, None
0xc9,0x1c = adds r1, r1, #3
0x03,0x31 = adds r1, #3
0x08,0x30 = adds r0, #8
0x00,0x18 = adds r0, r0, r0
0x40,0x44 = add r0, r8
0x41,0x44 = add r1, r8
0x85,0x44 = add sp, r0
0x6c,0x44 = add r4, sp, r4
0x6c,0x44 = add r4, sp
0x08,0xb0 = add sp, #0x20
0xfe,0xad = add r5, sp, #0x3f8
0x08,0x44 = add r0, r1
0x1a,0x44 = add r2, r3
0x00,0x1a = subs r0, r0, r0
0x5b,0x1f = subs r3, r3, #5
0x05,0x3b = subs r3, #5
0x08,0x3a = subs r2, #8
0x84,0xb0 = sub sp, #0x10
0x08,0x40 = ands r0, r1
0x08,0x40 = ands r0, r1
0x48,0x40 = eors r0, r1
0x48,0x40 = eors r0, r1
0x88,0x40 = lsls r0, r1
0xc8,0x40 = lsrs r0, r1
0x08,0x41 = asrs r0, r1
0x48,0x41 = adcs r0, r1
0x48,0x41 = adcs r0, r1
0x88,0x41 = sbcs r0, r1
0xc8,0x41 = rors r0, r1
0x08,0x43 = orrs r0, r1
0x08,0x43 = orrs r0, r1
0x88,0x43 = bics r0, r1
