# CS_ARCH_AARCH64, 0, None
0x30,0x00,0x00,0x54 = bc.eq	#4
0x51,0x00,0x00,0x54 = bc.ne	#8
0x92,0x00,0x00,0x54 = bc.hs	#16
0x13,0x01,0x00,0x54 = bc.lo	#32
0x14,0x02,0x00,0x54 = bc.mi	#64
0x15,0x04,0x00,0x54 = bc.pl	#128
0x16,0x08,0x00,0x54 = bc.vs	#256
0x17,0x10,0x00,0x54 = bc.vc	#512
0x18,0x20,0x00,0x54 = bc.hi	#1024
0x19,0x40,0x00,0x54 = bc.ls	#2048
0x1a,0x80,0x00,0x54 = bc.ge	#4096
0x1b,0x00,0x01,0x54 = bc.lt	#8192
0x1c,0x00,0x02,0x54 = bc.gt	#16384
0x1d,0x00,0x04,0x54 = bc.le	#32768
0x1e,0x00,0x08,0x54 = bc.al	#65536
