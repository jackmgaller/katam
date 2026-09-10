#include "hud.h"
#include "pause_transition.h"
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

struct PauseTransition {
    /* 0x00 */ void (*callback)(struct PauseTransition *);
    /* 0x04 */ bool32 finished;
    /* 0x08 */ u16 screen;
    /* 0x0A */ u16 timer;
}; /* size = 0xC */

extern struct Task *gUnk_0203AD4C;
extern void (*const gPauseTransitionScreens[])(void);

void ResumeGameplayAfterPauseScreen(struct PauseTransition *);
void UpdatePauseScreenTransition(void);
void PauseScreenTransitionDestructor(struct Task *);
void BeginPauseScreenTransition(struct PauseTransition *);
void StartPauseScreenFadeOut(struct PauseTransition *);
void WaitForPauseScreenFadeOut(struct PauseTransition *);
void OpenPauseTransitionScreen(struct PauseTransition *);
void WaitForPauseScreenFinish(struct PauseTransition *);
void RestoreGameplayAfterPauseScreen(struct PauseTransition *);
void DelayPauseScreenFadeIn(struct PauseTransition *);
void StartPauseScreenFadeIn(struct PauseTransition *);
void DestroyPauseScreenTransition(struct PauseTransition *);

void ResumeGameplayAfterPauseScreen(struct PauseTransition *transition)
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
    transition->callback = DelayPauseScreenFadeIn;
}

void ResetPauseScreenTransition(void)
{
    gUnk_0203AD4C = NULL;
    PauseMenuInitRetained();
}

bool32 CanStartPauseScreenTransition(void)
{
    if ((gMainFlags & 0x400) || gUnk_0203AD4C != NULL)
        return FALSE;
    return TRUE;
}

static inline void StartPauseTransitionInternal(u16 screen)
{
    struct Task *task = TaskCreate(UpdatePauseScreenTransition, sizeof(struct PauseTransition), 1, TASK_x0004, PauseScreenTransitionDestructor);
    struct PauseTransition *transition;

    gUnk_0203AD4C = task;
    transition = TaskGetStructPtr(task);
    transition->callback = BeginPauseScreenTransition;
    transition->screen = screen;
    transition->finished = FALSE;
    gMainFlags |= 0x400;
}

void StartPauseScreenTransition(u16 screen)
{
    struct Task *task = TaskCreate(UpdatePauseScreenTransition, sizeof(struct PauseTransition), 1, TASK_x0004, PauseScreenTransitionDestructor);
    struct PauseTransition *transition;

    gUnk_0203AD4C = task;
    transition = TaskGetStructPtr(task);
    transition->callback = BeginPauseScreenTransition;
    transition->screen = screen;
    transition->finished = FALSE;
    gMainFlags |= 0x400;
}

void FinishPauseScreen(void)
{
    struct PauseTransition *transition = TaskGetStructPtr(gUnk_0203AD4C);

    transition->finished = TRUE;
    CpuFill32(0, (void *)BG_VRAM, BG_VRAM_SIZE);
}

void sub_080396BC(void)
{
    StartPauseTransitionInternal(9);
}

void StartWorldMapUnlockMoonlightMansion(void)
{
    StartPauseTransitionInternal(10);
}

void StartWorldMapUnlockRainbowRouteEast(void)
{
    StartPauseTransitionInternal(11);
}

void StartWorldMapUnlockRainbowRouteSouth(void)
{
    StartPauseTransitionInternal(12);
}

void StartWorldMapUnlockCabbageCavernCenter(void)
{
    StartPauseTransitionInternal(13);
}

void StartWorldMapUnlockRainbowRouteWest(void)
{
    StartPauseTransitionInternal(14);
}

void StartWorldMapUnlockCarrotCastle(void)
{
    StartPauseTransitionInternal(15);
}

void StartWorldMapUnlockRainbowRouteNorth(void)
{
    StartPauseTransitionInternal(16);
}

void StartWorldMapUnlockMustardMountain(void)
{
    StartPauseTransitionInternal(17);
}

void StartWorldMapUnlockCabbageCavernWest(void)
{
    StartPauseTransitionInternal(18);
}

void StartWorldMapUnlockRadishRuins(void)
{
    StartPauseTransitionInternal(19);
}

void StartWorldMapUnlockPeppermintPalaceEast(void)
{
    StartPauseTransitionInternal(20);
}

void StartWorldMapUnlockPeppermintPalaceWest(void)
{
    StartPauseTransitionInternal(21);
}

void StartWorldMapUnlockCabbageCavernEast(void)
{
    StartPauseTransitionInternal(22);
}

void StartWorldMapUnlockOliveOcean(void)
{
    StartPauseTransitionInternal(23);
}

void StartWorldMapUnlockCandyConstellation(void)
{
    StartPauseTransitionInternal(24);
}

void UpdatePauseScreenTransition(void)
{
    struct PauseTransition *transition = TaskGetStructPtr(gCurTask);

    transition->callback(transition);
}

void PauseScreenTransitionDestructor(struct Task *UNUSED task)
{
    m4aSongNumContinue(MUS_VICTORY_LONG);
    m4aSongNumContinue(MUS_VICTORY_SHORT);
    m4aMPlayVolumeControl(&gMPlayInfo_1, 0xFFFF, 0x100);
    m4aMPlayVolumeControl(&gMPlayInfo_2, 0xFFFF, 0x100);
    m4aMPlayVolumeControl(&gMPlayInfo_3, 0xFFFF, 0x100);
    gUnk_0203AD4C = NULL;
}

void BeginPauseScreenTransition(struct PauseTransition *transition)
{
    if (transition->screen == 0)
        m4aSongNumStart(SE_PAUSE_MENU_OPEN);
    transition->callback = StartPauseScreenFadeOut;
}

void StartPauseScreenFadeOut(struct PauseTransition *transition)
{
    struct PaletteEffect *effect;

    transition->timer = 0;
    effect = CreatePaletteFadeToWhite(7);
    effect->unk8 |= 0x80;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    transition->callback = WaitForPauseScreenFadeOut;
}

void WaitForPauseScreenFadeOut(struct PauseTransition *transition)
{
    if (++transition->timer > 30) {
        u16 color = RGB_WHITE;

        LoadBgPaletteAndBase(&color, 0, 1);
        if (gUnk_0203AD10 & 2)
            sub_08031CE4(8);
        transition->callback = OpenPauseTransitionScreen;
        m4aSongNumStop(MUS_VICTORY_LONG);
        m4aSongNumStop(MUS_VICTORY_SHORT);
        m4aMPlayVolumeControl(&gMPlayInfo_1, 0xFFFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo_2, 0xFFFF, 0);
    }
}

void OpenPauseTransitionScreen(struct PauseTransition *transition)
{
    sub_08020220();
    BackupBasePalettes();
    SaveDisplayState();
    gPauseTransitionScreens[transition->screen]();
    transition->callback = WaitForPauseScreenFinish;
}

void WaitForPauseScreenFinish(struct PauseTransition *transition)
{
    sub_080203C8();
    if (transition->finished) {
        if (gUnk_0203AD10 & 2)
            sub_08031CE4(8);
        transition->callback = RestoreGameplayAfterPauseScreen;
    }
}

void RestoreGameplayAfterPauseScreen(struct PauseTransition *transition)
{
    sub_08020370();
    RestoreBasePalettes();
    RestoreDisplayState();
    RefreshGameplayHud(&gKirbys[gLocalPlayerId]);
    sub_0806F734();
    transition->callback = ResumeGameplayAfterPauseScreen;
}

void DelayPauseScreenFadeIn(struct PauseTransition *transition)
{
    if (transition->timer++ > 2)
        transition->callback = StartPauseScreenFadeIn;
}

void StartPauseScreenFadeIn(struct PauseTransition *transition)
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
    transition->callback = DestroyPauseScreenTransition;
    transition->callback(transition);
}

void DestroyPauseScreenTransition(struct PauseTransition *UNUSED transition)
{
    TaskDestroy(gCurTask);
}

void sub_0802E16C(void);

void (*const gPauseTransitionScreens[27])(void) = {
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
