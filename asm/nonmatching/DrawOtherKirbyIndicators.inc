	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	movs r0, #0
	mov sb, r0
	mov r8, r0
	b _08034804
_0803431A:
	ldr r1, _080343AC @ =gLocalPlayerId
	ldrb r1, [r1]
	cmp sb, r1
	bne _08034324
	b _080347FA
_08034324:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r2, #0xd4
	lsls r2, r2, #1
	mov r0, sb
	muls r0, r2, r0
	ldr r1, _080343B0 @ =gKirbys
	adds r6, r0, r1
	mov r3, sb
	lsls r0, r3, #2
	add r0, sb
	lsls r3, r0, #3
	adds r0, r3, #0
	adds r0, #0x20
	mov r5, sl
	adds r4, r5, r0
	adds r0, #0xa0
	adds r7, r5, r0
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r0, r3, r5
	mov r3, sl
	adds r5, r3, r0
	ldr r3, _080343AC @ =gLocalPlayerId
	ldrb r0, [r3]
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08034370
	b _08034620
_08034370:
	adds r0, r6, #0
	bl sub_0803D938
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08034380
	b _080345B8
_08034380:
	ldr r0, _080343AC @ =gLocalPlayerId
	ldrb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r1, r0, r1
	ldr r0, _080343B4 @ =gCurLevelInfo
	adds r1, r1, r0
	movs r0, #0xb7
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	movs r2, #0
	strb r2, [r4, #0x1a]
	ldr r3, [r1, #0xc]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r0, r3, r2
	ldr r2, [r6, #0x40]
	cmp r0, r2
	ble _080343B8
	movs r0, #6
	b _080343CC
	.align 2, 0
_080343AC: .4byte gLocalPlayerId
_080343B0: .4byte gKirbys
_080343B4: .4byte gCurLevelInfo
_080343B8:
	movs r0, #0xe8
	lsls r0, r0, #8
	adds r0, r0, r3
	mov ip, r0
	cmp ip, r2
	bge _080343C8
	movs r0, #0xe8
	b _080343CC
_080343C8:
	subs r0, r2, r3
	asrs r0, r0, #8
_080343CC:
	strh r0, [r4, #0x10]
	ldr r1, [r1, #0x10]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r2, [r6, #0x44]
	cmp r0, r2
	ble _080343E0
	movs r0, #0xa
	b _080343F2
_080343E0:
	movs r3, #0x8c
	lsls r3, r3, #8
	adds r0, r1, r3
	cmp r0, r2
	bge _080343EE
	movs r0, #0x8c
	b _080343F2
_080343EE:
	subs r0, r2, r1
	asrs r0, r0, #8
_080343F2:
	strh r0, [r4, #0x12]
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #0x10]
	mov ip, r2
	cmp r0, #0x15
	bgt _08034468
	movs r3, #0x12
	ldrsh r0, [r4, r3]
	cmp r0, #0x19
	bgt _08034428
	movs r0, #3
	strb r0, [r4, #0x1a]
	movs r0, #0x12
	ldrsh r2, [r4, r0]
	ldr r1, _08034424 @ =gOffscreenKirbyDirectionVariants
	mov r3, r8
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #0xa
	cmp r2, r0
	bge _08034456
	strh r0, [r4, #0x12]
	b _08034456
	.align 2, 0
_08034424: .4byte gOffscreenKirbyDirectionVariants
_08034428:
	cmp r0, #0x7c
	ble _08034450
	movs r0, #7
	strb r0, [r4, #0x1a]
	movs r0, #0x12
	ldrsh r2, [r4, r0]
	ldr r1, _0803444C @ =gOffscreenKirbyDirectionVariants
	mov r3, r8
	adds r0, r3, r1
	ldrb r3, [r0]
	movs r0, #0x8c
	subs r0, r0, r3
	cmp r2, r0
	ble _08034456
	movs r0, #0x8c
	subs r0, r0, r3
	strh r0, [r4, #0x12]
	b _08034456
	.align 2, 0
_0803444C: .4byte gOffscreenKirbyDirectionVariants
_08034450:
	movs r0, #1
	strb r0, [r4, #0x1a]
	ldr r1, _08034464 @ =gOffscreenKirbyDirectionVariants
_08034456:
	mov r2, r8
	adds r0, r2, r1
	ldrb r0, [r0]
	add r0, ip
	strh r0, [r4, #0x10]
	b _080344FE
	.align 2, 0
_08034464: .4byte gOffscreenKirbyDirectionVariants
_08034468:
	cmp r0, #0xd8
	ble _080344D4
	movs r3, #0x12
	ldrsh r0, [r4, r3]
	cmp r0, #0x19
	bgt _08034494
	movs r0, #2
	strb r0, [r4, #0x1a]
	movs r0, #0x12
	ldrsh r2, [r4, r0]
	ldr r1, _08034490 @ =gOffscreenKirbyDirectionVariants
	mov r3, r8
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #0xa
	cmp r2, r0
	bge _080344C2
	strh r0, [r4, #0x12]
	b _080344C2
	.align 2, 0
_08034490: .4byte gOffscreenKirbyDirectionVariants
_08034494:
	cmp r0, #0x7c
	ble _080344BC
	movs r0, #6
	strb r0, [r4, #0x1a]
	movs r0, #0x12
	ldrsh r2, [r4, r0]
	ldr r1, _080344B8 @ =gOffscreenKirbyDirectionVariants
	mov r3, r8
	adds r0, r3, r1
	ldrb r3, [r0]
	movs r0, #0x8c
	subs r0, r0, r3
	cmp r2, r0
	ble _080344C2
	movs r0, #0x8c
	subs r0, r0, r3
	strh r0, [r4, #0x12]
	b _080344C2
	.align 2, 0
_080344B8: .4byte gOffscreenKirbyDirectionVariants
_080344BC:
	movs r0, #0
	strb r0, [r4, #0x1a]
	ldr r1, _080344D0 @ =gOffscreenKirbyDirectionVariants
_080344C2:
	mov r2, r8
	adds r0, r2, r1
	ldrb r0, [r0]
	mov r3, ip
	subs r0, r3, r0
	strh r0, [r4, #0x10]
	b _080344FE
	.align 2, 0
_080344D0: .4byte gOffscreenKirbyDirectionVariants
_080344D4:
	ldrh r1, [r4, #0x12]
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	cmp r0, #0x19
	bgt _080344F0
	movs r0, #4
	strb r0, [r4, #0x1a]
	ldr r0, _080344EC @ =gOffscreenKirbyDirectionVariants
	add r0, r8
	ldrb r0, [r0]
	adds r0, r1, r0
	b _080344FC
	.align 2, 0
_080344EC: .4byte gOffscreenKirbyDirectionVariants
_080344F0:
	movs r0, #5
	strb r0, [r4, #0x1a]
	ldr r0, _080345A0 @ =gOffscreenKirbyDirectionVariants
	add r0, r8
	ldrb r0, [r0]
	subs r0, r1, r0
_080344FC:
	strh r0, [r4, #0x12]
_080344FE:
	mov r0, sl
	adds r0, #0x15
	mov r3, sb
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #1
	beq _08034520
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x1b]
	movs r0, #0
	strh r0, [r5, #0xc]
	strb r0, [r5, #0x1a]
	movs r0, #1
	strb r0, [r1]
_08034520:
	ldr r0, _080345A4 @ =gUnk_0203AD20
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _08034534
	ldr r0, [r4, #8]
	ldr r1, _080345A8 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r4, #8]
_08034534:
	ldr r0, [r6, #0x18]
	movs r2, #0x80
	lsls r2, r2, #0xc
	orrs r0, r2
	str r0, [r6, #0x18]
	adds r1, r6, #0
	adds r1, #0xac
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r1, #0x28
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl sub_08155128
	ldr r0, _080345AC @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08034564
	b _080347FA
_08034564:
	adds r1, #0xe0
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _08034574
	b _080347FA
_08034574:
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldr r2, _080345B0 @ =0xFFFFFC6C
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _08034588
	b _080347FA
_08034588:
	ldr r0, _080345B4 @ =0x0000038D
	cmp r1, r0
	bne _08034590
	b _080347FA
_08034590:
	adds r0, #0x46
	cmp r1, r0
	bls _08034598
	b _080347FA
_08034598:
	adds r0, r4, #0
	bl DisplaySprite
	b _080347FA
	.align 2, 0
_080345A0: .4byte gOffscreenKirbyDirectionVariants
_080345A4: .4byte gUnk_0203AD20
_080345A8: .4byte 0xFFFFF7FF
_080345AC: .4byte gUnk_0203AD10
_080345B0: .4byte 0xFFFFFC6C
_080345B4: .4byte 0x0000038D
_080345B8:
	mov r0, sl
	adds r0, #0x15
	mov r1, sb
	adds r7, r0, r1
	ldrb r0, [r7]
	cmp r0, #0
	bne _080345C8
	b _080347FA
_080345C8:
	ldr r0, [r6, #0x18]
	ldr r2, _08034618 @ =0xFFF7FFFF
	ands r0, r2
	str r0, [r6, #0x18]
	adds r1, r6, #0
	adds r1, #0xac
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	subs r1, #0x28
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	strh r3, [r5, #0xc]
	movs r2, #0
	strb r2, [r5, #0x1a]
	adds r0, r6, #0
	adds r0, #0x10
	ldr r4, _0803461C @ =0x0400000A
	mov r1, sp
	adds r2, r4, #0
	bl CpuSet
	ldrb r1, [r6, #1]
	mov r0, sp
	bl sub_0815521C
	adds r0, r6, #0
	adds r0, #0xa4
	mov r1, sp
	adds r2, r4, #0
	bl CpuSet
	ldrb r1, [r6, #1]
	mov r0, sp
	bl sub_0815521C
	movs r3, #0
	strb r3, [r7]
	b _080347FA
	.align 2, 0
_08034618: .4byte 0xFFF7FFFF
_0803461C: .4byte 0x0400000A
_08034620:
	ldr r0, [r6, #0x18]
	ldr r1, _08034680 @ =0xFFF7FFFF
	ands r0, r1
	str r0, [r6, #0x18]
	adds r3, r6, #0
	adds r3, #0xac
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	adds r2, r6, #0
	adds r2, #0x84
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08034684 @ =gUnk_0203AD20
	ldr r1, [r0]
	movs r0, #8
	ands r1, r0
	str r3, [sp, #0x28]
	str r2, [sp, #0x2c]
	cmp r1, #0
	beq _0803468C
	ldr r0, _08034688 @ =gOtherRoomKirbyIconX
	add r0, r8
	ldrb r1, [r0]
	strh r1, [r4, #0x10]
	movs r0, #0x91
	strh r0, [r4, #0x12]
	strh r1, [r7, #0x10]
	ldrh r0, [r4, #0x12]
	strh r0, [r7, #0x12]
	ldrh r0, [r4, #0x10]
	strh r0, [r5, #0x10]
	ldrh r0, [r4, #0x12]
	subs r0, #6
	strh r0, [r5, #0x12]
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r4, #8]
	ldr r0, [r7, #8]
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r5, #8]
	orrs r0, r1
	b _080346BA
	.align 2, 0
_08034680: .4byte 0xFFF7FFFF
_08034684: .4byte gUnk_0203AD20
_08034688: .4byte gOtherRoomKirbyIconX
_0803468C:
	ldr r0, _0803470C @ =gOtherRoomKirbyIconX
	add r0, r8
	ldrb r1, [r0]
	strh r1, [r4, #0x10]
	movs r0, #0xf
	strh r0, [r4, #0x12]
	strh r1, [r7, #0x10]
	ldrh r0, [r4, #0x12]
	strh r0, [r7, #0x12]
	ldrh r0, [r4, #0x10]
	strh r0, [r5, #0x10]
	ldrh r0, [r4, #0x12]
	subs r0, #6
	strh r0, [r5, #0x12]
	ldr r0, [r4, #8]
	ldr r1, _08034710 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r4, #8]
	ldr r0, [r7, #8]
	ands r0, r1
	str r0, [r7, #8]
	ldr r0, [r5, #8]
	ands r0, r1
_080346BA:
	str r0, [r5, #8]
	mov r0, sl
	adds r0, #0x15
	mov r2, sb
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #2
	beq _080346E0
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x1b]
	movs r0, #0
	strh r0, [r5, #0xc]
	movs r3, #0
	strb r3, [r5, #0x1a]
	movs r0, #2
	strb r0, [r1]
_080346E0:
	ldr r2, _08034714 @ =gRoomProps
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #0x12]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0803471C
	ldr r0, _08034718 @ =0x000002DB
	strh r0, [r4, #0xc]
	movs r0, #0
	strb r0, [r4, #0x1a]
	strh r1, [r7, #0xc]
	b _0803474A
	.align 2, 0
_0803470C: .4byte gOtherRoomKirbyIconX
_08034710: .4byte 0xFFFFF7FF
_08034714: .4byte gRoomProps
_08034718: .4byte 0x000002DB
_0803471C:
	ldr r1, _08034780 @ =gUnk_08350AAC
	ldr r3, _08034784 @ =0x00000103
	adds r2, r6, r3
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xc]
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	strb r0, [r4, #0x1a]
	ldr r1, _08034788 @ =gUnk_08350B30
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
_0803474A:
	strb r0, [r7, #0x1a]
	ldr r0, [r6, #0xc]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08034762
	movs r0, #0xae
	lsls r0, r0, #2
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r5, #0x1a]
_08034762:
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq _080347AA
	adds r0, r5, #0
	bl sub_08155128
	adds r1, r0, #0
	cmp r1, #0
	bne _08034792
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	bne _0803478C
	movs r0, #1
	strb r0, [r5, #0x1a]
	b _08034792
	.align 2, 0
_08034780: .4byte gUnk_08350AAC
_08034784: .4byte 0x00000103
_08034788: .4byte gUnk_08350B30
_0803478C:
	strh r1, [r5, #0xc]
	movs r1, #0
	strb r1, [r5, #0x1a]
_08034792:
	ldr r0, _08034820 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080347AA
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq _080347AA
	adds r0, r5, #0
	bl DisplaySprite
_080347AA:
	ldrh r0, [r7, #0xc]
	cmp r0, #0
	beq _080347C8
	adds r0, r7, #0
	bl sub_08155128
	ldr r0, _08034820 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080347C8
	adds r0, r7, #0
	bl DisplaySprite
_080347C8:
	adds r0, r4, #0
	bl sub_08155128
	ldr r0, _08034820 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080347E0
	adds r0, r4, #0
	bl DisplaySprite
_080347E0:
	ldr r0, [r6, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [r6, #0x18]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r3, [sp, #0x2c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_080347FA:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08034804:
	ldr r0, _08034824 @ =gNumKirbys
	ldrb r0, [r0]
	cmp sb, r0
	bhs _0803480E
	b _0803431A
_0803480E:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034820: .4byte gUnk_0203AD10
_08034824: .4byte gNumKirbys

	.syntax divided
