# CS_ARCH_ARM, CS_MODE_THUMB, None
0xef,0xf3,0x11,0x80 = mrs r0, basepri
0xef,0xf3,0x12,0x80 = mrs r0, basepri_max
0xef,0xf3,0x13,0x80 = mrs r0, faultmask
0x80,0xf3,0x11,0x88 = msr basepri, r0
0x80,0xf3,0x12,0x88 = msr basepri_max, r0
0x80,0xf3,0x13,0x88 = msr faultmask, r0