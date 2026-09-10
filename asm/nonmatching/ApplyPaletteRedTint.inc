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
	bne _0803BF80
	b _0803C6B4
_0803BF80:
	ldr r4, _0803C310 @ =gBgPalette
	movs r0, #0
	mov sl, r0
	ldr r1, _0803C314 @ =gBrightenRedTable
	mov r8, r1
	movs r6, #0x1f
	movs r2, #0x1f
	mov sb, r2
	ldr r0, _0803C318 @ =gDarkenGreenTable
	mov ip, r0
	ldr r7, _0803C31C @ =gDarkenBlueTable
_0803BF96:
	ldrh r0, [r5, #6]
	mov r1, sl
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803BFA6
	b _0803C320
_0803BFA6:
	mov r2, sl
	cmp r2, #0
	bne _0803BFE0
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
_0803BFE0:
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	b _0803C322
	.align 2, 0
_0803C310: .4byte gBgPalette
_0803C314: .4byte gBrightenRedTable
_0803C318: .4byte gDarkenGreenTable
_0803C31C: .4byte gDarkenBlueTable
_0803C320:
	adds r4, #0x20
_0803C322:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	cmp r0, #0xf
	bhi _0803C332
	b _0803BF96
_0803C332:
	ldr r4, _0803C688 @ =gObjPalette
	movs r0, #0
	mov sl, r0
	ldr r1, _0803C68C @ =gBrightenRedTable
	mov sb, r1
	movs r6, #0x1f
	movs r2, #0x1f
	mov ip, r2
	ldr r0, _0803C690 @ =gDarkenGreenTable
	mov r8, r0
	ldr r7, _0803C694 @ =gDarkenBlueTable
_0803C348:
	ldrh r0, [r5, #4]
	mov r1, sl
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803C358
	b _0803C698
_0803C358:
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
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
	subs r2, #0x1f
	subs r0, r0, r2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	orrs r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	orrs r3, r0
	strh r3, [r4]
	adds r4, #2
	b _0803C69A
	.align 2, 0
_0803C688: .4byte gObjPalette
_0803C68C: .4byte gBrightenRedTable
_0803C690: .4byte gDarkenGreenTable
_0803C694: .4byte gDarkenBlueTable
_0803C698:
	adds r4, #0x20
_0803C69A:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	cmp r0, #0xf
	bhi _0803C6AA
	b _0803C348
_0803C6AA:
	ldr r2, _0803C71C @ =gMainFlags
	ldr r0, [r2]
	movs r1, #3
	orrs r0, r1
	str r0, [r2]
_0803C6B4:
	ldrh r1, [r5, #8]
	movs r0, #1
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	bne _0803C738
	ldr r0, _0803C71C @ =gMainFlags
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803C6D6
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _0803C738
_0803C6D6:
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
	bgt _0803C6FA
	lsls r0, r1, #0x10
	cmp r0, #0
	blt _0803C700
	cmp r3, r2
	blt _0803C738
_0803C6FA:
	lsls r0, r1, #0x10
	cmp r0, #0
	ble _0803C738
_0803C700:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0
	beq _0803C730
	movs r0, #0x40
	ands r0, r4
	cmp r0, #0
	beq _0803C720
	movs r0, #2
	ldrsb r0, [r5, r0]
	lsls r0, r0, #8
	strh r0, [r5, #0xc]
	strb r6, [r5, #1]
	b _0803C738
	.align 2, 0
_0803C71C: .4byte gMainFlags
_0803C720:
	movs r0, #1
	orrs r0, r4
	ldr r1, _0803C72C @ =0x0000FF59
	ands r0, r1
	b _0803C736
	.align 2, 0
_0803C72C: .4byte 0x0000FF59
_0803C730:
	strb r6, [r5, #1]
	movs r0, #0x20
	orrs r0, r4
_0803C736:
	strh r0, [r5, #8]
_0803C738:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
