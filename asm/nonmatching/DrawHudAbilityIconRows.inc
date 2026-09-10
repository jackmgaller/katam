	.syntax unified
	.text

	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _08034CC8 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r4, #0x10
	ands r0, r4
	cmp r0, #0
	bne _08034D58
	ldr r0, _08034CCC @ =gGameplayHudTask
	ldr r2, [r0]
	ldrh r1, [r2, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08034CD0
	ldrh r0, [r2, #6]
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #0x12
	adds r0, r0, r1
	b _08034CD8
	.align 2, 0
_08034CC8: .4byte gUnk_0203AD10
_08034CCC: .4byte gGameplayHudTask
_08034CD0:
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r1, r0
_08034CD8:
	strb r3, [r0, #0x14]
	ldr r1, _08034D60 @ =0x0600E380
	movs r4, #0
	movs r0, #6
	subs r0, r0, r3
	lsls r5, r3, #0x10
	cmp r4, r0
	bge _08034D0E
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r3, #0
	adds r3, r0, #0
_08034CF0:
	strh r2, [r1]
	adds r1, #2
	strh r2, [r1]
	adds r1, #2
	strh r2, [r1]
	adds r1, #2
	strh r2, [r1]
	adds r1, #2
	strh r2, [r1]
	adds r1, #0x38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r3
	blt _08034CF0
_08034D0E:
	movs r4, #0
	cmp r5, #0
	beq _08034D58
	movs r0, #0xe
	lsls r3, r0, #0xc
_08034D18:
	lsls r0, r4, #2
	adds r2, r0, r4
	ldr r6, _08034D64 @ =0x000001C5
	adds r0, r2, r6
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r6, #1
	adds r0, r2, r6
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r6, #1
	adds r0, r2, r6
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r6, #1
	adds r0, r2, r6
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r6, #1
	adds r0, r2, r6
	orrs r0, r3
	strh r0, [r1]
	adds r1, #0x38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, r5
	blo _08034D18
_08034D58:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034D60: .4byte 0x0600E380
_08034D64: .4byte 0x000001C5

	.syntax divided
