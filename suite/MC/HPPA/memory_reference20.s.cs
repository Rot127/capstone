# CS_ARCH_HPPA, CS_MODE_HPPA_20+CS_MODE_BIG_ENDIAN, None
0x0c,0x41,0x40,0x03 = ldb	r1(sr1,rp),r3
0x0c,0x41,0x60,0x03 = ldb,s	r1(sr1,rp),r3
0x0c,0x41,0x60,0x23 = ldb,sm	r1(sr1,rp),r3
0x0c,0x41,0x40,0x23 = ldb,m	r1(sr1,rp),r3
0x0c,0x51,0x50,0x03 = ldb	-8(sr1,rp),r3
0x0c,0x51,0x50,0x23 = ldb,ma	-8(sr1,rp),r3
0x0c,0x51,0x70,0x23 = ldb,mb	-8(sr1,rp),r3
0x0c,0x50,0x58,0x03 = ldb,sl	8(sr1,rp),r3
0x0c,0x41,0x40,0x43 = ldh	r1(sr1,rp),r3
0x0c,0x41,0x60,0x43 = ldh,s	r1(sr1,rp),r3
0x0c,0x41,0x60,0x63 = ldh,sm	r1(sr1,rp),r3
0x0c,0x41,0x40,0x63 = ldh,m	r1(sr1,rp),r3
0x44,0x43,0x41,0xbc = ldh	0xde(sr1,rp),r3
0x0c,0x51,0x50,0x63 = ldh,ma	-8(sr1,rp),r3
0x0c,0x51,0x70,0x63 = ldh,mb	-8(sr1,rp),r3
0x0c,0x50,0x58,0x43 = ldh,sl	8(sr1,rp),r3
0x0c,0x41,0x40,0x83 = ldw	r1(sr1,rp),r3
0x0c,0x41,0x60,0x83 = ldw,s	r1(sr1,rp),r3
0x0c,0x41,0x60,0xa3 = ldw,sm	r1(sr1,rp),r3
0x0c,0x41,0x40,0xa3 = ldw,m	r1(sr1,rp),r3
0x48,0x43,0x41,0xbc = ldw	0xde(sr1,rp),r3
0x0c,0x51,0x50,0xa3 = ldw,ma	-8(sr1,rp),r3
0x0c,0x51,0x70,0xa3 = ldw,mb	-8(sr1,rp),r3
0x0c,0x50,0x58,0x83 = ldw,sl	8(sr1,rp),r3
0x0c,0x41,0x40,0xc3 = ldd	r1(sr1,rp),r3
0x0c,0x41,0x60,0xc3 = ldd,s	r1(sr1,rp),r3
0x0c,0x41,0x60,0xe3 = ldd,sm	r1(sr1,rp),r3
0x0c,0x41,0x40,0xe3 = ldd,m	r1(sr1,rp),r3
0x0c,0x51,0x50,0xc3 = ldd	-8(sr1,rp),r3
0x0c,0x51,0x50,0xe3 = ldd,ma	-8(sr1,rp),r3
0x0c,0x51,0x70,0xe3 = ldd,mb	-8(sr1,rp),r3
0x0c,0x50,0x58,0xc3 = ldd,sl	8(sr1,rp),r3
0x60,0x21,0xbf,0xb1 = stb	r1,-0x28(sr2,r1)
0x0c,0x21,0x92,0x31 = stb,ma	r1,-8(sr2,r1)
0x0c,0x21,0xb2,0x31 = stb,mb	r1,-8(sr2,r1)
0x0c,0x21,0x92,0x20 = stb,o	r1,0(sr2,r1)
0x64,0x21,0xbf,0xb1 = sth	r1,-0x28(sr2,r1)
0x0c,0x21,0x92,0x71 = sth,ma	r1,-8(sr2,r1)
0x0c,0x21,0xb2,0x71 = sth,mb	r1,-8(sr2,r1)
0x0c,0x21,0x92,0x60 = sth,o	r1,0(sr2,r1)
0x68,0x21,0xbf,0xb1 = stw	r1,-0x28(sr2,r1)
0x0c,0x21,0x92,0xb1 = stw,ma	r1,-8(sr2,r1)
0x0c,0x21,0xb2,0xb1 = stw,mb	r1,-8(sr2,r1)
0x0c,0x21,0x92,0xa0 = stw,o	r1,0(sr2,r1)
0x70,0x21,0xbf,0xb1 = std	r1,-0x28(sr2,r1)
0x0c,0x21,0x92,0xf1 = std,ma	r1,-8(sr2,r1)
0x0c,0x21,0xb2,0xf1 = std,mb	r1,-8(sr2,r1)
0x0c,0x21,0x92,0xe0 = std,o	r1,0(sr2,r1)
0x0c,0x41,0x01,0x83 = ldwa	r1(rp),r3
0x0c,0x41,0x21,0x83 = ldwa,s	r1(rp),r3
0x0c,0x41,0x21,0xa3 = ldwa,sm	r1(rp),r3
0x0c,0x41,0x01,0xa3 = ldwa,m	r1(rp),r3
0x0c,0x51,0x11,0x83 = ldwa	-8(rp),r3
0x0c,0x51,0x11,0xa3 = ldwa,ma	-8(rp),r3
0x0c,0x51,0x31,0xa3 = ldwa,mb	-8(rp),r3
0x0c,0x50,0x19,0x83 = ldwa,sl	8(rp),r3
0x0c,0x40,0x11,0xa3 = ldwa,o	0(rp),r3
0x0c,0x41,0x01,0x03 = ldda	r1(rp),r3
0x0c,0x41,0x21,0x03 = ldda,s	r1(rp),r3
0x0c,0x41,0x21,0x23 = ldda,sm	r1(rp),r3
0x0c,0x41,0x01,0x23 = ldda,m	r1(rp),r3
0x0c,0x51,0x11,0x03 = ldda	-8(rp),r3
0x0c,0x51,0x11,0x23 = ldda,ma	-8(rp),r3
0x0c,0x51,0x31,0x23 = ldda,mb	-8(rp),r3
0x0c,0x50,0x19,0x03 = ldda,sl	8(rp),r3
0x0c,0x40,0x11,0x23 = ldda,o	0(rp),r3
0x0c,0x21,0x13,0x91 = stwa	r1,-8(r1)
0x0c,0x21,0x13,0xb1 = stwa,ma	r1,-8(r1)
0x0c,0x21,0x33,0xb1 = stwa,mb	r1,-8(r1)
0x0c,0x21,0x13,0xa0 = stwa,o	r1,0(r1)
0x0c,0x21,0x13,0xd1 = stda	r1,-8(r1)
0x0c,0x21,0x13,0xf1 = stda,ma	r1,-8(r1)
0x0c,0x21,0x33,0xf1 = stda,mb	r1,-8(r1)
0x0c,0x21,0x13,0xe0 = stda,o	r1,0(r1)
0x0c,0x41,0x41,0xc3 = ldcw	r1(sr1,rp),r3
0x0c,0x41,0x61,0xc3 = ldcw,s	r1(sr1,rp),r3
0x0c,0x41,0x61,0xe3 = ldcw,sm	r1(sr1,rp),r3
0x0c,0x41,0x41,0xe3 = ldcw,m	r1(sr1,rp),r3
0x0c,0x51,0x51,0xc3 = ldcw	-8(sr1,rp),r3
0x0c,0x51,0x51,0xe3 = ldcw,ma	-8(sr1,rp),r3
0x0c,0x51,0x71,0xe3 = ldcw,mb	-8(sr1,rp),r3
0x0c,0x40,0x55,0xc3 = ldcw,co	0(sr1,rp),r3
0x0c,0x41,0x41,0x43 = ldcd	r1(sr1,rp),r3
0x0c,0x41,0x61,0x43 = ldcd,s	r1(sr1,rp),r3
0x0c,0x41,0x61,0x63 = ldcd,sm	r1(sr1,rp),r3
0x0c,0x41,0x41,0x63 = ldcd,m	r1(sr1,rp),r3
0x0c,0x51,0x51,0x43 = ldcd	-8(sr1,rp),r3
0x0c,0x51,0x51,0x63 = ldcd,ma	-8(sr1,rp),r3
0x0c,0x51,0x71,0x63 = ldcd,mb	-8(sr1,rp),r3
0x0c,0x40,0x55,0x43 = ldcd,co	0(sr1,rp),r3
0x0c,0x41,0x53,0x11 = stby	r1,-8(sr1,rp)
0x0c,0x41,0x53,0x31 = stby,b,m	r1,-8(sr1,rp)
0x0c,0x41,0x73,0x11 = stby,e	r1,-8(sr1,rp)
0x0c,0x41,0x73,0x31 = stby,e,m	r1,-8(sr1,rp)
0x0c,0x41,0x53,0x51 = stdby	r1,-8(sr1,rp)
0x0c,0x41,0x53,0x71 = stdby,b,m	r1,-8(sr1,rp)
0x0c,0x41,0x73,0x51 = stdby,e	r1,-8(sr1,rp)
0x0c,0x41,0x73,0x71 = stdby,e,m	r1,-8(sr1,rp)