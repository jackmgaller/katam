	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	movs r2, #0
	bl _08037FF0
_08037326:
	lsls r1, r2, #5
	ldr r0, _0803735C @ =gUnk_02022EC0
	adds r7, r1, r0
	ldr r0, _08037360 @ =gUnk_02022F40
	adds r0, r2, r0
	ldrb r3, [r0]
	lsls r0, r2, #6
	str r0, [sp, #0x10]
	lsls r1, r2, #8
	str r1, [sp, #0x14]
	lsls r0, r2, #1
	str r0, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #4]
	cmp r3, #0
	beq _0803740C
_08037346:
	adds r1, r7, #0
	ldm r1!, {r0}
	str r1, [sp, #8]
	subs r3, #1
	str r3, [sp]
	cmp r0, #0
	beq _08037400
	movs r2, #0
	mov sl, r2
	b _080373A0
	.align 2, 0
_0803735C: .4byte gUnk_02022EC0
_08037360: .4byte gUnk_02022F40
_08037364:
	movs r0, #0xd4
	lsls r0, r0, #1
	mov r1, sl
	muls r1, r0, r1
	ldr r0, _08037464 @ =gKirbys
	adds r4, r1, r0
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0x60
	adds r1, r4, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08037396
	ldr r1, [r4, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08037396
	adds r0, r4, #0
	adds r1, r2, #0
	bl ResolveSolidObjectCollision
_08037396:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_080373A0:
	ldr r0, _08037468 @ =gNumKirbys
	ldrb r0, [r0]
	cmp sl, r0
	blo _08037364
	ldr r0, _0803746C @ =gUnk_02022F50
	ldr r1, [sp, #0x14]
	adds r6, r1, r0
	ldr r0, _08037470 @ =gUnk_02022EB0
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldrb r0, [r0]
	mov sl, r0
	cmp r0, #0
	beq _08037400
_080373BC:
	ldr r2, [r6]
	ldr r1, [r2, #0xc]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _080373F0
	ldr r3, [r7]
	adds r0, r3, #0
	adds r0, #0x60
	adds r1, r2, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080373F0
	ldr r1, [r2, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080373F0
	adds r0, r2, #0
	adds r1, r3, #0
	bl ResolveSolidObjectCollision
_080373F0:
	mov r0, sl
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	adds r6, #4
	cmp r0, #0
	bne _080373BC
_08037400:
	ldr r1, [sp]
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
	ldr r7, [sp, #8]
	cmp r3, #0
	bne _08037346
_0803740C:
	movs r0, #0x20
	ldr r2, [sp, #0x10]
	orrs r0, r2
	lsls r0, r0, #2
	ldr r1, _0803746C @ =gUnk_02022F50
	adds r7, r0, r1
	ldr r1, _08037470 @ =gUnk_02022EB0
	ldr r0, [sp, #0xc]
	adds r0, #1
	adds r0, r0, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08037428
	b _08037B72
_08037428:
	adds r1, r7, #0
	ldm r1!, {r0}
	mov ip, r0
	str r1, [sp, #8]
	subs r2, r3, #1
	str r2, [sp]
	cmp r0, #0
	bne _0803743A
	b _08037B64
_0803743A:
	ldr r0, [r0, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803747A
	mov r0, ip
	ldr r2, [r0, #0x40]
	asrs r2, r2, #8
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	mov r8, r2
	b _0803748C
	.align 2, 0
_08037464: .4byte gKirbys
_08037468: .4byte gNumKirbys
_0803746C: .4byte gUnk_02022F50
_08037470: .4byte gUnk_02022EB0
_08037474:
	movs r0, #0
	str r0, [r6]
	b _08037B34
_0803747A:
	mov r1, ip
	ldr r0, [r1, #0x40]
	asrs r0, r0, #8
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	mov r8, r0
_0803748C:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x39
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	mov sb, r0
	ldr r1, [r2, #8]
	movs r0, #0x80
	lsls r0, r0, #0x16
	ands r0, r1
	subs r3, #1
	str r3, [sp]
	adds r2, r7, #4
	str r2, [sp, #8]
	cmp r0, #0
	bne _080374B6
	b _080376D2
_080374B6:
	ldr r0, _08037514 @ =gUnk_02022F50
	ldr r2, [sp, #0x14]
	adds r6, r2, r0
	ldr r0, _08037518 @ =gUnk_02022EB0
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldrb r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _080374CC
	b _080376B0
_080374CC:
	ldr r3, [r6]
	adds r4, r3, #0
	cmp r4, #0
	bne _080374D6
	b _08037688
_080374D6:
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	cmp r1, #0
	beq _080374E2
	b _080376B0
_080374E2:
	ldr r1, [r3, #8]
	ands r2, r1
	cmp r2, #0
	beq _080374EC
	b _08037688
_080374EC:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0803751C
	ldr r2, [r3, #0x40]
	asrs r2, r2, #8
	adds r0, r3, #0
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	b _0803752C
	.align 2, 0
_08037514: .4byte gUnk_02022F50
_08037518: .4byte gUnk_02022EB0
_0803751C:
	ldr r0, [r3, #0x40]
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
_0803752C:
	ldr r0, [r4, #0x44]
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, r1
	mov r1, ip
	adds r1, #0x3a
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _080375A8
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080375A8
	cmp r8, r2
	bgt _0803756A
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #1
	add r0, r8
	cmp r0, r2
	bge _0803757C
	cmp r8, r2
	blt _080375A8
_0803756A:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r8
	blt _080375A8
_0803757C:
	cmp sb, r5
	bgt _08037596
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, sb
	cmp r0, r5
	bge _08037626
	cmp sb, r5
	blt _080375A8
_08037596:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, sb
	bge _08037626
_080375A8:
	mov r1, ip
	ldr r0, [r1, #0x30]
	cmp r0, #0
	bne _08037688
	ldr r1, [r1, #0x40]
	asrs r1, r1, #8
	mov r0, ip
	adds r0, #0x34
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	cmp r1, r2
	bgt _080375D6
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r1, r0
	cmp r0, r2
	bge _080375E8
	cmp r1, r2
	blt _08037688
_080375D6:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r1
	blt _08037688
_080375E8:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
	cmp r2, r5
	bgt _08037614
	mov r0, ip
	adds r0, #0x37
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	adds r0, r2, r0
	cmp r0, r5
	bge _08037626
	cmp r2, r5
	blt _08037688
_08037614:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, r2
	blt _08037688
_08037626:
	ldr r1, [r7]
	ldrb r0, [r1]
	lsls r0, r0, #2
	ldr r2, _08037680 @ =gObjectCollisionCallbacks
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, [r6]
	ldrb r2, [r1]
	lsls r2, r2, #2
	ldr r0, _08037680 @ =gObjectCollisionCallbacks
	adds r2, r2, r0
	ldr r0, [r7]
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08037658
	movs r0, #0
	str r0, [r6]
_08037658:
	ldr r1, [r7]
	mov ip, r1
	cmp r4, #0
	beq _08037688
	ldr r1, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _0803767A
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	ldr r0, _08037684 @ =0xFBFFFFFF
	ands r1, r0
	mov r2, ip
	str r1, [r2, #8]
_0803767A:
	movs r0, #0
	str r0, [r7]
	b _080376B0
	.align 2, 0
_08037680: .4byte gObjectCollisionCallbacks
_08037684: .4byte 0xFBFFFFFF
_08037688:
	mov r0, sl
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	adds r6, #4
	cmp r0, #0
	beq _080376B0
	ldr r4, [r6]
	adds r3, r4, #0
	cmp r4, #0
	beq _08037688
	mov r1, ip
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r0, r2
	cmp r0, #0
	bne _080376B0
	b _080374E2
_080376B0:
	ldr r2, [r7]
	mov ip, r2
	cmp r2, #0
	bne _080376BA
	b _08037B64
_080376BA:
	ldr r1, [r2, #8]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _080376D2
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	ldr r0, _08037754 @ =0xFBFFFFFF
	ands r1, r0
	str r1, [r2, #8]
_080376D2:
	mov r1, ip
	ldr r0, [r1, #8]
	movs r1, #0x80
	lsls r1, r1, #0x15
	ands r0, r1
	cmp r0, #0
	bne _080376E2
	b _08037944
_080376E2:
	movs r2, #0
	mov sl, r2
	ldr r0, _08037758 @ =gNumKirbys
	ldrb r0, [r0]
	cmp sl, r0
	blo _080376F0
	b _08037920
_080376F0:
	ldr r6, _0803775C @ =gObjectCollisionCallbacks
_080376F2:
	movs r0, #0xd4
	lsls r0, r0, #1
	mov r1, sl
	muls r1, r0, r1
	ldr r0, _08037760 @ =gKirbys
	adds r4, r1, r0
	mov r0, ip
	adds r0, #0x60
	adds r1, r4, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08037710
	b _0803790C
_08037710:
	mov r1, ip
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r0, r2
	cmp r0, #0
	beq _08037720
	b _08037920
_08037720:
	ldr r1, [r4, #8]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0803772C
	b _0803790C
_0803772C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08037764
	ldr r2, [r4, #0x40]
	asrs r2, r2, #8
	adds r0, r4, #0
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	b _08037774
	.align 2, 0
_08037754: .4byte 0xFBFFFFFF
_08037758: .4byte gNumKirbys
_0803775C: .4byte gObjectCollisionCallbacks
_08037760: .4byte gKirbys
_08037764:
	ldr r0, [r4, #0x40]
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
_08037774:
	ldr r0, [r4, #0x44]
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, r1
	mov r1, ip
	adds r1, #0x3a
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0803783C
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803783C
	cmp r8, r2
	bgt _080377B2
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #1
	add r0, r8
	cmp r0, r2
	bge _080377C4
	cmp r8, r2
	blt _0803783C
_080377B2:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r8
	blt _0803783C
_080377C4:
	cmp sb, r5
	bgt _080377DE
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, sb
	cmp r0, r5
	bge _080377F0
	cmp sb, r5
	blt _0803783C
_080377DE:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, sb
	blt _0803783C
_080377F0:
	ldr r1, [r7]
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r0, [r7]
	ldr r2, [r1]
	adds r1, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x10
	ldr r2, [r7]
	mov ip, r2
	cmp r5, #0
	beq _0803790C
	ldr r1, [r2, #8]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _08037902
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	ldr r0, _08037838 @ =0xFBFFFFFF
	ands r1, r0
	b _08037900
	.align 2, 0
_08037838: .4byte 0xFBFFFFFF
_0803783C:
	mov r1, ip
	ldr r0, [r1, #0x30]
	cmp r0, #0
	bne _0803790C
	ldr r1, [r1, #0x40]
	asrs r1, r1, #8
	mov r0, ip
	adds r0, #0x34
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	cmp r1, r2
	bgt _0803786A
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r1, r0
	cmp r0, r2
	bge _0803787C
	cmp r1, r2
	blt _0803790C
_0803786A:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r1
	blt _0803790C
_0803787C:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
	cmp r2, r5
	bgt _080378A8
	mov r0, ip
	adds r0, #0x37
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	adds r0, r2, r0
	cmp r0, r5
	bge _080378BA
	cmp r2, r5
	blt _0803790C
_080378A8:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, r2
	blt _0803790C
_080378BA:
	ldr r1, [r7]
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r0, [r7]
	ldr r2, [r1]
	adds r1, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x10
	ldr r0, [r7]
	mov ip, r0
	cmp r5, #0
	beq _0803790C
	ldr r1, [r0, #8]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _08037902
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	ldr r0, _08037908 @ =0xFBFFFFFF
	ands r1, r0
	mov r2, ip
_08037900:
	str r1, [r2, #8]
_08037902:
	movs r0, #0
	str r0, [r7]
	b _08037920
	.align 2, 0
_08037908: .4byte 0xFBFFFFFF
_0803790C:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, _080379C0 @ =gNumKirbys
	ldrb r0, [r0]
	cmp sl, r0
	bhs _08037920
	b _080376F2
_08037920:
	ldr r0, [r7]
	mov ip, r0
	cmp r0, #0
	bne _0803792A
	b _08037B64
_0803792A:
	ldr r1, [r0, #8]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _08037944
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	ldr r0, _080379C4 @ =0xFBFFFFFF
	ands r1, r0
	mov r2, ip
	str r1, [r2, #8]
_08037944:
	mov r0, ip
	ldr r5, [r0, #8]
	movs r0, #0x80
	lsls r0, r0, #0x17
	ands r0, r5
	cmp r0, #0
	bne _08037954
	b _08037B56
_08037954:
	movs r0, #0x20
	ldr r1, [sp, #0x10]
	orrs r0, r1
	lsls r0, r0, #2
	ldr r1, _080379C8 @ =gUnk_02022F50
	adds r6, r0, r1
	ldr r1, _080379CC @ =gUnk_02022EB0
	ldr r0, [sp, #0xc]
	adds r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _08037972
	b _08037B34
_08037972:
	ldr r3, [r6]
	adds r4, r3, #0
	cmp r4, #0
	bne _0803797C
	b _08037B06
_0803797C:
	cmp r4, ip
	bne _08037982
	b _08037B06
_08037982:
	movs r2, #0x80
	lsls r2, r2, #2
	ands r5, r2
	cmp r5, #0
	beq _0803798E
	b _08037B34
_0803798E:
	ldr r1, [r3, #8]
	ands r2, r1
	cmp r2, #0
	beq _08037998
	b _08037B06
_08037998:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080379D0
	ldr r2, [r3, #0x40]
	asrs r2, r2, #8
	adds r0, r3, #0
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	b _080379E0
	.align 2, 0
_080379C0: .4byte gNumKirbys
_080379C4: .4byte 0xFBFFFFFF
_080379C8: .4byte gUnk_02022F50
_080379CC: .4byte gUnk_02022EB0
_080379D0:
	ldr r0, [r3, #0x40]
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
_080379E0:
	ldr r1, [r4, #0x44]
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x39
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, r0
	cmp r8, r2
	bgt _08037A0A
	mov r0, ip
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	cmp r0, r2
	bge _08037A1C
	cmp r8, r2
	blt _08037A88
_08037A0A:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r8
	blt _08037A88
_08037A1C:
	cmp sb, r5
	bgt _08037A36
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, sb
	cmp r0, r5
	bge _08037A48
	cmp sb, r5
	blt _08037A88
_08037A36:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, sb
	blt _08037A88
_08037A48:
	ldr r1, [r7]
	ldrb r0, [r1]
	lsls r0, r0, #2
	ldr r2, _08037A84 @ =gObjectCollisionCallbacks
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, [r6]
	ldrb r2, [r1]
	lsls r2, r2, #2
	ldr r0, _08037A84 @ =gObjectCollisionCallbacks
	adds r2, r2, r0
	ldr r0, [r7]
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08037A7A
	b _08037474
_08037A7A:
	cmp r4, #0
	beq _08037B06
	str r0, [r7]
	b _08037B34
	.align 2, 0
_08037A84: .4byte gObjectCollisionCallbacks
_08037A88:
	mov r1, ip
	ldr r0, [r1, #0x30]
	cmp r0, #0
	bne _08037B06
	ldr r1, [r1, #0x40]
	asrs r1, r1, #8
	mov r0, ip
	adds r0, #0x34
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	cmp r1, r2
	bgt _08037AB6
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r1, r0
	cmp r0, r2
	bge _08037AC8
	cmp r1, r2
	blt _08037B06
_08037AB6:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r1
	blt _08037B06
_08037AC8:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
	cmp r2, r5
	bgt _08037AF4
	mov r0, ip
	adds r0, #0x37
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	adds r0, r2, r0
	cmp r0, r5
	bge _08037A48
	cmp r2, r5
	blt _08037B06
_08037AF4:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, r2
	bge _08037A48
_08037B06:
	mov r0, sl
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	adds r6, #4
	cmp r0, #0
	beq _08037B34
	ldr r4, [r6]
	adds r3, r4, #0
	cmp r4, #0
	beq _08037B06
	ldr r1, [r7]
	mov ip, r1
	cmp r4, ip
	beq _08037B06
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r0, r2
	cmp r0, #0
	bne _08037B34
	b _0803798E
_08037B34:
	ldr r7, [r7]
	mov ip, r7
	mov r2, ip
	cmp r2, #0
	beq _08037B64
	ldr r1, [r2, #8]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _08037B56
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	ldr r0, _08037BC4 @ =0xFBFFFFFF
	ands r1, r0
	str r1, [r2, #8]
_08037B56:
	mov r1, ip
	ldr r0, [r1, #8]
	cmp r0, #0
	bge _08037B64
	mov r0, ip
	bl ProcessAttackTileCollisions
_08037B64:
	ldr r2, [sp]
	lsls r0, r2, #0x18
	lsrs r3, r0, #0x18
	ldr r7, [sp, #8]
	cmp r3, #0
	beq _08037B72
	b _08037428
_08037B72:
	ldr r0, _08037BC8 @ =gUnk_02022F50
	ldr r1, [sp, #0x14]
	adds r7, r1, r0
	ldr r0, _08037BCC @ =gUnk_02022EB0
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldrb r3, [r0]
	cmp r3, #0
	bne _08037B86
	b _08037FEA
_08037B86:
	adds r1, r7, #0
	ldm r1!, {r0}
	mov ip, r0
	str r1, [sp, #8]
	subs r2, r3, #1
	str r2, [sp]
	cmp r0, #0
	bne _08037B98
	b _08037FDC
_08037B98:
	ldr r0, [r0, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08037BD6
	mov r0, ip
	ldr r2, [r0, #0x40]
	asrs r2, r2, #8
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	mov r8, r2
	b _08037BE8
	.align 2, 0
_08037BC4: .4byte 0xFBFFFFFF
_08037BC8: .4byte gUnk_02022F50
_08037BCC: .4byte gUnk_02022EB0
_08037BD0:
	movs r0, #0
	str r0, [r6]
	b _08037DE0
_08037BD6:
	mov r1, ip
	ldr r0, [r1, #0x40]
	asrs r0, r0, #8
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	mov r8, r0
_08037BE8:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x39
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	mov sb, r0
	ldr r1, [r2, #8]
	movs r0, #0x80
	lsls r0, r0, #0x16
	ands r0, r1
	subs r3, #1
	str r3, [sp]
	adds r2, r7, #4
	str r2, [sp, #8]
	cmp r0, #0
	bne _08037C12
	b _08037DEA
_08037C12:
	ldr r0, _08037C74 @ =gUnk_02022F50
	ldr r2, [sp, #0x14]
	adds r6, r2, r0
	ldr r0, _08037C78 @ =gUnk_02022EB0
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldrb r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _08037C28
	b _08037DE0
_08037C28:
	ldr r3, [r6]
	adds r4, r3, #0
	cmp r3, #0
	bne _08037C32
	b _08037DB2
_08037C32:
	cmp r3, ip
	bne _08037C38
	b _08037DB2
_08037C38:
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	cmp r1, #0
	beq _08037C44
	b _08037DE0
_08037C44:
	ldr r1, [r3, #8]
	ands r2, r1
	cmp r2, #0
	beq _08037C4E
	b _08037DB2
_08037C4E:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08037C7C
	ldr r2, [r3, #0x40]
	asrs r2, r2, #8
	adds r0, r3, #0
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	b _08037C8C
	.align 2, 0
_08037C74: .4byte gUnk_02022F50
_08037C78: .4byte gUnk_02022EB0
_08037C7C:
	ldr r0, [r3, #0x40]
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
_08037C8C:
	ldr r1, [r4, #0x44]
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x39
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, r0
	cmp r8, r2
	bgt _08037CB6
	mov r0, ip
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	cmp r0, r2
	bge _08037CC8
	cmp r8, r2
	blt _08037D34
_08037CB6:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r8
	blt _08037D34
_08037CC8:
	cmp sb, r5
	bgt _08037CE2
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, sb
	cmp r0, r5
	bge _08037CF4
	cmp sb, r5
	blt _08037D34
_08037CE2:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, sb
	blt _08037D34
_08037CF4:
	ldr r1, [r7]
	ldrb r0, [r1]
	lsls r0, r0, #2
	ldr r2, _08037D30 @ =gObjectCollisionCallbacks
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, [r6]
	ldrb r2, [r1]
	lsls r2, r2, #2
	ldr r0, _08037D30 @ =gObjectCollisionCallbacks
	adds r2, r2, r0
	ldr r0, [r7]
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08037D26
	b _08037BD0
_08037D26:
	cmp r4, #0
	beq _08037DB2
	str r0, [r7]
	b _08037DE0
	.align 2, 0
_08037D30: .4byte gObjectCollisionCallbacks
_08037D34:
	mov r1, ip
	ldr r0, [r1, #0x30]
	cmp r0, #0
	bne _08037DB2
	ldr r1, [r1, #0x40]
	asrs r1, r1, #8
	mov r0, ip
	adds r0, #0x34
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	cmp r1, r2
	bgt _08037D62
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r1, r0
	cmp r0, r2
	bge _08037D74
	cmp r1, r2
	blt _08037DB2
_08037D62:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r1
	blt _08037DB2
_08037D74:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
	cmp r2, r5
	bgt _08037DA0
	mov r0, ip
	adds r0, #0x37
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	adds r0, r2, r0
	cmp r0, r5
	bge _08037CF4
	cmp r2, r5
	blt _08037DB2
_08037DA0:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, r2
	bge _08037CF4
_08037DB2:
	mov r0, sl
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	adds r6, #4
	cmp r0, #0
	beq _08037DE0
	ldr r3, [r6]
	adds r4, r3, #0
	cmp r3, #0
	beq _08037DB2
	ldr r1, [r7]
	mov ip, r1
	cmp r3, ip
	beq _08037DB2
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r0, r2
	cmp r0, #0
	bne _08037DE0
	b _08037C44
_08037DE0:
	ldr r2, [r7]
	mov ip, r2
	cmp r2, #0
	bne _08037DEA
	b _08037FDC
_08037DEA:
	mov r1, ip
	ldr r0, [r1, #8]
	movs r1, #0x80
	lsls r1, r1, #0x15
	ands r0, r1
	cmp r0, #0
	bne _08037DFA
	b _08037FC4
_08037DFA:
	movs r2, #0
	mov sl, r2
	ldr r0, _08037E6C @ =gNumKirbys
	ldrb r0, [r0]
	cmp sl, r0
	blo _08037E08
	b _08037FBA
_08037E08:
	ldr r6, _08037E70 @ =gObjectCollisionCallbacks
_08037E0A:
	movs r0, #0xd4
	lsls r0, r0, #1
	mov r1, sl
	muls r1, r0, r1
	ldr r0, _08037E74 @ =gKirbys
	adds r4, r1, r0
	mov r0, ip
	adds r0, #0x60
	adds r1, r4, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08037E28
	b _08037FA2
_08037E28:
	mov r1, ip
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r0, r2
	cmp r0, #0
	beq _08037E38
	b _08037FBA
_08037E38:
	ldr r1, [r4, #8]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08037E44
	b _08037FA2
_08037E44:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08037E78
	ldr r2, [r4, #0x40]
	asrs r2, r2, #8
	adds r0, r4, #0
	adds r0, #0x38
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r2, r2, r1
	b _08037E88
	.align 2, 0
_08037E6C: .4byte gNumKirbys
_08037E70: .4byte gObjectCollisionCallbacks
_08037E74: .4byte gKirbys
_08037E78:
	ldr r0, [r4, #0x40]
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
_08037E88:
	ldr r1, [r4, #0x44]
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x39
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, r0
	cmp r8, r2
	bgt _08037EB2
	mov r0, ip
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	cmp r0, r2
	bge _08037EC4
	cmp r8, r2
	blt _08037F24
_08037EB2:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r8
	blt _08037F24
_08037EC4:
	cmp sb, r5
	bgt _08037EDE
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, sb
	cmp r0, r5
	bge _08037EF0
	cmp sb, r5
	blt _08037F24
_08037EDE:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, sb
	blt _08037F24
_08037EF0:
	ldr r1, [r7]
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r0, [r7]
	ldr r2, [r1]
	adds r1, r4, #0
	bl _call_via_r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08037FBA
	cmp r5, #0
	beq _08037FA2
	str r0, [r7]
	b _08037FBA
_08037F24:
	mov r1, ip
	ldr r0, [r1, #0x30]
	cmp r0, #0
	bne _08037FA2
	ldr r1, [r1, #0x40]
	asrs r1, r1, #8
	mov r0, ip
	adds r0, #0x34
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r1, r1, r3
	cmp r1, r2
	bgt _08037F52
	adds r0, #2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r1, r0
	cmp r0, r2
	bge _08037F64
	cmp r1, r2
	blt _08037FA2
_08037F52:
	adds r0, r4, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r2, r0
	cmp r0, r1
	blt _08037FA2
_08037F64:
	mov r2, ip
	ldr r0, [r2, #0x44]
	asrs r0, r0, #8
	mov r1, ip
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
	cmp r2, r5
	bgt _08037F90
	mov r0, ip
	adds r0, #0x37
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	adds r0, r2, r0
	cmp r0, r5
	bge _08037EF0
	cmp r2, r5
	blt _08037FA2
_08037F90:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r5, r0
	cmp r0, r2
	bge _08037EF0
_08037FA2:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, _0803800C @ =gNumKirbys
	ldr r1, [r7]
	mov ip, r1
	ldrb r0, [r0]
	cmp sl, r0
	bhs _08037FBA
	b _08037E0A
_08037FBA:
	ldr r7, [r7]
	mov ip, r7
	mov r2, ip
	cmp r2, #0
	beq _08037FDC
_08037FC4:
	mov r0, ip
	ldr r1, [r0, #8]
	cmp r1, #0
	bge _08037FDC
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	bne _08037FDC
	mov r0, ip
	bl ProcessAttackTileCollisions
_08037FDC:
	ldr r1, [sp]
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
	ldr r7, [sp, #8]
	cmp r3, #0
	beq _08037FEA
	b _08037B86
_08037FEA:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x18
	lsrs r2, r0, #0x18

_08037FF0: @ 0x08037FF0
	ldr r0, _0803800C @ =gNumKirbys
	ldrb r0, [r0]
	cmp r2, r0
	bhs _08037FFC
	bl _08037326
_08037FFC:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803800C: .4byte gNumKirbys

	.syntax divided
