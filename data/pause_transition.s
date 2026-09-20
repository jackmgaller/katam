	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2

	@ Unidentified suffix of the original callback-table range.
gUnk_0834BE00:: @ 0834BE00
	.incbin "baserom.gba", 0x34BE00, 0x20
