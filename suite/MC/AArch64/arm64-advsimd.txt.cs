# CS_ARCH_AARCH64, None, None
# This regression test file is new. The option flags could not be determined.
# LLVM uses the following mattr = ['mattr=crypto']
0x41 0xd8 0x70 0x7e == faddp.2d	d1, v2
0x83 0xd8 0x30 0x7e == faddp.2s	s3, v4
0x82 0x70 0x01 0x4e == tbl.16b	v2, { v4, v5, v6, v7 }, v1
0x80 0x70 0x01 0x0e == tbl.8b	v0, { v4, v5, v6, v7 }, v1
0xa2 0x10 0x01 0x4e == tbl.16b	v2, { v5 }, v1
0xa0 0x10 0x01 0x0e == tbl.8b	v0, { v5 }, v1
0xa2 0x50 0x01 0x4e == tbl.16b	v2, { v5, v6, v7 }, v1
0xa0 0x50 0x01 0x0e == tbl.8b	v0, { v5, v6, v7 }, v1
0xc2 0x30 0x01 0x4e == tbl.16b	v2, { v6, v7 }, v1
0xc0 0x30 0x01 0x0e == tbl.8b	v0, { v6, v7 }, v1
0x00 0xd0 0x60 0x5e == sqdmull	s0, h0, h0
0x00 0xd0 0xa0 0x5e == sqdmull	d0, s0, s0
0xca 0xcd 0xc7 0x4d == ld1r.2d	{ v10 }, [x14], x7
0xea 0xc9 0xe7 0x4d == ld2r.4s	{ v10, v11 }, [x15], x7
0xea 0xe9 0xc7 0x4d == ld3r.4s	{ v10, v11, v12 }, [x15], x7
0xea 0xe9 0xe7 0x4d == ld4r.4s	{ v10, v11, v12, v13 }, [x15], x7
0x62 0xdc 0x21 0x5e == fmulx	s2, s3, s1
0x62 0xdc 0x61 0x5e == fmulx	d2, d3, d1
0xe8 0x6b 0xdf 0x4c == ld1.4s	{ v8, v9, v10 }, [sp], #48
