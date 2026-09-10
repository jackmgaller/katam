	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r7, _0803A350 @ =gPaletteEffectManager
	movs r0, #0
	mov r8, r0
	mov sl, r0
	ldrh r1, [r7, #8]
	ldrh r0, [r7, #0x18]
	adds r4, r1, #0
	orrs r4, r0
	ldrh r0, [r7, #0x28]
	orrs r4, r0
	ldrh r0, [r7, #0x38]
	orrs r4, r0
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r0, [r0]
	orrs r4, r0
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	orrs r4, r0
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r0, [r0]
	orrs r4, r0
	adds r0, r7, #0
	adds r0, #0x78
	ldrh r0, [r0]
	orrs r4, r0
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0803A2C6
	movs r6, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
_0803A250:
	lsls r0, r6, #4
	adds r1, r7, r0
	ldrh r2, [r1, #8]
	movs r1, #0x10
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	bne _0803A2BC
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0803A2BC
	ldr r0, _0803A354 @ =gMainFlags
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803A284
	mov r0, sb
	cmp r0, #0
	beq _0803A284
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0803A2BC
_0803A284:
	adds r0, r7, r5
	ldrh r0, [r0, #6]
	cmp r0, #0
	beq _0803A2A0
	mov r1, sl
	cmp r1, #0
	bne _0803A2A0
	ldr r0, _0803A358 @ =gUnk_02022120
	ldr r1, _0803A35C @ =gBgPalette
	ldr r2, _0803A360 @ =0x04000080
	bl CpuSet
	movs r2, #1
	mov sl, r2
_0803A2A0:
	adds r0, r7, r5
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _0803A2BC
	mov r0, r8
	cmp r0, #0
	bne _0803A2BC
	ldr r0, _0803A364 @ =gUnk_02022320
	ldr r1, _0803A368 @ =gObjPalette
	ldr r2, _0803A360 @ =0x04000080
	bl CpuSet
	movs r1, #1
	mov r8, r1
_0803A2BC:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #7
	bls _0803A250
_0803A2C6:
	ldr r0, _0803A354 @ =gMainFlags
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803A2DE
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	bne _0803A2DE
	b _0803A434
_0803A2DE:
	movs r6, #0
	adds r5, r7, #0
	adds r5, #0x80
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ands r4, r0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
_0803A2F2:
	lsls r1, r6, #2
	adds r0, r5, r1
	ldr r2, [r0]
	adds r3, r1, #0
	cmp r2, #0
	beq _0803A390
	ldr r0, _0803A354 @ =gMainFlags
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803A31C
	mov r0, sb
	cmp r0, #0
	beq _0803A31C
	ldrh r1, [r2, #8]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0803A390
_0803A31C:
	adds r4, r5, r3
	ldr r0, [r4]
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldr r2, _0803A36C @ =gPaletteEffectCallbacks
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r0, [r4]
	ldrh r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0803A370
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803A348
	str r2, [r4]
_0803A348:
	movs r0, #0
	mov r8, r0
	b _0803A390
	.align 2, 0
_0803A350: .4byte gPaletteEffectManager
_0803A354: .4byte gMainFlags
_0803A358: .4byte gUnk_02022120
_0803A35C: .4byte gBgPalette
_0803A360: .4byte 0x04000080
_0803A364: .4byte gUnk_02022320
_0803A368: .4byte gObjPalette
_0803A36C: .4byte gPaletteEffectCallbacks
_0803A370:
	lsls r0, r6, #4
	adds r2, r7, r0
	ldrh r1, [r2, #8]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0803A390
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803A390
	ldrh r0, [r2, #4]
	cmp r0, #0
	beq _0803A390
	movs r1, #1
	mov r8, r1
_0803A390:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #7
	bls _0803A2F2
	bl CompactPaletteEffectQueue
	ldr r3, _0803A3CC @ =gMainFlags
	ldr r2, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r2
	cmp r0, #0
	beq _0803A434
	mov r0, r8
	cmp r0, #0
	beq _0803A3E8
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _0803A3D4
	ldr r0, _0803A3D0 @ =gObjPalette
	movs r2, #0x80
	lsls r2, r2, #1
	movs r1, #0
	bl LoadObjPaletteWithTransformation
	b _0803A3E8
	.align 2, 0
_0803A3CC: .4byte gMainFlags
_0803A3D0: .4byte gObjPalette
_0803A3D4:
	ldr r1, _0803A40C @ =0x040000D4
	ldr r0, _0803A410 @ =gObjPalette
	str r0, [r1]
	str r0, [r1, #4]
	ldr r0, _0803A414 @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #2
	orrs r2, r0
	str r2, [r3]
_0803A3E8:
	mov r1, sl
	cmp r1, #0
	beq _0803A434
	ldr r3, _0803A418 @ =gMainFlags
	ldr r2, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r2
	cmp r0, #0
	beq _0803A420
	ldr r0, _0803A41C @ =gBgPalette
	movs r2, #0x80
	lsls r2, r2, #1
	movs r1, #0
	bl LoadBgPaletteWithTransformation
	b _0803A434
	.align 2, 0
_0803A40C: .4byte 0x040000D4
_0803A410: .4byte gObjPalette
_0803A414: .4byte 0x80000100
_0803A418: .4byte gMainFlags
_0803A41C: .4byte gBgPalette
_0803A420:
	ldr r1, _0803A444 @ =0x040000D4
	ldr r0, _0803A448 @ =gBgPalette
	str r0, [r1]
	str r0, [r1, #4]
	ldr r0, _0803A44C @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #1
	orrs r2, r0
	str r2, [r3]
_0803A434:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A444: .4byte 0x040000D4
_0803A448: .4byte gBgPalette
_0803A44C: .4byte 0x80000100

	.syntax divided
