	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldrh r1, [r5, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803B000
	b _0803B6F4
_0803B000:
	ldr r4, _0803B370 @ =gBgPalette
	movs r0, #0
	mov sl, r0
	ldr r1, _0803B374 @ =gBrightenRedTable
	mov r8, r1
	movs r6, #0x1f
	movs r2, #0x1f
	mov sb, r2
	ldr r0, _0803B378 @ =gBrightenGreenTable
	mov ip, r0
	ldr r7, _0803B37C @ =gBrightenBlueTable
_0803B016:
	ldrh r0, [r5, #6]
	mov r1, sl
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803B026
	b _0803B380
_0803B026:
	mov r2, sl
	cmp r2, #0
	bne _0803B05E
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
_0803B05E:
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	b _0803B382
	.align 2, 0
_0803B370: .4byte gBgPalette
_0803B374: .4byte gBrightenRedTable
_0803B378: .4byte gBrightenGreenTable
_0803B37C: .4byte gBrightenBlueTable
_0803B380:
	adds r4, #0x20
_0803B382:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	cmp r0, #0xf
	bhi _0803B392
	b _0803B016
_0803B392:
	ldr r4, _0803B6C8 @ =gObjPalette
	movs r0, #0
	mov sl, r0
	ldr r1, _0803B6CC @ =gBrightenRedTable
	mov sb, r1
	movs r6, #0x1f
	movs r2, #0x1f
	mov ip, r2
	ldr r0, _0803B6D0 @ =gBrightenGreenTable
	mov r8, r0
	ldr r7, _0803B6D4 @ =gBrightenBlueTable
_0803B3A8:
	ldrh r0, [r5, #4]
	mov r1, sl
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803B3B8
	b _0803B6D8
_0803B3B8:
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	ldrh r1, [r4]
	mov r0, ip
	ands r0, r1
	movs r2, #1
	ldrsb r2, [r5, r2]
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, sb
	ldrh r3, [r0]
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	ands r0, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	b _0803B6DA
	.align 2, 0
_0803B6C8: .4byte gObjPalette
_0803B6CC: .4byte gBrightenRedTable
_0803B6D0: .4byte gBrightenGreenTable
_0803B6D4: .4byte gBrightenBlueTable
_0803B6D8:
	adds r4, #0x20
_0803B6DA:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	cmp r0, #0xf
	bhi _0803B6EA
	b _0803B3A8
_0803B6EA:
	ldr r2, _0803B75C @ =gMainFlags
	ldr r0, [r2]
	movs r1, #3
	orrs r0, r1
	str r0, [r2]
_0803B6F4:
	ldrh r1, [r5, #8]
	movs r0, #1
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	bne _0803B778
	ldr r0, _0803B75C @ =gMainFlags
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803B716
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _0803B778
_0803B716:
	ldrh r1, [r5, #0xa]
	ldrh r2, [r5, #0xc]
	adds r0, r1, r2
	strh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strb r0, [r5, #1]
	adds r3, r0, #0
	movs r2, #2
	ldrsb r2, [r5, r2]
	ldrb r6, [r5, #2]
	cmp r3, r2
	bgt _0803B73A
	lsls r0, r1, #0x10
	cmp r0, #0
	blt _0803B740
	cmp r3, r2
	blt _0803B778
_0803B73A:
	lsls r0, r1, #0x10
	cmp r0, #0
	ble _0803B778
_0803B740:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0
	beq _0803B770
	movs r0, #0x40
	ands r0, r4
	cmp r0, #0
	beq _0803B760
	movs r0, #2
	ldrsb r0, [r5, r0]
	lsls r0, r0, #8
	strh r0, [r5, #0xc]
	strb r6, [r5, #1]
	b _0803B778
	.align 2, 0
_0803B75C: .4byte gMainFlags
_0803B760:
	movs r0, #1
	orrs r0, r4
	ldr r1, _0803B76C @ =0x0000FF59
	ands r0, r1
	b _0803B776
	.align 2, 0
_0803B76C: .4byte 0x0000FF59
_0803B770:
	strb r6, [r5, #1]
	movs r0, #0x20
	orrs r0, r4
_0803B776:
	strh r0, [r5, #8]
_0803B778:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
