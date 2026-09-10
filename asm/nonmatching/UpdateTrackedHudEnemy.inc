	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r5, [r6, #0x1c]
	adds r1, r5, #0
	adds r1, #0x80
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _08035354
	movs r0, #0
	b _080353D8
_08035354:
	adds r4, r5, #0
	adds r4, #0x82
	ldrb r2, [r4]
	adds r0, r2, #0
	subs r0, #0x38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1a
	bhi _080353B4
	cmp r2, #0x4f
	bne _08035388
	movs r0, #0
	ldrsh r3, [r1, r0]
	ldr r2, _08035380 @ =gUnk_08351628
	ldr r0, _08035384 @ =gNumHumanPlayers
	ldrb r1, [r0]
	subs r1, #1
	lsls r1, r1, #1
	adds r0, r5, #0
	adds r0, #0x87
	ldrb r0, [r0]
	b _0803539A
	.align 2, 0
_08035380: .4byte gUnk_08351628
_08035384: .4byte gNumHumanPlayers
_08035388:
	movs r2, #0
	ldrsh r3, [r1, r2]
	ldr r2, _080353AC @ =gUnk_08351458
	ldr r0, _080353B0 @ =gNumHumanPlayers
	ldrb r1, [r0]
	subs r1, #1
	lsls r1, r1, #1
	ldrb r0, [r4]
	subs r0, #0x38
_0803539A:
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1]
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #0x10
	b _080353C8
	.align 2, 0
_080353AC: .4byte gUnk_08351458
_080353B0: .4byte gNumHumanPlayers
_080353B4:
	movs r5, #0
	ldrsh r2, [r1, r5]
	ldr r1, _080353FC @ =gUnk_083513E8
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	muls r1, r0, r1
	lsls r1, r1, #0x10
_080353C8:
	asrs r2, r1, #0x18
	strb r2, [r6, #0xa]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080353DA
	adds r0, r2, #1
_080353D8:
	strb r0, [r6, #0xa]
_080353DA:
	ldr r2, [r6, #0x1c]
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _08035428
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08035400
	movs r0, #0
	strb r0, [r6, #0xa]
	b _08035418
	.align 2, 0
_080353FC: .4byte gUnk_083513E8
_08035400:
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r1, _08035420 @ =0x060077A0
	ldr r2, _08035424 @ =0x01000080
	bl CpuSet
	strb r4, [r6, #9]
	strb r4, [r6, #0xa]
	movs r0, #0
	bl DrawEnemyHealthOrAreaName
_08035418:
	movs r0, #0
	str r0, [r6, #0x1c]
	b _0803556A
	.align 2, 0
_08035420: .4byte 0x060077A0
_08035424: .4byte 0x01000080
_08035428:
	ldr r1, _0803546C @ =gKirbys
	ldr r2, _08035470 @ =gLocalPlayerId
	ldrb r5, [r2]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r5, r0
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x60
	adds r1, r4, #0
	adds r1, #0x60
	ldrh r0, [r0]
	adds r7, r2, #0
	ldrh r1, [r1]
	cmp r0, r1
	bne _08035464
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08035464
	ldr r0, _08035474 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08035478
_08035464:
	mov r0, sp
	adds r0, #2
	b _08035550
	.align 2, 0
_0803546C: .4byte gKirbys
_08035470: .4byte gLocalPlayerId
_08035474: .4byte gUnk_0203AD10
_08035478:
	adds r0, r4, #0
	adds r0, #0x82
	ldrb r0, [r0]
	subs r0, #0x38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1a
	bhi _080354E8
	ldr r2, _080354D4 @ =gCurLevelInfo
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r2, #0
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r4, #0x40]
	ldr r5, _080354D8 @ =0xFFFF8800
	adds r3, r0, r5
	ldr r0, [r1]
	subs r1, r0, r3
	cmp r1, #0
	bge _080354A8
	subs r1, r3, r0
_080354A8:
	movs r0, #0xf0
	lsls r0, r0, #8
	cmp r1, r0
	bgt _0803554E
	ldrb r1, [r7]
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r1, r0, r1
	adds r0, r2, #0
	adds r0, #0x10
	adds r1, r1, r0
	ldr r0, [r4, #0x44]
	ldr r2, _080354DC @ =0xFFFFB000
	adds r3, r0, r2
	ldr r0, [r1]
	subs r1, r0, r3
	cmp r1, #0
	blt _080354E0
	movs r0, #0xc8
	lsls r0, r0, #8
	b _08035530
	.align 2, 0
_080354D4: .4byte gCurLevelInfo
_080354D8: .4byte 0xFFFF8800
_080354DC: .4byte 0xFFFFB000
_080354E0:
	subs r1, r3, r0
	movs r0, #0xc8
	lsls r0, r0, #8
	b _0803554A
_080354E8:
	ldr r2, _08035538 @ =gCurLevelInfo
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r2, #0
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r4, #0x40]
	ldr r5, _0803553C @ =0xFFFF8800
	adds r3, r0, r5
	ldr r0, [r1]
	subs r1, r0, r3
	cmp r1, #0
	bge _08035508
	subs r1, r3, r0
_08035508:
	movs r0, #0xa8
	lsls r0, r0, #8
	cmp r1, r0
	bgt _0803554E
	ldrb r1, [r7]
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r1, r0, r1
	adds r0, r2, #0
	adds r0, #0x10
	adds r1, r1, r0
	ldr r0, [r4, #0x44]
	ldr r2, _08035540 @ =0xFFFFB000
	adds r3, r0, r2
	ldr r0, [r1]
	subs r1, r0, r3
	cmp r1, #0
	blt _08035544
	movs r0, #0x80
	lsls r0, r0, #8
_08035530:
	cmp r1, r0
	bgt _0803554E
	b _0803556A
	.align 2, 0
_08035538: .4byte gCurLevelInfo
_0803553C: .4byte 0xFFFF8800
_08035540: .4byte 0xFFFFB000
_08035544:
	subs r1, r3, r0
	movs r0, #0x80
	lsls r0, r0, #8
_0803554A:
	cmp r1, r0
	ble _0803556A
_0803554E:
	add r0, sp, #4
_08035550:
	movs r4, #0
	strh r4, [r0]
	ldr r1, _08035574 @ =0x060077A0
	ldr r2, _08035578 @ =0x01000080
	bl CpuSet
	movs r5, #0
	strb r4, [r6, #9]
	strb r4, [r6, #0xa]
	movs r0, #0
	bl DrawEnemyHealthOrAreaName
	str r5, [r6, #0x1c]
_0803556A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035574: .4byte 0x060077A0
_08035578: .4byte 0x01000080

	.syntax divided
