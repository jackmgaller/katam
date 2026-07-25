	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r6
	adds r2, r6, #0
	adds r2, #0xb7
	ldrb r4, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	bne _081227C8
	b _08122906
_081227C8:
	adds r0, r6, #0
	adds r0, #0xb0
	ldr r0, [r0]
	mov ip, r0
	ldrh r1, [r0, #0x22]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08122858
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _081228C0
	movs r4, #0
	ldr r0, _081227FC @ =gNumKirbys
	adds r5, r6, #0
	adds r5, #0xb4
	b _08122828
	.align 2, 0
_081227FC: .4byte gNumKirbys
_08122800:
	mov r0, r8
	adds r0, #0xba
	ldrb r0, [r0]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08122820
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r4, r0
	ldr r1, _0812284C @ =gKirbys
	adds r0, r0, r1
	ldrb r1, [r5]
	bl sub_08051F70
_08122820:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08122850 @ =gNumKirbys
_08122828:
	ldrb r0, [r0]
	cmp r4, r0
	blo _08122800
	ldr r0, _08122854 @ =EightDirCannonRecoil
	str r0, [r6, #0x78]
	ldrb r1, [r7]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7]
	ldrb r1, [r5]
	adds r0, r6, #0
	bl sub_081222AC
	movs r0, #3
	adds r1, r6, #0
	bl RequestScreenShake
	b _081228C0
	.align 2, 0
_0812284C: .4byte gKirbys
_08122850: .4byte gNumKirbys
_08122854: .4byte EightDirCannonRecoil
_08122858:
	movs r0, #2
	ands r0, r4
	adds r7, r2, #0
	cmp r0, #0
	beq _081228C0
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r5, r0, #0
	mov r2, ip
	ldrh r2, [r2, #0x14]
	cmp r1, r2
	bne _081228C0
	movs r4, #0
	b _0812289C
_08122876:
	mov r0, r8
	adds r0, #0xba
	ldrb r0, [r0]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08122896
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r4, r0
	ldr r1, _08122910 @ =gKirbys
	adds r0, r0, r1
	ldrb r1, [r5]
	bl sub_08051F70
_08122896:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0812289C:
	ldr r0, _08122914 @ =gNumKirbys
	ldrb r0, [r0]
	cmp r4, r0
	blo _08122876
	ldr r0, _08122918 @ =EightDirCannonRecoil
	str r0, [r6, #0x78]
	ldrb r1, [r7]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7]
	ldrb r1, [r5]
	adds r0, r6, #0
	bl sub_081222AC
	movs r0, #3
	adds r1, r6, #0
	bl RequestScreenShake
_081228C0:
	ldrb r1, [r7]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08122906
	mov r3, r8
	adds r3, #0xb5
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08122906
	mov r2, r8
	adds r2, #0xb4
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _081228FA
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r7]
	movs r1, #2
	orrs r0, r1
	strb r0, [r7]
_081228FA:
	ldrb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x83
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3]
_08122906:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08122910: .4byte gKirbys
_08122914: .4byte gNumKirbys
_08122918: .4byte EightDirCannonRecoil

	.syntax divided

