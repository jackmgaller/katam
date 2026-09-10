	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r7]
	cmp r0, #2
	bne _08036600
	adds r0, r5, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #0x46
	bne _080365F2
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080365F2
	b _0803698E
_080365F2:
	ldrb r0, [r7]
	cmp r0, #2
	bne _08036600
	ldr r0, [r7, #0x70]
	cmp r0, r5
	bne _08036600
	b _0803698E
_08036600:
	ldr r0, [r5, #8]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	cmp r0, #0
	beq _08036626
	ldr r0, [r7, #8]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0803661A
	b _0803698E
_0803661A:
	ldr r0, [r7, #0x68]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08036626
	b _0803698E
_08036626:
	ldr r0, [r7, #0x70]
	cmp r0, #0
	beq _08036646
	ldrb r0, [r0]
	cmp r0, #0
	bne _08036646
	adds r0, r7, #0
	adds r0, #0x56
	ldr r1, _080366B0 @ =gLocalPlayerId
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08036646
	adds r0, r5, #0
	bl TryTrackHudEnemy
_08036646:
	ldr r1, [r7, #0x68]
	movs r0, #0x20
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	bne _08036654
	b _08036864
_08036654:
	adds r4, r5, #0
	ldr r2, [r7, #0x70]
	mov ip, r2
	cmp r2, #0
	bne _08036660
	b _0803698E
_08036660:
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #1
	bne _080366B4
	mov r0, ip
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #7
	beq _08036678
	cmp r0, #0xe
	beq _08036678
	b _0803698E
_08036678:
	adds r0, r5, #0
	adds r0, #0x82
	ldrb r0, [r0]
	subs r0, #0x5e
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _0803668A
	b _0803698E
_0803668A:
	ldr r0, [r7, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	bne _080366A4
	ldr r0, [r5, #8]
	movs r1, #0x80
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r5, #8]
	mov r2, ip
	str r2, [r5, #0x6c]
_080366A4:
	adds r0, r5, #0
	bl sub_0809CFC4
	movs r0, #1
	b _08036990
	.align 2, 0
_080366B0: .4byte gLocalPlayerId
_080366B4:
	adds r0, r7, #0
	adds r0, #0x56
	ldr r1, _08036750 @ =gNumHumanPlayers
	ldrb r2, [r0]
	ldrb r3, [r1]
	mov r8, r0
	cmp r2, r3
	blo _080366F0
	adds r0, r5, #0
	adds r0, #0x82
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x5e
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _080366D8
	b _0803698E
_080366D8:
	adds r0, r1, #0
	cmp r0, #0xa4
	bne _080366E0
	b _0803698E
_080366E0:
	cmp r0, #0xa3
	bne _080366F0
	adds r0, r5, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, r3
	bhs _080366F0
	b _0803698E
_080366F0:
	ldr r1, [r7, #8]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08036766
	ldr r1, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	bne _08036766
	movs r0, #0x80
	lsls r0, r0, #0xd
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	bne _08036720
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r1, r0
	cmp r1, #0
	beq _08036758
_08036720:
	ldr r2, [r5, #0x5c]
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r2
	ldr r0, _08036754 @ =0x003FFFF8
	bics r0, r1
	ands r0, r6
	cmp r0, #0
	beq _08036766
	movs r1, #7
	adds r0, r6, #0
	ands r0, r1
	ands r2, r1
	cmp r0, r2
	blo _08036766
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r4, #8]
	mov r0, ip
	str r0, [r4, #0x6c]
	b _08036766
	.align 2, 0
_08036750: .4byte gNumHumanPlayers
_08036754: .4byte 0x003FFFF8
_08036758:
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r4, #8]
	mov r1, ip
	str r1, [r4, #0x6c]
_08036766:
	ldr r0, _08036788 @ =0x20000023
	cmp r6, r0
	bne _0803678C
	adds r3, r4, #0
	adds r3, #0x90
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #1
	movs r1, #3
	lsls r1, r0
	ldrb r2, [r3]
	bics r2, r1
	mov r0, r8
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r0, #2
	b _080367A6
	.align 2, 0
_08036788: .4byte 0x20000023
_0803678C:
	adds r3, r4, #0
	adds r3, #0x90
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #1
	movs r1, #3
	lsls r1, r0
	ldrb r2, [r3]
	bics r2, r1
	mov r0, r8
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r0, #1
_080367A6:
	lsls r0, r1
	orrs r2, r0
	strb r2, [r3]
	ldr r1, [r5, #0x5c]
	movs r0, #0x20
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq _080367D0
	adds r0, r4, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #0xd4
	bhi _080367C4
	b _0803698E
_080367C4:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r6
	cmp r0, #0
	bne _080367DA
	b _0803698E
_080367D0:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r6
	cmp r0, #0
	beq _080367F8
_080367DA:
	adds r0, r4, #0
	adds r0, #0x82
	ldrb r0, [r0]
	subs r0, #0x5e
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _080367F8
	ldr r0, _080367F4 @ =0xFFFBFFFF
	mov r1, sb
	ands r0, r1
	str r0, [r7, #8]
	b _0803698E
	.align 2, 0
_080367F4: .4byte 0xFFFBFFFF
_080367F8:
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r3
	ldr r0, _08036828 @ =0x003FFFF8
	bics r0, r1
	ands r0, r6
	cmp r0, #0
	beq _0803682C
	movs r0, #7
	ands r3, r0
	ands r0, r6
	cmp r0, r3
	blo _0803682C
	movs r0, #0x80
	lsls r0, r0, #0xb
	mov r2, sb
	orrs r0, r2
	str r0, [r7, #8]
	mov r0, ip
	str r0, [r4, #0x6c]
	adds r0, r4, #0
	bl sub_0809C380
	b _0803698E
	.align 2, 0
_08036828: .4byte 0x003FFFF8
_0803682C:
	ldr r0, _0803685C @ =gUnk_03000510
	ldrb r2, [r0, #4]
	adds r1, r5, #0
	adds r1, #0x56
	movs r0, #1
	ldrb r1, [r1]
	lsls r0, r1
	movs r1, #0x10
	orrs r0, r1
	ands r2, r0
	cmp r2, #0
	beq _08036846
	b _0803698E
_08036846:
	adds r2, r5, #0
	adds r2, #0x54
	ldr r0, _08036860 @ =gUnk_0203AD40
	ldr r1, [r0]
	movs r0, #2
	ands r1, r0
	lsls r1, r1, #1
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	b _0803698E
	.align 2, 0
_0803685C: .4byte gUnk_03000510
_08036860: .4byte gUnk_0203AD40
_08036864:
	ldr r2, [r7, #8]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r2
	ldr r3, [r5, #0x5c]
	cmp r0, #0
	bne _080368BC
	ldr r1, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	bne _080368BC
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r2, r0
	cmp r2, #0
	bne _08036894
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r4
	cmp r0, #0
	beq _080368B2
_08036894:
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r3
	ldr r0, _080368F4 @ =0x003FFFF8
	bics r0, r1
	ands r0, r6
	cmp r0, #0
	beq _0803690E
	movs r2, #7
	adds r1, r6, #0
	ands r1, r2
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	blo _080368BC
_080368B2:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r0, r4
	str r0, [r5, #8]
	str r7, [r5, #0x6c]
_080368BC:
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r3
	ldr r0, _080368F4 @ =0x003FFFF8
	bics r0, r1
	ands r0, r6
	ldr r4, [r5, #8]
	cmp r0, #0
	beq _0803690E
	movs r1, #7
	adds r0, r6, #0
	ands r0, r1
	ands r3, r1
	cmp r0, r3
	blo _0803690E
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0803690E
	ands r6, r1
	cmp r6, #0
	beq _080368F8
	adds r0, r5, #0
	bl sub_0809C6D0
	b _080368FE
	.align 2, 0
_080368F4: .4byte 0x003FFFF8
_080368F8:
	adds r0, r5, #0
	bl sub_0809B1E4
_080368FE:
	ldr r0, [r5, #0x68]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	bne _0803698E
	movs r0, #1
	b _08036990
_0803690E:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r0, r4
	cmp r0, #0
	beq _0803698E
	adds r4, r5, #0
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r0, r6
	cmp r0, #0
	bne _0803698E
	adds r0, r4, #0
	adds r0, #0x82
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1a
	bls _08036960
	cmp r1, #0x6d
	bne _08036942
	movs r0, #0x80
	ands r0, r6
	cmp r0, #0
	bne _0803694A
_08036942:
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0808845C
_0803694A:
	ldr r0, [r5, #8]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne _0803697C
	adds r0, r4, #0
	movs r1, #0x10
	bl sub_0808520C
	b _0803697C
_08036960:
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0808845C
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne _0803697C
	adds r0, r4, #0
	movs r1, #0x10
	bl sub_0808520C
_0803697C:
	ldr r0, [r7, #0x68]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	beq _0803698E
	adds r0, r4, #0
	bl sub_080884C4
_0803698E:
	movs r0, #0
_08036990:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	.syntax divided
