	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r0, #0
	str r0, [sp]
	ldr r6, _08038D54 @ =gNumKirbys
	ldrb r1, [r6]
	cmp r0, r1
	blo _08038B4E
	b _08039116
_08038B4E:
	movs r4, #0xd4
	lsls r4, r4, #1
	ldr r2, [sp]
	adds r0, r2, #0
	muls r0, r4, r0
	ldr r3, _08038D58 @ =gKirbys
	adds r7, r0, r3
	mov sb, r7
	ldr r0, _08038D5C @ =gUnk_03000510
	ldrb r1, [r0, #4]
	movs r2, #1
	ldr r0, [sp]
	lsls r2, r0
	movs r0, #0x10
	orrs r0, r2
	ands r1, r0
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp, #8]
	cmp r1, #0
	beq _08038B7A
	b _08039104
_08038B7A:
	ldr r0, [r7, #8]
	ldr r1, _08038D60 @ =0x03800F00
	ands r0, r1
	cmp r0, #0
	beq _08038B86
	b _08039104
_08038B86:
	ldr r1, [r7, #0x78]
	ldr r0, _08038D64 @ =sub_080566E0
	cmp r1, r0
	bne _08038B90
	b _08039104
_08038B90:
	adds r0, r7, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	subs r0, #0x4a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08038BA2
	b _08039104
_08038BA2:
	ldrh r1, [r7, #0x1c]
	movs r0, #0x88
	lsls r0, r0, #2
	cmp r1, r0
	bne _08038BAE
	b _08039104
_08038BAE:
	ldr r1, [sp, #8]
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	ldrb r6, [r6]
	cmp r5, r6
	blo _08038BBC
	b _08039104
_08038BBC:
	mov sl, r4
	str r2, [sp, #4]
_08038BC0:
	mov r2, sl
	muls r2, r5, r2
	ldr r3, _08038D58 @ =gKirbys
	adds r3, r3, r2
	mov r8, r3
	ldr r0, [r3, #8]
	ldr r1, _08038D60 @ =0x03800F00
	ands r0, r1
	cmp r0, #0
	beq _08038BD6
	b _080390F4
_08038BD6:
	ldr r6, _08038D68 @ =gKirbys+0x78
	adds r0, r2, r6
	ldr r1, [r0]
	ldr r0, _08038D64 @ =sub_080566E0
	cmp r1, r0
	bne _08038BE4
	b _080390F4
_08038BE4:
	mov r1, sb
	adds r1, #0xd4
	ldrh r0, [r1]
	subs r0, #0x4a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r1, #0
	cmp r0, #0xf
	bhi _08038BF8
	b _080390F4
_08038BF8:
	ldrh r1, [r3, #0x1c]
	movs r0, #0x88
	lsls r0, r0, #2
	cmp r1, r0
	bne _08038C04
	b _080390F4
_08038C04:
	mov r0, r8
	adds r0, #0x60
	adds r1, r7, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08038C16
	b _080390F4
_08038C16:
	adds r0, r7, #0
	mov r1, r8
	bl KirbyCanContactOther
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	bne _08038C2A
	b _08038EA4
_08038C2A:
	ldr r0, _08038D6C @ =0x00000103
	add r0, sb
	ldrb r2, [r0]
	cmp r2, #0x17
	bne _08038C36
	b _08038EA4
_08038C36:
	ldr r0, _08038D6C @ =0x00000103
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0x17
	bne _08038C42
	b _08038D74
_08038C42:
	mov r0, sb
	adds r0, #0xe5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08038C4E
	b _08038D74
_08038C4E:
	mov r1, sb
	adds r1, #0xe1
	ldrb r0, [r1]
	asrs r0, r5
	movs r3, #1
	ands r0, r3
	adds r6, r1, #0
	cmp r0, #0
	beq _08038C62
	b _08038D74
_08038C62:
	cmp r2, #0xe
	beq _08038C92
	ldrh r0, [r4]
	cmp r0, #0x15
	bls _08038C74
	cmp r0, #0x19
	beq _08038C74
	cmp r0, #0x2f
	bne _08038C7A
_08038C74:
	ldrh r0, [r4]
	cmp r0, #0xd
	bne _08038CA4
_08038C7A:
	ldrh r0, [r4]
	subs r0, #0x38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08038CA4
	ldr r0, _08038D6C @ =0x00000103
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _08038C92
	b _08038EA4
_08038C92:
	ldrh r0, [r4]
	cmp r0, #0x12
	bls _08038CA4
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bls _08038CA4
	b _08038EA4
_08038CA4:
	mov r0, sl
	muls r0, r5, r0
	ldr r2, _08038D58 @ =gKirbys
	adds r1, r0, r2
	ldr r3, _08038D6C @ =0x00000103
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r3, r2, #0
	cmp r0, #0xe
	beq _08038CFA
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	cmp r0, #0x15
	bls _08038CCA
	cmp r0, #0x19
	beq _08038CCA
	cmp r0, #0x2f
	bne _08038CD8
_08038CCA:
	mov r0, sl
	muls r0, r5, r0
	adds r0, r0, r3
	adds r0, #0xd4
	ldrh r0, [r0]
	cmp r0, #0xd
	bne _08038D14
_08038CD8:
	mov r0, sl
	muls r0, r5, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	subs r0, #0x38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08038D14
	ldr r2, _08038D6C @ =0x00000103
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _08038CFA
	b _08038EA4
_08038CFA:
	mov r0, sl
	muls r0, r5, r0
	adds r0, r0, r3
	adds r0, #0xd4
	ldrh r0, [r0]
	cmp r0, #0x12
	bls _08038D14
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bls _08038D14
	b _08038EA4
_08038D14:
	mov r1, sb
	adds r1, #0x56
	ldr r0, _08038D70 @ =gNumHumanPlayers
	ldrb r1, [r1]
	ldrb r2, [r0]
	cmp r1, r2
	blo _08038D32
	mov r0, sl
	muls r0, r5, r0
	adds r0, r0, r3
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, r2
	blo _08038D32
	b _08038EA4
_08038D32:
	mov r0, sb
	adds r1, r5, #0
	bl sub_08053DAC
	mov r0, sl
	muls r0, r5, r0
	ldr r3, _08038D58 @ =gKirbys
	adds r0, r0, r3
	ldr r1, [sp]
	bl sub_08054414
	movs r0, #1
	lsls r0, r5
	ldrb r1, [r6]
	orrs r0, r1
	strb r0, [r6]
	b _080390F4
	.align 2, 0
_08038D54: .4byte gNumKirbys
_08038D58: .4byte gKirbys
_08038D5C: .4byte gUnk_03000510
_08038D60: .4byte 0x03800F00
_08038D64: .4byte sub_080566E0
_08038D68: .4byte gKirbys+0x78
_08038D6C: .4byte 0x00000103
_08038D70: .4byte gNumHumanPlayers
_08038D74:
	ldr r0, _08038E98 @ =0x00000103
	add r0, sb
	ldrb r2, [r0]
	cmp r2, #0x17
	bne _08038D80
	b _08038EA4
_08038D80:
	mov r0, sl
	muls r0, r5, r0
	ldr r6, _08038E9C @ =gKirbys
	adds r1, r0, r6
	ldr r3, _08038E98 @ =0x00000103
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r3, r6, #0
	cmp r0, #0x17
	bne _08038D96
	b _08038EA4
_08038D96:
	adds r0, r1, #0
	adds r0, #0xe5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08038DA2
	b _08038EA4
_08038DA2:
	adds r0, r1, #0
	adds r0, #0xe1
	ldrb r0, [r0]
	ldr r6, [sp]
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08038EA4
	cmp r2, #0xe
	beq _08038DE2
	ldrh r0, [r4]
	cmp r0, #0x15
	bls _08038DC6
	cmp r0, #0x19
	beq _08038DC6
	cmp r0, #0x2f
	bne _08038DCC
_08038DC6:
	ldrh r0, [r4]
	cmp r0, #0xd
	bne _08038DF2
_08038DCC:
	ldrh r0, [r4]
	subs r0, #0x38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08038DF2
	ldr r0, _08038E98 @ =0x00000103
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _08038EA4
_08038DE2:
	ldrh r0, [r4]
	cmp r0, #0x12
	bls _08038DF2
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bhi _08038EA4
_08038DF2:
	mov r0, sl
	muls r0, r5, r0
	adds r1, r0, r3
	ldr r2, _08038E98 @ =0x00000103
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _08038E42
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	cmp r0, #0x15
	bls _08038E14
	cmp r0, #0x19
	beq _08038E14
	cmp r0, #0x2f
	bne _08038E22
_08038E14:
	mov r0, sl
	muls r0, r5, r0
	adds r0, r0, r3
	adds r0, #0xd4
	ldrh r0, [r0]
	cmp r0, #0xd
	bne _08038E5A
_08038E22:
	mov r0, sl
	muls r0, r5, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	subs r0, #0x38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08038E5A
	ldr r6, _08038E98 @ =0x00000103
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _08038EA4
_08038E42:
	mov r0, sl
	muls r0, r5, r0
	adds r0, r0, r3
	adds r0, #0xd4
	ldrh r0, [r0]
	cmp r0, #0x12
	bls _08038E5A
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bhi _08038EA4
_08038E5A:
	mov r1, sb
	adds r1, #0x56
	ldr r0, _08038EA0 @ =gNumHumanPlayers
	ldrb r1, [r1]
	ldrb r2, [r0]
	cmp r1, r2
	blo _08038E76
	mov r0, sl
	muls r0, r5, r0
	adds r0, r0, r3
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, r2
	bhs _08038EA4
_08038E76:
	mov r4, sl
	muls r4, r5, r4
	adds r4, r4, r3
	adds r0, r4, #0
	ldr r1, [sp]
	bl sub_08053DAC
	mov r0, sb
	adds r1, r5, #0
	bl sub_08054414
	adds r4, #0xe1
	ldrb r1, [r4]
	ldr r0, [sp, #4]
	orrs r0, r1
	strb r0, [r4]
	b _080390F4
	.align 2, 0
_08038E98: .4byte 0x00000103
_08038E9C: .4byte gKirbys
_08038EA0: .4byte gNumHumanPlayers
_08038EA4:
	adds r1, r7, #0
	adds r1, #0x62
	ldrb r2, [r1]
	movs r3, #4
	adds r0, r3, #0
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08038FA8
	mov r0, r8
	adds r0, #0x62
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08038FA8
	mov r0, ip
	cmp r0, #0
	beq _08038F94
	ldr r1, [r7, #0x40]
	mov r3, r8
	ldr r0, [r3, #0x40]
	cmp r1, r0
	ble _08038F34
	movs r1, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08038EE6
	ldr r0, [r7, #8]
	ands r0, r1
	cmp r0, #0
	beq _08038F00
_08038EE6:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08038EF6
	ldr r0, [r7, #8]
	ands r0, r1
	cmp r0, #0
	bne _08038F00
_08038EF6:
	mov r1, sb
	adds r1, #0xf4
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08038F00:
	ldrb r1, [r4]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08038F16
	ldr r0, [r7, #8]
	ands r0, r2
	cmp r0, #0
	beq _08038F16
	b _080390F4
_08038F16:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08038F28
	ldr r0, [r7, #8]
	ands r0, r2
	cmp r0, #0
	bne _08038F28
	b _080390F4
_08038F28:
	mov r1, r8
	adds r1, #0xf4
	ldrh r0, [r1]
	subs r0, #0x40
	strh r0, [r1]
	b _080390F4
_08038F34:
	movs r1, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08038F46
	ldr r0, [r7, #8]
	ands r0, r1
	cmp r0, #0
	bne _08038F60
_08038F46:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08038F56
	ldr r0, [r7, #8]
	ands r0, r1
	cmp r0, #0
	beq _08038F60
_08038F56:
	mov r1, sb
	adds r1, #0xf4
	ldrh r0, [r1]
	subs r0, #0x80
	strh r0, [r1]
_08038F60:
	ldrb r1, [r4]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08038F76
	ldr r0, [r7, #8]
	ands r0, r2
	cmp r0, #0
	bne _08038F76
	b _080390F4
_08038F76:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08038F88
	ldr r0, [r7, #8]
	ands r0, r2
	cmp r0, #0
	beq _08038F88
	b _080390F4
_08038F88:
	mov r1, r8
	adds r1, #0xf4
	ldrh r0, [r1]
	adds r0, #0x40
	strh r0, [r1]
	b _080390F4
_08038F94:
	movs r2, #0x82
	lsls r2, r2, #1
	add r2, sb
	lsls r1, r5, #2
	movs r0, #7
	lsls r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080390F4
_08038FA8:
	movs r3, #0x82
	lsls r3, r3, #1
	add r3, sb
	ldrh r2, [r3]
	lsls r1, r5, #2
	movs r0, #7
	lsls r0, r1
	ands r2, r0
	adds r6, r1, #0
	cmp r2, #0
	beq _08038FFE
	mov r0, ip
	cmp r0, #0
	beq _08039004
	ldr r1, [r7, #0x44]
	mov r2, r8
	ldr r0, [r2, #0x44]
	cmp r1, r0
	bge _08038FF4
	ldr r0, [r7, #0xc]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r7, #0xc]
	ldrb r1, [r4]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strb r0, [r4]
	adds r0, r7, #0
	adds r0, #0x52
	strh r2, [r0]
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r3]
	subs r0, r0, r1
	strh r0, [r3]
	b _08038FFE
_08038FF4:
	adds r1, r7, #0
	adds r1, #0x55
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08038FFE:
	mov r3, ip
	cmp r3, #0
	bne _08039038
_08039004:
	movs r4, #0x82
	lsls r4, r4, #1
	add r4, sb
	ldrh r2, [r4]
	movs r3, #7
	lsls r3, r6
	adds r0, r2, #0
	ands r0, r3
	cmp r0, r3
	beq _08039034
	mov r6, r8
	ldr r0, [r6, #0x44]
	ldr r1, _0803902C @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r7, #0x44]
	cmp r1, r0
	ble _08039030
	bics r2, r3
	b _08039036
	.align 2, 0
_0803902C: .4byte 0xFFFFF000
_08039030:
	orrs r2, r3
	b _08039036
_08039034:
	orrs r2, r0
_08039036:
	strh r2, [r4]
_08039038:
	mov r0, r8
	adds r1, r7, #0
	bl KirbyCanContactOther
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	mov r0, sl
	muls r0, r5, r0
	ldr r2, _080390A0 @ =gKirbys
	adds r0, r0, r2
	movs r3, #0x82
	lsls r3, r3, #1
	adds r4, r0, r3
	ldrh r2, [r4]
	ldr r6, [sp]
	lsls r1, r6, #2
	movs r0, #7
	lsls r0, r1
	ands r2, r0
	adds r6, r1, #0
	cmp r2, #0
	beq _080390AE
	mov r0, ip
	cmp r0, #0
	beq _080390B4
	ldr r1, [r7, #0x44]
	mov r2, r8
	ldr r0, [r2, #0x44]
	cmp r1, r0
	ble _080390A4
	ldr r0, [r2, #0xc]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r2, #0xc]
	mov r3, r8
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strb r0, [r3]
	mov r0, r8
	adds r0, #0x52
	strh r2, [r0]
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r4]
	subs r0, r0, r1
	strh r0, [r4]
	b _080390AE
	.align 2, 0
_080390A0: .4byte gKirbys
_080390A4:
	mov r1, r8
	adds r1, #0x55
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080390AE:
	mov r3, ip
	cmp r3, #0
	bne _080390F4
_080390B4:
	mov r0, sl
	muls r0, r5, r0
	ldr r1, _080390E4 @ =gKirbys
	adds r0, r0, r1
	movs r2, #0x82
	lsls r2, r2, #1
	adds r4, r0, r2
	ldrh r2, [r4]
	movs r3, #7
	lsls r3, r6
	adds r0, r2, #0
	ands r0, r3
	cmp r0, r3
	beq _080390F0
	ldr r0, [r7, #0x44]
	ldr r6, _080390E8 @ =0xFFFFF000
	adds r0, r0, r6
	mov r6, r8
	ldr r1, [r6, #0x44]
	cmp r1, r0
	ble _080390EC
	bics r2, r3
	b _080390F2
	.align 2, 0
_080390E4: .4byte gKirbys
_080390E8: .4byte 0xFFFFF000
_080390EC:
	orrs r2, r3
	b _080390F2
_080390F0:
	orrs r2, r0
_080390F2:
	strh r2, [r4]
_080390F4:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08039128 @ =gNumKirbys
	ldrb r0, [r0]
	cmp r5, r0
	bhs _08039104
	b _08038BC0
_08039104:
	ldr r1, [sp, #8]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	ldr r6, _08039128 @ =gNumKirbys
	ldrb r2, [r6]
	cmp r0, r2
	bhs _08039116
	b _08038B4E
_08039116:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039128: .4byte gNumKirbys

	.syntax divided
