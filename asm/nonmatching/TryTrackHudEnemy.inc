	.syntax unified
	.text

	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _08034E34 @ =gGameplayHudTask
	ldr r2, [r0]
	ldrh r1, [r2, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08034E38
	ldrh r0, [r2, #6]
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #0x12
	adds r0, r0, r1
	b _08034E40
	.align 2, 0
_08034E34: .4byte gGameplayHudTask
_08034E38:
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r1, r0
_08034E40:
	adds r5, r0, #0
	ldr r0, _08034EA0 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08034E9A
	ldr r0, _08034EA4 @ =gCurTask
	ldr r0, [r0]
	ldr r1, [r0, #8]
	ldr r0, _08034EA8 @ =UpdateGameOverHudIndicators
	cmp r1, r0
	beq _08034E9A
	ldr r0, _08034EAC @ =UpdateBorrowLifeHud
	cmp r1, r0
	beq _08034E9A
	movs r0, #0x82
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0x5d
	bhi _08034E9A
	ldr r2, _08034EB0 @ =gKirbys
	ldr r0, _08034EB4 @ =gLocalPlayerId
	ldrb r1, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x60
	adds r1, r3, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08034E9A
	ldr r0, [r5, #0x1c]
	cmp r0, r3
	beq _08034E9A
	cmp r3, #0
	bne _08034EB8
	str r3, [r5, #0x1c]
	movs r0, #0
	bl DrawEnemyHealthOrAreaName
_08034E9A:
	movs r0, #0
	b _08034F9E
	.align 2, 0
_08034EA0: .4byte gUnk_0203AD10
_08034EA4: .4byte gCurTask
_08034EA8: .4byte UpdateGameOverHudIndicators
_08034EAC: .4byte UpdateBorrowLifeHud
_08034EB0: .4byte gKirbys
_08034EB4: .4byte gLocalPlayerId
_08034EB8:
	adds r0, r3, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _08034E9A
	ldr r4, [r3, #8]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r4, r0
	cmp r4, #0
	bne _08034E9A
	str r3, [r5, #0x1c]
	ldr r1, _08034F24 @ =gHudEnemyAndAreaNameGraphics
	ldr r0, _08034F28 @ =gLanguage
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r2, ip
	ldrb r1, [r2]
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _08034F2C @ =0x060077A0
	movs r2, #0x80
	bl CpuSet
	strb r4, [r5, #0xf]
	ldr r0, [r5, #0x1c]
	mov ip, r0
	mov r4, ip
	adds r4, #0x82
	ldrb r1, [r4]
	adds r0, r1, #0
	subs r0, #0x38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1a
	bhi _08034F68
	cmp r1, #0x4f
	bne _08034F38
	mov r0, ip
	adds r0, #0x80
	movs r1, #0
	ldrsh r3, [r0, r1]
	ldr r2, _08034F30 @ =gUnk_08351628
	ldr r0, _08034F34 @ =gNumHumanPlayers
	ldrb r1, [r0]
	subs r1, #1
	lsls r1, r1, #1
	mov r0, ip
	adds r0, #0x87
	ldrb r0, [r0]
	b _08034F4E
	.align 2, 0
_08034F24: .4byte gHudEnemyAndAreaNameGraphics
_08034F28: .4byte gLanguage
_08034F2C: .4byte 0x060077A0
_08034F30: .4byte gUnk_08351628
_08034F34: .4byte gNumHumanPlayers
_08034F38:
	mov r0, ip
	adds r0, #0x80
	movs r2, #0
	ldrsh r3, [r0, r2]
	ldr r2, _08034F60 @ =gUnk_08351458
	ldr r0, _08034F64 @ =gNumHumanPlayers
	ldrb r1, [r0]
	subs r1, #1
	lsls r1, r1, #1
	ldrb r0, [r4]
	subs r0, #0x38
_08034F4E:
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1]
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #0x10
	b _08034F80
	.align 2, 0
_08034F60: .4byte gUnk_08351458
_08034F64: .4byte gNumHumanPlayers
_08034F68:
	mov r0, ip
	adds r0, #0x80
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r1, _08034FA4 @ =gUnk_083513E8
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	muls r1, r0, r1
	lsls r1, r1, #0x10
_08034F80:
	asrs r2, r1, #0x18
	strb r2, [r5, #0xa]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08034F92
	adds r0, r2, #1
	strb r0, [r5, #0xa]
_08034F92:
	ldrb r0, [r5, #0xa]
	strb r0, [r5, #9]
	adds r0, r5, #0
	bl DrawEnemyHealthOrAreaName
	adds r0, r5, #0
_08034F9E:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08034FA4: .4byte gUnk_083513E8

	.syntax divided
