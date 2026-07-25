	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnk_08357B18:: @ 08357B18
	.incbin "baserom.gba", 0x357B18, 0x000000C

gUnk_08357B24:: @ 08357B24
	.incbin "baserom.gba", 0x357B24, 0x000001A

gUnk_08357B3E:: @ 08357B3E
	.incbin "baserom.gba", 0x357B3E, 0x000004E

gUnk_08357B8C:: @ 08357B8C
	.4byte nullsub_127
	.4byte sub_08039728
	.4byte sub_08039794
	.4byte sub_08039800
	.4byte sub_0803986C
	.4byte sub_080398D8
	.4byte sub_08039944
	.4byte sub_080399B0
	.4byte sub_08039A1C
	.4byte sub_08039A88
	.4byte sub_08039AF4
	.4byte sub_08039B60
	.4byte sub_08039BCC
	.4byte sub_08039C38
	.4byte sub_08039CA4
	.4byte sub_08039D10
	.4byte sub_080396BC

gUnk_08357BD0:: @ 08357BD0
	.incbin "baserom.gba", 0x357BD0, 0x000000C

gUnk_08357BDC:: @ 08357BDC
	.incbin "baserom.gba", 0x357BDC, 0x000000C
