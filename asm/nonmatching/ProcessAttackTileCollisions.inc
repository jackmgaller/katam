	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r6, r0, #0
	ldr r0, [r6, #0x68]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	bne _08036CD6
	b _08036EAA
_08036CD6:
	movs r0, #1
	str r0, [sp, #0x1c]
	ldr r1, [r6, #8]
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _08036CEA
	b _080372E8
_08036CEA:
	ldr r3, _08036D54 @ =gCurLevelInfo
	adds r2, r6, #0
	adds r2, #0x56
	ldrb r1, [r2]
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x50
	adds r0, r1, r0
	ldr r0, [r0]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r3, #0
	adds r0, #0x54
	adds r0, r1, r0
	ldr r0, [r0]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
	adds r0, r3, #0
	adds r0, #0x48
	adds r0, r1, r0
	ldr r0, [r0]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	adds r0, r3, #0
	adds r0, #0x4c
	adds r1, r1, r0
	ldr r0, [r1]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	ands r0, r1
	str r2, [sp, #0x28]
	cmp r0, #0
	beq _08036D58
	mov r1, sp
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1]
	b _08036D6A
	.align 2, 0
_08036D54: .4byte gCurLevelInfo
_08036D58:
	mov r1, sp
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	strb r0, [r1, #2]
_08036D6A:
	mov r1, sp
	adds r0, r6, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r0, r6, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	strb r0, [r1, #3]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _08036D88
	movs r2, #0xff
	str r2, [sp, #0x1c]
_08036D88:
	ldr r0, [r6, #0x40]
	asrs r1, r0, #8
	movs r0, #0xf
	ands r1, r0
	mov r0, sp
	movs r3, #2
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r0, r2]
	subs r0, r3, r2
	cmp r0, #0
	bge _08036DA2
	subs r0, r2, r3
_08036DA2:
	adds r0, r0, r1
	asrs r0, r0, #4
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	ldr r2, [r6, #0x44]
	asrs r1, r2, #8
	mov r0, sp
	movs r3, #1
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	movs r0, #0xf
	ands r1, r0
	mov r0, sp
	movs r4, #3
	ldrsb r4, [r0, r4]
	subs r0, r4, r3
	cmp r0, #0
	bge _08036DCC
	subs r0, r3, r4
_08036DCC:
	adds r0, r0, r1
	asrs r0, r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r0, r2, #4
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r3, #0
	str r3, [sp, #4]
	cmp r3, sl
	bls _08036DE6
	b _080372E8
_08036DE6:
	ldr r4, [sp, #0x14]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp sb, r0
	bgt _08036E9A
	ldr r1, [sp, #0x18]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp sb, r0
	blt _08036E9A
	ldr r0, [r6, #0x40]
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r7, [sp, #8]
	cmp r7, #0
	beq _08036E72
	subs r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r2, [sp, #0xc]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r3, r0, #0
	cmp r8, r1
	bgt _08036E72
	ldr r4, [sp, #0x10]
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r5, r0, #0
	cmp r8, r1
	blt _08036E72
	ldr r1, [sp, #0x1c]
	lsls r0, r1, #0x18
	asrs r4, r0, #0x18
_08036E2C:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2]
	mov r1, r8
	mov r2, sb
	str r3, [sp, #0x2c]
	bl GetCollisionTile
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	ldr r1, _08036E84 @ =gCollisionAttributes
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08036E88 @ =0x00F01000
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r3, [sp, #0x2c]
	cmp r1, r0
	beq _08036F38
	mov r2, r8
	adds r0, r2, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r7, #0
	beq _08036E72
	subs r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	asrs r0, r3, #0x10
	cmp r8, r0
	bgt _08036E72
	asrs r0, r5, #0x10
	cmp r8, r0
	bge _08036E2C
_08036E72:
	movs r0, #1
	ldr r3, [sp, #4]
	ands r0, r3
	cmp r0, #0
	beq _08036E8C
	mov r0, sb
	adds r0, #1
	adds r0, r0, r3
	b _08036E94
	.align 2, 0
_08036E84: .4byte gCollisionAttributes
_08036E88: .4byte 0x00F01000
_08036E8C:
	mov r0, sb
	subs r0, #1
	ldr r4, [sp, #4]
	subs r0, r0, r4
_08036E94:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
_08036E9A:
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, sl
	bls _08036DE6
	b _080372E8
_08036EAA:
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08036ECC
	mov r1, sp
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1]
	b _08036EDE
_08036ECC:
	mov r1, sp
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	strb r0, [r1, #2]
_08036EDE:
	mov r1, sp
	adds r0, r6, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r0, r6, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	strb r0, [r1, #3]
	ldr r2, [r6, #0x40]
	asrs r1, r2, #8
	mov r0, sp
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	movs r0, #0xf
	ands r1, r0
	mov r0, sp
	movs r4, #2
	ldrsb r4, [r0, r4]
	subs r0, r4, r3
	adds r5, r2, #0
	cmp r0, #0
	bge _08036F10
	subs r0, r3, r4
_08036F10:
	adds r0, r0, r1
	asrs r0, r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	ldr r2, [r6, #0x44]
	asrs r1, r2, #8
	mov r0, sp
	movs r3, #1
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	movs r0, #0xf
	ands r1, r0
	mov r0, sp
	movs r4, #3
	ldrsb r4, [r0, r4]
	subs r0, r4, r3
	cmp r0, #0
	blt _08036F78
	b _08036F7A
_08036F38:
	ldr r0, [sp, #0x28]
	ldrb r4, [r0]
	mov r2, r8
	lsls r1, r2, #0x18
	lsrs r1, r1, #0x18
	mov r3, sb
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	bl sub_080025AC
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl sub_08001408
	ldr r0, [r6, #0x70]
	mov r4, r8
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	mov r3, sb
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	bl sub_08088F84
	ldr r0, [r6, #8]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [r6, #8]
	b _080372E8
_08036F78:
	subs r0, r3, r4
_08036F7A:
	adds r0, r0, r1
	asrs r0, r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	asrs r0, r5, #8
	mov r1, sp
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	mov r8, r0
	asrs r0, r2, #8
	mov r1, sp
	ldrb r1, [r1, #1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r4, _08037118 @ =gCurLevelInfo
	adds r2, r6, #0
	adds r2, #0x56
	ldrb r1, [r2]
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r3, r1, #0
	muls r3, r0, r3
	adds r0, r4, #0
	adds r0, #0x50
	adds r0, r3, r0
	ldr r0, [r0]
	asrs r0, r0, #0xc
	ldr r1, [sp, #8]
	add r1, r8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x80
	lsls r5, r5, #8
	ands r0, r5
	str r2, [sp, #0x28]
	cmp r0, #0
	beq _08036FF0
	ldr r2, [sp, #8]
	adds r0, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x80
	ldr r1, [sp, #8]
	ands r0, r1
	cmp r0, #0
	beq _08036FF0
	b _080372E8
_08036FF0:
	adds r0, r4, #0
	adds r0, #0x48
	adds r0, r3, r0
	ldr r0, [r0]
	asrs r0, r0, #0xc
	mov r2, r8
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08037028
	ldr r0, [sp, #8]
	cmn r0, r2
	bge _08037014
	b _080372E8
_08037014:
	mov r2, r8
	subs r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r2, [sp, #8]
	adds r0, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
_08037028:
	adds r0, r4, #0
	adds r0, #0x54
	adds r0, r3, r0
	ldr r0, [r0]
	asrs r0, r0, #0xc
	mov r1, sb
	add r1, sl
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq _0803705A
	mov r2, sl
	adds r0, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r0, #0x80
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _0803705A
	b _080372E8
_0803705A:
	adds r0, r4, #0
	adds r0, #0x4c
	adds r0, r3, r0
	ldr r0, [r0]
	asrs r0, r0, #0xc
	mov r2, sb
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08037090
	mov r3, sl
	cmn r3, r2
	bge _0803707E
	b _080372E8
_0803707E:
	mov r4, sb
	subs r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r0, r3, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_08037090:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, #0
	bne _080370A0
	b _080372E8
_080370A0:
	ldr r0, [sp, #4]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080370B8
	b _080372E0
_080370B8:
	ldr r0, [sp, #4]
	add r0, sb
	mov sl, r0
	lsls r0, r0, #0x10
	str r0, [sp, #0x20]
	mov r1, sl
	lsls r1, r1, #0xc
	str r1, [sp, #0x24]
_080370C8:
	subs r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r4, _0803711C @ =gCollisionAttributes
	ldr r2, [sp, #0x28]
	ldrb r0, [r2]
	mov r3, r8
	adds r1, r3, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x20]
	lsrs r2, r3, #0x10
	bl GetCollisionTile
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r2, [r0]
	adds r0, r2, #0
	movs r4, #0x80
	lsls r4, r4, #5
	ands r0, r4
	cmp r0, #0
	bne _080370FA
	b _080372DA
_080370FA:
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r2
	movs r0, #0xc0
	lsls r0, r0, #0xe
	cmp r1, r0
	beq _08037132
	cmp r1, r0
	bhi _08037120
	movs r0, #0x80
	lsls r0, r0, #0xe
	cmp r1, r0
	beq _0803712A
	b _08037148
	.align 2, 0
_08037118: .4byte gCurLevelInfo
_0803711C: .4byte gCollisionAttributes
_08037120:
	movs r0, #0x80
	lsls r0, r0, #0xf
	cmp r1, r0
	beq _0803713A
	b _08037148
_0803712A:
	ldr r0, [r6, #0x68]
	movs r1, #0x80
	lsls r1, r1, #5
	b _08037140
_08037132:
	ldr r0, [r6, #0x68]
	movs r1, #0x80
	lsls r1, r1, #7
	b _08037140
_0803713A:
	ldr r0, [r6, #0x68]
	movs r1, #0x80
	lsls r1, r1, #4
_08037140:
	ands r0, r1
	cmp r0, #0
	bne _08037148
	b _080372DA
_08037148:
	movs r0, #0x20
	ands r2, r0
	cmp r2, #0
	beq _0803720C
	ldr r2, [sp, #0x28]
	ldrb r5, [r2]
	mov r3, r8
	adds r4, r7, r3
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	mov r0, sl
	lsls r2, r0, #0x18
	adds r0, r5, #0
	lsrs r2, r2, #0x18
	bl sub_080025AC
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_08001408
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	ldr r3, [sp, #0x20]
	asrs r2, r3, #0x10
	bl sub_0800E0E4
	ldr r1, _080371F4 @ =gKirbys
	ldr r0, _080371F8 @ =gLocalPlayerId
	ldrb r2, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _080371A2
	b _080372D0
_080371A2:
	ldrb r0, [r6]
	cmp r0, #0
	bne _080371B2
	ldr r4, [sp, #0x28]
	ldrb r0, [r4]
	cmp r0, r2
	beq _080371B2
	b _080372D0
_080371B2:
	ldr r1, _080371FC @ =gSongTable
	ldr r2, _08037200 @ =0x00000FF4
	adds r0, r1, r2
	ldrh r3, [r0]
	lsls r0, r3, #2
	ldr r4, _08037204 @ =gUnk_08D60FA4
	adds r0, r0, r4
	ldr r2, [r0]
	ldr r0, [r2, #4]
	cmp r0, #0
	blt _080371D8
	movs r4, #0xff
	lsls r4, r4, #4
	adds r0, r1, r4
	ldr r1, [r0]
	ldrb r0, [r2, #9]
	ldrb r1, [r1, #2]
	cmp r0, r1
	bhi _080372D0
_080371D8:
	cmp r3, #0
	beq _080371EA
	ldr r0, _08037208 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080372D0
_080371EA:
	movs r0, #0xff
	lsls r0, r0, #1
	bl m4aSongNumStart
	b _080372D0
	.align 2, 0
_080371F4: .4byte gKirbys
_080371F8: .4byte gLocalPlayerId
_080371FC: .4byte gSongTable
_08037200: .4byte 0x00000FF4
_08037204: .4byte gUnk_08D60FA4
_08037208: .4byte gUnk_0203AD10
_0803720C:
	ldr r0, [sp, #0x28]
	ldrb r5, [r0]
	mov r1, r8
	adds r4, r7, r1
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	mov r3, sl
	lsls r2, r3, #0x18
	adds r0, r5, #0
	lsrs r2, r2, #0x18
	bl sub_080025AC
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_08001408
	adds r0, r6, #0
	movs r1, #0
	ldr r2, _080372F8 @ =0x0000028D
	movs r3, #0
	bl CreateEffectObject
	lsls r4, r4, #0xc
	movs r1, #0x80
	lsls r1, r1, #4
	adds r4, r4, r1
	str r4, [r0, #0x34]
	ldr r4, [sp, #0x24]
	adds r1, r4, r1
	str r1, [r0, #0x38]
	ldr r1, _080372FC @ =gKirbys
	ldr r0, _08037300 @ =gLocalPlayerId
	ldrb r2, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080372B6
	ldrb r0, [r6]
	cmp r0, #0
	bne _08037276
	ldr r1, [sp, #0x28]
	ldrb r0, [r1]
	cmp r0, r2
	bne _080372B6
_08037276:
	ldr r1, _08037304 @ =gSongTable
	ldr r2, _08037308 @ =0x00000FF4
	adds r0, r1, r2
	ldrh r3, [r0]
	lsls r0, r3, #2
	ldr r4, _0803730C @ =gUnk_08D60FA4
	adds r0, r0, r4
	ldr r2, [r0]
	ldr r0, [r2, #4]
	cmp r0, #0
	blt _0803729C
	movs r4, #0xff
	lsls r4, r4, #4
	adds r0, r1, r4
	ldr r1, [r0]
	ldrb r0, [r2, #9]
	ldrb r1, [r1, #2]
	cmp r0, r1
	bhi _080372B6
_0803729C:
	cmp r3, #0
	beq _080372AE
	ldr r0, _08037310 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080372B6
_080372AE:
	movs r0, #0xff
	lsls r0, r0, #1
	bl m4aSongNumStart
_080372B6:
	ldr r0, [r6, #0x68]
	movs r1, #0x80
	lsls r1, r1, #0x15
	ands r0, r1
	cmp r0, #0
	beq _080372D0
	ldr r0, [r6, #0x70]
	bl sub_08085328
	movs r0, #2
	adds r1, r6, #0
	bl RequestScreenShake
_080372D0:
	ldr r0, [r6, #8]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [r6, #8]
_080372DA:
	cmp r7, #0
	beq _080372E0
	b _080370C8
_080372E0:
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _080372E8
	b _080370A0
_080372E8:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080372F8: .4byte 0x0000028D
_080372FC: .4byte gKirbys
_08037300: .4byte gLocalPlayerId
_08037304: .4byte gSongTable
_08037308: .4byte 0x00000FF4
_0803730C: .4byte gUnk_08D60FA4
_08037310: .4byte gUnk_0203AD10

	.syntax divided
