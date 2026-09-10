	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080369C4
	adds r0, r4, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #0x46
	bne _080369C4
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080369C4
	b _08036CB0
_080369C4:
	ldr r5, [r7, #0x70]
	cmp r5, r4
	bne _080369CC
	b _08036CB0
_080369CC:
	ldrb r0, [r4]
	cmp r0, #1
	bne _080369EC
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	cmp r0, #0
	beq _080369EC
	ldr r0, [r7, #8]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _080369EC
	b _08036CB0
_080369EC:
	ldr r1, [r7, #0x68]
	movs r0, #0x20
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	bne _080369FA
	b _08036BB2
_080369FA:
	str r4, [r7, #0x6c]
	ldr r2, [r4, #0x5c]
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r2
	ldr r0, _08036A70 @ =0x003FFFF8
	bics r0, r1
	ands r0, r6
	cmp r0, #0
	bne _08036A10
	b _08036CB0
_08036A10:
	movs r0, #7
	ands r2, r0
	ands r0, r6
	cmp r0, r2
	bhs _08036A1C
	b _08036CB0
_08036A1C:
	ldr r0, [r4, #8]
	movs r2, #0x80
	lsls r2, r2, #8
	ands r0, r2
	cmp r0, #0
	beq _08036A2A
	b _08036CB0
_08036A2A:
	adds r3, r5, #0
	cmp r5, #0
	bne _08036A32
	b _08036CB0
_08036A32:
	ldr r0, [r5, #0xc]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0xc]
	ldrb r0, [r5]
	cmp r0, #1
	beq _08036A44
	b _08036CB0
_08036A44:
	adds r0, r5, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _08036A50
	b _08036B8E
_08036A50:
	cmp r0, #0x3c
	bgt _08036A8E
	cmp r0, #0x32
	beq _08036ABE
	cmp r0, #0x32
	bgt _08036A7A
	cmp r0, #0xe
	bne _08036A62
	b _08036BA2
_08036A62:
	cmp r0, #0xe
	bgt _08036A74
	cmp r0, #7
	bne _08036A6C
	b _08036BA2
_08036A6C:
	b _08036CB0
	.align 2, 0
_08036A70: .4byte 0x003FFFF8
_08036A74:
	cmp r0, #0xf
	beq _08036B26
	b _08036CB0
_08036A7A:
	cmp r0, #0x38
	beq _08036AE6
	cmp r0, #0x38
	bgt _08036A88
	cmp r0, #0x33
	beq _08036AD2
	b _08036CB0
_08036A88:
	cmp r0, #0x3a
	beq _08036B12
	b _08036CB0
_08036A8E:
	cmp r0, #0x4d
	beq _08036B76
	cmp r0, #0x4d
	bgt _08036AAA
	cmp r0, #0x47
	beq _08036B76
	cmp r0, #0x47
	bgt _08036AA4
	cmp r0, #0x3e
	beq _08036B62
	b _08036CB0
_08036AA4:
	cmp r0, #0x48
	beq _08036B3A
	b _08036CB0
_08036AAA:
	cmp r0, #0x9f
	beq _08036B4E
	cmp r0, #0x9f
	bgt _08036AB8
	cmp r0, #0x9e
	beq _08036AFA
	b _08036CB0
_08036AB8:
	cmp r0, #0xae
	beq _08036AFA
	b _08036CB0
_08036ABE:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036AC8
	b _08036CB0
_08036AC8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080A049C
	b _08036BAA
_08036AD2:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036ADC
	b _08036CB0
_08036ADC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080A1804
	b _08036BAA
_08036AE6:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036AF0
	b _08036CB0
_08036AF0:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080CC6F0
	b _08036BAA
_08036AFA:
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08036B08
	b _08036CB0
_08036B08:
	adds r0, r3, #0
	adds r1, r4, #0
	bl sub_080B6368
	b _08036BAA
_08036B12:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036B1C
	b _08036CB0
_08036B1C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080CE94C
	b _08036BAA
_08036B26:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036B30
	b _08036CB0
_08036B30:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080B0758
	b _08036BAA
_08036B3A:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036B44
	b _08036CB0
_08036B44:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080E588C
	b _08036BAA
_08036B4E:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036B58
	b _08036CB0
_08036B58:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080E74E4
	b _08036BAA
_08036B62:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036B6C
	b _08036CB0
_08036B6C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080D4004
	b _08036BAA
_08036B76:
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08036B84
	b _08036CB0
_08036B84:
	adds r0, r3, #0
	adds r1, r4, #0
	bl sub_080E1B8C
	b _08036BAA
_08036B8E:
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08036B98
	b _08036CB0
_08036B98:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C8548
	b _08036BAA
_08036BA2:
	adds r0, r3, #0
	adds r1, r4, #0
	bl sub_080AC5E0
_08036BAA:
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08036CA6
	b _08036CB0
_08036BB2:
	ldr r1, [r4, #8]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _08036C08
	ldr r2, [r7, #8]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	bne _08036C08
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r0, r1
	cmp r0, #0
	bne _08036BE0
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r2
	cmp r0, #0
	beq _08036BFE
_08036BE0:
	ldr r3, [r4, #0x5c]
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r3
	ldr r0, _08036CAC @ =0x003FFFF8
	bics r0, r1
	ands r0, r6
	cmp r0, #0
	beq _08036C08
	movs r1, #7
	adds r0, r6, #0
	ands r0, r1
	ands r3, r1
	cmp r0, r3
	blo _08036C08
_08036BFE:
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	str r2, [r7, #8]
	str r4, [r7, #0x6c]
_08036C08:
	adds r3, r6, #0
	movs r0, #0x80
	lsls r0, r0, #0x15
	ands r0, r3
	cmp r0, #0
	beq _08036C70
	movs r0, #0x80
	lsls r0, r0, #0xf
	mov r8, r0
	mov r0, ip
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _08036C70
	movs r0, #0x80
	lsls r0, r0, #9
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	bne _08036C70
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r0, r1
	cmp r0, #0
	beq _08036C56
	ldr r2, [r4, #0x5c]
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r2
	ldr r0, _08036CAC @ =0x003FFFF8
	bics r0, r1
	ands r0, r3
	cmp r0, #0
	beq _08036CB0
	movs r0, #7
	ands r3, r0
	ands r2, r0
	cmp r3, r2
	blo _08036C70
_08036C56:
	mov r0, r8
	ands r6, r0
	cmp r6, #0
	beq _08036C68
	ldr r0, [r4, #0x5c]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _08036C70
_08036C68:
	adds r0, r5, #0
	movs r1, #4
	bl sub_080853C8
_08036C70:
	ldr r2, [r4, #0x5c]
	movs r1, #8
	rsbs r1, r1, #0
	ands r1, r2
	ldr r0, _08036CAC @ =0x003FFFF8
	bics r0, r1
	ldr r3, [r7, #0x68]
	ands r0, r3
	cmp r0, #0
	beq _08036CB0
	movs r1, #7
	adds r0, r3, #0
	ands r0, r1
	ands r2, r1
	cmp r0, r2
	blo _08036CB0
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne _08036CB0
	movs r0, #0x80
	lsls r0, r0, #0x16
	ands r3, r0
	cmp r3, #0
	bne _08036CB0
_08036CA6:
	movs r0, #1
	b _08036CB2
	.align 2, 0
_08036CAC: .4byte 0x003FFFF8
_08036CB0:
	movs r0, #0
_08036CB2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	.syntax divided
