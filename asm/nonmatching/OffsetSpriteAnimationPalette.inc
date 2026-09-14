	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	ldr r4, [sp, #0x78]
	ldr r5, [sp, #0x7c]
	ldr r6, [sp, #0x80]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x48]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sl, r4
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov sb, r5
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	add r3, sp, #0x20
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [sp, #0x20]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r0, #0
	strh r0, [r3, #0x10]
	strh r0, [r3, #0x12]
	strh r0, [r3, #0x14]
	strh r0, [r3, #0x16]
	movs r0, #0x10
	strb r0, [r3, #0x1c]
	strb r7, [r3, #0x1f]
	movs r0, #0x80
	lsls r0, r0, #0xc
	str r0, [r3, #8]
	cmp r1, #0
	bne _0803D024
	cmp r2, #0
	beq _0803D030
_0803D024:
	strh r1, [r3, #0xc]
	mov r0, r8
	strb r0, [r3, #0x1a]
	adds r0, r3, #0
	bl sub_08155128
_0803D030:
	lsls r4, r7, #5
	ldr r0, _0803D140 @ =gObjPalette
	adds r0, r4, r0
	mov r1, sp
	movs r2, #0x10
	bl CpuSet
	movs r5, #1
	str r4, [sp, #0x4c]
	ldr r1, [sp, #0x48]
	lsls r1, r1, #0x18
	str r1, [sp, #0x54]
	mov r2, sl
	lsls r2, r2, #0x18
	mov sl, r2
	mov r4, sb
	lsls r4, r4, #0x18
	mov sb, r4
	lsls r0, r7, #0x1c
	str r0, [sp, #0x50]
	movs r1, #0x1f
	mov r8, r1
	movs r2, #0xe0
	mov ip, r2
_0803D060:
	lsls r3, r5, #1
	mov r4, sp
	adds r0, r4, r3
	ldrb r2, [r0]
	ldr r7, [sp, #0x54]
	asrs r0, r7, #0x18
	adds r1, r0, #0
	muls r1, r6, r1
	asrs r1, r1, #8
	mov r0, r8
	ands r0, r2
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	adds r0, r1, #0
	mov r4, ip
	ands r0, r4
	adds r4, r3, #0
	cmp r0, #0
	beq _0803D096
	movs r7, #0x80
	ands r1, r7
	movs r2, #0x1f
	cmp r1, #0
	beq _0803D096
	movs r2, #0
_0803D096:
	lsls r0, r2, #0x18
	asrs r0, r0, #8
	lsrs r3, r0, #0x10
	mov r1, sp
	adds r0, r1, r4
	ldrh r0, [r0]
	lsrs r0, r0, #5
	mov r2, sl
	asrs r1, r2, #0x18
	muls r1, r6, r1
	asrs r1, r1, #8
	mov r7, r8
	ands r0, r7
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	adds r0, r1, #0
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq _0803D0CE
	movs r0, #0x80
	ands r1, r0
	movs r2, #0x1f
	cmp r1, #0
	beq _0803D0CE
	movs r2, #0
_0803D0CE:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x13
	orrs r3, r0
	lsls r0, r3, #0x10
	lsrs r3, r0, #0x10
	mov r1, sp
	adds r0, r1, r4
	ldrh r0, [r0]
	lsrs r0, r0, #0xa
	mov r2, sb
	asrs r1, r2, #0x18
	muls r1, r6, r1
	asrs r1, r1, #8
	mov r7, r8
	ands r0, r7
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	adds r0, r1, #0
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq _0803D10A
	movs r0, #0x80
	ands r1, r0
	movs r2, #0x1f
	cmp r1, #0
	beq _0803D10A
	movs r2, #0
_0803D10A:
	lsls r0, r2, #0x18
	asrs r0, r0, #0xe
	orrs r3, r0
	mov r1, sp
	adds r0, r1, r4
	strh r3, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq _0803D060
	ldr r3, _0803D144 @ =gMainFlags
	ldr r2, [r3]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _0803D148
	ldr r2, [sp, #0x50]
	lsrs r1, r2, #0x18
	mov r0, sp
	movs r2, #0x10
	bl LoadObjPaletteWithTransformation
	b _0803D162
	.align 2, 0
_0803D140: .4byte gObjPalette
_0803D144: .4byte gMainFlags
_0803D148:
	ldr r1, _0803D190 @ =0x040000D4
	mov r4, sp
	str r4, [r1]
	ldr r0, _0803D194 @ =gObjPalette
	ldr r7, [sp, #0x4c]
	adds r0, r7, r0
	str r0, [r1, #4]
	ldr r0, _0803D198 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #2
	orrs r2, r0
	str r2, [r3]
_0803D162:
	ldr r2, _0803D19C @ =gMainFlags
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, [sp, #0x50]
	lsrs r1, r0, #0x17
	ldr r0, _0803D194 @ =gObjPalette
	adds r0, r1, r0
	ldr r2, _0803D1A0 @ =gUnk_02022320
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuSet
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D190: .4byte 0x040000D4
_0803D194: .4byte gObjPalette
_0803D198: .4byte 0x80000010
_0803D19C: .4byte gMainFlags
_0803D1A0: .4byte gUnk_02022320

	.syntax divided
