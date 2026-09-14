	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x78
	ldr r4, [sp, #0x98]
	ldr r5, [sp, #0x9c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x68]
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r8, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x6c]
	add r1, sp, #0x40
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [sp, #0x40]
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	movs r0, #0
	strh r0, [r1, #0x10]
	strh r0, [r1, #0x12]
	strh r0, [r1, #0x14]
	strh r0, [r1, #0x16]
	movs r0, #0x10
	strb r0, [r1, #0x1c]
	mov r0, sl
	strb r0, [r1, #0x1f]
	movs r0, #0x80
	lsls r0, r0, #0xc
	str r0, [r1, #8]
	adds r7, r1, #0
	add r5, sp, #0x20
	cmp r3, #0
	bne _0803CE0A
	cmp r4, #0
	bne _0803CE0A
	mov r1, sl
	lsls r0, r1, #5
	ldr r1, _0803CF6C @ =gObjPalette
	adds r0, r0, r1
	adds r1, r5, #0
	movs r2, #0x10
	bl CpuSet
_0803CE0A:
	ldr r2, [sp, #0x68]
	cmp r2, #0
	bne _0803CE14
	cmp r6, #0
	beq _0803CE22
_0803CE14:
	add r3, sp, #0x68
	ldrh r3, [r3]
	strh r3, [r7, #0xc]
	strb r6, [r7, #0x1a]
	adds r0, r7, #0
	bl sub_08155128
_0803CE22:
	mov r0, sl
	lsls r4, r0, #5
	ldr r0, _0803CF6C @ =gObjPalette
	adds r6, r4, r0
	adds r0, r6, #0
	mov r1, sp
	movs r2, #0x10
	bl CpuSet
	str r4, [sp, #0x70]
	mov r1, sb
	cmp r1, #0
	bne _0803CE42
	mov r2, r8
	cmp r2, #0
	beq _0803CE5A
_0803CE42:
	mov r3, sb
	strh r3, [r7, #0xc]
	mov r4, r8
	strb r4, [r7, #0x1a]
	adds r0, r7, #0
	bl sub_08155128
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x10
	bl CpuSet
_0803CE5A:
	movs r7, #1
	mov r8, r7
	ldr r0, _0803CF70 @ =gMainFlags
	mov ip, r0
	mov r1, sl
	lsls r1, r1, #0x1c
	mov sl, r1
	movs r6, #0x1f
	str r5, [sp, #0x74]
	movs r2, #0xe0
	mov sb, r2
	movs r5, #0x80
_0803CE72:
	mov r3, r8
	lsls r2, r3, #1
	mov r4, sp
	adds r0, r4, r2
	ldrb r3, [r0]
	ldr r7, [sp, #0x74]
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	adds r1, r6, #0
	ands r1, r3
	subs r0, r0, r1
	ldr r3, [sp, #0x6c]
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r1, #0
	mov r4, sb
	ands r0, r4
	adds r4, r2, #0
	cmp r0, #0
	beq _0803CEB0
	ands r1, r5
	movs r3, #0x1f
	cmp r1, #0
	beq _0803CEB0
	movs r3, #0
_0803CEB0:
	lsls r0, r3, #0x18
	asrs r0, r0, #8
	lsrs r2, r0, #0x10
	mov r7, sp
	adds r0, r7, r4
	ldrh r1, [r0]
	lsrs r1, r1, #5
	ldr r3, [sp, #0x74]
	adds r0, r3, r4
	ldrh r0, [r0]
	lsrs r0, r0, #5
	ands r0, r6
	ands r1, r6
	subs r0, r0, r1
	ldr r7, [sp, #0x6c]
	muls r0, r7, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r1, #0
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	beq _0803CEEE
	ands r1, r5
	movs r3, #0x1f
	cmp r1, #0
	beq _0803CEEE
	movs r3, #0
_0803CEEE:
	lsls r0, r3, #0x18
	asrs r0, r0, #0x13
	orrs r2, r0
	lsls r0, r2, #0x10
	lsrs r2, r0, #0x10
	mov r1, sp
	adds r0, r1, r4
	ldrh r1, [r0]
	lsrs r1, r1, #0xa
	ldr r3, [sp, #0x74]
	adds r0, r3, r4
	ldrh r0, [r0]
	lsrs r0, r0, #0xa
	ands r0, r6
	ands r1, r6
	subs r0, r0, r1
	ldr r7, [sp, #0x6c]
	muls r0, r7, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r1, #0
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	beq _0803CF30
	ands r1, r5
	movs r3, #0x1f
	cmp r1, #0
	beq _0803CF30
	movs r3, #0
_0803CF30:
	lsls r0, r3, #0x18
	asrs r0, r0, #0xe
	orrs r2, r0
	mov r1, sp
	adds r0, r1, r4
	strh r2, [r0]
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r0, #0xf0
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0803CE72
	mov r3, ip
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0803CF74
	mov r4, sl
	lsrs r1, r4, #0x18
	mov r0, sp
	movs r2, #0x10
	bl LoadObjPaletteWithTransformation
	b _0803CF92
	.align 2, 0
_0803CF6C: .4byte gObjPalette
_0803CF70: .4byte gMainFlags
_0803CF74:
	ldr r1, _0803CFB4 @ =0x040000D4
	mov r7, sp
	str r7, [r1]
	ldr r0, _0803CFB8 @ =gObjPalette
	ldr r2, [sp, #0x70]
	adds r0, r2, r0
	str r0, [r1, #4]
	ldr r0, _0803CFBC @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
_0803CF92:
	mov r4, sl
	lsrs r1, r4, #0x17
	ldr r0, _0803CFB8 @ =gObjPalette
	adds r0, r1, r0
	ldr r2, _0803CFC0 @ =gUnk_02022320
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuSet
	add sp, #0x78
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CFB4: .4byte 0x040000D4
_0803CFB8: .4byte gObjPalette
_0803CFBC: .4byte 0x80000010
_0803CFC0: .4byte gUnk_02022320

	.syntax divided
