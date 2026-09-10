	.syntax unified
	.text

	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrh r1, [r6, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803C7BA
	ldr r4, _0803C80C @ =gBgPalette
	movs r5, #0
_0803C75C:
	ldrh r0, [r6, #6]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C778
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0803C810 @ =0x05000008
	bl CpuSet
_0803C778:
	adds r4, #0x20
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xf
	bls _0803C75C
	ldr r4, _0803C814 @ =gObjPalette
	movs r5, #0
_0803C788:
	ldrh r0, [r6, #4]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C7A4
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0803C810 @ =0x05000008
	bl CpuSet
_0803C7A4:
	adds r4, #0x20
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xf
	bls _0803C788
	ldr r0, _0803C818 @ =gMainFlags
	ldr r1, [r0]
	movs r2, #3
	orrs r1, r2
	str r1, [r0]
_0803C7BA:
	ldrh r1, [r6, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0803C834
	ldrh r2, [r6, #0xa]
	ldrh r3, [r6, #0xc]
	adds r0, r2, r3
	strh r0, [r6, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strb r0, [r6, #1]
	adds r4, r0, #0
	movs r3, #2
	ldrsb r3, [r6, r3]
	ldrb r5, [r6, #2]
	cmp r4, r3
	bgt _0803C7E8
	lsls r0, r2, #0x10
	cmp r0, #0
	blt _0803C7EE
	cmp r4, r3
	blt _0803C834
_0803C7E8:
	lsls r0, r2, #0x10
	cmp r0, #0
	ble _0803C834
_0803C7EE:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803C82C
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803C81C
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #8
	strh r0, [r6, #0xc]
	strb r5, [r6, #1]
	b _0803C834
	.align 2, 0
_0803C80C: .4byte gBgPalette
_0803C810: .4byte 0x05000008
_0803C814: .4byte gObjPalette
_0803C818: .4byte gMainFlags
_0803C81C:
	movs r0, #1
	orrs r0, r1
	ldr r1, _0803C828 @ =0x0000FF59
	ands r0, r1
	b _0803C832
	.align 2, 0
_0803C828: .4byte 0x0000FF59
_0803C82C:
	strb r5, [r6, #1]
	movs r0, #0x20
	orrs r0, r1
_0803C832:
	strh r0, [r6, #8]
_0803C834:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	.syntax divided
