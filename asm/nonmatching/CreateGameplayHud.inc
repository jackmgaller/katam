	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r1, _08033920 @ =gBgCntRegs
	movs r4, #0
	ldr r0, _08033924 @ =0x00001C04
	strh r0, [r1, #2]
	add r1, sp, #4
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08033928 @ =0x0600E000
	ldr r2, _0803392C @ =0x01000400
	add r0, sp, #4
	bl CpuSet
	mov r0, sp
	adds r0, #6
	strh r4, [r0]
	ldr r1, _08033930 @ =0x06007080
	ldr r2, _08033934 @ =0x01000300
	bl CpuSet
	ldr r0, _08033938 @ =gBgScrollRegs
	strh r4, [r0, #4]
	strh r4, [r0, #6]
	ldr r0, _0803393C @ =UpdateGameplayHud
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xf5
	lsls r2, r2, #8
	ldr r3, _08033940 @ =GameplayHudDestructor
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	adds r5, r0, #0
	ldr r0, _08033944 @ =gGameplayHudTask
	str r5, [r0]
	ldrh r1, [r5, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08033948
	ldrh r0, [r5, #6]
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #0x12
	adds r1, r0, r1
	b _08033950
	.align 2, 0
_08033920: .4byte gBgCntRegs
_08033924: .4byte 0x00001C04
_08033928: .4byte 0x0600E000
_0803392C: .4byte 0x01000400
_08033930: .4byte 0x06007080
_08033934: .4byte 0x01000300
_08033938: .4byte gBgScrollRegs
_0803393C: .4byte UpdateGameplayHud
_08033940: .4byte GameplayHudDestructor
_08033944: .4byte gGameplayHudTask
_08033948:
	ldrh r1, [r5, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r1, r1, r0
_08033950:
	adds r6, r1, #0
	add r0, sp, #8
	movs r3, #0
	mov r8, r3
	strh r3, [r0]
	ldr r2, _08033984 @ =0x01000100
	bl CpuSet
	ldr r4, _08033988 @ =gLocalPlayerId
	ldrb r1, [r4]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r1, r0
	ldr r1, _0803398C @ =gKirbys
	adds r4, r0, r1
	ldr r0, _08033990 @ =gUnk_0203AD10
	ldr r7, [r0]
	movs r0, #0x10
	ands r7, r0
	cmp r7, #0
	beq _08033998
	bl DrawDemoHud
	ldr r0, _08033994 @ =HideKirbySpritesInOtherRooms
	str r0, [r5, #8]
	b _08033B82
	.align 2, 0
_08033984: .4byte 0x01000100
_08033988: .4byte gLocalPlayerId
_0803398C: .4byte gKirbys
_08033990: .4byte gUnk_0203AD10
_08033994: .4byte HideKirbySpritesInOtherRooms
_08033998:
	bl LoadGameplayHudGraphics
	ldr r2, _08033A90 @ =0x00000103
	adds r0, r4, r2
	ldrb r0, [r0]
	bl LoadHudAbilityIcon
	bl DrawHudLivesLabel
	adds r0, r4, #0
	bl DrawHudLivesCount
	adds r0, r4, #0
	bl DrawKirbyHealthBar
	movs r0, #2
	bl DrawHudAbilityIconRows
	bl DrawHudPhoneIcon
	adds r0, r4, #0
	bl DrawPhoneBattery
	bl DrawHudEnemyNameTiles
	movs r0, #0
	bl DrawEnemyHealthOrAreaName
	mov r0, sp
	adds r0, #0xa
	strh r7, [r0]
	ldr r1, _08033A94 @ =0x060077A0
	ldr r2, _08033A98 @ =0x01000080
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0xec
	ldr r0, [r0]
	str r0, [r6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r6, #6]
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r6, #7]
	adds r0, r4, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	strb r0, [r6, #0xc]
	ldr r2, _08033A9C @ =gRoomProps
	adds r0, r4, #0
	adds r0, #0x60
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r1, [r0, #0x12]
	movs r0, #8
	ands r0, r1
	strb r0, [r6, #0xb]
	movs r0, #0x80
	strh r0, [r6, #4]
	mov r2, r8
	strb r2, [r6, #9]
	strb r2, [r6, #0xa]
	strb r2, [r6, #0xf]
	str r7, [r6, #0x1c]
	strb r2, [r6, #0xe]
	str r7, [r6, #0x10]
	strb r2, [r6, #0xd]
	movs r7, #0
	ldr r0, _08033AA0 @ =gNumKirbys
	ldrb r3, [r0]
	cmp r7, r3
	blo _08033A3A
	b _08033B82
_08033A3A:
	movs r5, #0
	movs r4, #0x80
	mov sl, r4
	movs r1, #0xff
	mov sb, r1
	movs r2, #0x10
	mov r8, r2
	ldr r3, _08033AA4 @ =gKirbys
	mov ip, r3
_08033A4C:
	ldr r4, _08033AA8 @ =gLocalPlayerId
	ldrb r0, [r4]
	cmp r0, r7
	bne _08033AB0
	lsls r2, r7, #2
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r1, r0, #0
	adds r1, #0x20
	str r5, [r0, #0x20]
	mov r0, sl
	strh r0, [r1, #0x14]
	ldr r0, _08033AAC @ =0x000002DB
	strh r0, [r1, #0xc]
	movs r0, #1
	strb r0, [r1, #0x1a]
	strh r5, [r1, #0x16]
	ldrb r0, [r1, #0x1b]
	mov r3, sb
	orrs r0, r3
	strb r0, [r1, #0x1b]
	mov r4, r8
	strb r4, [r1, #0x1c]
	strb r5, [r1, #0x1f]
	movs r0, #8
	strh r0, [r1, #0x10]
	movs r0, #0xf
	strh r0, [r1, #0x12]
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r1, #8]
	b _08033AF8
	.align 2, 0
_08033A90: .4byte 0x00000103
_08033A94: .4byte 0x060077A0
_08033A98: .4byte 0x01000080
_08033A9C: .4byte gRoomProps
_08033AA0: .4byte gNumKirbys
_08033AA4: .4byte gKirbys
_08033AA8: .4byte gLocalPlayerId
_08033AAC: .4byte 0x000002DB
_08033AB0:
	lsls r4, r7, #2
	adds r1, r4, r7
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r2, r1, #0
	adds r2, #0x20
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r3, r7, #0
	muls r3, r0, r3
	mov r0, ip
	adds r0, #0x10
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1, #0x20]
	mov r0, sl
	strh r0, [r2, #0x14]
	strh r5, [r2, #0xc]
	strb r5, [r2, #0x1a]
	strh r5, [r2, #0x16]
	ldrb r0, [r2, #0x1b]
	mov r1, sb
	orrs r0, r1
	strb r0, [r2, #0x1b]
	mov r0, r8
	strb r0, [r2, #0x1c]
	add r3, ip
	adds r3, #0x2f
	ldrb r0, [r3]
	strb r0, [r2, #0x1f]
	strh r5, [r2, #0x10]
	strh r5, [r2, #0x12]
	movs r1, #0x84
	lsls r1, r1, #0xb
	str r1, [r2, #8]
	adds r2, r4, #0
_08033AF8:
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r3, r0, r6
	adds r1, r3, #0
	adds r1, #0xc0
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r2, r7, #0
	muls r2, r0, r2
	mov r0, ip
	adds r0, #0x10
	adds r0, r2, r0
	ldr r0, [r0]
	adds r0, #0x80
	str r0, [r1]
	mov r4, sl
	strh r4, [r1, #0x14]
	strh r5, [r1, #0xc]
	strb r5, [r1, #0x1a]
	strh r5, [r1, #0x16]
	ldrb r0, [r1, #0x1b]
	mov r4, sb
	orrs r0, r4
	strb r0, [r1, #0x1b]
	mov r0, r8
	strb r0, [r1, #0x1c]
	mov r4, ip
	adds r0, r2, r4
	adds r0, #0xc3
	ldrb r0, [r0]
	strb r0, [r1, #0x1f]
	strh r5, [r1, #0x10]
	strh r5, [r1, #0x12]
	movs r0, #0x84
	lsls r0, r0, #0xb
	str r0, [r1, #8]
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, _08033B94 @ =gKirbys+0x7C
	adds r2, r2, r0
	ldr r0, [r2]
	str r0, [r1]
	mov r2, sl
	strh r2, [r1, #0x14]
	strh r5, [r1, #0xc]
	strb r5, [r1, #0x1a]
	strh r5, [r1, #0x16]
	ldrb r0, [r1, #0x1b]
	mov r3, sb
	orrs r0, r3
	strb r0, [r1, #0x1b]
	mov r4, r8
	strb r4, [r1, #0x1c]
	movs r0, #0xf
	strb r0, [r1, #0x1f]
	strh r5, [r1, #0x10]
	strh r5, [r1, #0x12]
	movs r0, #0x84
	lsls r0, r0, #0xb
	str r0, [r1, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _08033B98 @ =gNumKirbys
	ldrb r1, [r1]
	cmp r7, r1
	bhs _08033B82
	b _08033A4C
_08033B82:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033B94: .4byte gKirbys+0x7C
_08033B98: .4byte gNumKirbys

	.syntax divided
