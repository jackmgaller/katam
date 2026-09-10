#include "global.h"

struct ObjectBase;
struct Kirby;
struct Task;

// The matching compiler emits these inline bodies in declaration order.
// Declare them before headers that expose only part of this sequence.
inline void LoadHudAbilityIcon(u8 ability);
inline void StartHudAbilityIconExpansion(struct ObjectBase *object);
inline void HoldExpandedHudAbilityIcon(struct ObjectBase *object);
inline void ScheduleHudAbilityIconCollapse(struct ObjectBase *object);
inline void RequestHudAbilityIconCollapse(struct ObjectBase *object);
inline void UpdateGameOverHudIndicators(void);
inline void GameplayHudDestructor(struct Task *task);
inline void LoadGameplayHudGraphics(void);
inline void DrawHudLivesLabel(void);
inline void DrawHudLivesCount(struct Kirby *kirby);
inline void DrawDemoHud(void);
inline void DrawHudPhoneIcon(void);
inline void ClearHudPhoneIcon(void);
inline void DrawHudEnemyNameTiles(void);
inline void ShowGameOverHud(void);
inline void ShowBorrowLifeHud(void);
inline void RestoreHudAfterLifeBorrow(void);
inline void ClearBorrowLifeHud(struct ObjectBase *object);
inline void ExpireHudEnemyHealthDelay(void);
inline void DrawGameOverMessage(void);

#include "data.h"
#include "kirby.h"
#include "main.h"
#include "sprite.h"
#include "level.h"
#include "task.h"
#include "constants/object_types.h"
#include "constants/songs.h"

#include "hud.h"
#include "palette_effects.h"
#include "functions.h"

extern struct Task *gGameplayHudTask;
extern const u16 gHudPalettes[][16];
extern const u32 gHudDecimalDivisors[8];
extern const u8 gUnk_082EC7A0[];
extern const u8 *gHudEnemyAndAreaNameGraphics[6];
extern const u8 *gHudGameOverAndDemoGraphics[6];

extern const u8 gUnk_082ECBA0[];
extern const u8 *gHudBorrowMessageGraphics[6];
extern const u8 *gHudGiveMessageGraphics[6];
extern const u8 *gHudConnectingMessageGraphics[6];
extern const u8 *gHudAnswerMessageGraphics[6];
extern const u8 *gHudBorrowLifePromptGraphics[6];
extern const u8 *gHudBorrowLifeChoiceGraphics[6];
extern const u16 gUnk_083513E8[56];
extern const u16 gUnk_08351458[27][4];
extern const u16 gUnk_08351628[4][4];
extern const u16 *gAbilityIconPalettes[32];
extern const u8 *gAbilityIconGraphics[6][32];
extern const u8 gOffscreenKirbyDirectionVariants[4];
extern const u8 gOtherRoomKirbyIconX[4];
bool16 sub_0803D938(struct ObjectBase *);
void DrawBorrowLifeNoCursor(void);
void DrawBorrowLifeYesCursor(void);

void DrawCallHudMessage(u8);
void DrawLifeSharingHudMessage(u8);
void UpdateTrackedHudEnemy(struct GameplayHud *);
void AnimateHudEnemyHealth(struct GameplayHud *);
void UpdateGameplayHud(void);
void HideKirbySpritesInOtherRooms(void);
void UpdateBorrowLifeHud(void);
void DrawOtherKirbyIndicators(struct GameplayHud *);
void DrawBorrowLifePrompt(void);
void DrawPhoneBattery(struct Kirby *);
void DrawKirbyHealthBar(struct Kirby *);

static inline bool32 ShouldShowKirbyCall(struct Kirby *kirby)
{
    bool32 show;
    u8 i;
    if (gUnk_02021580 >= gNumKirbys)
        return FALSE;
    if (!(gKirbys[gUnk_02021580].base.unkC & 0x10000) && gKirbys[gUnk_02021580].base.roomId == kirby->base.roomId)
        return FALSE;
    if (!(gRoomProps[kirby->base.roomId].priorityFlags & 0x10))
        return FALSE;
    show = TRUE;
    for (i = 1; i <= 8; i++) {
        if (gUnk_0835105C[i] == kirby->base.roomId && *GetStateSlot(STATE_SLOT_SESSION, i, 0)) {
            show = FALSE;
            break;
        }
    }
    for (i = 9; i <= 13; i++) {
        if (gUnk_0835105C[i] == kirby->base.roomId && *GetStateSlot(STATE_SLOT_SESSION, i + 3, 0)) {
            show = FALSE;
            break;
        }
    }
    return show;
}

static inline void DisplayCallingKirby(struct GameplayHud *hud)
{
    struct Sprite *sprite = &hud->unk20[0][gLocalPlayerId];
    sprite->tilesVram = gKirbys[gUnk_02021580].base.sprite.tilesVram + 0x100;
    sprite->palId = gUnk_02021580;
    sprite->unk1B = 0xFF;
    if (gUnk_0203AD20 & 8) {
        sprite->y = 0x91;
        sprite->unk8 |= 0x800;
    } else {
        sprite->y = 15;
        sprite->unk8 &= ~0x800;
    }
    sub_08155128(sprite);
    DisplaySprite(sprite);
}

// TODO: Task-data address formation and sprite initialization spill differently; the HUD/task subobject lifetime remains unresolved.
#ifndef NONMATCHING
NAKED void CreateGameplayHud(void)
{
    asm(".include \"asm/nonmatching/CreateGameplayHud.inc\"");
}
#else
void CreateGameplayHud(void)
{
    struct Task *task;
    struct GameplayHud *hud;
    struct Kirby *kirby;
    u8 i;
    gBgCntRegs[1] = 0x1C04;
    CpuFill16(0x184, BG_SCREEN_ADDR(28), 0x800);
    CpuFill16(0, (void *)(BG_VRAM + 0x7080), 0x600);
    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;
    task = TaskCreate(UpdateGameplayHud, sizeof(struct GameplayHud), 0xF500, 0, GameplayHudDestructor);
    gGameplayHudTask = task;
    hud = TaskGetStructPtr(task);
    CpuFill16(0, hud, sizeof(struct GameplayHud));
    kirby = &gKirbys[gLocalPlayerId];
    if (gUnk_0203AD10 & 0x10) {
        DrawDemoHud();
        task->main = HideKirbySpritesInOtherRooms;
        return;
    }
    LoadGameplayHudGraphics();
    LoadHudAbilityIcon(kirby->ability);
    DrawHudLivesLabel();
    DrawHudLivesCount(kirby);
    DrawKirbyHealthBar(kirby);
    DrawHudAbilityIconRows(2);
    DrawHudPhoneIcon();
    DrawPhoneBattery(kirby);
    DrawHudEnemyNameTiles();
    DrawEnemyHealthOrAreaName(NULL);
    CpuFill16(0, (void *)(BG_VRAM + 0x77A0), 0x100);
    hud->unk0 = kirby->score;
    hud->unk6 = kirby->hp;
    hud->unk7 = kirby->lives;
    hud->unkC = kirby->battery;
    hud->unkB = gRoomProps[kirby->base.roomId].priorityFlags & 8;
    hud->unk4 = 0x80;
    hud->unk9 = 0;
    hud->unkA = 0;
    hud->unkF = 0;
    hud->unk1C = NULL;
    hud->unkE = 0;
    hud->unk10 = 0;
    hud->unkD = 0;
    for (i = 0; i < gNumKirbys; i++) {
        struct Sprite *sprite;
        sprite = &hud->unk20[0][i];
        if (gLocalPlayerId == i) {
            SpriteInitNoFunc(sprite, 0, 0x80, 0x2DB, 1, 0, 0xFF, 0x10, 0, 8, 15, 0x40000);
        } else {
            SpriteInitNoFunc(sprite, gKirbys[i].base.sprite.tilesVram, 0x80, 0, 0, 0, 0xFF, 0x10,
                gKirbys[i].base.sprite.palId, 0, 0, 0x42000);
        }
        sprite = &hud->unk20[1][i];
        SpriteInitNoFunc(sprite, gKirbys[i].base.sprite.tilesVram + 0x80, 0x80, 0, 0, 0, 0xFF, 0x10,
            gKirbys[i].sprites[1].palId, 0, 0, 0x42000);
        sprite = &hud->unk20[2][i];
        SpriteInitNoFunc(sprite, gKirbys[i].sprites[0].tilesVram, 0x80, 0, 0, 0, 0xFF, 0x10, 15, 0, 0, 0x42000);
    }
}
#endif

void UpdateGameplayHud(void)
{
    void *taskData = TaskGetStructPtr(gCurTask);
    struct GameplayHud *hud = taskData;
    struct Kirby *kirby = &gKirbys[gLocalPlayerId];
    bool32 showCall;
    u8 i;
    if (hud->unk6 != kirby->hp)
        DrawKirbyHealthBar(kirby);
    if (hud->unk7 != kirby->lives)
        DrawHudLivesCount(kirby);
    if (gUnk_02021580 >= gNumKirbys)
        goto noCall;
    if (!(gKirbys[gUnk_02021580].base.unkC & 0x10000) && gKirbys[gUnk_02021580].base.roomId == kirby->base.roomId)
        goto noCall;
    if (!(gRoomProps[kirby->base.roomId].priorityFlags & 0x10))
        goto noCall;
    showCall = TRUE;
    for (i = 1; i <= 8; i++) {
        if (gUnk_0835105C[i] == kirby->base.roomId && *GetStateSlot(STATE_SLOT_SESSION, i, 0)) {
            showCall = FALSE;
            break;
        }
    }
    for (i = 9; i <= 13; i++) {
        if (gUnk_0835105C[i] == kirby->base.roomId && *GetStateSlot(STATE_SLOT_SESSION, i + 3, 0)) {
            showCall = FALSE;
            break;
        }
    }

    if (showCall) {
        u32 dead;
        PlaySfxAlt(&kirby->base, SE_08D5AF5C);
        dead = gKirbys[gUnk_02021580].base.unkC & 0x10000;
        if (!dead || kirby->lives != 0) {
            switch (hud->unkE) {
            case 0:
                if (dead)
                    DrawLifeSharingHudMessage(1);
                else
                    DrawCallHudMessage(1);
                break;
            case 0x60:
            case 0xE0:
                if (gKirbys[gUnk_02021580].base.unkC & 0x10000)
                    DrawLifeSharingHudMessage(0);
                else
                    DrawCallHudMessage(0);
                DrawHudPhoneIcon();
                DrawPhoneBattery(kirby);
                hud->unkD = 0;
                break;
            case 0x80:
                if (dead)
                    DrawLifeSharingHudMessage(2);
                else
                    DrawCallHudMessage(2);
                break;
            }
            if (hud->unkE <= 0x5F || (u8)(hud->unkE + 0x80) <= 0x5F)
                DisplayCallingKirby(hud);
        } else {
            DrawLifeSharingHudMessage(0);
            DrawHudPhoneIcon();
            DrawPhoneBattery(kirby);
            hud->unkD = 0;
        }
        hud->unkE++;
        hud->unk10 |= 1;
    } else {
    noCall:
        if (hud->unk10 & 1) {
            if (kirby->base.unk56 == gLocalPlayerId)
                m4aSongNumStop(SE_08D5AF5C);
            DrawCallHudMessage(0);
            DrawHudPhoneIcon();
            DrawPhoneBattery(kirby);
            hud->unkD = 0;
            hud->unkE = 0;
            hud->unk10 &= ~1;
        }
        if (hud->unkC != kirby->battery) {
            DrawPhoneBattery(kirby);
            hud->unkD = 0;
        } else if (hud->unkC == 1) {
            hud->unkD++;
            DrawPhoneBattery(kirby);
        }
        if (hud->unkB != (gRoomProps[kirby->base.roomId].priorityFlags & 8)) {
            if (gRoomProps[kirby->base.roomId].priorityFlags & 8)
                DrawHudPhoneIcon();
            else
                ClearHudPhoneIcon();
        }
    }
    if (hud->unk1C != NULL)
        UpdateTrackedHudEnemy(hud);
    AnimateHudEnemyHealth(hud);
    if (hud->unk4 <= 0x7D) {
        if (hud->unk4 == 8)
            DrawHudAbilityIconRows(2);
        if (hud->unk4 == 9)
            DrawHudAbilityIconRows(3);
        if (hud->unk4 == 10)
            DrawHudAbilityIconRows(4);
        if (hud->unk4 == 11)
            DrawHudAbilityIconRows(5);
        if (hud->unk4 == 12)
            DrawHudAbilityIconRows(6);
        if (hud->unk4 == 0x79)
            DrawHudAbilityIconRows(5);
        if (hud->unk4 == 0x7A)
            DrawHudAbilityIconRows(4);
        if (hud->unk4 == 0x7B)
            DrawHudAbilityIconRows(3);
        if (hud->unk4 == 0x7C)
            DrawHudAbilityIconRows(2);
        hud->unk4++;
    }
    hud->unk0 = kirby->score;
    hud->unk6 = kirby->hp;
    hud->unk7 = kirby->lives;
    hud->unkC = kirby->battery;
    hud->unkB = gRoomProps[kirby->base.roomId].priorityFlags & 8;
    DrawOtherKirbyIndicators(hud);
}

void HideKirbySpritesInOtherRooms(void)
{
    u8 i;
    for (i = 0; i < gNumKirbys; i++) {
        if (i != gLocalPlayerId) {
            struct Kirby *kirby = &gKirbys[i];
            if (gKirbys[gLocalPlayerId].base.roomId != kirby->base.roomId) {
                kirby->base.sprite.unk8 |= 0x80000;
                kirby->sprites[1].unk8 |= 0x80000;
                kirby->sprites[0].unk8 |= 0x80000;
            }
        }
    }
}

void UpdateBorrowLifeHud(void)
{
    void *taskData = TaskGetStructPtr(gCurTask);
    struct GameplayHud *hud = taskData;
    struct Kirby *kirby = &gKirbys[gLocalPlayerId];
    bool32 showCall;
    u8 i;
    if (kirby->base.roomId != 0x397) {
        if (kirby->unkD9)
            DrawBorrowLifeNoCursor();
        else
            DrawBorrowLifeYesCursor();
    }
    if (hud->unkC != kirby->battery)
        DrawPhoneBattery(kirby);
    if (gRoomProps[kirby->base.roomId].priorityFlags & 8)
        DrawHudPhoneIcon();
    else
        ClearHudPhoneIcon();
    DrawOtherKirbyIndicators(hud);
    hud->unkC = kirby->battery;
    hud->unkB = gRoomProps[kirby->base.roomId].priorityFlags & 8;
    if (gUnk_02021580 >= gNumKirbys)
        goto noCall;
    if (!(gKirbys[gUnk_02021580].base.unkC & 0x10000) && gKirbys[gUnk_02021580].base.roomId == kirby->base.roomId)
        goto noCall;
    if (!(gRoomProps[kirby->base.roomId].priorityFlags & 0x10))
        goto noCall;
    showCall = TRUE;
    for (i = 1; i <= 8; i++) {
        if (gUnk_0835105C[i] == kirby->base.roomId && *GetStateSlot(STATE_SLOT_SESSION, i, 0)) {
            showCall = FALSE;
            break;
        }
    }
    for (i = 9; i <= 13; i++) {
        if (gUnk_0835105C[i] == kirby->base.roomId && *GetStateSlot(STATE_SLOT_SESSION, i + 3, 0)) {
            showCall = FALSE;
            break;
        }
    }

    if (showCall) {
        PlaySfxAlt(&kirby->base, SE_08D5AF5C);
        hud->unkE++;
        hud->unk10 |= 1;
    } else {
    noCall:
        if (hud->unk10 & 1) {
            if (kirby->base.unk56 == gLocalPlayerId)
                m4aSongNumStop(SE_08D5AF5C);
            hud->unkE = 0;
            hud->unk10 &= ~1;
        }
    }
}

// TODO: The sprite-copy scratch and per-Kirby pointers occupy different stack slots; the original local aggregate layout remains unresolved.
#ifndef NONMATCHING
NAKED void DrawOtherKirbyIndicators(struct GameplayHud *hud)
{
    asm(".include \"asm/nonmatching/DrawOtherKirbyIndicators.inc\"");
}
#else
void DrawOtherKirbyIndicators(struct GameplayHud *hud)
{
    struct Sprite savedSprite;
    u8 i, indicator = 0;
    for (i = 0; i < gNumKirbys; i++) {
        struct Kirby *kirby;
        struct Sprite *body, *ability, *effect;
        if (i == gLocalPlayerId)
            continue;
        indicator++;
        kirby = &gKirbys[i];
        body = &hud->unk20[0][i];
        ability = &hud->unk20[1][i];
        effect = &hud->unk20[2][i];
        if (gKirbys[gLocalPlayerId].base.roomId != kirby->base.roomId) {
            kirby->base.sprite.unk8 &= ~0x80000;
            kirby->sprites[1].unk8 &= ~0x80000;
            kirby->sprites[0].unk8 &= ~0x80000;
            if (gUnk_0203AD20 & 8) {
                body->x = gOtherRoomKirbyIconX[indicator];
                body->y = 0x91;
                ability->x = body->x;
                ability->y = body->y;
                effect->x = body->x;
                effect->y = body->y - 6;
                body->unk8 |= 0x800;
                ability->unk8 |= 0x800;
                effect->unk8 |= 0x800;
            } else {
                body->x = gOtherRoomKirbyIconX[indicator];
                body->y = 15;
                ability->x = body->x;
                ability->y = body->y;
                effect->x = body->x;
                effect->y = body->y - 6;
                body->unk8 &= ~0x800;
                ability->unk8 &= ~0x800;
                effect->unk8 &= ~0x800;
            }
            if (hud->unk15[i] != 2) {
                ability->unk1B = 0xFF;
                body->unk1B = 0xFF;
                effect->animId = 0;
                effect->variant = 0;
                hud->unk15[i] = 2;
            }
            if (!(gRoomProps[kirby->base.roomId].priorityFlags & 8)) {
                body->animId = 0x2DB;
                body->variant = 0;
                ability->animId = 0;
                ability->variant = 0;
            } else {
                body->animId = gUnk_08350AAC[kirby->ability].animId;
                body->variant = gUnk_08350AAC[kirby->ability].variant;
                ability->animId = gUnk_08350B30[kirby->ability].animId;
                ability->variant = gUnk_08350B30[kirby->ability].variant;
            }
            if (kirby->base.unkC & 0x400) {
                effect->animId = 0x2B8;
                effect->variant = 0;
            }
            if (effect->animId != 0) {
                if (!sub_08155128(effect)) {
                    if (effect->variant == 0)
                        effect->variant = 1;
                    else {
                        effect->animId = 0;
                        effect->variant = 0;
                    }
                }
                if (!(gUnk_0203AD10 & 0x20) && effect->animId != 0)
                    DisplaySprite(effect);
            }
            if (ability->animId != 0) {
                sub_08155128(ability);
                if (!(gUnk_0203AD10 & 0x20))
                    DisplaySprite(ability);
            }
            sub_08155128(body);
            if (!(gUnk_0203AD10 & 0x20))
                DisplaySprite(body);
            kirby->base.sprite.unk8 |= 0x80000;
            kirby->sprites[1].unk8 |= 0x80000;
            kirby->sprites[0].unk8 |= 0x80000;
        } else if (!sub_0803D938(&kirby->base)) {
            if (hud->unk15[i]) {
                kirby->base.sprite.unk8 &= ~0x80000;
                kirby->sprites[1].unk8 &= ~0x80000;
                kirby->sprites[0].unk8 &= ~0x80000;
                effect->animId = 0;
                effect->variant = 0;
                CpuCopy32(&kirby->base.sprite, &savedSprite, sizeof(savedSprite));
                sub_0815521C(&savedSprite, kirby->base.header.unk1);
                CpuCopy32(&kirby->sprites[1], &savedSprite, sizeof(savedSprite));
                sub_0815521C(&savedSprite, kirby->base.header.unk1);
                hud->unk15[i] = 0;
            }
        } else {
            struct LevelInfo *level = &gCurLevelInfo[gLocalPlayerId];
            body->animId = 0x2DC;
            body->variant = 0;
            if (level->viewportPosition.x + 0x600 > kirby->base.x)
                body->x = 6;
            else if (level->viewportPosition.x + 0xE800 < kirby->base.x)
                body->x = 0xE8;
            else
                body->x = (kirby->base.x - level->viewportPosition.x) >> 8;
            if (level->viewportPosition.y + 0xA00 > kirby->base.y)
                body->y = 10;
            else if (level->viewportPosition.y + 0x8C00 < kirby->base.y)
                body->y = 0x8C;
            else
                body->y = (kirby->base.y - level->viewportPosition.y) >> 8;
            if (body->x <= 21) {
                if (body->y <= 25) {
                    body->variant = 3;
                    if (body->y < gOffscreenKirbyDirectionVariants[indicator] + 10)
                        body->y = gOffscreenKirbyDirectionVariants[indicator] + 10;
                } else if (body->y > 124) {
                    body->variant = 7;
                    if (body->y > 140 - gOffscreenKirbyDirectionVariants[indicator])
                        body->y = 140 - gOffscreenKirbyDirectionVariants[indicator];
                } else {
                    body->variant = 1;
                }
                body->x += gOffscreenKirbyDirectionVariants[indicator];
            } else if (body->x > 216) {
                if (body->y <= 25) {
                    body->variant = 2;
                    if (body->y < gOffscreenKirbyDirectionVariants[indicator] + 10)
                        body->y = gOffscreenKirbyDirectionVariants[indicator] + 10;
                } else if (body->y > 124) {
                    body->variant = 6;
                    if (body->y > 140 - gOffscreenKirbyDirectionVariants[indicator])
                        body->y = 140 - gOffscreenKirbyDirectionVariants[indicator];
                } else {
                    body->variant = 0;
                }
                body->x -= gOffscreenKirbyDirectionVariants[indicator];
            } else {
                if (body->y <= 25) {
                    body->variant = 4;
                    body->y += gOffscreenKirbyDirectionVariants[indicator];
                } else {
                    body->variant = 5;
                    body->y -= gOffscreenKirbyDirectionVariants[indicator];
                }
            }
            if (hud->unk15[i] != 1) {
                ability->unk1B = 0xFF;
                body->unk1B = 0xFF;
                effect->animId = 0;
                effect->variant = 0;
                hud->unk15[i] = 1;
            }
            if (!(gUnk_0203AD20 & 8))
                body->unk8 &= ~0x800;
            kirby->base.sprite.unk8 |= 0x80000;
            kirby->sprites[1].unk8 |= 0x80000;
            kirby->sprites[0].unk8 |= 0x80000;
            sub_08155128(body);
            if (!(gUnk_0203AD10 & 0x20) && kirby->hp > 0
                && (u16)(kirby->base.roomId - 0x394) > 3
                && kirby->base.roomId != 0x38D && kirby->base.roomId <= 0x3D3)
                DisplaySprite(body);
        }
    }
}
#endif

void DrawCallHudMessage(u8 message)
{
    u16 *tiles = BG_SCREEN_ADDR(28);
    u8 y, x;
    switch (message) {
    case 0:
    default:
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 14; x++)
                *tiles++ = 0xF184;
            tiles += 18;
        }
        break;
    case 1:
        CpuCopy16(gHudConnectingMessageGraphics[gLanguage], (void *)(BG_VRAM + 0x7C60), 0x3A0);
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 14; x++)
                *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
            tiles += 18;
        }
        break;
    case 2:
        CpuCopy16(gHudAnswerMessageGraphics[gLanguage], (void *)(BG_VRAM + 0x7C60), 0x3A0);
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 14; x++)
                *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
            tiles += 18;
        }
        break;
    }
}

void DrawLifeSharingHudMessage(u8 message)
{
    u16 *tiles = BG_SCREEN_ADDR(28);
    u8 y, x;
    switch (message) {
    case 0:
    default:
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 14; x++)
                *tiles++ = 0xF184;
            tiles += 18;
        }
        break;
    case 1:
        CpuCopy16(gHudBorrowMessageGraphics[gLanguage], (void *)(BG_VRAM + 0x7C60), 0x3A0);
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 14; x++)
                *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
            tiles += 18;
        }
        break;
    case 2:
        CpuCopy16(gHudGiveMessageGraphics[gLanguage], (void *)(BG_VRAM + 0x7C60), 0x3A0);
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 14; x++)
                *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
            tiles += 18;
        }
        break;
    }
}

void DrawBorrowLifePrompt(void)
{
    struct Kirby *kirby = &gKirbys[gLocalPlayerId];
    u16 *tiles = (u16 *)(BG_VRAM + 0xE190);
    u8 y, x;
    CpuCopy16(gHudBorrowLifePromptGraphics[gLanguage], (void *)(BG_VRAM + 0x70A0), 0x400);
    CpuCopy16(gHudBorrowLifeChoiceGraphics[gLanguage], (void *)(BG_VRAM + 0x7C60), 0x3A0);
    if (gKirbys[gLocalPlayerId].base.roomId != 0x397) {
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 16; x++)
                *tiles++ = (y * 16 + (x + 0x185)) | 0xF000;
            tiles += 16;
        }
        tiles = (u16 *)(BG_VRAM + 0xE294);
        for (y = 0; y < 2; y++) {
            for (x = 0; x < 6; x++)
                *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
            tiles += 26;
        }
        tiles = (u16 *)(BG_VRAM + 0xE354);
        for (y = 0; y < 2; y++) {
            for (x = 6; x < 12; x++)
                *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
            tiles += 26;
        }
        if (gKirbys[gLocalPlayerId].unkD9)
            DrawBorrowLifeNoCursor();
        else
            DrawBorrowLifeYesCursor();
    }
    if (gRoomProps[gKirbys[gLocalPlayerId].base.roomId].priorityFlags & 8)
        DrawHudPhoneIcon();
    else
        ClearHudPhoneIcon();
    DrawPhoneBattery(kirby);
}

void DrawBorrowLifeNoCursor(void)
{
    u16 *tiles = (u16 *)(BG_VRAM + 0xE350);
    u8 y, x;
    for (y = 0; y < 2; y++) {
        for (x = 12; x < 14; x++)
            *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
        tiles += 30;
    }
    tiles = (u16 *)(BG_VRAM + 0xE290);
    for (y = 0; y < 2; y++) {
        for (x = 12; x < 14; x++)
            *tiles++ = 0xF184;
        tiles += 30;
    }
}

void DrawBorrowLifeYesCursor(void)
{
    u16 *tiles = (u16 *)(BG_VRAM + 0xE290);
    u8 y, x;
    for (y = 0; y < 2; y++) {
        for (x = 12; x < 14; x++)
            *tiles++ = (y * 15 + (x + 0x1E3)) | 0xF000;
        tiles += 30;
    }
    tiles = (u16 *)(BG_VRAM + 0xE350);
    for (y = 0; y < 2; y++) {
        for (x = 12; x < 14; x++)
            *tiles++ = 0xF184;
        tiles += 30;
    }
}

// TODO: The row offset uses a different register and constant materialization; signed/unsigned row variants did not recover the original lifetime.
#ifndef NONMATCHING
NAKED void DrawHudAbilityIconRows(u8 rows)
{
    asm(".include \"asm/nonmatching/DrawHudAbilityIconRows.inc\"");
}
#else
void DrawHudAbilityIconRows(u8 rows)
{
    struct GameplayHud *hud;
    u16 *tiles;
    u16 y;
    if (!(gUnk_0203AD10 & 0x10)) {
        hud = TaskGetStructPtr(gGameplayHudTask);
        hud->unk14 = rows;
        tiles = (u16 *)(BG_VRAM + 0xE380);
        for (y = 0; y < 6 - rows; y++) {
            *tiles++ = 0x184;
            *tiles++ = 0x184;
            *tiles++ = 0x184;
            *tiles++ = 0x184;
            *tiles = 0x184;
            tiles += 28;
        }
        for (y = 0; y < rows; y++) {
            *tiles++ = (y * 5 + 0x1C5) | 0xE000;
            *tiles++ = (y * 5 + 0x1C6) | 0xE000;
            *tiles++ = (y * 5 + 0x1C7) | 0xE000;
            *tiles++ = (y * 5 + 0x1C8) | 0xE000;
            *tiles = (y * 5 + 0x1C9) | 0xE000;
            tiles += 28;
        }
    }
}
#endif

void DrawPhoneBattery(struct Kirby *kirby)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    s16 left, right;
    u16 *tiles = (u16 *)(BG_VRAM + 0xE004);
    switch (kirby->battery) {
    case 0:
        left = 0x30;
        right = 0x31;
        break;
    case 1:
        if (hud->unkD & 0x20) {
            left = 0x35;
            right = 0x37;
        } else {
            left = 0x35;
            right = 0x36;
        }
        break;
    case 2:
        left = 0x34;
        right = 0x33;
        break;
    default:
        left = 0x32;
        right = 0x33;
        break;
    }
    *tiles++ = (0x185 + left) | 0xF000;
    *tiles = (0x185 + right) | 0xF000;
    tiles += 31;
    *tiles++ = (0x185 + left) | 0xF800;
    *tiles = (0x185 + right) | 0xF800;
}

// TODO: The HUD/task pointer and scaled health use different registers; the selection branches and health-scaling temporary still differ.
#ifndef NONMATCHING
NAKED struct GameplayHud *TryTrackHudEnemy(struct Object *object)
{
    asm(".include \"asm/nonmatching/TryTrackHudEnemy.inc\"");
}
#else
struct GameplayHud *TryTrackHudEnemy(struct Object *object)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    // These are comparisons against the calling task, as in the original.
    if (!(gUnk_0203AD10 & 0x10) && gCurTask->main != UpdateGameOverHudIndicators
        && gCurTask->main != UpdateBorrowLifeHud && object->type <= 0x5D
        && gKirbys[gLocalPlayerId].base.roomId == object->base.roomId && hud->unk1C != object) {
        // TODO: The original dereferences object before this null branch; preserve that ordering.
        if (object == NULL) {
            hud->unk1C = object;
            DrawEnemyHealthOrAreaName(NULL);
        } else if (object->unk80 > 0 && !(object->base.flags & 0x1000)) {
            s16 scaledHp;
            hud->unk1C = object;
            CpuCopy16(gHudEnemyAndAreaNameGraphics[gLanguage] + object->type * 0x100, (void *)(BG_VRAM + 0x77A0), 0x100);
            hud->unkF = 0;
            object = hud->unk1C;
            if ((u8)(object->type - 0x38) <= 0x1A) {
                if (object->type == OBJ_DARK_MIND_FORM_1)
                    scaledHp = (u16)(object->unk80 * gUnk_08351628[object->subtype][gNumHumanPlayers - 1]);
                else
                    scaledHp = (u16)(object->unk80 * gUnk_08351458[object->type - 0x38][gNumHumanPlayers - 1]);
            } else {
                // TODO: Types 0x53-0x5D can index beyond the original 56-entry scale table.
                scaledHp = gUnk_083513E8[object->type] * object->unk80;
            }
            hud->unkA = scaledHp >> 8;
            if (scaledHp & 0xFF)
                hud->unkA++;
            hud->unk9 = hud->unkA;
            DrawEnemyHealthOrAreaName(hud);
            return hud;
        }
    }
    return NULL;
}
#endif

void DrawEnemyHealthOrAreaName(struct GameplayHud *hud)
{
    u16 *tiles;
    if (gUnk_0203AD10 & 0x10)
        return;
    if (gGameplayHudTask->main == UpdateGameOverHudIndicators || gGameplayHudTask->main == UpdateBorrowLifeHud)
        return;
    tiles = (u16 *)(BG_VRAM + 0xE4E8);
    if (hud == NULL) {
        u16 baseTile;
        CpuCopy16(gHudEnemyAndAreaNameGraphics[gLanguage] + (gUnk_08D6CD0C[gKirbys[gLocalPlayerId].base.roomId]->unk46 * 0x200 + 0x5300),
            (void *)(BG_VRAM + 0x77A0), 0x100);
        CpuCopy16(gHudEnemyAndAreaNameGraphics[gLanguage] + (gUnk_08D6CD0C[gKirbys[gLocalPlayerId].base.roomId]->unk46 * 0x200 + 0x5400),
            (void *)(BG_VRAM + 0x74A0), 0x100);
        *tiles++ = 0xF184;
        *tiles++ = 0xF184;
        // TODO(match): Remove this input when the base tile is loaded into r2 before copying it to r1.
        asm("" : : "r"((u16)0x185));
        baseTile = 0x185;
        *tiles++ = (baseTile + 0x20) | 0xF000;
        *tiles++ = (baseTile + 0x21) | 0xF000;
        *tiles++ = (baseTile + 0x22) | 0xF000;
        *tiles++ = (baseTile + 0x23) | 0xF000;
        *tiles++ = (baseTile + 0x24) | 0xF000;
        *tiles++ = (baseTile + 0x25) | 0xF000;
        *tiles++ = (baseTile + 0x26) | 0xF000;
        *tiles = (baseTile + 0x27) | 0xF000;
    } else {
        s16 hp;
        u16 cells;
        CpuCopy16(gUnk_082ECBA0, (void *)(BG_VRAM + 0x74A0), 0x100);
        *tiles++ = 0xF1A5;
        hp = (s8)hud->unk9;
        cells = 8;
        do {
            if (hp & 0xF8) {
                *tiles++ = 0xF1A7;
                hp -= 8;
            } else if (hp & 7) {
                *tiles++ = (0x1AF - hp) | 0xF000;
                hp = 0;
            } else {
                *tiles++ = 0xF1AF;
            }
        } while (--cells);
        *tiles = 0xF1A6;
    }
}

void DrawKirbyHealthBar(struct Kirby *kirby)
{
    s8 capacity, hp;
    u16 i;
    s8 cells;
    if (gUnk_0203AD10 & 0x10)
        return;
    capacity = kirby->maxHp;
    // TODO(match): Remove this input when natural lifetimes keep capacity in r4 and the column offset in r5.
    asm("" : : "r"(capacity));
    hp = kirby->hp;
    if (hp < 0)
        hp = 0;
    cells = (capacity >> 1) + (capacity & 1);
    for (i = 0; i < cells; i++) {
        u32 column = i + 13;
        u16 *tiles = (u16 *)(BG_VRAM + 0xE480);
        tiles += column;
        if (hp & 0xFE) {
            *tiles = 0xF192;
            tiles = (u16 *)(BG_VRAM + 0xE4C0);
            tiles += column;
            *tiles = 0xF1A2;
            hp -= 2;
            capacity -= 2;
            continue;
        } else if (hp & 1) {
            if (!(capacity & 0xFE) && (capacity & 1)) {
                *tiles = 0xF1B2;
                tiles = (u16 *)(BG_VRAM + 0xE4C0);
                tiles += column;
                *tiles = 0xF1A4;
            } else {
                *tiles = 0xF193;
                tiles += 32;
                *tiles = 0xF1A3;
            }
            hp--;
        } else {
            if (!(capacity & 0xFE) && (capacity & 1)) {
                *tiles = 0xF9B4;
                tiles = (u16 *)(BG_VRAM + 0xE4C0);
                tiles += column;
                *tiles = 0xF1B4;
            } else {
                *tiles = 0xF194;
                tiles += 32;
                *tiles = 0xF994;
            }
        }
        capacity -= 2;
    }
    if (!(kirby->maxHp & 1)) {
        u32 column = i + 13;
        u16 *tiles = (u16 *)(BG_VRAM + 0xE480);
        tiles += column;
        *tiles = 0xF9B3;
        tiles = (u16 *)(BG_VRAM + 0xE4C0);
        tiles += column;
        *tiles = 0xF1B3;
    }
}

// TODO: Health scaling and offscreen checks spill differently; the original shared scaling helper/source form remains unresolved.
#ifndef NONMATCHING
NAKED void UpdateTrackedHudEnemy(struct GameplayHud *hud)
{
    asm(".include \"asm/nonmatching/UpdateTrackedHudEnemy.inc\"");
}
#else
void UpdateTrackedHudEnemy(struct GameplayHud *hud)
{
    struct Object *object = hud->unk1C;
    struct Kirby *kirby;
    if (object->unk80 <= 0) {
        hud->unkA = 0;
    } else {
        s16 scaledHp;
        if ((u8)(object->type - 0x38) <= 0x1A) {
            if (object->type == OBJ_DARK_MIND_FORM_1)
                scaledHp = (u16)(object->unk80 * gUnk_08351628[object->subtype][gNumHumanPlayers - 1]);
            else
                scaledHp = (u16)(object->unk80 * gUnk_08351458[object->type - 0x38][gNumHumanPlayers - 1]);
        } else {
            // TODO: Types 0x53-0x5D can index beyond the original 56-entry scale table.
            scaledHp = gUnk_083513E8[object->type] * object->unk80;
        }
        hud->unkA = scaledHp >> 8;
        if (scaledHp & 0xFF)
            hud->unkA++;
    }
    object = hud->unk1C;
    if (object->base.flags & 0x1000) {
        if (object->unk80 <= 0) {
            hud->unkA = 0;
        } else {
            CpuFill16(0, (void *)(BG_VRAM + 0x77A0), 0x100);
            hud->unk9 = 0;
            hud->unkA = 0;
            DrawEnemyHealthOrAreaName(NULL);
        }
        hud->unk1C = NULL;
        return;
    }
    kirby = &gKirbys[gLocalPlayerId];
    if (kirby->base.roomId != object->base.roomId || kirby->hp <= 0 || (gUnk_0203AD10 & 0x20)) {
        CpuFill16(0, (void *)(BG_VRAM + 0x77A0), 0x100);
        hud->unk9 = 0;
        hud->unkA = 0;
        DrawEnemyHealthOrAreaName(NULL);
        hud->unk1C = NULL;
        return;
    }
    if ((u8)(object->type - 0x38) <= 0x1A) {
        if (abs(gCurLevelInfo[gLocalPlayerId].viewportPosition.x - (object->base.x - 0x7800)) <= 0xF000
            && abs(gCurLevelInfo[gLocalPlayerId].viewportPosition.y - (object->base.y - 0x5000)) <= 0xC800)
            return;
    } else {
        if (abs(gCurLevelInfo[gLocalPlayerId].viewportPosition.x - (object->base.x - 0x7800)) <= 0xA800
            && abs(gCurLevelInfo[gLocalPlayerId].viewportPosition.y - (object->base.y - 0x5000)) <= 0x8000)
            return;
    }
    CpuFill16(0, (void *)(BG_VRAM + 0x77A0), 0x100);
    hud->unk9 = 0;
    hud->unkA = 0;
    DrawEnemyHealthOrAreaName(NULL);
    hud->unk1C = NULL;
}
#endif

void AnimateHudEnemyHealth(struct GameplayHud *hud)
{
    if (hud->unkF != 0) {
        u32 paused = gUnk_03000510.unk4 & ((1 << gLocalPlayerId) | 0x10);
        if (!paused) {
            if (++hud->unkF > 48) {
                CpuFill16(0, (void *)(BG_VRAM + 0x77A0), 0x100);
                hud->unkF = 0;
                DrawEnemyHealthOrAreaName(NULL);
                hud->unk1C = NULL;
            }
        }
    }
    if ((s8)hud->unk9 != (s8)hud->unkA) {
        if ((s8)hud->unk9 > (s8)hud->unkA) {
            s32 step = ((s8)hud->unk9 - (s8)hud->unkA) >> 3;
            if (step)
                hud->unk9 -= step;
            else
                hud->unk9--;
            if ((s8)hud->unk9 <= 0) {
                hud->unk9 = 0;
                hud->unkF = 1;
            }
        } else if ((s8)hud->unk9 < (s8)hud->unkA && (gUnk_0203AD40 & 7)) {
            struct Kirby *kirby;
            hud->unk9++;
            kirby = gKirbys;
            kirby += gLocalPlayerId;
            PlaySfxInternal(&kirby->base, SE_08D5AD9C);
        }
        DrawEnemyHealthOrAreaName(hud);
    }
}

void LoadAbilityIconGraphicsAndPalette(u32 tilesVram, u8 paletteId, u8 ability)
{
    LoadBgPaletteAndBase(gAbilityIconPalettes[ability], paletteId * 16, 16);
    gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE;
    if (ability > 27) {
        gUnk_03002EC0[gUnk_030039A4].unk0 = (u32)gAbilityIconGraphics[gLanguage][ability];
        gUnk_03002EC0[gUnk_030039A4].unk4 = tilesVram;
        gUnk_03002EC0[gUnk_030039A4].unk8 = 0x140;
    } else {
        gUnk_03002EC0[gUnk_030039A4].unk0 = (u32)gAbilityIconGraphics[gLanguage][ability];
        gUnk_03002EC0[gUnk_030039A4].unk4 = tilesVram;
        gUnk_03002EC0[gUnk_030039A4].unk8 = 0x3C0;
    }
    gUnk_030039A4 = (gUnk_030039A4 + 1) & 0x3F;
}

inline void LoadHudAbilityIcon(u8 ability)
{
    LoadAbilityIconGraphicsAndPalette(BG_VRAM + 0x78A0, 0xE, ability);
}

inline void StartHudAbilityIconExpansion(struct ObjectBase *object)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    u32 mode = gUnk_0203AD10 & 0x10;
    if (!mode && object->unk56 == gLocalPlayerId) {
        hud->unk4 = mode;
        DrawHudAbilityIconRows(2);
    }
}

inline void HoldExpandedHudAbilityIcon(struct ObjectBase *object)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    if (!(gUnk_0203AD10 & 0x10) && object->unk56 == gLocalPlayerId) {
        hud->unk4 = 0x80;
        DrawHudAbilityIconRows(6);
    }
}

inline void ScheduleHudAbilityIconCollapse(struct ObjectBase *object)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    if (!(gUnk_0203AD10 & 0x10) && object->unk56 == gLocalPlayerId)
        hud->unk4 = 0xC;
}

inline void RequestHudAbilityIconCollapse(struct ObjectBase *object)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    if (!(gUnk_0203AD10 & 0x10) && object->unk56 == gLocalPlayerId)
        hud->unk4 = 0x7C;
}

inline void UpdateGameOverHudIndicators(void)
{
    struct GameplayHud *hud = TaskGetStructPtr(gCurTask);
    DrawOtherKirbyIndicators(hud);
}

inline void GameplayHudDestructor(struct Task *task UNUSED)
{
}

inline void LoadGameplayHudGraphics(void)
{
    u8 color = gKirbys[gLocalPlayerId].color;
    u8 *tiles = (u8 *)(BG_VRAM + 0x70A0);
    LoadBgPaletteAndBase(gHudPalettes[color], 0xF0, 16);
    CpuCopy16(gUnk_082EC7A0, tiles, 0x700);
    tiles += 0x700;
    CpuCopy16(gHudEnemyAndAreaNameGraphics[gLanguage], tiles, 0x100);
}

inline void DrawHudLivesLabel(void)
{
    u16 *tiles = (u16 *)(BG_VRAM + 0xE48E);
    *tiles++ = 0xF18F;
    *tiles++ = 0xF190;
    *tiles = 0xF191;
    tiles += 30;
    *tiles++ = 0xF19F;
    *tiles++ = 0xF59F;
    *tiles = 0xF1A1;
}

inline void DrawHudLivesCount(struct Kirby *kirby)
{
    u8 lives = kirby->lives;
    u16 i;
    if (lives > 99)
        lives = 99;
    for (i = 0; i < 2; i++) {
        u32 column = i + 10;
        u16 *tiles = (u16 *)(BG_VRAM + 0xE480);
        u32 divisor;
        u32 quotient;
        u16 digit;
        tiles += column;
        divisor = gHudDecimalDivisors[i + 6];
        quotient = lives / divisor;
        digit = quotient;
        lives -= divisor * quotient;
        *tiles = (digit + 0x185) | 0xF000;
        tiles = (u16 *)(BG_VRAM + 0xE4C0);
        tiles += column;
        *tiles = (digit + 0x195) | 0xF000;
    }
}

inline void DrawDemoHud(void)
{
    u8 color = gKirbys[gLocalPlayerId].color;
    u16 *tiles = (u16 *)(BG_VRAM + 0xE198);
    u8 i;
    LoadBgPaletteAndBase(gHudPalettes[color], 0xF0, 16);
    CpuCopy16(gHudGameOverAndDemoGraphics[gLanguage], (void *)(BG_VRAM + 0x70A0), 0x800);
    for (i = 0; i < 6; i++)
        *tiles++ = (i + 0x1B5) | 0xF000;
}

inline void DrawHudPhoneIcon(void)
{
    u16 *tiles = (u16 *)(BG_VRAM + 0xE002);
    tiles[0] = 0xF1B0;
    tiles[32] = 0xF1B1;
}

inline void ClearHudPhoneIcon(void)
{
    u16 *tiles = (u16 *)(BG_VRAM + 0xE002);
    tiles[0] = 0xF184;
    tiles[32] = 0xF184;
}

inline void DrawHudEnemyNameTiles(void)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        u16 *tiles = (u16 *)(BG_VRAM + 0xE4AA);
        u16 i;
        for (i = 0; i < 8; i++)
            *tiles++ = (i + 0x1BD) | 0xF000;
    }
}

inline void ShowGameOverHud(void)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        CpuFill16(0x184, BG_SCREEN_ADDR(28), 0x500);
        DrawGameOverMessage();
        gGameplayHudTask->main = UpdateGameOverHudIndicators;
    }
}

inline void ShowBorrowLifeHud(void)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        CpuFill16(0x184, BG_SCREEN_ADDR(28), 0x500);
        DrawBorrowLifePrompt();
        gGameplayHudTask->main = UpdateBorrowLifeHud;
    }
}

inline void RestoreHudAfterLifeBorrow(void)
{
    if (!(gUnk_0203AD10 & 0x10) && gGameplayHudTask->main == UpdateBorrowLifeHud) {
        CpuFill16(0x184, BG_SCREEN_ADDR(28), 0x500);
        gGameplayHudTask->main = UpdateGameplayHud;
        RefreshGameplayHud(&gKirbys[gLocalPlayerId]);
    }
}

inline void ClearBorrowLifeHud(struct ObjectBase *object UNUSED)
{
    if (!(gUnk_0203AD10 & 0x10) && gGameplayHudTask->main == UpdateBorrowLifeHud) {
        CpuFill16(0x184, BG_SCREEN_ADDR(28), 0x500);
        DrawPhoneBattery(&gKirbys[gLocalPlayerId]);
    }
}

inline void ExpireHudEnemyHealthDelay(void)
{
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    if (hud != NULL && hud->unkF != 0)
        hud->unkF = 0x31;
}

inline void DrawGameOverMessage(void)
{
    u16 *tiles = (u16 *)(BG_VRAM + 0xE18E);
    u8 y, x;
    CpuCopy16(gHudGameOverAndDemoGraphics[gLanguage], (void *)(BG_VRAM + 0x70A0), 0x800);
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 16; x++)
            *tiles++ = (y * 16 + (x + 0x185)) | 0xF000;
        tiles += 16;
    }
}

// TODO: The inline HUD helpers produce different spills in the rebuild path; their original local lifetimes remain unresolved.
#ifndef NONMATCHING
NAKED void RefreshGameplayHud(struct Kirby *kirby)
{
    asm(".include \"asm/nonmatching/RefreshGameplayHud.inc\"");
}
#else
void RefreshGameplayHud(struct Kirby *kirby)
{
    u8 color = gKirbys[gLocalPlayerId].color;
    struct GameplayHud *hud = TaskGetStructPtr(gGameplayHudTask);
    CpuFill16(0x184, BG_SCREEN_ADDR(28), 0x500);
    if (gUnk_0203AD10 & 0x10) {
        DrawDemoHud();
        return;
    }
    LoadBgPaletteAndBase(gHudPalettes[color], 0xF0, 16);
    if (gGameplayHudTask->main == UpdateGameOverHudIndicators) {
        DrawGameOverMessage();
        return;
    }
    LoadGameplayHudGraphics();
    if (gGameplayHudTask->main == UpdateBorrowLifeHud) {
        DrawBorrowLifePrompt();
        return;
    }
    if (gKirbys[gLocalPlayerId].unkDB)
        LoadHudAbilityIcon(gKirbys[gLocalPlayerId].unkDB);
    else
        LoadHudAbilityIcon(gKirbys[gLocalPlayerId].ability);
    DrawHudLivesLabel();
    DrawHudLivesCount(&gKirbys[gLocalPlayerId]);
    DrawKirbyHealthBar(&gKirbys[gLocalPlayerId]);
    DrawHudAbilityIconRows(hud->unk14);
    if (gRoomProps[gKirbys[gLocalPlayerId].base.roomId].priorityFlags & 8)
        DrawHudPhoneIcon();
    else
        ClearHudPhoneIcon();
    DrawPhoneBattery(&gKirbys[gLocalPlayerId]);
    DrawHudEnemyNameTiles();
    if (hud->unk1C != NULL) {
        CpuCopy16(gHudEnemyAndAreaNameGraphics[gLanguage] + hud->unk1C->type * 0x100, (void *)(BG_VRAM + 0x77A0), 0x100);
        DrawEnemyHealthOrAreaName(hud);
    } else {
        CpuFill16(0, (void *)(BG_VRAM + 0x77A0), 0x100);
        DrawEnemyHealthOrAreaName(NULL);
    }
    if (!ShouldShowKirbyCall(kirby))
        return;
    if ((gKirbys[gUnk_02021580].base.unkC & 0x10000) && kirby->lives == 0) {
    } else {
        if (hud->unkE <= 0x5F) {
            if (gKirbys[gUnk_02021580].base.unkC & 0x10000)
                DrawLifeSharingHudMessage(1);
            else
                DrawCallHudMessage(1);
        } else if ((u8)(hud->unkE + 0x80) <= 0x5F) {
            if (gKirbys[gUnk_02021580].base.unkC & 0x10000)
                DrawLifeSharingHudMessage(2);
            else
                DrawCallHudMessage(2);
        } else {
            if (gKirbys[gUnk_02021580].base.unkC & 0x10000)
                DrawLifeSharingHudMessage(0);
            else
                DrawCallHudMessage(0);
            DrawHudPhoneIcon();
            DrawPhoneBattery(kirby);
            hud->unkD = 0;
        }
        if (hud->unkE <= 0x5F || (u8)(hud->unkE + 0x80) <= 0x5F) {
            DisplayCallingKirby(hud);
        } else {
            if (gKirbys[gUnk_02021580].base.unkC & 0x10000)
                DrawLifeSharingHudMessage(0);
            else
                DrawCallHudMessage(0);
            DrawHudPhoneIcon();
            DrawPhoneBattery(kirby);
            hud->unkD = 0;
        }
    }
    hud->unk10 |= 1;
}
#endif

const u16 gHudPalettes[18][16] = {
    { 0xA1C0, 0x729F, 0xE5BF, 0xCD3F, 0x001F, 0x1011, 0x90AE, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x1BFF, 0x8EFF, 0x021F, 0x815F, 0x8111, 0x808C, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x011F, 0x00BA, 0x0094, 0x601B, 0x000C, 0x0007, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x832E, 0x02AB, 0x8208, 0x015F, 0x0166, 0x0100, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0xFFFF, 0x5EF7, 0xCA52, 0x313F, 0x39CE, 0x294A, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0xC631, 0xB5AD, 0xAD6B, 0x01FF, 0xA108, 0x1CE7, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0xFF71, 0x7EED, 0x7E6A, 0x6D09, 0x7DE5, 0x6182, 0x0000, 0xFFFF, 0x035F, 0xFFF4, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0xF66F, 0xEE0C, 0x65CA, 0x4808, 0x5940, 0xCCE0, 0x0000, 0xFFFF, 0x035F, 0xFFF4, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x7E76, 0xFDD4, 0x7D51, 0x3492, 0x682E, 0xCCAC, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0xDFEE, 0x4B47, 0x3680, 0x91FB, 0x3200, 0x29A0, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x8EDF, 0x0E7F, 0x11FF, 0x00D8, 0x015F, 0x005A, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x321A, 0x29B7, 0xA153, 0x0450, 0x98F0, 0x10AD, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0x6E5F, 0x61FF, 0x519E, 0x2A06, 0xB8DB, 0x1C53, 0x0000, 0xFFFF, 0x035F, 0xFF4D, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0xA1C0, 0xEF7B, 0x5EF7, 0x4E73, 0xAD6B, 0xB9CE, 0xA94A, 0x0000, 0xFFFF, 0x035F, 0x7BDE, 0x825F, 0x01DF, 0x5000, 0x035F, 0xCA52 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};
const u32 gHudDecimalDivisors[8] = {
    10000000, 1000000, 100000, 10000, 1000, 100, 10, 1,
};
const u8 gOffscreenKirbyDirectionVariants[4] = {
    0, 4, 8, 12,
};
const u8 gOtherRoomKirbyIconX[4] = {
    24, 40, 56, 72,
};

extern const u8 gUnk_082ECFA0[];
extern const u8 gUnk_082F38A0[];
extern const u8 gUnk_082FA1A0[];
extern const u8 gUnk_08300AA0[];
extern const u8 gUnk_083073A0[];
extern const u8 gUnk_0830DCA0[];
extern const u16 gUnk_083145A0[];
extern const u8 gUnk_083145C0[];
extern const u16 gUnk_08314980[];
extern const u8 gUnk_083149A0[];
extern const u16 gUnk_08314D60[];
extern const u8 gUnk_08314D80[];
extern const u16 gUnk_08315140[];
extern const u8 gUnk_08315160[];
extern const u16 gUnk_08315520[];
extern const u8 gUnk_08315540[];
extern const u16 gUnk_08315900[];
extern const u8 gUnk_08315920[];
extern const u16 gUnk_08315CE0[];
extern const u8 gUnk_08315D00[];
extern const u16 gUnk_083160C0[];
extern const u8 gUnk_083160E0[];
extern const u16 gUnk_083164A0[];
extern const u8 gUnk_083164C0[];
extern const u16 gUnk_08316880[];
extern const u8 gUnk_083168A0[];
extern const u16 gUnk_08316C60[];
extern const u8 gUnk_08316C80[];
extern const u16 gUnk_08317040[];
extern const u8 gUnk_08317060[];
extern const u16 gUnk_08317420[];
extern const u8 gUnk_08317440[];
extern const u16 gUnk_08317800[];
extern const u8 gUnk_08317820[];
extern const u16 gUnk_08317BE0[];
extern const u8 gUnk_08317C00[];
extern const u16 gUnk_08317FC0[];
extern const u8 gUnk_08317FE0[];
extern const u16 gUnk_083183A0[];
extern const u8 gUnk_083183C0[];
extern const u16 gUnk_08318780[];
extern const u8 gUnk_083187A0[];
extern const u16 gUnk_08318B60[];
extern const u8 gUnk_08318B80[];
extern const u16 gUnk_08318F40[];
extern const u8 gUnk_08318F60[];
extern const u16 gUnk_08319320[];
extern const u8 gUnk_08319340[];
extern const u16 gUnk_08319700[];
extern const u8 gUnk_08319720[];
extern const u16 gUnk_08319AE0[];
extern const u8 gUnk_08319B00[];
extern const u16 gUnk_08319EC0[];
extern const u8 gUnk_08319EE0[];
extern const u16 gUnk_0831A2A0[];
extern const u8 gUnk_0831A2C0[];
extern const u16 gUnk_0831A680[];
extern const u8 gUnk_0831A6A0[];
extern const u16 gUnk_0831AA60[];
extern const u8 gUnk_0831AA80[];
extern const u16 gUnk_0831AE40[];
extern const u8 gUnk_0831AE60[];
extern const u16 gUnk_0831B220[];
extern const u8 gUnk_0831B240[];
extern const u16 gUnk_0831B600[];
extern const u8 gUnk_0831B620[];
extern const u16 gUnk_0831B9E0[];
extern const u8 gUnk_0831BA00[];
extern const u16 gUnk_0831BDC0[];
extern const u8 gUnk_0831BDE0[];
extern const u8 gUnk_0831C1A0[];
extern const u8 gUnk_0831C560[];
extern const u8 gUnk_0831C920[];
extern const u8 gUnk_0831CCE0[];
extern const u8 gUnk_0831D0A0[];
extern const u8 gUnk_0831D460[];
extern const u8 gUnk_0831D820[];
extern const u8 gUnk_0831DBE0[];
extern const u8 gUnk_0831DFA0[];
extern const u8 gUnk_0831E360[];
extern const u8 gUnk_0831E720[];
extern const u8 gUnk_0831EAE0[];
extern const u8 gUnk_0831EEA0[];
extern const u8 gUnk_0831F260[];
extern const u8 gUnk_0831F620[];
extern const u8 gUnk_0831F9E0[];
extern const u8 gUnk_0831FDA0[];
extern const u8 gUnk_08320160[];
extern const u8 gUnk_08320520[];
extern const u8 gUnk_083208E0[];
extern const u8 gUnk_08320CA0[];
extern const u8 gUnk_08321060[];
extern const u8 gUnk_08321420[];
extern const u8 gUnk_083217E0[];
extern const u8 gUnk_08321BA0[];
extern const u8 gUnk_08321F60[];
extern const u8 gUnk_08322320[];
extern const u8 gUnk_083226E0[];
extern const u8 gUnk_08322AA0[];
extern const u8 gUnk_083235E0[];
extern const u8 gUnk_083239A0[];
extern const u8 gUnk_08323D60[];
extern const u8 gUnk_08324120[];
extern const u8 gUnk_083244E0[];
extern const u8 gUnk_083248A0[];
extern const u8 gUnk_08324C60[];
extern const u8 gUnk_08325020[];
extern const u8 gUnk_083253E0[];
extern const u8 gUnk_083257A0[];
extern const u8 gUnk_08325B60[];
extern const u8 gUnk_08325F20[];
extern const u8 gUnk_083262E0[];
extern const u8 gUnk_083266A0[];
extern const u8 gUnk_08326A60[];
extern const u8 gUnk_08326E20[];
extern const u8 gUnk_083271E0[];
extern const u8 gUnk_083275A0[];
extern const u8 gUnk_08327960[];
extern const u8 gUnk_08327D20[];
extern const u8 gUnk_083280E0[];
extern const u8 gUnk_083284A0[];
extern const u8 gUnk_08328860[];
extern const u8 gUnk_08328C20[];
extern const u8 gUnk_08328FE0[];
extern const u8 gUnk_083293A0[];
extern const u8 gUnk_08329760[];
extern const u8 gUnk_08329B20[];
extern const u8 gUnk_08329EE0[];
extern const u8 gUnk_0832AA20[];
extern const u8 gUnk_0832ADE0[];
extern const u8 gUnk_0832B1A0[];
extern const u8 gUnk_0832B560[];
extern const u8 gUnk_0832B920[];
extern const u8 gUnk_0832BCE0[];
extern const u8 gUnk_0832C0A0[];
extern const u8 gUnk_0832C460[];
extern const u8 gUnk_0832C820[];
extern const u8 gUnk_0832CBE0[];
extern const u8 gUnk_0832CFA0[];
extern const u8 gUnk_0832D360[];
extern const u8 gUnk_0832D720[];
extern const u8 gUnk_0832DAE0[];
extern const u8 gUnk_0832DEA0[];
extern const u8 gUnk_0832E260[];
extern const u8 gUnk_0832E620[];
extern const u8 gUnk_0832E9E0[];
extern const u8 gUnk_0832EDA0[];
extern const u8 gUnk_0832F160[];
extern const u8 gUnk_0832F520[];
extern const u8 gUnk_0832F8E0[];
extern const u8 gUnk_0832FCA0[];
extern const u8 gUnk_08330060[];
extern const u8 gUnk_08330420[];
extern const u8 gUnk_083307E0[];
extern const u8 gUnk_08330BA0[];
extern const u8 gUnk_08330F60[];
extern const u8 gUnk_08331320[];
extern const u8 gUnk_08331E60[];
extern const u8 gUnk_08332220[];
extern const u8 gUnk_083325E0[];
extern const u8 gUnk_083329A0[];
extern const u8 gUnk_08332D60[];
extern const u8 gUnk_08333120[];
extern const u8 gUnk_083334E0[];
extern const u8 gUnk_083338A0[];
extern const u8 gUnk_08333C60[];
extern const u8 gUnk_08334020[];
extern const u8 gUnk_083343E0[];
extern const u8 gUnk_083347A0[];
extern const u8 gUnk_08334B60[];
extern const u8 gUnk_08334F20[];
extern const u8 gUnk_083352E0[];
extern const u8 gUnk_083356A0[];
extern const u8 gUnk_08335A60[];
extern const u8 gUnk_08335E20[];
extern const u8 gUnk_083361E0[];
extern const u8 gUnk_083365A0[];
extern const u8 gUnk_08336960[];
extern const u8 gUnk_08336D20[];
extern const u8 gUnk_083370E0[];
extern const u8 gUnk_083374A0[];
extern const u8 gUnk_08337860[];
extern const u8 gUnk_08337C20[];
extern const u8 gUnk_08337FE0[];
extern const u8 gUnk_083383A0[];
extern const u8 gUnk_08338760[];
extern const u8 gUnk_083392A0[];
extern const u8 gUnk_08339660[];
extern const u8 gUnk_08339A20[];
extern const u8 gUnk_08339DE0[];
extern const u8 gUnk_0833A1A0[];
extern const u8 gUnk_0833A560[];
extern const u8 gUnk_0833A920[];
extern const u8 gUnk_0833ACE0[];
extern const u8 gUnk_0833B0A0[];
extern const u8 gUnk_0833B460[];
extern const u8 gUnk_0833B820[];
extern const u8 gUnk_0833BBE0[];
extern const u8 gUnk_0833BFA0[];
extern const u8 gUnk_0833C360[];
extern const u8 gUnk_0833C720[];
extern const u8 gUnk_0833CAE0[];
extern const u8 gUnk_0833CEA0[];
extern const u8 gUnk_0833D260[];
extern const u8 gUnk_0833D620[];
extern const u8 gUnk_0833D9E0[];
extern const u8 gUnk_0833DDA0[];
extern const u8 gUnk_0833E160[];
extern const u8 gUnk_0833E520[];
extern const u8 gUnk_0833E8E0[];
extern const u8 gUnk_0833ECA0[];
extern const u8 gUnk_0833F060[];
extern const u8 gUnk_0833F420[];
extern const u8 gUnk_0833F7E0[];
extern const u8 gUnk_0833FBA0[];
extern const u8 gUnk_083406E0[];
extern const u8 gUnk_08340AA0[];
extern const u8 gUnk_08340E60[];
extern const u8 gUnk_08341220[];
extern const u8 gUnk_083415E0[];
extern const u8 gUnk_083419E0[];
extern const u8 gUnk_08341DA0[];
extern const u8 gUnk_08342160[];
extern const u8 gUnk_08342520[];
extern const u8 gUnk_083428E0[];
extern const u8 gUnk_08342CA0[];
extern const u8 gUnk_083430A0[];
extern const u8 gUnk_08343460[];
extern const u8 gUnk_08343820[];
extern const u8 gUnk_08343BE0[];
extern const u8 gUnk_08343FA0[];
extern const u8 gUnk_08344360[];
extern const u8 gUnk_08344760[];
extern const u8 gUnk_08344B20[];
extern const u8 gUnk_08344EE0[];
extern const u8 gUnk_083452A0[];
extern const u8 gUnk_08345660[];
extern const u8 gUnk_08345A20[];
extern const u8 gUnk_08345E20[];
extern const u8 gUnk_083461E0[];
extern const u8 gUnk_083465A0[];
extern const u8 gUnk_08346D20[];
extern const u8 gUnk_083470E0[];
extern const u8 gUnk_083474A0[];
extern const u8 gUnk_083478A0[];
extern const u8 gUnk_08347C60[];
extern const u8 gUnk_08348020[];
extern const u8 gUnk_083483E0[];
extern const u8 gUnk_083487A0[];
extern const u8 gUnk_08348B60[];
extern const u8 gUnk_08348F60[];
extern const u8 gUnk_08349320[];
extern const u8 gUnk_08349B20[];
extern const u8 gUnk_0834A320[];
extern const u8 gUnk_0834AB20[];
extern const u8 gUnk_0834B320[];

const u16 *gAbilityIconPalettes[32] = {
    gUnk_083145A0, gUnk_08314980, gUnk_08314D60, gUnk_08315140,
    gUnk_08315520, gUnk_08315900, gUnk_08315CE0, gUnk_083160C0,
    gUnk_083164A0, gUnk_08316880, gUnk_08316C60, gUnk_08317040,
    gUnk_08317420, gUnk_08317800, gUnk_08317BE0, gUnk_08317FC0,
    gUnk_083183A0, gUnk_08318780, gUnk_08318B60, gUnk_08318F40,
    gUnk_08319320, gUnk_08319700, gUnk_08319AE0, gUnk_08319EC0,
    gUnk_0831A2A0, gUnk_0831A680, gUnk_0831AA60, gUnk_0831AE40,
    gUnk_0831B220, gUnk_0831B600, gUnk_0831B9E0, gUnk_0831BDC0,
};
const u8 *gAbilityIconGraphics[6][32] = {
    {
        gUnk_083145C0, gUnk_083149A0, gUnk_08314D80, gUnk_08315160,
        gUnk_08315540, gUnk_08315920, gUnk_08315D00, gUnk_083160E0,
        gUnk_083164C0, gUnk_083168A0, gUnk_08316C80, gUnk_08317060,
        gUnk_08317440, gUnk_08317820, gUnk_08317C00, gUnk_08317FE0,
        gUnk_083183C0, gUnk_083187A0, gUnk_08318B80, gUnk_08318F60,
        gUnk_08319340, gUnk_08319720, gUnk_08319B00, gUnk_08319EE0,
        gUnk_0831A2C0, gUnk_0831A6A0, gUnk_0831AA80, gUnk_0831AE60,
        gUnk_0831B240, gUnk_0831B620, gUnk_0831BA00, gUnk_0831BDE0,
    },
    {
        gUnk_083235E0, gUnk_083239A0, gUnk_08323D60, gUnk_08324120,
        gUnk_083244E0, gUnk_083248A0, gUnk_08324C60, gUnk_08325020,
        gUnk_083253E0, gUnk_083257A0, gUnk_08325B60, gUnk_08325F20,
        gUnk_083262E0, gUnk_083266A0, gUnk_08326A60, gUnk_08326E20,
        gUnk_083271E0, gUnk_083275A0, gUnk_08327960, gUnk_08327D20,
        gUnk_083280E0, gUnk_083284A0, gUnk_08328860, gUnk_08328C20,
        gUnk_08328FE0, gUnk_083293A0, gUnk_08329760, gUnk_08329B20,
        gUnk_08329EE0, gUnk_08329EE0, gUnk_08329EE0, gUnk_08329EE0,
    },
    {
        gUnk_0831C1A0, gUnk_0831C560, gUnk_0831C920, gUnk_0831CCE0,
        gUnk_0831D0A0, gUnk_0831D460, gUnk_0831D820, gUnk_0831DBE0,
        gUnk_0831DFA0, gUnk_0831E360, gUnk_0831E720, gUnk_0831EAE0,
        gUnk_0831EEA0, gUnk_0831F260, gUnk_0831F620, gUnk_0831F9E0,
        gUnk_0831FDA0, gUnk_08320160, gUnk_08320520, gUnk_083208E0,
        gUnk_08320CA0, gUnk_08321060, gUnk_08321420, gUnk_083217E0,
        gUnk_08321BA0, gUnk_08321F60, gUnk_08322320, gUnk_083226E0,
        gUnk_08322AA0, gUnk_08322AA0, gUnk_08322AA0, gUnk_08322AA0,
    },
    {
        gUnk_08331E60, gUnk_08332220, gUnk_083325E0, gUnk_083329A0,
        gUnk_08332D60, gUnk_08333120, gUnk_083334E0, gUnk_083338A0,
        gUnk_08333C60, gUnk_08334020, gUnk_083343E0, gUnk_083347A0,
        gUnk_08334B60, gUnk_08334F20, gUnk_083352E0, gUnk_083356A0,
        gUnk_08335A60, gUnk_08335E20, gUnk_083361E0, gUnk_083365A0,
        gUnk_08336960, gUnk_08336D20, gUnk_083370E0, gUnk_083374A0,
        gUnk_08337860, gUnk_08337C20, gUnk_08337FE0, gUnk_083383A0,
        gUnk_08338760, gUnk_08338760, gUnk_08338760, gUnk_08338760,
    },
    {
        gUnk_0832AA20, gUnk_0832ADE0, gUnk_0832B1A0, gUnk_0832B560,
        gUnk_0832B920, gUnk_0832BCE0, gUnk_0832C0A0, gUnk_0832C460,
        gUnk_0832C820, gUnk_0832CBE0, gUnk_0832CFA0, gUnk_0832D360,
        gUnk_0832D720, gUnk_0832DAE0, gUnk_0832DEA0, gUnk_0832E260,
        gUnk_0832E620, gUnk_0832E9E0, gUnk_0832EDA0, gUnk_0832F160,
        gUnk_0832F520, gUnk_0832F8E0, gUnk_0832FCA0, gUnk_08330060,
        gUnk_08330420, gUnk_083307E0, gUnk_08330BA0, gUnk_08330F60,
        gUnk_08331320, gUnk_08331320, gUnk_08331320, gUnk_08331320,
    },
    {
        gUnk_083392A0, gUnk_08339660, gUnk_08339A20, gUnk_08339DE0,
        gUnk_0833A1A0, gUnk_0833A560, gUnk_0833A920, gUnk_0833ACE0,
        gUnk_0833B0A0, gUnk_0833B460, gUnk_0833B820, gUnk_0833BBE0,
        gUnk_0833BFA0, gUnk_0833C360, gUnk_0833C720, gUnk_0833CAE0,
        gUnk_0833CEA0, gUnk_0833D260, gUnk_0833D620, gUnk_0833D9E0,
        gUnk_0833DDA0, gUnk_0833E160, gUnk_0833E520, gUnk_0833E8E0,
        gUnk_0833ECA0, gUnk_0833F060, gUnk_0833F420, gUnk_0833F7E0,
        gUnk_0833FBA0, gUnk_0833FBA0, gUnk_0833FBA0, gUnk_0833FBA0,
    },
};
const u8 *gHudEnemyAndAreaNameGraphics[6] = {
    gUnk_082ECFA0, gUnk_082F38A0, gUnk_08300AA0, gUnk_083073A0, gUnk_082FA1A0, gUnk_0830DCA0,
};
const u8 *gHudBorrowMessageGraphics[6] = {
    gUnk_08340E60, gUnk_08342520, gUnk_08343BE0, gUnk_083483E0, gUnk_083452A0, gUnk_08346D20,
};
const u8 *gHudGiveMessageGraphics[6] = {
    gUnk_08341220, gUnk_083428E0, gUnk_08343FA0, gUnk_083487A0, gUnk_08345660, gUnk_083470E0,
};
const u8 *gHudConnectingMessageGraphics[6] = {
    gUnk_083406E0, gUnk_08341DA0, gUnk_08343460, gUnk_08347C60, gUnk_08344B20, gUnk_083461E0,
};
const u8 *gHudAnswerMessageGraphics[6] = {
    gUnk_08340AA0, gUnk_08342160, gUnk_08343820, gUnk_08348020, gUnk_08344EE0, gUnk_083465A0,
};
const u8 *gHudBorrowLifePromptGraphics[6] = {
    gUnk_083415E0, gUnk_08342CA0, gUnk_08344360, gUnk_08348B60, gUnk_08345A20, gUnk_083474A0,
};
const u8 *gHudBorrowLifeChoiceGraphics[6] = {
    gUnk_083419E0, gUnk_083430A0, gUnk_08344760, gUnk_08348F60, gUnk_08345E20, gUnk_083478A0,
};
const u8 *gHudGameOverAndDemoGraphics[6] = {
    gUnk_08349320, gUnk_08349320, gUnk_08349B20, gUnk_0834AB20, gUnk_0834A320, gUnk_0834B320,
};
