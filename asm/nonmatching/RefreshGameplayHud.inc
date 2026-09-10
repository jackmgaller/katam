	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #4]
	ldr r2, _080357C4 @ =gKirbys
	ldr r0, _080357C8 @ =gLocalPlayerId
	ldrb r1, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0xdf
	ldrb r4, [r0]
	ldr r0, _080357CC @ =gGameplayHudTask
	ldr r2, [r0]
	ldrh r1, [r2, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080357D0
	ldrh r0, [r2, #6]
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #0x12
	adds r0, r0, r1
	b _080357D8
	.align 2, 0
_080357C4: .4byte gKirbys
_080357C8: .4byte gLocalPlayerId
_080357CC: .4byte gGameplayHudTask
_080357D0:
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r1, r0
_080357D8:
	mov sb, r0
	mov r1, sp
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08035850 @ =0x0600E000
	ldr r2, _08035854 @ =0x01000280
	mov r0, sp
	bl CpuSet
	ldr r0, _08035858 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08035880
	ldr r2, _0803585C @ =gKirbys
	ldr r0, _08035860 @ =gLocalPlayerId
	ldrb r1, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0xdf
	ldrb r0, [r0]
	ldr r4, _08035864 @ =0x0600E198
	lsls r0, r0, #5
	ldr r1, _08035868 @ =gHudPalettes
	adds r0, r0, r1
	movs r1, #0xf0
	movs r2, #0x10
	bl LoadBgPaletteAndBase
	ldr r1, _0803586C @ =gHudGameOverAndDemoGraphics
	ldr r0, _08035870 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08035874 @ =0x060070A0
	movs r2, #0x80
	lsls r2, r2, #3
	bl CpuSet
	movs r1, #0
	ldr r0, _08035878 @ =0x000001B5
	adds r3, r0, #0
	ldr r0, _0803587C @ =0xFFFFF000
	adds r2, r0, #0
_0803583C:
	adds r0, r1, r3
	orrs r0, r2
	strh r0, [r4]
	adds r4, #2
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #5
	bls _0803583C
	b _08035E0C
	.align 2, 0
_08035850: .4byte 0x0600E000
_08035854: .4byte 0x01000280
_08035858: .4byte gUnk_0203AD10
_0803585C: .4byte gKirbys
_08035860: .4byte gLocalPlayerId
_08035864: .4byte 0x0600E198
_08035868: .4byte gHudPalettes
_0803586C: .4byte gHudGameOverAndDemoGraphics
_08035870: .4byte gLanguage
_08035874: .4byte 0x060070A0
_08035878: .4byte 0x000001B5
_0803587C: .4byte 0xFFFFF000
_08035880:
	lsls r0, r4, #5
	ldr r5, _080358E4 @ =gHudPalettes
	adds r0, r0, r5
	movs r1, #0xf0
	movs r2, #0x10
	bl LoadBgPaletteAndBase
	ldr r1, _080358E8 @ =gGameplayHudTask
	mov r8, r1
	ldr r0, [r1]
	ldr r1, [r0, #8]
	ldr r0, _080358EC @ =UpdateGameOverHudIndicators
	cmp r1, r0
	bne _08035908
	ldr r4, _080358F0 @ =0x0600E18E
	ldr r1, _080358F4 @ =gHudGameOverAndDemoGraphics
	ldr r0, _080358F8 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _080358FC @ =0x060070A0
	movs r2, #0x80
	lsls r2, r2, #3
	bl CpuSet
	movs r0, #0
	ldr r2, _08035900 @ =0x00000185
	adds r6, r2, #0
	ldr r3, _08035904 @ =0xFFFFF000
	adds r5, r3, #0
_080358BE:
	movs r1, #0
	adds r3, r0, #1
	lsls r2, r0, #4
_080358C4:
	adds r0, r1, r6
	adds r0, r2, r0
	orrs r0, r5
	strh r0, [r4]
	adds r4, #2
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xf
	bls _080358C4
	adds r4, #0x20
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080358BE
	b _08035E0C
	.align 2, 0
_080358E4: .4byte gHudPalettes
_080358E8: .4byte gGameplayHudTask
_080358EC: .4byte UpdateGameOverHudIndicators
_080358F0: .4byte 0x0600E18E
_080358F4: .4byte gHudGameOverAndDemoGraphics
_080358F8: .4byte gLanguage
_080358FC: .4byte 0x060070A0
_08035900: .4byte 0x00000185
_08035904: .4byte 0xFFFFF000
_08035908:
	ldr r0, _08035960 @ =gKirbys
	mov sl, r0
	ldr r7, _08035964 @ =gLocalPlayerId
	ldrb r0, [r7]
	movs r6, #0xd4
	lsls r6, r6, #1
	muls r0, r6, r0
	add r0, sl
	adds r0, #0xdf
	ldrb r0, [r0]
	ldr r4, _08035968 @ =0x060070A0
	lsls r0, r0, #5
	adds r0, r0, r5
	movs r1, #0xf0
	movs r2, #0x10
	bl LoadBgPaletteAndBase
	ldr r0, _0803596C @ =gUnk_082EC7A0
	adds r1, r4, #0
	movs r2, #0xe0
	lsls r2, r2, #2
	bl CpuSet
	ldr r4, _08035970 @ =0x060077A0
	ldr r1, _08035974 @ =gHudEnemyAndAreaNameGraphics
	ldr r0, _08035978 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuSet
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #8]
	ldr r0, _0803597C @ =UpdateBorrowLifeHud
	cmp r1, r0
	bne _08035980
	bl DrawBorrowLifePrompt
	b _08035E0C
	.align 2, 0
_08035960: .4byte gKirbys
_08035964: .4byte gLocalPlayerId
_08035968: .4byte 0x060070A0
_0803596C: .4byte gUnk_082EC7A0
_08035970: .4byte 0x060077A0
_08035974: .4byte gHudEnemyAndAreaNameGraphics
_08035978: .4byte gLanguage
_0803597C: .4byte UpdateBorrowLifeHud
_08035980:
	ldrb r0, [r7]
	muls r0, r6, r0
	mov r3, sl
	adds r2, r0, r3
	adds r1, r2, #0
	adds r1, #0xdb
	ldrb r0, [r1]
	cmp r0, #0
	beq _080359A4
	adds r2, r0, #0
	ldr r0, _080359A0 @ =0x060078A0
	movs r1, #0xe
	bl LoadAbilityIconGraphicsAndPalette
	b _080359B2
	.align 2, 0
_080359A0: .4byte 0x060078A0
_080359A4:
	ldr r1, _08035A9C @ =0x00000103
	adds r0, r2, r1
	ldrb r2, [r0]
	ldr r0, _08035AA0 @ =0x060078A0
	movs r1, #0xe
	bl LoadAbilityIconGraphicsAndPalette
_080359B2:
	ldr r1, _08035AA4 @ =0x0600E48E
	ldr r2, _08035AA8 @ =0x0000F18F
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08035AAC @ =0x0000F190
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x3c
	adds r3, #0xf
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08035AB0 @ =0x0000F59F
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _08035AB4 @ =gLocalPlayerId
	ldrb r1, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r1, r0
	ldr r1, _08035AB8 @ =gKirbys
	adds r0, r0, r1
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r7, [r0]
	cmp r7, #0x63
	bls _080359FE
	movs r7, #0x63
_080359FE:
	movs r3, #0
	ldr r2, _08035ABC @ =gHudDecimalDivisors
	mov sl, r2
	ldr r0, _08035AC0 @ =0xFFFFF000
	mov r8, r0
_08035A08:
	adds r5, r3, #0
	adds r5, #0xa
	lsls r5, r5, #1
	ldr r1, _08035AC4 @ =0x0600E480
	adds r6, r5, r1
	adds r4, r3, #6
	lsls r4, r4, #2
	add r4, sl
	ldr r1, [r4]
	adds r0, r7, #0
	str r3, [sp, #8]
	bl __udivsi3
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	ldr r1, [r4]
	muls r0, r1, r0
	subs r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _08035AC8 @ =0x00000185
	adds r0, r2, r1
	mov r1, r8
	orrs r0, r1
	strh r0, [r6]
	ldr r0, _08035ACC @ =0x0600E4C0
	adds r6, r5, r0
	ldr r1, _08035AD0 @ =0x00000195
	adds r0, r2, r1
	mov r2, r8
	orrs r0, r2
	strh r0, [r6]
	ldr r3, [sp, #8]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #1
	bls _08035A08
	ldr r6, _08035AB4 @ =gLocalPlayerId
	ldrb r0, [r6]
	movs r5, #0xd4
	lsls r5, r5, #1
	muls r0, r5, r0
	ldr r4, _08035AB8 @ =gKirbys
	adds r0, r0, r4
	bl DrawKirbyHealthBar
	mov r3, sb
	ldrb r0, [r3, #0x14]
	bl DrawHudAbilityIconRows
	ldr r2, _08035AD4 @ =gRoomProps
	ldrb r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	adds r0, #0x60
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #0x12]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08035AE4
	ldr r1, _08035AD8 @ =0x0600E002
	ldr r2, _08035ADC @ =0x0000F1B0
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x40
	ldr r3, _08035AE0 @ =0x0000F1B1
	adds r0, r3, #0
	b _08035AEE
	.align 2, 0
_08035A9C: .4byte 0x00000103
_08035AA0: .4byte 0x060078A0
_08035AA4: .4byte 0x0600E48E
_08035AA8: .4byte 0x0000F18F
_08035AAC: .4byte 0x0000F190
_08035AB0: .4byte 0x0000F59F
_08035AB4: .4byte gLocalPlayerId
_08035AB8: .4byte gKirbys
_08035ABC: .4byte gHudDecimalDivisors
_08035AC0: .4byte 0xFFFFF000
_08035AC4: .4byte 0x0600E480
_08035AC8: .4byte 0x00000185
_08035ACC: .4byte 0x0600E4C0
_08035AD0: .4byte 0x00000195
_08035AD4: .4byte gRoomProps
_08035AD8: .4byte 0x0600E002
_08035ADC: .4byte 0x0000F1B0
_08035AE0: .4byte 0x0000F1B1
_08035AE4:
	ldr r1, _08035B5C @ =0x0600E002
	ldr r2, _08035B60 @ =0x0000F184
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x40
_08035AEE:
	strh r0, [r1]
	ldr r0, _08035B64 @ =gLocalPlayerId
	ldrb r1, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r1, r0
	ldr r1, _08035B68 @ =gKirbys
	adds r0, r0, r1
	bl DrawPhoneBattery
	ldr r0, _08035B6C @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08035B2C
	ldr r2, _08035B70 @ =0x0600E4AA
	movs r1, #0
	ldr r3, _08035B74 @ =0x000001BD
	adds r4, r3, #0
	ldr r0, _08035B78 @ =0xFFFFF000
	adds r3, r0, #0
_08035B1A:
	adds r0, r1, r4
	orrs r0, r3
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #7
	bls _08035B1A
_08035B2C:
	mov r1, sb
	ldr r2, [r1, #0x1c]
	cmp r2, #0
	beq _08035B88
	ldr r1, _08035B7C @ =gHudEnemyAndAreaNameGraphics
	ldr r0, _08035B80 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x82
	ldrb r1, [r1]
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _08035B84 @ =0x060077A0
	movs r2, #0x80
	bl CpuSet
	mov r0, sb
	bl DrawEnemyHealthOrAreaName
	b _08035B9C
	.align 2, 0
_08035B5C: .4byte 0x0600E002
_08035B60: .4byte 0x0000F184
_08035B64: .4byte gLocalPlayerId
_08035B68: .4byte gKirbys
_08035B6C: .4byte gUnk_0203AD10
_08035B70: .4byte 0x0600E4AA
_08035B74: .4byte 0x000001BD
_08035B78: .4byte 0xFFFFF000
_08035B7C: .4byte gHudEnemyAndAreaNameGraphics
_08035B80: .4byte gLanguage
_08035B84: .4byte 0x060077A0
_08035B88:
	mov r0, sp
	adds r0, #2
	strh r2, [r0]
	ldr r1, _08035BFC @ =0x060077A0
	ldr r2, _08035C00 @ =0x01000080
	bl CpuSet
	movs r0, #0
	bl DrawEnemyHealthOrAreaName
_08035B9C:
	ldr r2, _08035C04 @ =gUnk_02021580
	ldr r1, _08035C08 @ =gNumKirbys
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	blo _08035BAA
	b _08035E0C
_08035BAA:
	ldr r3, _08035C0C @ =gKirbys
	adds r1, r0, #0
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r3, #0
	adds r0, #0xc
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	ldr r5, [sp, #4]
	adds r5, #0x60
	cmp r0, #0
	bne _08035BDA
	adds r0, r2, r3
	adds r0, #0x60
	ldrh r0, [r0]
	ldrh r2, [r5]
	cmp r0, r2
	bne _08035BDA
	b _08035E0C
_08035BDA:
	ldr r2, _08035C10 @ =gRoomProps
	ldrh r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08035BF2
	b _08035E0C
_08035BF2:
	movs r6, #1
	movs r4, #1
	ldr r7, _08035C14 @ =gUnk_0835105C
	b _08035C1E
	.align 2, 0
_08035BFC: .4byte 0x060077A0
_08035C00: .4byte 0x01000080
_08035C04: .4byte gUnk_02021580
_08035C08: .4byte gNumKirbys
_08035C0C: .4byte gKirbys
_08035C10: .4byte gRoomProps
_08035C14: .4byte gUnk_0835105C
_08035C18:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08035C1E:
	cmp r4, #8
	bhi _08035C40
	lsls r0, r4, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	ldrh r3, [r5]
	cmp r0, r3
	bne _08035C18
	movs r0, #1
	adds r1, r4, #0
	movs r2, #0
	bl GetStateSlot
	ldr r0, [r0]
	cmp r0, #0
	beq _08035C18
	movs r6, #0
_08035C40:
	movs r4, #9
	b _08035C4A
_08035C44:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08035C4A:
	cmp r4, #0xd
	bhi _08035C72
	ldr r0, _08035CB8 @ =gUnk_0835105C
	lsls r1, r4, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r1, [r5]
	cmp r0, r1
	bne _08035C44
	adds r1, r4, #3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #1
	movs r2, #0
	bl GetStateSlot
	ldr r0, [r0]
	cmp r0, #0
	beq _08035C44
	movs r6, #0
_08035C72:
	cmp r6, #0
	bne _08035C78
	b _08035E0C
_08035C78:
	ldr r1, _08035CBC @ =gKirbys
	ldr r0, _08035CC0 @ =gUnk_02021580
	ldrb r2, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r1, #0xc
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _08035CA4
	ldr r2, [sp, #4]
	movs r3, #0x81
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08035CA4
	b _08035E02
_08035CA4:
	mov r2, sb
	ldrb r0, [r2, #0xe]
	cmp r0, #0x5f
	bhi _08035CCC
	cmp r1, #0
	beq _08035CC4
	movs r0, #1
	bl DrawLifeSharingHudMessage
	b _08035D18
	.align 2, 0
_08035CB8: .4byte gUnk_0835105C
_08035CBC: .4byte gKirbys
_08035CC0: .4byte gUnk_02021580
_08035CC4:
	movs r0, #1
	bl DrawCallHudMessage
	b _08035D18
_08035CCC:
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5f
	bhi _08035CEA
	cmp r1, #0
	beq _08035CE2
	movs r0, #2
	bl DrawLifeSharingHudMessage
	b _08035D18
_08035CE2:
	movs r0, #2
	bl DrawCallHudMessage
	b _08035D18
_08035CEA:
	cmp r1, #0
	beq _08035CF6
	movs r0, #0
	bl DrawLifeSharingHudMessage
	b _08035CFC
_08035CF6:
	movs r0, #0
	bl DrawCallHudMessage
_08035CFC:
	ldr r1, _08035D78 @ =0x0600E002
	ldr r3, _08035D7C @ =0x0000F1B0
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #0x40
	ldr r2, _08035D80 @ =0x0000F1B1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, [sp, #4]
	bl DrawPhoneBattery
	movs r0, #0
	mov r3, sb
	strb r0, [r3, #0xd]
_08035D18:
	mov r1, sb
	ldrb r0, [r1, #0xe]
	cmp r0, #0x5f
	bls _08035D2A
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5f
	bhi _08035DB4
_08035D2A:
	ldr r0, _08035D84 @ =gLocalPlayerId
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, sb
	adds r4, r2, r0
	ldr r1, _08035D88 @ =gKirbys
	ldr r3, _08035D8C @ =gUnk_02021580
	ldrb r2, [r3]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldrb r0, [r3]
	strb r0, [r4, #0x1f]
	movs r0, #0xff
	strb r0, [r4, #0x1b]
	ldr r0, _08035D90 @ =gUnk_0203AD20
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08035D94
	movs r0, #0x91
	strh r0, [r4, #0x12]
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	b _08035D9E
	.align 2, 0
_08035D78: .4byte 0x0600E002
_08035D7C: .4byte 0x0000F1B0
_08035D80: .4byte 0x0000F1B1
_08035D84: .4byte gLocalPlayerId
_08035D88: .4byte gKirbys
_08035D8C: .4byte gUnk_02021580
_08035D90: .4byte gUnk_0203AD20
_08035D94:
	movs r0, #0xf
	strh r0, [r4, #0x12]
	ldr r0, [r4, #8]
	ldr r1, _08035DB0 @ =0xFFFFF7FF
	ands r0, r1
_08035D9E:
	str r0, [r4, #8]
	adds r0, r4, #0
	bl sub_08155128
	adds r0, r4, #0
	bl DisplaySprite
	b _08035E02
	.align 2, 0
_08035DB0: .4byte 0xFFFFF7FF
_08035DB4:
	ldr r1, _08035DD8 @ =gKirbys
	ldr r0, _08035DDC @ =gUnk_02021580
	ldrb r2, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r1, #0xc
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	beq _08035DE0
	movs r0, #0
	bl DrawLifeSharingHudMessage
	b _08035DE6
	.align 2, 0
_08035DD8: .4byte gKirbys
_08035DDC: .4byte gUnk_02021580
_08035DE0:
	movs r0, #0
	bl DrawCallHudMessage
_08035DE6:
	ldr r1, _08035E1C @ =0x0600E002
	ldr r2, _08035E20 @ =0x0000F1B0
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x40
	ldr r3, _08035E24 @ =0x0000F1B1
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, [sp, #4]
	bl DrawPhoneBattery
	movs r0, #0
	mov r1, sb
	strb r0, [r1, #0xd]
_08035E02:
	mov r2, sb
	ldr r0, [r2, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x10]
_08035E0C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035E1C: .4byte 0x0600E002
_08035E20: .4byte 0x0000F1B0
_08035E24: .4byte 0x0000F1B1

	.syntax divided
