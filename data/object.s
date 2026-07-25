    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

gUnk_0835105C:: @ 0835105C
	.incbin "baserom.gba", 0x35105C, 0x0000020

gSpawnFuncTable1:: @ 0835107C
    .4byte CreateWaddleDee
    .4byte CreateBrontoBurt
    .4byte CreateBlipper
    .4byte CreateGlunk
    .4byte CreateSquishy
    .4byte CreateScarfy
    .4byte CreateGordo
    .4byte CreateSnooter
    .4byte CreateChip
    .4byte CreateSoarar
    .4byte CreateHaley
    .4byte CreateRolyPoly
    .4byte CreateCupie
    .4byte CreateBlockin
    .4byte CreateSnooter
    .4byte CreateLeap
    .4byte CreateJack
    .4byte CreateBigWaddleDee
    .4byte CreateWaddleDoo
    .4byte CreateFlamer
    .4byte CreateHotHead
    .4byte CreateLaserBall
    .4byte CreatePengy
    .4byte CreateRocky
    .4byte CreateSirKibble
    .4byte CreateSparky
    .4byte CreateSwordKnight
    .4byte CreateUFO
    .4byte CreateTwister
    .4byte CreateWheelie
    .4byte CreateNoddy
    .4byte CreateGolem
    .4byte CreateGolem
    .4byte CreateGolem
    .4byte CreateFoley
    .4byte CreateShooty
    .4byte CreateScarfy
    .4byte CreateBoxin
    .4byte CreateCookin
    .4byte CreateMinny
    .4byte CreateBomber
    .4byte CreateHeavyKnight
    .4byte CreateGiantRocky
    .4byte CreateMetalGuardian
    .4byte CreateEmpty
    .4byte CreateBatty
    .4byte CreateFoley
    .4byte CreateBangBang
    .4byte CreateDarkMindBomb
    .4byte CreateEmpty
    .4byte CreateDroppy
    .4byte CreatePrank
    .4byte CreateMirra
    .4byte CreateShotzo
    .4byte CreateShadowKirby
    .4byte CreateWaddleDee
    .4byte CreateMrFrosty
    .4byte CreateBonkers
    .4byte CreatePhanPhan
    .4byte CreateBatafire
    .4byte CreateBoxBoxer
    .4byte CreateBoxy
    .4byte CreateMasterHand
    .4byte CreateBombar
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateKracko
    .4byte CreateKingGolem
    .4byte CreateCrazyHand
    .4byte CreateGobbler
    .4byte CreateWiz
    .4byte CreateMoley
    .4byte CreateMegaTitan
    .4byte CreateTitanHead
    .4byte CreateCrazyHand
    .4byte CreateDarkMetaKnight
    .4byte CreateDarkMindForm1
    .4byte CreateDarkMindForm2
    .4byte CreateDarkMindTrigger
    .4byte CreateDarkMetaKnight
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateBonus
    .4byte CreateBonus
    .4byte CreateBonus
    .4byte CreateBonus
    .4byte CreateBonus
    .4byte CreateBonus
    .4byte CreateBonus
    .4byte CreateShard
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateGoalGameBonus
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateEmpty
    .4byte CreateSmallSwitch
    .4byte CreateFire
    .4byte CreateMirrorDoor
    .4byte CreateShotzo
    .4byte CreateVertSlidingDoor
    .4byte CreateBossChallengeDoor
    .4byte CreateObjectSpawner
    .4byte CreateDestroyableRockBlock
    .4byte CreateUnknown75
    .4byte CreateLavaWall
    .4byte CreateScrollLock
    .4byte CreateCannonFuse
    .4byte CreateStarStoneBlock
    .4byte CreateUnknown7A
    .4byte CreateStarPlatform
    .4byte CreateFlameColumn
    .4byte CreateLargeStarStoneBlock7D
    .4byte CreateLargeStarStoneBlock7E
    .4byte CreateCPUKirbyTrigger
    .4byte CreateChest
    .4byte CreateChest
    .4byte CreateUnknown82
    .4byte CreateUnknown83
    .4byte CreateWarpStar
    .4byte CreateGoalStar
    .4byte CreateBigSwitch
    .4byte CreateUnknown87
    .4byte CreateLargeStarStoneBlock88
    .4byte CreateLargeStarStoneBlock89
    .4byte CreateKirbyCannon
    .4byte Create8DirCannon
    .4byte CreateSpecialHubMirror
    .4byte CreateHammerPeg
    .4byte CreateCutsceneTrigger
    .4byte CreateMasterSwordNonCollectible
    .4byte CreateDustCloud
    .4byte CreateLeverWall
    .4byte CreateAbilityStatue
    .4byte CreateAbilityStatue
    .4byte CreateAbilityStatue
    .4byte CreateAbilityStatue
    .4byte CreateAbilityStatueRandom
    .4byte CreateDoorToHub
    .4byte CreateAbilityStatue
    .4byte CreateAreaDoor
    .4byte CreateEmpty
    .4byte CreateKingGolemRockOrGordo
    .4byte CreateKingGolemRockOrGordo
    .4byte CreateFoleyLeaves
    .4byte CreateCookinPan
    .4byte CreateGobblerBaby
    .4byte CreateUnknownA0
    .4byte CreateBatafireFireball
    .4byte CreateParasol
    .4byte CreateAbilityStar
    .4byte CreateAbilityStar
    .4byte CreateInhalableStar
    .4byte CreateMrFrostyIceCube
    .4byte CreateMrFrostyIceCube
    .4byte CreateBonkersNut
    .4byte CreateBonkersNut
    .4byte CreatePhanPhanApple
    .4byte CreatePrankItem
    .4byte CreatePrankItem
    .4byte CreatePrankItem
    .4byte CreateCookinPan
    .4byte CreateBananaPeel
    .4byte CreateBoxyBox
    .4byte CreateShootingEnemyStar
    .4byte CreateBombarBomb
    .4byte CreateBombarMissile
    .4byte CreateBoxBoxerEnergyBall
    .4byte CreateWizFootball
    .4byte CreateWizCar
    .4byte CreateWizBalloon
    .4byte CreateWizBomb
    .4byte CreateWizCloud
    .4byte CreateWizApple
    .4byte CreateWizDroppy
    .4byte CreateTitanArm1
    .4byte CreateTitanArm2
    .4byte CreateTitanArm3
    .4byte CreateTitanArm4
    .4byte CreateTitanHeadMissile
    .4byte CreateMoleyItem
    .4byte CreateMoleyItem
    .4byte CreateMoleyItem
    .4byte CreateMoleyItem
    .4byte CreateMoleyItem
    .4byte CreateMoleyItem
    .4byte CreateMoleyItem
    .4byte CreateMasterHandBullet
    .4byte CreateThrownBomb2
    .4byte CreateShadowKirbyBomb
    .4byte CreateDarkMindStar
    .4byte CreateDarkMindStar
    .4byte CreateDarkMindStar
    .4byte CreateDarkMindStar
    .4byte sub_08107780
    .4byte sub_0810F320
    .4byte DarkMindLaserShot
    .4byte DarkMindLaserBeam
    .4byte CreateDarkMindMirrorCutter
    .4byte sub_08117BBC
    .4byte CreateSirKibbleCutter
    .4byte CreateGlunkBullet
    .4byte CreateShotzoBullet
    .4byte CreateCupieArrow
    .4byte CreateJackStar
    .4byte CreateShootyBomb

gUnk_083513E8:: @ 083513E8
	.incbin "baserom.gba", 0x3513E8, 0x0000070

gUnk_08351458:: @ 08351458
	.incbin "baserom.gba", 0x351458, 0x00000D8

gUnk_08351530:: @ 08351530
	.incbin "baserom.gba", 0x351530, 0x00000D8

gUnk_08351608:: @ 08351608
	.incbin "baserom.gba", 0x351608, 0x0000020

gUnk_08351628:: @ 08351628
	.incbin "baserom.gba", 0x351628, 0x0000020

gUnk_08351648:: @ 08351648
    @ 0x00 OBJ_WADDLE_DEE_1
    .byte 4, 5
    .2byte 200, 2, 0, 0x0308, 0
    .4byte 9
    .4byte WaddleDeeChooseBehavior
    .4byte gWaddleDeeAnimInfo

    @ 0x01 OBJ_BRONTO_BURT
    .byte 4, 5
    .2byte 100, 2, 0, 0x0309, 0
    .4byte 9
    .4byte sub_080AD7C0
    .4byte gBrontoBurtAnimInfo

    @ 0x02 OBJ_BLIPPER
    .byte 12, 13
    .2byte 100, 2, 0, 0x0327, 0
    .4byte 9
    .4byte sub_080A712C
    .4byte gBlipperAnimInfo

    @ 0x03 OBJ_GLUNK
    .byte 3, 4
    .2byte 100, 2, 0, 0x0327, 0
    .4byte 9
    .4byte sub_080AF610
    .4byte gGlunkAnimInfo

    @ 0x04 OBJ_SQUISHY
    .byte 6, 7
    .2byte 100, 2, 0, 0x0324, 0
    .4byte 9
    .4byte sub_080AF754
    .4byte gSquishyAnimInfo

    @ 0x05 OBJ_SCARFY
    .byte 3, 4
    .2byte 150, 1, 0, 0x0332, 0
    .4byte 16
    .4byte sub_080A80EC
    .4byte gScarfyAnimInfo

    @ 0x06 OBJ_GORDO
    .byte 0, 0
    .2byte 0, 2, 0, 0x0000, 0
    .4byte 14
    .4byte sub_0809FC58
    .4byte gUnk_08352E14

    @ 0x07 OBJ_SNOOTER_1
    .byte 9, 10
    .2byte 300, 4, 0, 0x02FB, 0
    .4byte 12
    .4byte sub_080ACBA4
    .4byte gUnk_08353980

    @ 0x08 OBJ_CHIP
    .byte 7, 8
    .2byte 100, 2, 0, 0x02F9, 0
    .4byte 12
    .4byte sub_080AB720
    .4byte gChipAnimInfo

    @ 0x09 OBJ_SOARAR
    .byte 11, 12
    .2byte 150, 2, 0, 0x02FC, 0
    .4byte 12
    .4byte sub_080AB8DC
    .4byte gUnk_0835394C

    @ 0x0A OBJ_HALEY
    .byte 2, 3
    .2byte 200, 2, 0, 0x02F8, 0
    .4byte 12
    .4byte sub_080A0E98
    .4byte gHaleyAnimInfo

    @ 0x0B OBJ_ROLYPOLY
    .byte 4, 5
    .2byte 300, 2, 0, 0x0300, 0
    .4byte 9
    .4byte sub_080AD5D4
    .4byte gRolyPolyAnimInfo

    @ 0x0C OBJ_CUPIE
    .byte 4, 5
    .2byte 200, 2, 19, 0x02FD, 0
    .4byte 20
    .4byte sub_080A2AF0
    .4byte gCupieAnimInfo

    @ 0x0D OBJ_BLOCKIN
    .byte 3, 4
    .2byte 200, 2, 0, 0x030F, 0
    .4byte 12
    .4byte sub_080A49D0
    .4byte gBlockinAnimInfo

    @ 0x0E OBJ_SNOOTER_2
    .byte 11, 12
    .2byte 300, 4, 0, 0x02FB, 0
    .4byte 12
    .4byte sub_080ACBA4
    .4byte gUnk_08353980

    @ 0x0F OBJ_LEAP
    .byte 3, 4
    .2byte 200, 2, 0, 0x0312, 0
    .4byte 16
    .4byte sub_080B0F28
    .4byte gUnk_08353D0C

    @ 0x10 OBJ_JACK
    .byte 6, 7
    .2byte 150, 2, 0, 0x031C, 0
    .4byte 16
    .4byte sub_080A8904
    .4byte gJackAnimInfo

    @ 0x11 OBJ_BIG_WADDLE_DEE
    .byte 3, 4
    .2byte 1000, 2, 0, 0x0314, 0
    .4byte 25
    .4byte sub_080A4FD0
    .4byte gBigWaddleDeeAnimInfo

    @ 0x12 OBJ_WADDLE_DOO
    .byte 8, 9
    .2byte 300, 4, 7, 0x0308, 0
    .4byte 9
    .4byte sub_080B6A54
    .4byte gUnk_08354624

    @ 0x13 OBJ_FLAMER
    .byte 11, 12
    .2byte 300, 4, 3, 0x031E, 0
    .4byte 15
    .4byte sub_080BA334
    .4byte gFlamerAnimInfo

    @ 0x14 OBJ_HOT_HEAD
    .byte 3, 4
    .2byte 250, 4, 1, 0x031F, 0
    .4byte 9
    .4byte sub_080C3234
    .4byte gUnk_08355518

    @ 0x15 OBJ_LASER_BALL
    .byte 4, 5
    .2byte 300, 4, 13, 0x0321, 0
    .4byte 12
    .4byte sub_080B2BE0
    .4byte gLaserBallAnimInfo3

    @ 0x16 OBJ_PENGY
    .byte 7, 8
    .2byte 250, 4, 2, 0x032C, 0
    .4byte 9
    .4byte sub_080BBBF8
    .4byte gPengyAnimInfo

    @ 0x17 OBJ_ROCKY
    .byte 5, 6
    .2byte 400, 5, 8, 0x0323, 0
    .4byte 9
    .4byte sub_080BE898
    .4byte gRockyAnimInfo

    @ 0x18 OBJ_SIR_KIBBLE
    .byte 4, 5
    .2byte 300, 4, 6, 0x032D, 0
    .4byte 12
    .4byte sub_080B2108
    .4byte gSirKibbleAnimInfo

    @ 0x19 OBJ_SPARKY
    .byte 8, 9
    .2byte 250, 4, 15, 0x032E, 0
    .4byte 90
    .4byte sub_080C4570
    .4byte gSparkyAnimInfo

    @ 0x1A OBJ_SWORD_KNIGHT
    .byte 7, 8
    .2byte 500, 4, 18, 0x032F, 0
    .4byte 28
    .4byte sub_080B3A18
    .4byte gUnk_08353FA8

    @ 0x1B OBJ_UFO
    .byte 2, 3
    .2byte 1000, 2, 14, 0x0326, 0
    .4byte 12
    .4byte sub_080C4ACC
    .4byte gUfoAnimInfo3

    @ 0x1C OBJ_TWISTER
    .byte 3, 4
    .2byte 300, 4, 16, 0x0325, 0
    .4byte 12
    .4byte sub_080BC440
    .4byte gTwisterAnimInfo

    @ 0x1D OBJ_WHEELIE
    .byte 7, 8
    .2byte 250, 4, 4, 0x032A, 0
    .4byte 9
    .4byte sub_080BC594
    .4byte gWheelieAnimInfo

    @ 0x1E OBJ_NODDY
    .byte 4, 5
    .2byte 100, 2, 11, 0x0322, 0
    .4byte 9
    .4byte sub_080C22E4
    .4byte gNoddyAnimInfo

    @ 0x1F OBJ_GOLEM_1
    .byte 3, 3
    .2byte 1500, 7, 8, 0x02EA, 0
    .4byte 56
    .4byte sub_080C6404
    .4byte gGolemAnimInfo

    @ 0x20 OBJ_GOLEM_2
    .byte 3, 3
    .2byte 1500, 7, 8, 0x02E9, 0
    .4byte 56
    .4byte sub_080C6404
    .4byte gGolemAnimInfo

    @ 0x21 OBJ_GOLEM_3
    .byte 3, 3
    .2byte 1500, 7, 8, 0x02EB, 0
    .4byte 56
    .4byte sub_080C6404
    .4byte gGolemAnimInfo

    @ 0x22 OBJ_FOLEY_1
    .byte 3, 3
    .2byte 200, 2, 9, 0x0302, 0
    .4byte 16
    .4byte sub_080C0C6C
    .4byte gFoleyAnimInfo

    @ 0x23 OBJ_SHOOTY
    .byte 17, 18
    .2byte 500, 2, 0, 0x030A, 0
    .4byte 12
    .4byte sub_080C2044
    .4byte gShootyAnimInfo

    @ 0x24 OBJ_SCARFY_FALLING
    .byte 5, 5
    .2byte 150, 1, 0, 0x0332, 0
    .4byte 16
    .4byte sub_080A80EC
    .4byte gScarfyAnimInfo

    @ 0x25 OBJ_BOXIN
    .byte 14, 15
    .2byte 600, 4, 20, 0x0307, 0
    .4byte 12
    .4byte sub_080B5838
    .4byte gBoxinAnimInfo

    @ 0x26 OBJ_COOKIN
    .byte 6, 7
    .2byte 200, 2, 12, 0x030B, 0
    .4byte 35
    .4byte sub_080B681C
    .4byte gUnk_08354334

    @ 0x27 OBJ_MINNY
    .byte 2, 3
    .2byte 200, 2, 23, 0x02FF, 0
    .4byte 4
    .4byte MinnyStart
    .4byte gMinnyAnimInfo

    @ 0x28 OBJ_BOMBER
    .byte 4, 5
    .2byte 500, 1, 24, 0x032B, 0
    .4byte 9
    .4byte sub_080C478C
    .4byte gBomberAnimInfo

    @ 0x29 OBJ_HEAVY_KNIGHT
    .byte 7, 8
    .2byte 1000, 8, 18, 0x0310, 0
    .4byte 60
    .4byte sub_080BFBE0
    .4byte gHeavyKnightAnimInfo

    @ 0x2A OBJ_GIANT_ROCKY
    .byte 6, 7
    .2byte 1000, 10, 8, 0x0315, 0
    .4byte 30
    .4byte sub_080C0410
    .4byte gGiantRockyAnimInfo

    @ 0x2B OBJ_METAL_GUARDIAN
    .byte 5, 6
    .2byte 1000, 10, 13, 0x0311, 0
    .4byte 30
    .4byte sub_080BE228
    .4byte gMetalGuardianAnimInfo

    @ 0x2C OBJ_EMPTY_2C
    .byte 0, 0
    .2byte 204, 2, 0, 0x0000, 0
    .4byte 9
    .4byte sub_0809FE9C
    .4byte gGolemAnimInfo

    @ 0x2D OBJ_BATTY
    .byte 4, 5
    .2byte 150, 2, 0, 0x0333, 0
    .4byte 12
    .4byte sub_080BD3CC
    .4byte gBattyAnimInfo

    @ 0x2E OBJ_FOLEY_2
    .byte 4, 4
    .2byte 200, 2, 9, 0x0302, 0
    .4byte 16
    .4byte sub_080C0CBC
    .4byte gFoleyAnimInfo

    @ 0x2F OBJ_BANG_BANG
    .byte 24, 25
    .2byte 200, 2, 25, 0x033E, 0
    .4byte 16
    .4byte sub_080C70D8
    .4byte gBangBangAnimInfo

    @ 0x30 OBJ_DARK_MIND_BOMB
    .byte 0, 0
    .2byte 200, 10, 24, 0x0399, 0
    .4byte 36
    .4byte sub_081099A4
    .4byte gDarkMindAnimInfo7

    @ 0x31 OBJ_EMPTY_31
    .byte 8, 9
    .2byte 200, 2, 12, 0x030B, 0
    .4byte 35
    .4byte sub_080B681C
    .4byte gUnk_08354334

    @ 0x32 OBJ_DROPPY
    .byte 20, 21
    .2byte 500, 4, 0, 0x02F7, 0
    .4byte 16
    .4byte sub_0809FE9C
    .4byte gDroppyAnimInfo

    @ 0x33 OBJ_PRANK
    .byte 18, 19
    .2byte 200, 4, 0, 0x02FA, 0
    .4byte 36
    .4byte sub_080A12E4
    .4byte gUnk_08352F10

    @ 0x34 OBJ_MIRRA
    .byte 3, 3
    .2byte 800, 2, 0, 0x0336, 0
    .4byte 16
    .4byte sub_080B1174
    .4byte gMirraAnimInfo

    @ 0x35 OBJ_SHOTZO_1
    .byte 5, 5
    .2byte 100, 2, 0, 0x030E, 0
    .4byte 12
    .4byte sub_0811A874
    .4byte gUnk_08357BF8

    @ 0x36 OBJ_SHADOW_KIRBY
    .byte 19, 19
    .2byte 200, 4, 0, 0x0383, 0
    .4byte 16
    .4byte ShadowKirbyStartLeave
    .4byte gShadowKirbyAnimInfo

    @ 0x37 OBJ_WADDLE_DEE_2
    .byte 4, 5
    .2byte 200, 30, 0, 0x0308, 0
    .4byte 9
    .4byte WaddleDee37ChooseXSpeed
    .4byte gWaddleDeeAnimInfo

    @ 0x38 OBJ_MR_FROSTY
    .byte 17, 18
    .2byte 1000, 30, 2, 0x1319, 0
    .4byte 36
    .4byte MrFrostyActivate
    .4byte gMrFrostyAnimInfo

    @ 0x39 OBJ_BONKERS
    .byte 20, 21
    .2byte 2000, 40, 17, 0x131A, 0
    .4byte 72
    .4byte BonkersStartIdle
    .4byte gBonkersAnimInfo

    @ 0x3A OBJ_PHAN_PHAN
    .byte 29, 30
    .2byte 2000, 30, 10, 0x131B, 0
    .4byte 64
    .4byte sub_080CF44C
    .4byte gPhanPhanAnimInfo3

    @ 0x3B OBJ_BATAFIRE
    .byte 12, 13
    .2byte 2000, 30, 3, 0x12E7, 0
    .4byte 112
    .4byte sub_080C95D4
    .4byte gBatafireAnimInfo

    @ 0x3C OBJ_BOX_BOXER
    .byte 19, 20
    .2byte 2000, 40, 20, 0x12FE, 0
    .4byte 63
    .4byte BoxBoxerStartIdle
    .4byte gBoxBoxerAnimInfo

    @ 0x3D OBJ_BOXY
    .byte 13, 14
    .2byte 2000, 40, 21, 0x1338, 0
    .4byte 70
    .4byte BoxyStartIdle
    .4byte gBoxyAnimInfo

    @ 0x3E OBJ_MASTER_HAND
    .byte 22, 23
    .2byte 2000, 40, 22, 0x1335, 0
    .4byte 72
    .4byte MasterHandStartIdle
    .4byte gCrazyHandAnimInfo

    @ 0x3F OBJ_BOMBAR
    .byte 8, 9
    .2byte 2000, 40, 25, 0x1316, 0
    .4byte 70
    .4byte sub_080D9E94
    .4byte gBombarAnimInfo

    @ 0x40 OBJ_EMPTY_40
    .byte 0, 0
    .2byte 224, 2, 0, 0x0000, 0
    .4byte 9
    .4byte sub_0809FE9C
    .4byte gGolemAnimInfo

    @ 0x41 OBJ_EMPTY_41
    .byte 3, 3
    .2byte 1500, 2, 0, 0x0000, 0
    .4byte 56
    .4byte sub_080C6404
    .4byte gGolemAnimInfo

    @ 0x42 OBJ_EMPTY_42
    .byte 3, 3
    .2byte 1500, 2, 0, 0x0000, 0
    .4byte 56
    .4byte sub_080C6404
    .4byte gGolemAnimInfo

    @ 0x43 OBJ_EMPTY_43
    .byte 3, 3
    .2byte 1500, 2, 0, 0x0000, 0
    .4byte 56
    .4byte sub_080C6404
    .4byte gGolemAnimInfo

    @ 0x44 OBJ_EMPTY_44
    .byte 0, 0
    .2byte 20000, 2, 0, 0x0000, 0
    .4byte 9
    .4byte sub_0809FE9C
    .4byte gGolemAnimInfo

    @ 0x45 OBJ_KRACKO
    .byte 0, 0
    .2byte 20000, 60, 0, 0x0339, 0
    .4byte 0
    .4byte KrackoStartIdle
    .4byte gKrackoAnimInfo4

    @ 0x46 OBJ_KING_GOLEM
    .byte 4, 4
    .2byte 20000, 60, 0, 0x0303, 0
    .4byte 150
    .4byte sub_080DA4B0
    .4byte gKingGolemAnimInfo

    @ 0x47 OBJ_CRAZY_HAND_1
    .byte 22, 22
    .2byte 20000, 60, 0, 0x1335, 0
    .4byte 72
    .4byte CrazyHandStartIdle
    .4byte gCrazyHandAnimInfo

    @ 0x48 OBJ_GOBBLER
    .byte 16, 17
    .2byte 20000, 60, 0, 0x030C, 0
    .4byte 88
    .4byte GobblerStartIdle
    .4byte gGobblerAnimInfo

    @ 0x49 OBJ_WIZ
    .byte 0, 0
    .2byte 20000, 80, 0, 0x1317, 0
    .4byte 64
    .4byte WizStartChooseAttack
    .4byte gWizAnimInfo

    @ 0x4A OBJ_MOLEY
    .byte 0, 0
    .2byte 20000, 80, 0, 0x133F, 0
    .4byte 56
    .4byte MoleyStartEmerge
    .4byte gMoleyAnimInfo

    @ 0x4B OBJ_MEGA_TITAN
    .byte 4, 4
    .2byte 5000, 40, 0, 0x033C, 0
    .4byte 48
    .4byte MegaTitanStartIdle
    .4byte gMegaTitanAnimInfo

    @ 0x4C OBJ_TITAN_HEAD
    .byte 5, 5
    .2byte 20000, 20, 0, 0x133D, 0
    .4byte 20
    .4byte TitanHeadStartIdle
    .4byte gMegaTitanAnimInfo6

    @ 0x4D OBJ_CRAZY_HAND_2
    .byte 22, 22
    .2byte 20000, 60, 0, 0x1335, 0
    .4byte 72
    .4byte CrazyHandStartIdle
    .4byte gCrazyHandAnimInfo

    @ 0x4E OBJ_DARK_META_KNIGHT
    .byte 0, 0
    .2byte 30000, 2, 0, 0x0394, 0
    .4byte 56
    .4byte DarkMetaKnightStartIdle
    .4byte gMegaTitanAnimInfo9

    @ 0x4F OBJ_DARK_MIND_FORM_1
    .byte 0, 0
    .2byte 60000, 2, 0, 0x0398, 0
    .4byte 176
    .4byte sub_08101630
    .4byte gDarkMindAnimInfo4

    @ 0x50 OBJ_DARK_MIND_FORM_2
    .byte 0, 0
    .2byte 60000, 2, 0, 0x0399, 0
    .4byte 0
    .4byte sub_0810C9C8
    .4byte gUnk_08357300

    @ 0x51 OBJ_DARK_MIND_FORM_3_TRIGGER
    .byte 0, 0
    .2byte 60000, 2, 0, 0x039C, 0
    .4byte 36
    .4byte sub_08114BA0
    .4byte gDarkMindAnimInfo12

    @ 0x52 OBJ_DARK_META_KNIGHT_W8
    .byte 0, 0
    .2byte 30000, 2, 0, 0x0390, 0
    .4byte 56
    .4byte DarkMetaKnightStartIdle
    .4byte gMegaTitanAnimInfo9

    @ 0x53 OBJ_EMPTY_53
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x54 OBJ_EMPTY_54
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0811A624
    .4byte gMirrorDoorAnimInfo

    @ 0x55 OBJ_EMPTY_55
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x56 OBJ_EMPTY_56
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x57 OBJ_EMPTY_57
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x58 OBJ_EMPTY_58
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x59 OBJ_EMPTY_59
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x5A OBJ_EMPTY_5A
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x5B OBJ_EMPTY_5B
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x5C OBJ_EMPTY_5C
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x5D OBJ_EMPTY_5D
    .byte 0, 0
    .2byte 20000, 32, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080DA4B0
    .4byte gGolemAnimInfo

    @ 0x5E OBJ_SMALL_FOOD
    .byte 0, 0
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357F00

    @ 0x5F OBJ_POP_SODA
    .byte 0, 0
    .2byte 0, 2, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357EF4

    @ 0x60 OBJ_MEAT
    .byte 0, 0
    .2byte 0, 3, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357F18

    @ 0x61 OBJ_TOMATO
    .byte 0, 0
    .2byte 0, 10, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357EFC

    @ 0x62 OBJ_BATTERY
    .byte 0, 0
    .2byte 0, 3, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357F1C

    @ 0x63 OBJ_1UP
    .byte 0, 0
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357F20

    @ 0x64 OBJ_INVINCIBLE_CANDY
    .byte 0, 0
    .2byte 0, 200, 0, 0x0000, 0
    .4byte 4
    .4byte BonusSetFunc
    .4byte gUnk_08357EF8

    @ 0x65 OBJ_MIRROR_SHARD
    .byte 0, 0
    .2byte 0, 0, 0, 0x02D3, 0
    .4byte 48
    .4byte ShardInit
    .4byte gShardAnimInfo

    @ 0x66 OBJ_EMPTY_66
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D1, 0
    .4byte 4
    .4byte sub_08123780
    .4byte gUnk_08357EF4

    @ 0x67 OBJ_EMPTY_67
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D1, 0
    .4byte 4
    .4byte sub_08123780
    .4byte gUnk_08357EF4

    @ 0x68 OBJ_EMPTY_68
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D1, 0
    .4byte 4
    .4byte sub_08123780
    .4byte gUnk_08357EF4

    @ 0x69 OBJ_GOAL_GAME_BONUS
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 16
    .4byte sub_0801ABFC
    .4byte gGoalGameBonusAnimInfo

    @ 0x6A OBJ_EMPTY_6A
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D1, 0
    .4byte 4
    .4byte sub_08123780
    .4byte gUnk_08357EF4

    @ 0x6B OBJ_EMPTY_6B
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D1, 0
    .4byte 4
    .4byte sub_08123780
    .4byte gUnk_08357EF4

    @ 0x6C OBJ_EMPTY_6C
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D1, 0
    .4byte 4
    .4byte sub_08123780
    .4byte gUnk_08357EF4

    @ 0x6D OBJ_SMALL_BUTTON
    .byte 0, 0
    .2byte 0, 0, 0, 0x0304, 0
    .4byte 4
    .4byte sub_0811938C
    .4byte gUnk_08357BD0

    @ 0x6E OBJ_FLAME
    .byte 0, 0
    .2byte 0, 0, 0, 0x0305, 0
    .4byte 4
    .4byte FireCounterInit
    .4byte gFireAnimInfo

    @ 0x6F OBJ_DOOR
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 4294967295
    .4byte sub_0811A624
    .4byte gMirrorDoorAnimInfo

    @ 0x70 OBJ_SHOTZO_2
    .byte 0, 0
    .2byte 0, 0, 0, 0x030E, 0
    .4byte 6
    .4byte sub_0811A874
    .4byte gUnk_08357BF8

    @ 0x71 OBJ_VERTICAL_SLIDING_DOOR
    .byte 0, 0
    .2byte 0, 0, 0, 0x02DF, 0
    .4byte 16
    .4byte VertSlidingDoorSetFunc
    .4byte gUnk_08357C44

    @ 0x72 OBJ_BOSS_CHALLENGE_DOOR
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 4294967295
    .4byte sub_08118C18
    .4byte gUnk_08357B18

    @ 0x73 OBJ_OBJECT_SPAWNER
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0811BA30
    .4byte gUnk_08357C50

    @ 0x74 OBJ_DESTROYABLE_ROCK_BLOCK
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte DestroyableRockBlockInit
    .4byte gDestroyableRockBlockAnimInfo

    @ 0x75 OBJ_UNKNOWN_75
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0811C29C
    .4byte gUnknown75AnimInfo

    @ 0x76 OBJ_LAVA_WALL
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0811C758
    .4byte gLavaWallAnimInfo

    @ 0x77 OBJ_SCROLL_LOCK
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0811C9D4
    .4byte gScrollLockAnimInfo

    @ 0x78 OBJ_CANNON_FUSE
    .byte 0, 0
    .2byte 0, 0, 0, 0x02DD, 0
    .4byte 4
    .4byte sub_0811DD94
    .4byte gCannonFuseAnimInfo

    @ 0x79 OBJ_STAR_STONE_BLOCK
    .byte 0, 0
    .2byte 0, 0, 0, 0x02A2, 0
    .4byte 4
    .4byte sub_0811F0CC
    .4byte gUnk_08357CC8

    @ 0x7A OBJ_UNKNOWN_7A
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0811F20C
    .4byte gUnk_08357CD0

    @ 0x7B OBJ_STAR_PLATFORM
    .byte 0, 0
    .2byte 0, 0, 0, 0x02E1, 0
    .4byte 8
    .4byte sub_0811FC3C
    .4byte gUnk_08357CD4

    @ 0x7C OBJ_FLAME_COLUMN
    .byte 0, 0
    .2byte 0, 0, 0, 0x0306, 0
    .4byte 16
    .4byte sub_0811FDF0
    .4byte gFlameColumnAnimInfo

    @ 0x7D OBJ_LARGE_STAR_STONE_BLOCK_7D
    .byte 0, 0
    .2byte 0, 0, 0, 0x02A2, 0
    .4byte 16
    .4byte LargeStarStoneBlock7DSetFunc
    .4byte gUnk_08357D08

    @ 0x7E OBJ_LARGE_STAR_STONE_BLOCK_7E
    .byte 0, 0
    .2byte 0, 0, 0, 0x02A2, 0
    .4byte 16
    .4byte sub_08120594
    .4byte gUnk_08357D10

    @ 0x7F OBJ_CPU_KIRBY_TRIGGER
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0812098C
    .4byte gUnk_08357D18

    @ 0x80 OBJ_SMALL_CHEST
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D2, 0
    .4byte 4
    .4byte sub_0800BD4C
    .4byte gUnk_082D9244

    @ 0x81 OBJ_BIG_CHEST
    .byte 0, 0
    .2byte 0, 3, 0, 0x02D2, 0
    .4byte 16
    .4byte sub_0800BD4C
    .4byte gUnk_082D9254

    @ 0x82 OBJ_UNKNOWN_82
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_08120A40
    .4byte gUnk_08357D1C

    @ 0x83 OBJ_UNKNOWN_83
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080AA94C
    .4byte 0

    @ 0x84 OBJ_WARP_STAR
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 4294967295
    .4byte nullsub_101
    .4byte gWarpStarAnimInfo

    @ 0x85 OBJ_GOAL_STAR
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 4294967295
    .4byte nullsub_102
    .4byte gWarpStarAnimInfo2

    @ 0x86 OBJ_BIG_BUTTON
    .byte 0, 0
    .2byte 0, 0, 0, 0x02E0, 0
    .4byte 24
    .4byte sub_0811938C
    .4byte gUnk_08357BDC

    @ 0x87 OBJ_UNKNOWN_87
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_0812102C
    .4byte gUnk_08357E50

    @ 0x88 OBJ_LARGE_STAR_STONE_BLOCK_88
    .byte 0, 0
    .2byte 0, 0, 0, 0x02A2, 0
    .4byte 16
    .4byte sub_08121480
    .4byte gUnk_08357E54

    @ 0x89 OBJ_LARGE_STAR_STONE_BLOCK_89
    .byte 0, 0
    .2byte 0, 0, 0, 0x02A2, 0
    .4byte 16
    .4byte sub_08121940
    .4byte gUnk_08357E5C

    @ 0x8A OBJ_CANNON
    .byte 0, 0
    .2byte 0, 0, 0, 0x02DD, 0
    .4byte 25
    .4byte sub_08121AF8
    .4byte gUnk_08357E64

    @ 0x8B OBJ_8_DIR_CANNON
    .byte 0, 0
    .2byte 0, 0, 0, 0x02E3, 0
    .4byte 25
    .4byte sub_081224B8
    .4byte gUnk_08357E84

    @ 0x8C OBJ_HUB_MIRROR
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte nullsub_109
    .4byte 0

    @ 0x8D OBJ_HAMMER_PEG
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 4
    .4byte sub_08025320
    .4byte gHammerPegAnimInfo

    @ 0x8E OBJ_CUTSCENE_TRIGGER
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_08022DE4
    .4byte 0

    @ 0x8F OBJ_MASTER_SWORD_UNOBTAINABLE
    .byte 0, 0
    .2byte 0, 0, 0, 0x02C3, 0
    .4byte 6
    .4byte sub_08025434
    .4byte gMasterSwordAnimInfo

    @ 0x90 OBJ_WIND_EFFECT
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte sub_080AA960
    .4byte 0

    @ 0x91 OBJ_TRIGGERABLE_WALL
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte LeverWallSetFunc
    .4byte 0

    @ 0x92 OBJ_ABILITY_STATUE_1
    .byte 0, 0
    .2byte 0, 1, 0, 0x0385, 0
    .4byte 4
    .4byte sub_080AA4EC
    .4byte gAbilityObjectsAnimInfo2

    @ 0x93 OBJ_ABILITY_STATUE_2
    .byte 0, 0
    .2byte 0, 1, 0, 0x0386, 0
    .4byte 4
    .4byte sub_080AA4EC
    .4byte gAbilityObjectsAnimInfo3

    @ 0x94 OBJ_ABILITY_STATUE_3
    .byte 0, 0
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 4
    .4byte sub_080AA4EC
    .4byte gAbilityObjectsAnimInfo4

    @ 0x95 OBJ_ABILITY_STATUE_4
    .byte 0, 0
    .2byte 0, 1, 0, 0x0387, 0
    .4byte 4
    .4byte sub_080AA4EC
    .4byte gAbilityObjectsAnimInfo5

    @ 0x96 OBJ_ABILITY_STATUE_RANDOM
    .byte 0, 0
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 0
    .4byte 0
    .4byte 0

    @ 0x97 OBJ_DOOR_TO_HUB
    .byte 0, 0
    .2byte 0, 1, 0, 0x12C6, 0
    .4byte 20
    .4byte nullsub_116
    .4byte gSpecialDoorsAnimInfo2

    @ 0x98 OBJ_MASTER_SWORD_STAND
    .byte 0, 0
    .2byte 0, 1, 0, 0x02C3, 0
    .4byte 6
    .4byte sub_080AA4EC
    .4byte gAbilityObjectsAnimInfo6

    @ 0x99 OBJ_AREA_DOOR
    .byte 0, 0
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 15
    .4byte nullsub_117
    .4byte gSpecialDoorsAnimInfo3

    @ 0x9A OBJ_EMPTY_9A
    .byte 0, 0
    .2byte 0, 0, 0, 0x0000, 0
    .4byte 0
    .4byte 0
    .4byte 0

    @ 0x9B OBJ_KING_GOLEM_ROCK
    .byte 0, 0
    .2byte 100, 1, 0, 0x0303, 0
    .4byte 9
    .4byte sub_080DB5E0
    .4byte gKingGolemAnimInfo2

    @ 0x9C OBJ_KING_GOLEM_GORDO
    .byte 0, 0
    .2byte 100, 1, 0, 0x0000, 0
    .4byte 14
    .4byte sub_080DB5E0
    .4byte gUnk_08352E14

    @ 0x9D OBJ_FOLEY_LEAVES
    .byte 0, 0
    .2byte 200, 1, 0, 0x0302, 0
    .4byte 6
    .4byte sub_080C0CF0
    .4byte gFoleyAnimInfo2

    @ 0x9E OBJ_COOKIN_PAN
    .byte 2, 0
    .2byte 200, 1, 0, 0x030B, 0
    .4byte 12
    .4byte sub_080B6880
    .4byte gUnk_0835435C

    @ 0x9F OBJ_GOBBLER_BABY
    .byte 9, 10
    .2byte 100, 7, 18, 0x030D, 0
    .4byte 12
    .4byte sub_080E79A4
    .4byte gGobblerAnimInfo2

    @ 0xA0 OBJ_UNKNOWN_A0
    .byte 0, 0
    .2byte 50, 1, 0, 0x0000, 0
    .4byte 779
    .4byte sub_080B2130
    .4byte gSirKibbleAnimInfo2

    @ 0xA1 OBJ_BATAFIRE_FIREBALL
    .byte 0, 0
    .2byte 50, 1, 0, 0x02E7, 0
    .4byte 32
    .4byte sub_080CB4A0
    .4byte gBatafireAnimInfo2

    @ 0xA2 OBJ_PARASOL
    .byte 0, 0
    .2byte 50, 1, 5, 0x0000, 0
    .4byte 9
    .4byte sub_080C2B28
    .4byte gParasolAnimInfo

    @ 0xA3 OBJ_ABILITY_STAR_1
    .byte 4, 4
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 4294967295
    .4byte sub_080AA91C
    .4byte gInhalableStarAnimInfo

    @ 0xA4 OBJ_ABILITY_STAR_2
    .byte 4, 4
    .2byte 0, 1, 0, 0x0000, 0
    .4byte 16
    .4byte sub_080AA91C
    .4byte gAbilityObjectsAnimInfo

    @ 0xA5 OBJ_INHALABLE_STAR
    .byte 4, 4
    .2byte 50, 1, 0, 0x0000, 0
    .4byte 4294967295
    .4byte sub_080A8EF4
    .4byte gInhalableStarAnimInfo

    @ 0xA6 OBJ_MR_FROSTY_ICE_CUBE_SMALL
    .byte 0, 0
    .2byte 50, 1, 0, 0x0000, 0
    .4byte 9
    .4byte sub_080CD2CC
    .4byte gMrFrostyAnimInfo2

    @ 0xA7 OBJ_MR_FROSTY_ICE_CUBE_LARGE
    .byte 1, 1
    .2byte 50, 1, 0, 0x0000, 0
    .4byte 25
    .4byte sub_080CD2CC
    .4byte gMrFrostyAnimInfo2

    @ 0xA8 OBJ_BONKERS_NUT_SMALL
    .byte 0, 0
    .2byte 50, 1, 0, 0x031A, 0
    .4byte 9
    .4byte BonkersNutInit
    .4byte gBonkersAnimInfo2

    @ 0xA9 OBJ_BONKERS_NUT_LARGE
    .byte 1, 1
    .2byte 50, 1, 0, 0x031A, 0
    .4byte 9
    .4byte BonkersNutInit
    .4byte gBonkersAnimInfo2

    @ 0xAA OBJ_APPLE
    .byte 0, 0
    .2byte 50, 1, 0, 0x031B, 0
    .4byte 6
    .4byte AppleInit
    .4byte gPhanPhanAnimInfo4

    @ 0xAB OBJ_PRANK_FIRE
    .byte 0, 0
    .2byte 200, 1, 1, 0x0000, 0
    .4byte 4
    .4byte sub_080A243C
    .4byte gUnk_08352F60

    @ 0xAC OBJ_PRANK_ICE
    .byte 0, 0
    .2byte 200, 1, 2, 0x0000, 0
    .4byte 4
    .4byte sub_080A243C
    .4byte gUnk_08352F64

    @ 0xAD OBJ_PRANK_BOMB
    .byte 0, 0
    .2byte 200, 1, 9, 0x0000, 0
    .4byte 4
    .4byte sub_080A243C
    .4byte gUnk_08352F68

    @ 0xAE OBJ_PRANK_PAN
    .byte 2, 2
    .2byte 200, 1, 0, 0x02FA, 0
    .4byte 12
    .4byte sub_080B6880
    .4byte gUnk_08352F70

    @ 0xAF OBJ_BANANA_PEEL
    .byte 1, 1
    .2byte 200, 1, 0, 0x02FA, 0
    .4byte 4
    .4byte sub_080A2494
    .4byte gUnk_08352F7C

    @ 0xB0 OBJ_BOXY_BOX
    .byte 0, 0
    .2byte 200, 1, 0, 0x0338, 0
    .4byte 16
    .4byte BoxyBoxStart
    .4byte gBoxyAnimInfo2

    @ 0xB1 OBJ_SHOOTING_ENEMY_STAR
    .byte 2, 2
    .2byte 200, 1, 0, 0x0000, 0
    .4byte 4294967295
    .4byte ShootingEnemyStarInit
    .4byte gMasterHandAnimInfo

    @ 0xB2 OBJ_BOMBAR_BOMB
    .byte 1, 1
    .2byte 200, 1, 9, 0x0316, 0
    .4byte 9
    .4byte sub_080D9EE8
    .4byte gBombarAnimInfo2

    @ 0xB3 OBJ_BOMBAR_MISSILE
    .byte 8, 8
    .2byte 200, 1, 25, 0x0316, 0
    .4byte 9
    .4byte sub_080D99A4
    .4byte gBombarAnimInfo3

    @ 0xB4 OBJ_BOX_BOXER_ENERGY_BALL
    .byte 1, 1
    .2byte 200, 1, 0, 0x02FE, 0
    .4byte 24
    .4byte sub_080C8FA4
    .4byte gBoxBoxerAnimInfo2

    @ 0xB5 OBJ_WIZ_FOOTBALL
    .byte 1, 1
    .2byte 200, 2, 0, 0x0317, 0
    .4byte 6
    .4byte sub_080EA874
    .4byte gWizAnimInfo2

    @ 0xB6 OBJ_WIZ_CAR
    .byte 1, 1
    .2byte 200, 2, 4, 0x0317, 0
    .4byte 9
    .4byte sub_080EA95C
    .4byte gWizAnimInfo3

    @ 0xB7 OBJ_WIZ_BALLOON
    .byte 1, 1
    .2byte 200, 2, 0, 0x0317, 0
    .4byte 8
    .4byte sub_080E9948
    .4byte gWizAnimInfo4

    @ 0xB8 OBJ_WIZ_BOMB
    .byte 0, 0
    .2byte 200, 2, 9, 0x0000, 0
    .4byte 4
    .4byte sub_080E9B18
    .4byte gUnk_08352F68

    @ 0xB9 OBJ_WIZ_CLOUD
    .byte 2, 2
    .2byte 200, 2, 15, 0x0317, 0
    .4byte 9
    .4byte sub_080EAA30
    .4byte gWizAnimInfo5

    @ 0xBA OBJ_WIZ_APPLE
    .byte 1, 1
    .2byte 200, 2, 11, 0x0317, 0
    .4byte 9
    .4byte sub_080EA084
    .4byte gWizAnimInfo6

    @ 0xBB OBJ_WIZ_DROPPY
    .byte 20, 21
    .2byte 200, 2, 0, 0x02F7, 0
    .4byte 16
    .4byte sub_080EA340
    .4byte gDroppyAnimInfo

    @ 0xBC OBJ_TITAN_ARM_1
    .byte 8, 8
    .2byte 200, 100, 0, 0x033C, 0
    .4byte 16
    .4byte TitanArm1StartHover
    .4byte gMegaTitanAnimInfo2

    @ 0xBD OBJ_TITAN_ARM_2
    .byte 8, 8
    .2byte 200, 100, 0, 0x033C, 0
    .4byte 16
    .4byte TitanArm2StartHover
    .4byte gMegaTitanAnimInfo3

    @ 0xBE OBJ_TITAN_ARM_3
    .byte 8, 8
    .2byte 200, 100, 0, 0x033C, 0
    .4byte 16
    .4byte TitanArm3StartHover
    .4byte gMegaTitanAnimInfo4

    @ 0xBF OBJ_TITAN_ARM_4
    .byte 8, 8
    .2byte 200, 100, 0, 0x033C, 0
    .4byte 16
    .4byte TitanArm4StartHover
    .4byte gMegaTitanAnimInfo5

    @ 0xC0 OBJ_TITAN_HEAD_MISSILE
    .byte 1, 1
    .2byte 200, 2, 0, 0x033D, 0
    .4byte 15
    .4byte TitanHeadMissileInit
    .4byte gMegaTitanAnimInfo7

    @ 0xC1 OBJ_MOLEY_ROCK
    .byte 2, 2
    .2byte 200, 2, 0, 0x033F, 0
    .4byte 9
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo2

    @ 0xC2 OBJ_MOLEY_SCREW
    .byte 2, 2
    .2byte 200, 2, 0, 0x033F, 0
    .4byte 9
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo3

    @ 0xC3 OBJ_MOLEY_TIRE
    .byte 2, 2
    .2byte 200, 2, 4, 0x033F, 0
    .4byte 9
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo4

    @ 0xC4 OBJ_MOLEY_BOMB
    .byte 2, 2
    .2byte 200, 2, 9, 0x033F, 0
    .4byte 9
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo5

    @ 0xC5 OBJ_MOLEY_BIG_ROCK
    .byte 2, 2
    .2byte 200, 2, 8, 0x033F, 0
    .4byte 16
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo6

    @ 0xC6 OBJ_MOLEY_BARREL
    .byte 2, 2
    .2byte 200, 2, 3, 0x033F, 0
    .4byte 16
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo7

    @ 0xC7 OBJ_MOLEY_SPIKE_BALL
    .byte 2, 2
    .2byte 200, 2, 6, 0x0341, 0
    .4byte 16
    .4byte MoleyThrowAttack
    .4byte gMoleyAnimInfo8

    @ 0xC8 OBJ_MASTER_HAND_BULLET
    .byte 2, 2
    .2byte 200, 1, 3, 0x0335, 0
    .4byte 105
    .4byte MasterHandBulletInit
    .4byte gCrazyHandAnimInfo2

    @ 0xC9 OBJ_THROWN_BOMB_2
    .byte 0, 0
    .2byte 200, 2, 9, 0x0000, 0
    .4byte 4
    .4byte ShadowKirbyBombStartHeld
    .4byte gUnk_08352F68

    @ 0xCA OBJ_SHADOW_KIRBY_BOMB
    .byte 0, 0
    .2byte 200, 2, 0, 0x039A, 0
    .4byte 32
    .4byte sub_08109960
    .4byte gDarkMindAnimInfo5

    @ 0xCB OBJ_DARK_MIND_STAR_FIRE
    .byte 0, 0
    .2byte 200, 2, 1, 0x0399, 0
    .4byte 16
    .4byte sub_08106508
    .4byte gDarkMindAnimInfo6

    @ 0xCC OBJ_DARK_MIND_STAR_ICE
    .byte 1, 1
    .2byte 200, 2, 2, 0x0399, 0
    .4byte 16
    .4byte sub_08106508
    .4byte gDarkMindAnimInfo6

    @ 0xCD OBJ_DARK_MIND_STAR_SPARK
    .byte 2, 2
    .2byte 200, 2, 15, 0x0399, 0
    .4byte 16
    .4byte sub_08106508
    .4byte gDarkMindAnimInfo6

    @ 0xCE OBJ_DARK_MIND_STAR_MIX
    .byte 3, 3
    .2byte 200, 2, 27, 0x0399, 0
    .4byte 16
    .4byte sub_08106508
    .4byte gDarkMindAnimInfo6

    @ 0xCF OBJ_UNKNOWN_CF
    .byte 0, 0
    .2byte 0, 8, 0, 0x0000, 0
    .4byte 0
    .4byte sub_081099C0
    .4byte 0

    @ 0xD0 OBJ_UNKNOWN_D0
    .byte 0, 0
    .2byte 20000, 9999, 0, 0x039A, 0
    .4byte 32
    .4byte sub_08113B68
    .4byte gDarkMindAnimInfo8

    @ 0xD1 OBJ_DARK_MIND_LASER
    .byte 0, 0
    .2byte 0, 2, 0, 0x039A, 0
    .4byte 36
    .4byte sub_08113BAC
    .4byte gDarkMindAnimInfo9

    @ 0xD2 OBJ_DARK_MIND_LASER_SHOWER
    .byte 0, 0
    .2byte 0, 2, 0, 0x039A, 0
    .4byte 102
    .4byte sub_08113BEC
    .4byte gDarkMindAnimInfo10

    @ 0xD3 OBJ_DARK_MIND_MIRROR_CUTTER
    .byte 0, 0
    .2byte 0, 2, 0, 0x039A, 0
    .4byte 16
    .4byte sub_08113C10
    .4byte gDarkMindAnimInfo11

    @ 0xD4 OBJ_UNKNOWN_D4
    .byte 0, 0
    .2byte 200, 2, 0, 0x0399, 0
    .4byte 16
    .4byte sub_08106508
    .4byte gDarkMindAnimInfo6

    @ 0xD5 OBJ_SIR_KIBBLE_CUTTER
    .byte 0, 0
    .2byte 200, 2, 0, 0x032D, 0
    .4byte 6
    .4byte sub_080B1FD0
    .4byte gSirKibbleAnimInfo2

    @ 0xD6 OBJ_GLUNK_BULLET
    .byte 0, 0
    .2byte 200, 2, 0, 0x0327, 0
    .4byte 6
    .4byte sub_080AF0A8
    .4byte gGlunkAnimInfo2

    @ 0xD7 OBJ_SHOTZO_BULLET
    .byte 0, 0
    .2byte 200, 2, 0, 0x030E, 0
    .4byte 2
    .4byte sub_0811B2A4
    .4byte gUnk_08357C10

    @ 0xD8 OBJ_CUPIE_ARROW
    .byte 0, 0
    .2byte 200, 2, 0, 0x02FD, 0
    .4byte 16
    .4byte CupieArrowAttack
    .4byte gCupieAnimInfo2

    @ 0xD9 OBJ_JACK_STAR
    .byte 0, 0
    .2byte 200, 2, 0, 0x031C, 0
    .4byte 16
    .4byte JackAttack
    .4byte gJackAnimInfo2

    @ 0xDA OBJ_SHOOTY_BOMB
    .byte 0, 0
    .2byte 200, 2, 0, 0x030A, 0
    .4byte 12
    .4byte sub_080C1E38
    .4byte gShootyAnimInfo2
