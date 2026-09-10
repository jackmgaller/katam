	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrh r1, [r7, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803A46A
	bl _0803AF7E
_0803A46A:
	ldr r5, _0803A7D0 @ =gBgPalette
	movs r0, #0
	mov sb, r0
	ldr r1, _0803A7D4 @ =gObjPalette
	mov sl, r1
_0803A474:
	ldrh r0, [r7, #6]
	mov r1, sb
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803A484
	b _0803A9E4
_0803A484:
	adds r5, #2
	ldrh r4, [r5]
	movs r0, #0x1f
	ands r0, r4
	movs r3, #1
	ldrsb r3, [r7, r3]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r6, #0x80
	lsls r6, r6, #8
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A4A6
	movs r2, #0
_0803A4A6:
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A4C4
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A4C4:
	lsrs r0, r4, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A4E0
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A4E0:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A500
	movs r2, #0
_0803A500:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A51E
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A51E:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A53A
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A53A:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A55A
	movs r2, #0
_0803A55A:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A578
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A578:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A594
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A594:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A5B4
	movs r2, #0
_0803A5B4:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A5D2
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A5D2:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A5EE
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A5EE:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A60E
	movs r2, #0
_0803A60E:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A62C
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A62C:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A648
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A648:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A668
	movs r2, #0
_0803A668:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A686
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A686:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A6A2
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A6A2:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A6C2
	movs r2, #0
_0803A6C2:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A6E0
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A6E0:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A6FC
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A6FC:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A71C
	movs r2, #0
_0803A71C:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A73A
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A73A:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A756
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A756:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A776
	movs r2, #0
_0803A776:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A794
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A794:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A7B0
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A7B0:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	b _0803A7D8
	.align 2, 0
_0803A7D0: .4byte gBgPalette
_0803A7D4: .4byte gObjPalette
_0803A7D8:
	beq _0803A7DC
	movs r2, #0
_0803A7DC:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A7FA
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A7FA:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A816
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A816:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A836
	movs r2, #0
_0803A836:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A854
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A854:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A870
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A870:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	mov r8, r0
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A892
	movs r2, #0
_0803A892:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A8B0
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A8B0:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	mov ip, r1
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A8D0
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A8D0:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	mov r0, r8
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A8F0
	movs r2, #0
_0803A8F0:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A90E
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A90E:
	lsrs r0, r3, #0x1a
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A92A
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A92A:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	mov r0, r8
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A94A
	movs r2, #0
_0803A94A:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A968
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A968:
	lsrs r0, r3, #0x1a
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A984
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A984:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	mov r0, r8
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803A9A4
	movs r2, #0
_0803A9A4:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A9C2
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A9C2:
	lsrs r0, r3, #0x1a
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803A9DE
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A9DE:
	strh r2, [r5]
	adds r5, #2
	b _0803A9E6
_0803A9E4:
	adds r5, #0x20
_0803A9E6:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0xf
	bhi _0803A9F6
	b _0803A474
_0803A9F6:
	mov r5, sl
	movs r0, #0
	mov sb, r0
_0803A9FC:
	ldrh r0, [r7, #4]
	mov r1, sb
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803AA0C
	b _0803AF60
_0803AA0C:
	adds r5, #2
	ldrh r4, [r5]
	movs r0, #0x1f
	ands r0, r4
	movs r3, #1
	ldrsb r3, [r7, r3]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r6, #0x80
	lsls r6, r6, #8
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AA2E
	movs r2, #0
_0803AA2E:
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AA4C
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AA4C:
	lsrs r0, r4, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AA68
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AA68:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AA88
	movs r2, #0
_0803AA88:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AAA6
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AAA6:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AAC2
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AAC2:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AAE2
	movs r2, #0
_0803AAE2:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AB00
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AB00:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AB1C
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AB1C:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AB3C
	movs r2, #0
_0803AB3C:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AB5A
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AB5A:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AB76
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AB76:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AB96
	movs r2, #0
_0803AB96:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803ABB4
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803ABB4:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803ABD0
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803ABD0:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803ABF0
	movs r2, #0
_0803ABF0:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AC0E
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AC0E:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AC2A
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AC2A:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AC4A
	movs r2, #0
_0803AC4A:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AC68
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AC68:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AC84
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AC84:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803ACA4
	movs r2, #0
_0803ACA4:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803ACC2
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803ACC2:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803ACDE
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803ACDE:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803ACFE
	movs r2, #0
_0803ACFE:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AD1C
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AD1C:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AD38
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AD38:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AD58
	movs r2, #0
_0803AD58:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AD76
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AD76:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AD92
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AD92:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803ADB2
	movs r2, #0
_0803ADB2:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803ADD0
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803ADD0:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803ADEC
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803ADEC:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	movs r0, #0x1f
	mov r8, r0
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AE0E
	movs r2, #0
_0803AE0E:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	movs r1, #0x1f
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AE2C
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AE2C:
	lsrs r0, r3, #0x1a
	movs r1, #0x1f
	mov ip, r1
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AE4C
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AE4C:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	mov r0, r8
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AE6C
	movs r2, #0
_0803AE6C:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AE8A
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AE8A:
	lsrs r0, r3, #0x1a
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AEA6
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AEA6:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	mov r0, r8
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AEC6
	movs r2, #0
_0803AEC6:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AEE4
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AEE4:
	lsrs r0, r3, #0x1a
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AF00
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AF00:
	strh r2, [r5]
	adds r5, #2
	ldrh r3, [r5]
	mov r0, r8
	ands r0, r3
	movs r4, #1
	ldrsb r4, [r7, r4]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	beq _0803AF20
	movs r2, #0
_0803AF20:
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AF3E
	lsls r0, r1, #5
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AF3E:
	lsrs r0, r3, #0x1a
	mov r1, ip
	ands r0, r1
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0803AF5A
	lsls r0, r1, #0xa
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803AF5A:
	strh r2, [r5]
	adds r5, #2
	b _0803AF62
_0803AF60:
	adds r5, #0x20
_0803AF62:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0xf
	bhi _0803AF72
	b _0803A9FC
_0803AF72:
	ldr r1, _0803AFB8 @ =gMainFlags
	ldr r0, [r1]
	movs r1, #3
	orrs r0, r1
	ldr r1, _0803AFB8 @ =gMainFlags
	str r0, [r1]
_0803AF7E:
	ldrh r2, [r7, #8]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	bne _0803AFD8
	ldr r0, _0803AFB8 @ =gMainFlags
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803AF9E
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0803AFD8
_0803AF9E:
	movs r1, #1
	ldrsb r1, [r7, r1]
	ldrb r3, [r7, #2]
	movs r0, #2
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _0803AFCC
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0803AFBC
	strb r3, [r7, #1]
	b _0803AFD8
	.align 2, 0
_0803AFB8: .4byte gMainFlags
_0803AFBC:
	movs r0, #1
	orrs r0, r2
	ldr r1, _0803AFC8 @ =0x0000FF79
	ands r0, r1
	strh r0, [r7, #8]
	b _0803AFD8
	.align 2, 0
_0803AFC8: .4byte 0x0000FF79
_0803AFCC:
	ldrh r0, [r7, #0xa]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
	lsrs r0, r0, #8
	strb r0, [r7, #1]
_0803AFD8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
