#include "screen_transition.h"
#include "hud.h"
#include "palette_effects.h"
#include "global.h"
#include "data.h"
#include "functions.h"
#include "kirby.h"
#include "main.h"
#include "pause_world_map.h"
#include "pause_help.h"
#include "code_0801C6F8.h"
#include "code_0801DA58.h"
#include "code_08020220.h"
#include "code_0814A828.h"
#include "level.h"
#include "constants/songs.h"
#include "task.h"

struct ScreenTransition {
    /* 0x00 */ void (*callback)(struct ScreenTransition *);
    /* 0x04 */ bool32 finished;
    /* 0x08 */ u16 screen;
    /* 0x0A */ u16 timer;
}; /* size = 0xC */

extern struct Task *gUnk_0203AD4C;
static void (*const sTransitionScreens[27])(void);

static void UnpauseGameplay(struct ScreenTransition *);
static void UpdateScreenTransition(void);
static void ScreenTransitionDestructor(struct Task *);
static void BeginScreenTransition(struct ScreenTransition *);
static void StartScreenTransitionFadeOut(struct ScreenTransition *);
static void WaitForScreenTransitionFadeOut(struct ScreenTransition *);
static void OpenTransitionScreen(struct ScreenTransition *);
static void WaitForTransitionScreenFinish(struct ScreenTransition *);
static void RestoreGameplayAfterTransitionScreen(struct ScreenTransition *);
static void DelayScreenTransitionFadeIn(struct ScreenTransition *);
static void StartScreenTransitionFadeIn(struct ScreenTransition *);
static void DestroyScreenTransition(struct ScreenTransition *);

static void UnpauseGameplay(struct ScreenTransition *transition)
{
    u16 i;

    gMainFlags &= ~0x400;
    transition->timer = 0;
    if (gUnk_0203AD10 & 2) {
        for (i = 0; i < gNumHumanPlayers; i++) {
            struct Kirby *kirby = &gKirbys[i];
            u16 heldKeys = gUnk_020382D0.unk8[0][i];

            kirby->movementState |= heldKeys & B_BUTTON;
        }
    } else {
        gKirbys[0].movementState |= gHeldKeys & B_BUTTON;
    }
    transition->callback = DelayScreenTransitionFadeIn;
}

void ResetScreenTransition(void)
{
    gUnk_0203AD4C = NULL;
    PauseMenuInitRetained();
}

bool32 CanStartScreenTransition(void)
{
    if ((gMainFlags & 0x400) || gUnk_0203AD4C != NULL)
        return FALSE;
    return TRUE;
}

static inline void StartScreenTransitionInternal(u16 screen)
{
    struct Task *task = TaskCreate(UpdateScreenTransition, sizeof(struct ScreenTransition), 1, TASK_x0004 | TASK_USE_IWRAM, ScreenTransitionDestructor);
    struct ScreenTransition *transition;

    gUnk_0203AD4C = task;
    transition = TaskGetStructPtr(task);
    transition->callback = BeginScreenTransition;
    transition->screen = screen;
    transition->finished = FALSE;
    gMainFlags |= 0x400;
}

void StartScreenTransition(u16 screen)
{
    struct Task *task = TaskCreate(UpdateScreenTransition, sizeof(struct ScreenTransition), 1, TASK_x0004 | TASK_USE_IWRAM, ScreenTransitionDestructor);
    struct ScreenTransition *transition;

    gUnk_0203AD4C = task;
    transition = TaskGetStructPtr(task);
    transition->callback = BeginScreenTransition;
    transition->screen = screen;
    transition->finished = FALSE;
    gMainFlags |= 0x400;
}

void FinishTransitionScreen(void)
{
    struct ScreenTransition *transition = TaskGetStructPtr(gUnk_0203AD4C);

    transition->finished = TRUE;
    CpuFill32(0, (void *)BG_VRAM, BG_VRAM_SIZE);
}

void sub_080396BC(void)
{
    StartScreenTransitionInternal(9);
}

void StartWorldMapUnlockMoonlightMansion(void)
{
    StartScreenTransitionInternal(10);
}

void StartWorldMapUnlockRainbowRouteEast(void)
{
    StartScreenTransitionInternal(11);
}

void StartWorldMapUnlockRainbowRouteSouth(void)
{
    StartScreenTransitionInternal(12);
}

void StartWorldMapUnlockCabbageCavernCenter(void)
{
    StartScreenTransitionInternal(13);
}

void StartWorldMapUnlockRainbowRouteWest(void)
{
    StartScreenTransitionInternal(14);
}

void StartWorldMapUnlockCarrotCastle(void)
{
    StartScreenTransitionInternal(15);
}

void StartWorldMapUnlockRainbowRouteNorth(void)
{
    StartScreenTransitionInternal(16);
}

void StartWorldMapUnlockMustardMountain(void)
{
    StartScreenTransitionInternal(17);
}

void StartWorldMapUnlockCabbageCavernWest(void)
{
    StartScreenTransitionInternal(18);
}

void StartWorldMapUnlockRadishRuins(void)
{
    StartScreenTransitionInternal(19);
}

void StartWorldMapUnlockPeppermintPalaceEast(void)
{
    StartScreenTransitionInternal(20);
}

void StartWorldMapUnlockPeppermintPalaceWest(void)
{
    StartScreenTransitionInternal(21);
}

void StartWorldMapUnlockCabbageCavernEast(void)
{
    StartScreenTransitionInternal(22);
}

void StartWorldMapUnlockOliveOcean(void)
{
    StartScreenTransitionInternal(23);
}

void StartWorldMapUnlockCandyConstellation(void)
{
    StartScreenTransitionInternal(24);
}

static void UpdateScreenTransition(void)
{
    struct ScreenTransition *transition = TaskGetStructPtr(gCurTask);

    transition->callback(transition);
}

static void ScreenTransitionDestructor(struct Task *task UNUSED)
{
    m4aSongNumContinue(MUS_VICTORY_LONG);
    m4aSongNumContinue(MUS_VICTORY_SHORT);
    m4aMPlayVolumeControl(&gMPlayInfo_1, 0xFFFF, 0x100);
    m4aMPlayVolumeControl(&gMPlayInfo_2, 0xFFFF, 0x100);
    m4aMPlayVolumeControl(&gMPlayInfo_3, 0xFFFF, 0x100);
    gUnk_0203AD4C = NULL;
}

static void BeginScreenTransition(struct ScreenTransition *transition)
{
    if (transition->screen == 0)
        m4aSongNumStart(SE_PAUSE_MENU_OPEN);
    transition->callback = StartScreenTransitionFadeOut;
}

static void StartScreenTransitionFadeOut(struct ScreenTransition *transition)
{
    struct PaletteEffect *effect;

    transition->timer = 0;
    effect = CreatePaletteFadeToWhite(7);
    effect->unk8 |= 0x80;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    transition->callback = WaitForScreenTransitionFadeOut;
}

static void WaitForScreenTransitionFadeOut(struct ScreenTransition *transition)
{
    if (++transition->timer > 30) {
        u16 color = RGB_WHITE;

        LoadBgPaletteAndBase(&color, 0, 1);
        if (gUnk_0203AD10 & 2)
            sub_08031CE4(8);
        transition->callback = OpenTransitionScreen;
        m4aSongNumStop(MUS_VICTORY_LONG);
        m4aSongNumStop(MUS_VICTORY_SHORT);
        m4aMPlayVolumeControl(&gMPlayInfo_1, 0xFFFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo_2, 0xFFFF, 0);
    }
}

static void OpenTransitionScreen(struct ScreenTransition *transition)
{
    sub_08020220();
    BackupBasePalettes();
    SaveDisplayState();
    sTransitionScreens[transition->screen]();
    transition->callback = WaitForTransitionScreenFinish;
}

static void WaitForTransitionScreenFinish(struct ScreenTransition *transition)
{
    sub_080203C8();
    if (transition->finished) {
        if (gUnk_0203AD10 & 2)
            sub_08031CE4(8);
        transition->callback = RestoreGameplayAfterTransitionScreen;
    }
}

static void RestoreGameplayAfterTransitionScreen(struct ScreenTransition *transition)
{
    sub_08020370();
    RestoreBasePalettes();
    RestoreDisplayState();
    RefreshGameplayHud(&gKirbys[gLocalPlayerId]);
    sub_0806F734();
    transition->callback = UnpauseGameplay;
}

static void DelayScreenTransitionFadeIn(struct ScreenTransition *transition)
{
    if (transition->timer++ > 2)
        transition->callback = StartScreenTransitionFadeIn;
}

static void StartScreenTransitionFadeIn(struct ScreenTransition *transition)
{
    struct PaletteEffect *effect;
    u16 color;

    transition->timer = 0;
    effect = CreatePaletteFadeFromWhite(7);
    effect->unk8 |= 0x80;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    color = RGB_WHITE;
    LoadBgPaletteAndBase(&color, 0, 1);
    transition->callback = DestroyScreenTransition;
    transition->callback(transition);
}

static void DestroyScreenTransition(struct ScreenTransition *transition UNUSED)
{
    TaskDestroy(gCurTask);
}

static void (*const sTransitionScreens[27])(void) = {
    CreatePauseMenu,
    sub_0801D618,
    sub_0801D624,
    sub_0801D630,
    sub_0801D63C,
    sub_0801D648,
    sub_0801D654,
    sub_0801D660,
    sub_0801D66C,
    sub_0801DFE8,
    WorldMapUnlockMoonlightMansion,
    WorldMapUnlockRainbowRouteEast,
    WorldMapUnlockRainbowRouteSouth,
    WorldMapUnlockCabbageCavernCenter,
    WorldMapUnlockRainbowRouteWest,
    WorldMapUnlockCarrotCastle,
    WorldMapUnlockRainbowRouteNorth,
    WorldMapUnlockMustardMountain,
    WorldMapUnlockCabbageCavernWest,
    WorldMapUnlockRadishRuins,
    WorldMapUnlockPeppermintPalaceEast,
    WorldMapUnlockPeppermintPalaceWest,
    WorldMapUnlockCabbageCavernEast,
    WorldMapUnlockOliveOcean,
    WorldMapUnlockCandyConstellation,
    sub_0802E16C,
    sub_0814A828,
};

static const u16 sUnk_0834BE00[16] UNUSED = {
    RGB(0, 0, 1), RGB(0, 1, 1), RGB(1, 1, 1), RGB(1, 1, 3),
    RGB(1, 3, 3), RGB(3, 3, 3), RGB(3, 3, 7), RGB(3, 7, 7),
    RGB(7, 7, 7), RGB(7, 7, 15), RGB(23, 14, 15), RGB(31, 14, 15),
    RGB(31, 14, 31), RGB(31, 30, 31), RGB_WHITE, RGB_WHITE | 0x8000,
};
