	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnk_08D60814:: @ 08D60814
	.incbin "baserom.gba", 0xD60814, 0x0000008

gAnimCmdTable:: @ 08D6081C
	.4byte sub_08155370
	.4byte sub_08155400
	.4byte AnimCmd_JumpBack
	.4byte AnimCmd_4
	.4byte AnimCmd_PlaySoundEffect
	.4byte sub_08155494
	.4byte AnimCmd_TranslateSprite
	.4byte AnimCmd_8
	.4byte AnimCmd_SetIdAndVariant
	.4byte AnimCmd_10
	.4byte AnimCmd_SetPriority
	.4byte AnimCmd_12

gUnk_08D6084C:: @ 08D6084C
	.incbin "baserom.gba", 0xD6084C, 0x0000018
