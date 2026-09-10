	.syntax unified
	.text

	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r2, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08035714 @ =gAbilityIconPalettes
	lsls r5, r4, #2
	adds r0, r5, r0
	ldr r0, [r0]
	lsls r1, r1, #0x1c
	lsrs r1, r1, #0x18
	movs r2, #0x10
	bl LoadBgPaletteAndBase
	ldr r2, _08035718 @ =gMainFlags
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	cmp r4, #0x1b
	bls _0803572C
	ldr r4, _0803571C @ =gUnk_03002EC0
	ldr r3, _08035720 @ =gUnk_030039A4
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r2, _08035724 @ =gAbilityIconGraphics
	ldr r0, _08035728 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #7
	adds r0, r5, r0
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #4
	adds r0, r0, r1
	str r6, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0xa0
	lsls r1, r1, #1
	b _08035766
	.align 2, 0
_08035714: .4byte gAbilityIconPalettes
_08035718: .4byte gMainFlags
_0803571C: .4byte gUnk_03002EC0
_08035720: .4byte gUnk_030039A4
_08035724: .4byte gAbilityIconGraphics
_08035728: .4byte gLanguage
_0803572C:
	ldr r4, _08035778 @ =gUnk_03002EC0
	ldr r3, _0803577C @ =gUnk_030039A4
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r2, _08035780 @ =gAbilityIconGraphics
	ldr r0, _08035784 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #7
	adds r0, r5, r0
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #4
	adds r0, r0, r1
	str r6, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0xf0
	lsls r1, r1, #2
_08035766:
	strh r1, [r0, #8]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035778: .4byte gUnk_03002EC0
_0803577C: .4byte gUnk_030039A4
_08035780: .4byte gAbilityIconGraphics
_08035784: .4byte gLanguage

	.syntax divided
