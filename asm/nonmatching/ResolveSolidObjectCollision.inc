	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov ip, r0
	adds r5, r1, #0
	ldr r0, [r0, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038042
	mov r1, sp
	mov r0, ip
	adds r0, #0x3c
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1, #2]
	mov r0, ip
	adds r0, #0x3e
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1]
	b _08038054
_08038042:
	mov r1, sp
	mov r0, ip
	adds r0, #0x3c
	ldrb r0, [r0]
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x3e
	ldrb r0, [r0]
	strb r0, [r1, #2]
_08038054:
	mov r1, sp
	mov r0, ip
	adds r0, #0x3d
	ldrb r0, [r0]
	strb r0, [r1, #1]
	mov r0, ip
	adds r0, #0x3f
	ldrb r0, [r0]
	strb r0, [r1, #3]
	ldr r1, [r5, #8]
	movs r0, #1
	ands r0, r1
	str r1, [sp, #0x1c]
	cmp r0, #0
	beq _0803808A
	add r1, sp, #4
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1, #2]
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strb r0, [r1]
	b _0803809C
_0803808A:
	add r1, sp, #4
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	strb r0, [r1, #2]
_0803809C:
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x3d
	ldrb r3, [r0]
	mov r0, sb
	strb r3, [r0, #1]
	adds r0, r5, #0
	adds r0, #0x3f
	ldrb r2, [r0]
	mov r1, sb
	strb r2, [r1, #3]
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0, #2]
	ldrb r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	mov r4, sb
	ldrb r0, [r4, #2]
	ldrb r1, [r4]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0, #3]
	ldrb r1, [r1, #1]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x14]
	subs r2, r2, r3
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x18]
	movs r4, #0
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r2, r1, r0
	mov r3, sb
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x48]
	adds r1, r1, r0
	cmp r2, r1
	bgt _08038118
	mov r3, r8
	lsls r0, r3, #8
	adds r0, r2, r0
	cmp r0, r1
	bge _08038122
	cmp r2, r1
	blt _08038124
_08038118:
	ldr r3, [sp, #0x10]
	lsls r0, r3, #8
	adds r0, r1, r0
	cmp r0, r2
	blt _08038124
_08038122:
	movs r4, #1
_08038124:
	str r4, [sp, #8]
	movs r4, #0
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r2, ip
	ldr r1, [r2, #0x4c]
	adds r2, r1, r0
	mov r3, sb
	movs r0, #1
	ldrsb r0, [r3, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x4c]
	adds r1, r1, r0
	cmp r2, r1
	bgt _08038156
	ldr r3, [sp, #0x14]
	lsls r0, r3, #8
	adds r0, r2, r0
	cmp r0, r1
	bge _08038160
	cmp r2, r1
	blt _08038162
_08038156:
	ldr r3, [sp, #0x18]
	lsls r0, r3, #8
	adds r0, r1, r0
	cmp r0, r2
	blt _08038162
_08038160:
	movs r4, #1
_08038162:
	str r4, [sp, #0xc]
	movs r7, #0
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r4, ip
	ldr r2, [r4, #0x40]
	adds r4, r2, r0
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x40]
	adds r3, r1, r0
	adds r6, r2, #0
	mov sl, r1
	cmp r4, r3
	bgt _08038198
	mov r2, r8
	lsls r0, r2, #8
	adds r0, r4, r0
	cmp r0, r3
	bge _080381A2
	cmp r4, r3
	blt _080381A4
_08038198:
	ldr r1, [sp, #0x10]
	lsls r0, r1, #8
	adds r0, r3, r0
	cmp r0, r4
	blt _080381A4
_080381A2:
	movs r7, #1
_080381A4:
	movs r2, #0
	mov r8, r2
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r3, ip
	ldr r2, [r3, #0x44]
	adds r4, r2, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r3, r1, r0
	str r1, [sp, #0x20]
	cmp r4, r3
	bgt _080381D8
	ldr r1, [sp, #0x14]
	lsls r0, r1, #8
	adds r0, r4, r0
	cmp r0, r3
	bge _080381E2
	cmp r4, r3
	blt _080381E6
_080381D8:
	ldr r1, [sp, #0x18]
	lsls r0, r1, #8
	adds r0, r3, r0
	cmp r0, r4
	blt _080381E6
_080381E2:
	movs r3, #1
	mov r8, r3
_080381E6:
	cmp r7, #0
	bne _080381EE
	bl _08038B20
_080381EE:
	mov r4, r8
	cmp r4, #0
	bne _080381F8
	bl _08038B20
_080381F8:
	movs r0, #0x80
	ldr r1, [sp, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08038216
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2]
	mov r2, ip
	str r5, [r2, #0x6c]
	bl _08038B20
_08038216:
	ldr r3, [sp, #8]
	cmp r3, #0
	bne _0803821E
	b _0803838C
_0803821E:
	ldr r4, [sp, #0xc]
	cmp r4, #0
	beq _08038226
	b _08038384
_08038226:
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	mov r1, sp
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	lsls r0, r0, #8
	add r0, sl
	cmp r6, r0
	bne _08038240
	b _08038384
_08038240:
	mov r3, sb
	movs r0, #0
	ldrsb r0, [r3, r0]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	lsls r0, r0, #8
	add r0, sl
	cmp r6, r0
	bne _0803825A
	b _08038384
_0803825A:
	mov r0, ip
	adds r0, #0x52
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r4, r0, #0
	cmp r1, #0
	ble _080382F6
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r6, r0, r3
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r1, r2, r0
	mov r2, sb
	movs r0, #3
	ldrsb r0, [r2, r0]
	lsls r0, r0, #8
	ldr r3, [sp, #0x20]
	adds r0, r3, r0
	subs r3, r1, r0
	cmp r3, #0
	blt _08038296
	cmp r3, r6
	blt _0803829C
	b _080382E2
_08038296:
	subs r0, r0, r1
	cmp r0, r6
	bge _080382E2
_0803829C:
	mov r3, ip
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #8
	movs r2, #0
	orrs r0, r1
	strb r0, [r3]
	adds r3, r5, #0
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #4
	orrs r0, r1
	strb r0, [r3]
	mov r0, sb
	movs r1, #3
	ldrsb r1, [r0, r1]
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x44]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x52
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x44]
	strh r2, [r4]
_080382E2:
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _080382F6
	adds r0, r5, #0
	adds r0, #0x52
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _08038384
_080382F6:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0xc0
	lsls r0, r0, #2
	subs r6, r0, r1
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r2, ip
	ldr r1, [r2, #0x44]
	adds r3, r1, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r0, r1, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _08038328
	cmp r2, r6
	blt _0803832E
	b _08038384
_08038328:
	subs r0, r0, r3
	cmp r0, r6
	bge _08038384
_0803832E:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	mov r2, sb
	movs r1, #1
	ldrsb r1, [r2, r1]
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	adds r1, #1
	lsls r1, r1, #8
	ldr r0, [r5, #0x44]
	adds r0, r0, r1
	mov r3, ip
	str r0, [r3, #0x44]
	ldr r0, [r3, #8]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803837C
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _0803837C
	movs r0, #0xff
	ands r0, r1
	b _0803837E
_0803837C:
	movs r0, #0
_0803837E:
	strh r0, [r4]
	mov r3, ip
	str r5, [r3, #0x74]
_08038384:
	ldr r4, [sp, #8]
	cmp r4, #0
	beq _0803838C
	b _08038824
_0803838C:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _08038394
	b _0803853C
_08038394:
	mov r2, ip
	adds r2, #0x52
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r0, #0x80
	lsls r0, r0, #2
	subs r7, r0, r1
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r4, ip
	ldr r1, [r4, #0x44]
	adds r6, r1, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r0, r1, r0
	subs r3, r6, r0
	adds r4, r2, #0
	cmp r3, #0
	blt _080383CC
	cmp r3, r7
	bgt _080383D4
	b _0803853C
_080383CC:
	subs r0, r0, r6
	cmp r0, r7
	bgt _080383D4
	b _0803853C
_080383D4:
	ldr r7, [r5, #0x40]
	mov r2, ip
	ldr r6, [r2, #0x40]
	cmp r6, r7
	ble _0803848A
	adds r0, r5, #0
	adds r0, #0x50
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x50
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r3, r0, r1
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r2, r6, r0
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	adds r0, r7, r0
	subs r1, r2, r0
	cmp r1, #0
	blt _08038418
	cmp r1, r3
	blt _0803841E
	b _08038476
_08038418:
	subs r0, r0, r2
	cmp r0, r3
	bge _08038476
_0803841E:
	mov r2, ip
	ldr r0, [r2, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038432
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	b _0803843A
_08038432:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
_0803843A:
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038452
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
	b _0803845A
_08038452:
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
_0803845A:
	orrs r0, r1
	strb r0, [r2]
	mov r3, sb
	movs r1, #2
	ldrsb r1, [r3, r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x40]
	adds r0, r0, r1
	b _08038538
_08038476:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0803853C
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, ip
	str r0, [r3, #0x40]
	b _0803853C
_0803848A:
	mov r0, ip
	adds r0, #0x50
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x50
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r2, _080384C4 @ =0xFFFFFC00
	adds r0, r0, r2
	subs r1, r1, r0
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r3, r6, r0
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #8
	adds r0, r7, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _080384C8
	cmp r2, r1
	blt _080384CE
	b _0803852C
	.align 2, 0
_080384C4: .4byte 0xFFFFFC00
_080384C8:
	subs r0, r0, r3
	cmp r0, r1
	bge _0803852C
_080384CE:
	mov r3, ip
	ldr r0, [r3, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080384E4
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
	b _080384EC
_080384E4:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
_080384EC:
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038504
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	b _0803850C
_08038504:
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
_0803850C:
	orrs r0, r1
	strb r0, [r2]
	mov r4, sb
	movs r1, #0
	ldrsb r1, [r4, r1]
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x40]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x40]
	b _0803853C
_0803852C:
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0803853C
	ldr r3, _08038594 @ =0xFFFFFF00
	adds r0, r6, r3
_08038538:
	mov r4, ip
	str r0, [r4, #0x40]
_0803853C:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _08038544
	b _08038824
_08038544:
	ldr r1, [sp, #0xc]
	cmp r1, #0
	beq _0803854C
	b _0803881C
_0803854C:
	mov r3, ip
	ldr r2, [r3, #0x44]
	ldr r3, [r5, #0x44]
	cmp r2, r3
	ble _080385E6
	mov r0, ip
	adds r0, #0x52
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r4, r0, #0
	cmp r1, #0
	bgt _08038566
	b _0803867C
_08038566:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r6, r0, r1
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r2, r2, r0
	mov r1, sb
	movs r0, #3
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	adds r0, r3, r0
	subs r1, r2, r0
	cmp r1, #0
	blt _08038598
	cmp r1, r6
	blt _0803859E
	b _0803867C
	.align 2, 0
_08038594: .4byte 0xFFFFFF00
_08038598:
	subs r0, r0, r2
	cmp r0, r6
	bge _0803867C
_0803859E:
	mov r3, ip
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #8
	movs r2, #0
	orrs r0, r1
	strb r0, [r3]
	adds r3, r5, #0
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #4
	orrs r0, r1
	strb r0, [r3]
	mov r3, sb
	movs r1, #3
	ldrsb r1, [r3, r1]
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x44]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x52
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x44]
	strh r2, [r4]
	b _0803867C
_080385E6:
	mov r0, ip
	adds r0, #0x52
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r4, r0, #0
	cmp r1, #0
	bgt _0803867C
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0xc0
	lsls r0, r0, #2
	subs r6, r0, r1
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r2, r2, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	adds r0, r3, r0
	subs r1, r2, r0
	cmp r1, #0
	blt _08038620
	cmp r1, r6
	blt _08038626
	b _0803867C
_08038620:
	subs r0, r0, r2
	cmp r0, r6
	bge _0803867C
_08038626:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	mov r2, sb
	movs r1, #1
	ldrsb r1, [r2, r1]
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	adds r1, #1
	lsls r1, r1, #8
	ldr r0, [r5, #0x44]
	adds r0, r0, r1
	mov r3, ip
	str r0, [r3, #0x44]
	ldr r0, [r3, #8]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08038674
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _08038674
	movs r0, #0xff
	ands r0, r1
	b _08038676
_08038674:
	movs r0, #0
_08038676:
	strh r0, [r4]
	mov r3, ip
	str r5, [r3, #0x74]
_0803867C:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0x80
	lsls r0, r0, #2
	subs r6, r0, r1
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r2, ip
	ldr r1, [r2, #0x44]
	adds r3, r1, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r0, r1, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _080386AE
	cmp r2, r6
	bgt _080386B6
	b _0803881C
_080386AE:
	subs r0, r0, r3
	cmp r0, r6
	bgt _080386B6
	b _0803881C
_080386B6:
	ldr r7, [r5, #0x40]
	mov r2, ip
	ldr r6, [r2, #0x40]
	cmp r6, r7
	ble _0803876C
	adds r0, r5, #0
	adds r0, #0x50
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x50
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r3, r0, r1
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r2, r6, r0
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	adds r0, r7, r0
	subs r1, r2, r0
	cmp r1, #0
	blt _080386FA
	cmp r1, r3
	blt _08038700
	b _08038758
_080386FA:
	subs r0, r0, r2
	cmp r0, r3
	bge _08038758
_08038700:
	mov r2, ip
	ldr r0, [r2, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038714
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	b _0803871C
_08038714:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
_0803871C:
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038734
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
	b _0803873C
_08038734:
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
_0803873C:
	orrs r0, r1
	strb r0, [r2]
	mov r3, sb
	movs r1, #2
	ldrsb r1, [r3, r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x40]
	adds r0, r0, r1
	b _08038818
_08038758:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0803881C
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, ip
	str r0, [r3, #0x40]
	b _0803881C
_0803876C:
	mov r0, ip
	adds r0, #0x50
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x50
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r2, _080387A4 @ =0xFFFFFC00
	adds r0, r0, r2
	subs r1, r1, r0
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r3, r6, r0
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #8
	adds r0, r7, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _080387A8
	cmp r2, r1
	blt _080387AE
	b _0803880C
	.align 2, 0
_080387A4: .4byte 0xFFFFFC00
_080387A8:
	subs r0, r0, r3
	cmp r0, r1
	bge _0803880C
_080387AE:
	mov r3, ip
	ldr r0, [r3, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080387C4
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
	b _080387CC
_080387C4:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
_080387CC:
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080387E4
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	b _080387EC
_080387E4:
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
_080387EC:
	orrs r0, r1
	strb r0, [r2]
	mov r4, sb
	movs r1, #0
	ldrsb r1, [r4, r1]
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x40]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x40]
	b _0803881C
_0803880C:
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0803881C
	ldr r3, _0803889C @ =0xFFFFFF00
	adds r0, r6, r3
_08038818:
	mov r4, ip
	str r0, [r4, #0x40]
_0803881C:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _08038824
	b _08038B20
_08038824:
	ldr r1, [sp, #0xc]
	cmp r1, #0
	bne _0803882C
	b _08038B20
_0803882C:
	mov r2, sb
	movs r0, #2
	ldrsb r0, [r2, r0]
	mov r1, sp
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	lsls r0, r0, #8
	ldr r3, [r5, #0x40]
	adds r0, r3, r0
	mov r4, ip
	ldr r2, [r4, #0x40]
	adds r4, #0x52
	cmp r2, r0
	bne _0803884E
	b _08038980
_0803884E:
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	lsls r0, r0, #8
	adds r0, r3, r0
	cmp r2, r0
	bne _08038868
	b _08038980
_08038868:
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r0, #0xc0
	lsls r0, r0, #2
	subs r6, r0, r1
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r3, ip
	ldr r1, [r3, #0x44]
	adds r3, r1, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r0, r1, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _080388A0
	cmp r2, r6
	blt _080388A6
	b _080388FE
	.align 2, 0
_0803889C: .4byte 0xFFFFFF00
_080388A0:
	subs r0, r0, r3
	cmp r0, r6
	bge _080388FE
_080388A6:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	mov r2, sb
	movs r1, #1
	ldrsb r1, [r2, r1]
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	adds r1, #1
	lsls r1, r1, #8
	ldr r0, [r5, #0x44]
	adds r0, r0, r1
	mov r3, ip
	str r0, [r3, #0x44]
	ldr r0, [r3, #8]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080388F4
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _080388F4
	movs r0, #0xff
	ands r0, r1
	b _080388F6
_080388F4:
	movs r0, #0
_080388F6:
	strh r0, [r4]
	mov r3, ip
	str r5, [r3, #0x74]
	b _08038980
_080388FE:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _08038980
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r6, r0, r3
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r2, ip
	ldr r1, [r2, #0x44]
	adds r3, r1, r0
	mov r1, sb
	movs r0, #3
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r0, r1, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _08038934
	cmp r2, r6
	blt _0803893A
	b _08038980
_08038934:
	subs r0, r0, r3
	cmp r0, r6
	bge _08038980
_0803893A:
	mov r3, ip
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #8
	movs r2, #0
	orrs r0, r1
	strb r0, [r3]
	adds r3, r5, #0
	adds r3, #0x62
	ldrb r1, [r3]
	movs r0, #4
	orrs r0, r1
	strb r0, [r3]
	mov r3, sb
	movs r1, #3
	ldrsb r1, [r3, r1]
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x44]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x52
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x44]
	strh r2, [r4]
_08038980:
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	subs r6, r0, r1
	mov r0, sp
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r3, ip
	ldr r1, [r3, #0x44]
	adds r3, r1, r0
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	ldr r1, [r5, #0x44]
	adds r0, r1, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _080389B2
	cmp r2, r6
	bgt _080389BA
	b _08038B20
_080389B2:
	subs r0, r0, r3
	cmp r0, r6
	bgt _080389BA
	b _08038B20
_080389BA:
	ldr r7, [r5, #0x40]
	mov r2, ip
	ldr r6, [r2, #0x40]
	cmp r6, r7
	ble _08038A70
	adds r0, r5, #0
	adds r0, #0x50
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x50
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r3, r0, r1
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r2, r6, r0
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #8
	adds r0, r7, r0
	subs r1, r2, r0
	cmp r1, #0
	blt _080389FE
	cmp r1, r3
	blt _08038A04
	b _08038A5C
_080389FE:
	subs r0, r0, r2
	cmp r0, r3
	bge _08038A5C
_08038A04:
	mov r2, ip
	ldr r0, [r2, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038A18
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	b _08038A20
_08038A18:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
_08038A20:
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038A38
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
	b _08038A40
_08038A38:
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
_08038A40:
	orrs r0, r1
	strb r0, [r2]
	mov r3, sb
	movs r1, #2
	ldrsb r1, [r3, r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x40]
	adds r0, r0, r1
	b _08038B1C
_08038A5C:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08038B20
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, ip
	str r0, [r3, #0x40]
	b _08038B20
_08038A70:
	mov r0, ip
	adds r0, #0x50
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x50
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r2, _08038AA8 @ =0xFFFFFC00
	adds r0, r0, r2
	subs r1, r1, r0
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r3, r6, r0
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #8
	adds r0, r7, r0
	subs r2, r3, r0
	cmp r2, #0
	blt _08038AAC
	cmp r2, r1
	blt _08038AB2
	b _08038B10
	.align 2, 0
_08038AA8: .4byte 0xFFFFFC00
_08038AAC:
	subs r0, r0, r3
	cmp r0, r1
	bge _08038B10
_08038AB2:
	mov r3, ip
	ldr r0, [r3, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038AC8
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
	b _08038AD0
_08038AC8:
	mov r2, ip
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
_08038AD0:
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08038AE8
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	b _08038AF0
_08038AE8:
	adds r2, r5, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #2
_08038AF0:
	orrs r0, r1
	strb r0, [r2]
	mov r4, sb
	movs r1, #0
	ldrsb r1, [r4, r1]
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r5, #0x40]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x40]
	b _08038B20
_08038B10:
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _08038B20
	ldr r3, _08038B30 @ =0xFFFFFF00
	adds r0, r6, r3
_08038B1C:
	mov r4, ip
	str r0, [r4, #0x40]
_08038B20:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038B30: .4byte 0xFFFFFF00

	.syntax divided
