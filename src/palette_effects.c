#include "global.h"

struct PaletteEffect;
struct Task;

// The matching compiler emits these inline bodies in declaration order.
// Declare them before headers that expose only part of this sequence.
inline bool8 IsPaletteEffectFinished(u8 arg0);
inline bool32 AreKirbyPaletteEffectsInactive(void);
inline void DestroyPaletteEffectsTask(u32 arg0 UNUSED);
inline void LoadBgPaletteAndBase(const u16 *palette, u8 offset, u16 num);
inline void LoadLevelBasePalettes(const u16 **arg0, const u16 **arg1);
inline void SaveObjPaletteColors(u8 offset, u8 num);
inline void SaveBgPaletteColors(u8 offset, u8 num);
inline void BackupBasePalettes(void);
inline void RestoreBasePalettes(void);
inline struct PaletteEffect *GetPaletteEffect(u8 arg0);
inline void PaletteEffectsTaskDestructor(struct Task *task UNUSED);
inline void InsertPaletteEffectByPriority(struct PaletteEffect *arg0, u8 arg1);

#include "data.h"
#include "kirby.h"
#include "main.h"
#include "palette.h"
#include "task.h"

#include "palette_effects.h"
#include "functions.h"

extern u16 gUnk_02022120[256];
extern u16 gUnk_02022320[256];
extern u16 gUnk_02022520[512];

static void QueuePaletteEffect(struct PaletteEffect *);
void CompactPaletteEffectQueue(void);
static void UpdatePaletteEffects(void);
void PaletteEffectsTaskDestructor(struct Task *);
void InsertPaletteEffectByPriority(struct PaletteEffect *, u8);

void ApplyPaletteDarkening(struct PaletteEffect *);
void ApplyPaletteBrightening(struct PaletteEffect *);
void ApplyPaletteTableDarkening(struct PaletteEffect *);
void ApplyPaletteRedTint(struct PaletteEffect *);
void ApplyPaletteWhiteFill(struct PaletteEffect *);
extern void (*const gPaletteEffectCallbacks[5])(struct PaletteEffect *);
extern const u16 gBrightenRedTable[64];
extern const u16 gBrightenGreenTable[64];
extern const u16 gBrightenBlueTable[64];
extern const u16 gDarkenRedTable[64];
extern const u16 gDarkenGreenTable[64];
extern const u16 gDarkenBlueTable[64];

static void QueuePaletteEffect(struct PaletteEffect *effect)
{
    struct Task *task = gPaletteEffectsTask;
    struct PaletteEffectManager *state = &gPaletteEffectManager;
    u8 i;
    struct PaletteEffect **slot;
    struct PaletteEffect *existing;

    if (task == NULL) {
        gPaletteEffectsTask = TaskCreate(UpdatePaletteEffects, 0, 0xFFFE, TASK_x0004, PaletteEffectsTaskDestructor);
        for (i = 0; i < 8; i++)
            state->unk80[i] = NULL;
    }
    slot = &state->unk80[0];
    existing = *slot;
    if (existing != NULL) {
        if (existing->unk3 <= effect->unk3) {
            InsertPaletteEffectByPriority(effect, 1);
            return;
        }
        InsertPaletteEffectByPriority(existing, 1);
    }
    *slot = effect;
}

void CompactPaletteEffectQueue(void)
{
    struct PaletteEffectManager *state = &gPaletteEffectManager;

    if (!state->unk80[0] && !state->unk80[1] && !state->unk80[2] && !state->unk80[3]
        && !state->unk80[4] && !state->unk80[5] && !state->unk80[6] && !state->unk80[7])
        return;
    if (state->unk80[6] == NULL) {
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
    if (state->unk80[5] == NULL) {
        state->unk80[5] = state->unk80[6];
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
    if (state->unk80[4] == NULL) {
        state->unk80[4] = state->unk80[5];
        state->unk80[5] = state->unk80[6];
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
    if (state->unk80[3] == NULL) {
        state->unk80[3] = state->unk80[4];
        state->unk80[4] = state->unk80[5];
        state->unk80[5] = state->unk80[6];
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
    if (state->unk80[2] == NULL) {
        state->unk80[2] = state->unk80[3];
        state->unk80[3] = state->unk80[4];
        state->unk80[4] = state->unk80[5];
        state->unk80[5] = state->unk80[6];
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
    if (state->unk80[1] == NULL) {
        state->unk80[1] = state->unk80[2];
        state->unk80[2] = state->unk80[3];
        state->unk80[3] = state->unk80[4];
        state->unk80[4] = state->unk80[5];
        state->unk80[5] = state->unk80[6];
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
    if (state->unk80[0] == NULL) {
        state->unk80[0] = state->unk80[1];
        state->unk80[1] = state->unk80[2];
        state->unk80[2] = state->unk80[3];
        state->unk80[3] = state->unk80[4];
        state->unk80[4] = state->unk80[5];
        state->unk80[5] = state->unk80[6];
        state->unk80[6] = state->unk80[7];
        state->unk80[7] = NULL;
    }
}

static void UpdatePaletteEffects(void)
{
    struct PaletteEffectManager *state = &gPaletteEffectManager;
    bool32 objRestored = FALSE;
    bool32 bgRestored = FALSE;
    u16 flags = state->unk0[0].unk8 | state->unk0[1].unk8 | state->unk0[2].unk8 | state->unk0[3].unk8
        | state->unk0[4].unk8 | state->unk0[5].unk8 | state->unk0[6].unk8 | state->unk0[7].unk8;
    u8 i;

    if (flags & 4) {
        for (i = 0; i < 8; i++) {
            if (!(state->unk0[i].unk8 & 0x10)) {
                if ((state->unk0[i].unk8 & 4)
                    && (!(gMainFlags & 0x800) || !(flags & 0x100) || (state->unk0[i].unk8 & 0x80))) {
                    if (state->unk0[i].unk6 && !bgRestored) {
                        CpuCopy32(gUnk_02022120, gBgPalette, sizeof(gBgPalette));
                        bgRestored = TRUE;
                    }
                    if (state->unk0[i].unk4 && !objRestored) {
                        CpuCopy32(gUnk_02022320, gObjPalette, sizeof(gObjPalette));
                        objRestored = TRUE;
                    }
                }
            }
        }
    }
    if ((gMainFlags & 0x800) && !(flags & 0x80))
        return;
    for (i = 0; i < 8; i++) {
        if (state->unk80[i] && (!(gMainFlags & 0x800) || !(flags & 0x100) || (state->unk80[i]->unk8 & 0x80))) {
            gPaletteEffectCallbacks[state->unk80[i]->unk0](state->unk80[i]);
            if (!(state->unk80[i]->unk8 & 2)) {
                if (state->unk80[i]->unk8 & 1)
                    state->unk80[i] = NULL;
                objRestored = FALSE;
            } else {
                // Indexed by queue position, not by the effect the slot points at.
                struct PaletteEffect *effect = &state->unk0[i];
                if (!(effect->unk8 & 0x10)) {
                    if ((effect->unk8 & 4) && effect->unk4)
                        objRestored = TRUE;
                }
            }
        }
    }
    CompactPaletteEffectQueue();
    if (gMainFlags & 0x10000) {
        if (objRestored) {
            if (gMainFlags & 0x20000) {
                LoadObjPaletteWithTransformation(gObjPalette, 0, 0x100);
            } else {
                DmaCopy16(3, gObjPalette, gObjPalette, sizeof(gObjPalette));
                gMainFlags |= MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
            }
        }
        if (bgRestored) {
            if (gMainFlags & 0x10000) {
                LoadBgPaletteWithTransformation(gBgPalette, 0, 0x100);
            } else {
                DmaCopy16(3, gBgPalette, gBgPalette, sizeof(gBgPalette));
                gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE;
            }
        }
    }
}

static inline void DarkenColor(u16 *palette, struct PaletteEffect *effect)
{
    u16 channel = (*palette & 31) - effect->unk1;
    u32 underflow = channel & 0x8000;
    u16 result = channel;
    if (underflow)
        result = 0;
    channel = ((*palette >> 5) & 31) - effect->unk1;
    if (!(channel & 0x8000))
        result |= channel << 5;
    channel = ((*palette >> 10) & 31) - effect->unk1;
    if (!(channel & 0x8000))
        result |= channel << 10;
    *palette = result;
}

static inline void BrightenColor(u16 *palette, struct PaletteEffect *effect)
{
    s8 amount = effect->unk1;
    // TODO(match): Keep the accumulated color in r3 and the signed adjustment in r2.
    register u32 result asm("r3") = gBrightenRedTable[(*palette & 31) + amount];
    result |= gBrightenGreenTable[((*palette >> 5) & 31) + amount];
    result |= gBrightenBlueTable[((*palette >> 10) & 31) + amount];
    *palette = result;
}

static inline void DarkenColorWithTable(u16 *palette, struct PaletteEffect *effect)
{
    const u16 *redTable = gDarkenRedTable;
    s32 offset;
    u32 result;
    u32 red = *palette & 31;
    offset = effect->unk1 - 31;
    result = redTable[red - offset];
    result |= gDarkenGreenTable[((*palette >> 5) & 31) - offset];
    result |= gDarkenBlueTable[((*palette >> 10) & 31) - offset];
    *palette = result;
}

static inline void TintColorRed(u16 *palette, struct PaletteEffect *effect)
{
    s8 amount = effect->unk1;
    s32 offset;
    u32 green;
    u32 result = gBrightenRedTable[(*palette & 31) + amount];
    green = (*palette >> 5) & 31;
    offset = amount - 31;
    result |= gDarkenGreenTable[green - offset];
    result |= gDarkenBlueTable[((*palette >> 10) & 31) - offset];
    *palette = result;
}

static inline void AdvancePaletteEffect(struct PaletteEffect *effect, u32 flags)
{
    s32 current;
    s32 tgt;
    u8 target;
    effect->unkC += effect->unkA;
    current = effect->unk1 = (s16)effect->unkC >> 8;
    tgt = effect->unk2;
    target = effect->unk2;
    if ((current <= tgt && effect->unkA < 0) || (current >= tgt && effect->unkA > 0)) {
        struct PaletteEffect *e = effect;
        if (flags & 0x20) {
            if (flags & 0x40) {
                e->unkC = e->unk2 * 0x100;
                e->unk1 = target;
            } else {
                u16 newFlags = flags | 1;
                // TODO(match): Materialize the halfword before masking to preserve the r0 flag-update result.
                asm("" : : "r"(newFlags));
                e->unk8 = newFlags & 0xFF59;
            }
        } else {
            e->unk1 = target;
            {
                u16 newFlags = flags | 0x20;
                // TODO(match): Keep the OR result separate from the previous flags until the shared store.
                asm("" : : "r"(newFlags));
                e->unk8 = newFlags;
            }
        }
    }
}

// Each bank has fifteen visible colors after its transparent entry.
#define TRANSFORM_VISIBLE_COLORS(transform) \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect); \
    ++palette; transform(palette, effect);

void ApplyPaletteDarkening(struct PaletteEffect *effect)
{
    u16 *palette;
    u16 bank;
    u32 flags;
    if (effect->unk8 & 2) {
        palette = gBgPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk6 >> bank) & 1) {
                TRANSFORM_VISIBLE_COLORS(DarkenColor);
                ++palette;
            } else {
                palette += 16;
            }
        }
        palette = gObjPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk4 >> bank) & 1) {
                TRANSFORM_VISIBLE_COLORS(DarkenColor);
                ++palette;
            } else {
                palette += 16;
            }
        }
        gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE | MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    flags = effect->unk8;
    if (!(flags & 1) && (!(gMainFlags & 0x800) || (flags & 0x80))) {
        if ((s8)effect->unk1 == (s8)effect->unk2) {
            if (flags & 0x40)
                effect->unk1 = effect->unk2;
            else {
                u16 newFlags = flags | 1;
                flags = newFlags & 0xFF79;
                effect->unk8 = flags;
            }
        } else {
            effect->unkC += effect->unkA;
            effect->unk1 = effect->unkC >> 8;
        }
    }
}

void ApplyPaletteBrightening(struct PaletteEffect *effect)
{
    u16 *palette;
    u16 bank;
    u32 finished;
    u32 flags;
    u32 savedFlags;
    if (effect->unk8 & 2) {
        palette = gBgPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk6 >> bank) & 1) {
                if (bank == 0)
                    BrightenColor(palette, effect);
                TRANSFORM_VISIBLE_COLORS(BrightenColor);
                ++palette;
            } else {
                palette += 16;
            }
        }
        palette = gObjPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk4 >> bank) & 1) {
                TRANSFORM_VISIBLE_COLORS(BrightenColor);
                ++palette;
            } else {
                palette += 16;
            }
        }
        gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE | MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    flags = effect->unk8;
    finished = flags & 1;
    savedFlags = flags;
    if (!finished && (!(gMainFlags & 0x800) || (savedFlags & 0x80)))
        AdvancePaletteEffect(effect, savedFlags);
}

void ApplyPaletteTableDarkening(struct PaletteEffect *effect)
{
    u16 *palette;
    u16 bank;
    u32 finished;
    u32 flags;
    u32 savedFlags;
    if (effect->unk8 & 2) {
        palette = gBgPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk6 >> bank) & 1) {
                if (bank == 0)
                    DarkenColorWithTable(palette, effect);
                TRANSFORM_VISIBLE_COLORS(DarkenColorWithTable);
                ++palette;
            } else {
                palette += 16;
            }
        }
        palette = gObjPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk4 >> bank) & 1) {
                TRANSFORM_VISIBLE_COLORS(DarkenColorWithTable);
                ++palette;
            } else {
                palette += 16;
            }
        }
        gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE | MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    flags = effect->unk8;
    finished = flags & 1;
    savedFlags = flags;
    if (!finished && (!(gMainFlags & 0x800) || (savedFlags & 0x80)))
        AdvancePaletteEffect(effect, savedFlags);
}

void ApplyPaletteRedTint(struct PaletteEffect *effect)
{
    u16 *palette;
    u16 bank;
    u32 finished;
    u32 flags;
    u32 savedFlags;
    if (effect->unk8 & 2) {
        palette = gBgPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk6 >> bank) & 1) {
                if (bank == 0)
                    TintColorRed(palette, effect);
                TRANSFORM_VISIBLE_COLORS(TintColorRed);
                ++palette;
            } else {
                palette += 16;
            }
        }
        palette = gObjPalette;
        for (bank = 0; bank < 16; bank++) {
            if ((effect->unk4 >> bank) & 1) {
                TRANSFORM_VISIBLE_COLORS(TintColorRed);
                ++palette;
            } else {
                palette += 16;
            }
        }
        gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE | MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    flags = effect->unk8;
    finished = flags & 1;
    savedFlags = flags;
    if (!finished && (!(gMainFlags & 0x800) || (savedFlags & 0x80)))
        AdvancePaletteEffect(effect, savedFlags);
}

void ApplyPaletteWhiteFill(struct PaletteEffect *effect)
{
    u16 *palette;
    u32 fill;
    u16 bgBank;
    u16 objBank;
    u32 finished;
    u32 flags;
    u32 savedFlags;
    if (effect->unk8 & 2) {
        palette = gBgPalette;
        for (bgBank = 0; bgBank < 16; bgBank++) {
            if ((effect->unk6 >> bgBank) & 1) {
                fill = 0xFFFFFFFF;
                CpuSet(&fill, palette, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 8);
                palette += 16;
            } else {
                palette += 16;
            }
        }
        palette = gObjPalette;
        for (objBank = 0; objBank < 16; objBank++) {
            if ((effect->unk4 >> objBank) & 1) {
                fill = 0xFFFFFFFF;
                CpuSet(&fill, palette, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 8);
                palette += 16;
            } else {
                palette += 16;
            }
        }
        gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE | MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    flags = effect->unk8;
    finished = flags & 1;
    savedFlags = flags;
    if (!finished)
        AdvancePaletteEffect(effect, savedFlags);
}

#undef TRANSFORM_VISIBLE_COLORS

struct PaletteEffect *CreateRoomPaletteEffect(u8 slot, u16 room)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u16 roomId;
    u8 queueIndex;

    roomId = room;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slot];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 0xC;
    if (gKirbys[gLocalPlayerId].base.roomId == roomId) {
        effect->unk8 = 0xE;
    }
    effect->unkE = roomId;
    effect->unkA = 0x200;
    effect->unkC = 0;
    effect->unk1 = 0;
    effect->unk2 = 0x1F;
    effect->unk0 = 1;
    effect->unk3 = 0xF;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    QueuePaletteEffect(effect);
    return effect;
}

struct PaletteEffect *CreateLowPriorityRoomPaletteEffect(u8 slot, u16 room)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u16 roomId;
    u8 queueIndex;

    roomId = room;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slot];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 0xC;
    if (gKirbys[gLocalPlayerId].base.roomId == roomId) {
        effect->unk8 = 0xE;
    }
    effect->unkE = roomId;
    effect->unkA = 0x200;
    effect->unkC = 0;
    effect->unk1 = 0;
    effect->unk2 = 0x1F;
    effect->unk0 = 1;
    effect->unk3 = 8;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    QueuePaletteEffect(effect);
    return effect;
}

struct PaletteEffect *CreatePaletteFadeFromWhite(u8 slot)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u8 slotId;
    u8 queueIndex;

    slotId = slot;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slotId];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 4;
    if ((u32) slotId >= (u32) gNumKirbys) {
        effect->unk8 = 6;
    } else if (gKirbys[gLocalPlayerId].base.roomId == gKirbys[slotId].base.roomId) {
        effect->unk8 = 6;
    }
    // TODO: Slots 4-7 still read beyond the four Kirbys, as in the original.
    effect->unkE = gKirbys[slotId].base.roomId;
    effect->unkA = -0x200;
    effect->unkC = 0x1F00;
    effect->unk1 = 0x1F;
    effect->unk2 = 0;
    effect->unk0 = 1;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    effect->unk3 = 0xA;
    QueuePaletteEffect(effect);
    return effect;
}

struct PaletteEffect *CreatePaletteFadeToWhite(u8 slot)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u8 slotId;
    u8 queueIndex;

    slotId = slot;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slotId];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 0x4C;
    if ((u32) slotId >= (u32) gNumKirbys) {
        effect->unk8 = 0x4E;
    } else if (gKirbys[gLocalPlayerId].base.roomId == gKirbys[slotId].base.roomId) {
        effect->unk8 = 0x4E;
    }
    // TODO: Slots 4-7 still read beyond the four Kirbys, as in the original.
    effect->unkE = gKirbys[slotId].base.roomId;
    effect->unkA = 0x200;
    effect->unkC = 0;
    effect->unk1 = 0;
    effect->unk2 = 0x1F;
    effect->unk0 = 1;
    effect->unk3 = 0xA;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    QueuePaletteEffect(effect);
    return effect;
}

struct PaletteEffect *CreateHiddenPaletteFadeToWhite(u8 slot)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u8 slotId;
    u8 queueIndex;

    slotId = slot;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slotId];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 0x14;
    effect->unkE = gKirbys[slotId].base.roomId;
    effect->unkA = 0x200;
    effect->unkC = 0;
    effect->unk1 = 0;
    effect->unk2 = 0x1F;
    effect->unk0 = 1;
    effect->unk3 = 0xA;
    effect->unk4 = 0xFFFF;
    effect->unk6 = 0xFFFF;
    QueuePaletteEffect(effect);
    return effect;
}

static struct PaletteEffect *HoldPaletteEffect(u8 slot)
{
    struct PaletteEffect *effect;
    u8 slotId;

    struct PaletteEffectManager *state;

    slotId = slot;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slotId];
    effect->unk8 = 4;
    if (((u32) slotId >= (u32) gNumKirbys) || (gKirbys[gLocalPlayerId].base.roomId == gKirbys[slotId].base.roomId)) {
        effect->unk8 = 6;
    }
    effect->unkA = 0;
    effect->unk2 = 0xFF;
    return effect;
}

struct PaletteEffect *CreatePaletteDim(u8 slot)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u8 slotId;
    u8 queueIndex;

    slotId = slot;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slotId];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 0x4C;
    if ((u32) slotId >= (u32) gNumKirbys) {
        effect->unk8 = 0x4E;
    } else if (gKirbys[gLocalPlayerId].base.roomId == gKirbys[slotId].base.roomId) {
        effect->unk8 = 0x4E;
    }
    effect->unkE = gKirbys[slotId].base.roomId;
    effect->unkA = 0x100;
    effect->unkC = 0;
    effect->unk1 = 0;
    effect->unk2 = 0xA;
    effect->unk0 = 0;
    effect->unk4 = 0x3F00;
    effect->unk6 = 0x3FFF;
    effect->unk3 = 5;
    QueuePaletteEffect(effect);
    return effect;
}

struct PaletteEffect *CreatePaletteUndim(u8 slot)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect *effect;
    u8 slotId;
    u8 queueIndex;

    slotId = slot;
    state = &gPaletteEffectManager;
    effect = &state->unk0[slotId];
    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        if (state->unk80[queueIndex] == effect) {
            state->unk80[queueIndex] = NULL;
            CompactPaletteEffectQueue();
        }
    }
    effect->unk8 = 4;
    if ((u32) slotId >= (u32) gNumKirbys) {
        effect->unk8 = 6;
    } else if (gKirbys[gLocalPlayerId].base.roomId == gKirbys[slotId].base.roomId) {
        effect->unk8 = 6;
    }
    effect->unkE = gKirbys[slotId].base.roomId;
    effect->unkA = -0x200;
    effect->unkC = 0xA00;
    effect->unk1 = 0xA;
    effect->unk2 = 0;
    effect->unk0 = 0;
    effect->unk4 = 0x3F00;
    effect->unk6 = 0x3FFF;
    effect->unk3 = 5;
    QueuePaletteEffect(effect);
    return effect;
}

void EnablePaletteEffectsForCurrentRoom(void)
{
    struct PaletteEffectManager *state = &gPaletteEffectManager;
    struct PaletteEffect *effect;
    u32 flags;
    u8 queueIndex;

    for (queueIndex = 0; queueIndex < 8; queueIndex++) {
        effect = &state->unk0[queueIndex];
        flags = effect->unk8;
        if ((4 & flags) && (gKirbys[gLocalPlayerId].base.roomId == (s16) effect->unkE) && !(0x10 & flags)) {
            u32 enabledFlags = 2;
            enabledFlags |= flags;
            effect->unk8 = enabledFlags;
        }
    }
}

inline bool8 IsPaletteEffectFinished(u8 slot)
{
    if (gPaletteEffectManager.unk0[slot].unk8 & 1)
        return TRUE;
    else
        return FALSE;
}

inline bool32 AreKirbyPaletteEffectsInactive(void)
{
    if (!(gPaletteEffectManager.unk0[0].unk8 & 4)
        && !(gPaletteEffectManager.unk0[1].unk8 & 4)
        && !(gPaletteEffectManager.unk0[2].unk8 & 4)
        && !(gPaletteEffectManager.unk0[3].unk8 & 4))
        return TRUE;
    else
        return FALSE;
}

inline void DestroyPaletteEffectsTask(u32 arg0 UNUSED)
{
    TaskDestroy(gPaletteEffectsTask);
}

inline void LoadBgPaletteAndBase(const u16 *palette, u8 offset, u16 num)
{
    u16 *destination = gBgPalette;
    destination += offset;
    CpuSet(palette, destination, num);
    destination = gUnk_02022120;
    destination += offset;
    CpuSet(palette, destination, num);
}

inline void LoadLevelBasePalettes(const u16 **arg0, const u16 **arg1)
{
    CpuCopy32(*arg0, gUnk_02022120, 0xC0);
    CpuCopy32(*arg1, &gUnk_02022120[0x60], 0x100);
}

inline void SaveObjPaletteColors(u8 offset, u8 num)
{
    CpuCopy16(&gObjPalette[offset], &gUnk_02022320[offset], num << 1);
}

inline void SaveBgPaletteColors(u8 offset, u8 num)
{
    CpuCopy16(&gBgPalette[offset], &gUnk_02022120[offset], num << 1);
}

inline void BackupBasePalettes(void)
{
    // The BG and OBJ base palettes occupy one contiguous 0x400-byte range.
    CpuFastCopy(gUnk_02022120, gUnk_02022520, 0x400);
}

inline void RestoreBasePalettes(void)
{
    CpuFastCopy(gUnk_02022520, gUnk_02022120, 0x400);
}

inline struct PaletteEffect *GetPaletteEffect(u8 slot)
{
    return &gPaletteEffectManager.unk0[slot];
}

inline void PaletteEffectsTaskDestructor(struct Task *task UNUSED)
{
    gPaletteEffectsTask = NULL;
}

inline void InsertPaletteEffectByPriority(struct PaletteEffect *effect, u8 index)
{
    struct PaletteEffectManager *state;
    struct PaletteEffect **queue;
    struct PaletteEffect **slot;
    struct PaletteEffect *existing;
    u8 queueIndex;
    u32 offset;

    queueIndex = index;
    state = &gPaletteEffectManager;
    offset = queueIndex * sizeof(*slot);
    queue = state->unk80;
    slot = (struct PaletteEffect **)((u8 *)queue + offset);
    existing = *slot;
    if (existing != NULL) {
        if (existing->unk3 <= effect->unk3) {
            InsertPaletteEffectByPriority(effect, queueIndex + 1);
            return;
        }
        InsertPaletteEffectByPriority(existing, queueIndex + 1);
        *slot = effect;
        return;
    }
    *slot = effect;
}

static inline s8 ClampPaletteChannel(s32 value)
{
    u8 result = value;
    s8 channel = value;

    if (channel & 0xE0) {
        if (channel & 0x80)
            result = 0;
        else
            result = 31;
    }
    return result;
}

void BlendSpriteAnimationPalettes(u8 paletteId, u16 sourceAnim, u8 sourceVariant, u16 targetAnim, u8 targetVariant, u16 amount)
{
    u16 source[16];
    u16 target[16];
    struct Sprite sprite;
    u8 i;

    sprite.tilesVram = BG_VRAM;
    sprite.unk1B = 0xFF;
    sprite.x = 0;
    sprite.y = 0;
    sprite.unk14 = 0;
    sprite.unk16 = 0;
    sprite.unk1C = 0x10;
    sprite.palId = paletteId;
    sprite.unk8 = 0x80000;
    if (targetAnim == 0 && targetVariant == 0)
        CpuCopy16(&gObjPalette[paletteId * 16], target, sizeof(target));
    if (sourceAnim != 0 || sourceVariant != 0) {
        sprite.animId = sourceAnim;
        sprite.variant = sourceVariant;
        sub_08155128(&sprite);
    }
    CpuCopy16(&gObjPalette[paletteId * 16], source, sizeof(source));
    if (targetAnim != 0 || targetVariant != 0) {
        sprite.animId = targetAnim;
        sprite.variant = targetVariant;
        sub_08155128(&sprite);
        CpuCopy16(&gObjPalette[paletteId * 16], target, sizeof(target));
    }
    for (i = 1; !(i & 0xF0); i++) {
        u8 srcLow, dstLow;
        u16 srcChannel, dstChannel;
        u16 color;
        s32 difference;
        s32 mask = 31;
        srcLow = source[i];
        dstLow = target[i];
        {
            s32 sourceRed, targetRed;
            // TODO(match): Preserve separate mask copies for the two byte-channel ANDs.
            targetRed = mask;
            asm("" : "+r"(targetRed));
            targetRed &= dstLow;
            sourceRed = mask;
            asm("" : "+r"(sourceRed));
            sourceRed &= srcLow;
            color = ClampPaletteChannel(sourceRed + ((amount * (targetRed - sourceRed)) >> 8));
        }
        srcChannel = source[i] >> 5;
        dstChannel = target[i] >> 5;
        difference = (dstChannel & mask) - (srcChannel & mask);
        color |= ClampPaletteChannel((srcChannel & mask) + ((amount * difference) >> 8)) * 32;
        srcChannel = source[i] >> 10;
        dstChannel = target[i] >> 10;
        difference = (dstChannel & mask) - (srcChannel & mask);
        color |= ClampPaletteChannel((srcChannel & mask) + ((amount * difference) >> 8)) * 1024;
        source[i] = color;
    }
    if (gMainFlags & 0x20000)
        LoadObjPaletteWithTransformation(source, paletteId * 16, 16);
    else {
        DmaCopy16(3, source, &gObjPalette[paletteId * 16], sizeof(source));
        gMainFlags |= MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    SaveObjPaletteColors(paletteId * 16, 16);
}

void OffsetSpriteAnimationPalette(u8 paletteId, u16 anim, u8 variant, s8 red, s8 green, s8 blue, u16 amount)
{
    u16 colors[16];
    struct Sprite sprite;
    u8 i;

    sprite.tilesVram = BG_VRAM;
    sprite.unk1B = 0xFF;
    sprite.x = 0;
    sprite.y = 0;
    sprite.unk14 = 0;
    sprite.unk16 = 0;
    sprite.unk1C = 0x10;
    sprite.palId = paletteId;
    sprite.unk8 = 0x80000;
    if (anim != 0 || variant != 0) {
        sprite.animId = anim;
        sprite.variant = variant;
        sub_08155128(&sprite);
    }
    CpuCopy16(&gObjPalette[paletteId * 16], colors, sizeof(colors));
    for (i = 1; !(i & 0xF0); i++) {
        u8 low;
        u16 color;
        s32 mask = 31;
        low = colors[i];
        {
            s32 delta = (red * amount) >> 8;
            s32 redChannel;
            // TODO(match): Keep a separate red-channel mask copy; the tied input preserves its value.
            asm("" : "=r"(redChannel) : "0"(mask));
            redChannel &= low;
            color = ClampPaletteChannel(redChannel + delta);
        }
        {
            u32 channel = colors[i] >> 5;
            s32 delta = (amount * green) >> 8;
            color |= ClampPaletteChannel((channel & mask) + delta) * 32;
        }
        {
            u32 channel = colors[i] >> 10;
            s32 delta = (amount * blue) >> 8;
            color |= ClampPaletteChannel((channel & mask) + delta) * 1024;
        }
        colors[i] = color;
    }
    if (gMainFlags & 0x20000)
        LoadObjPaletteWithTransformation(colors, paletteId * 16, 16);
    else {
        DmaCopy16(3, colors, &gObjPalette[paletteId * 16], sizeof(colors));
        gMainFlags |= MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    }
    gMainFlags |= MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
    SaveObjPaletteColors(paletteId * 16, 16);
}

const u16 gBrightenRedTable[64] = {
    0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008,
    0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F, 0x0010,
    0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018,
    0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F, 0x001F,
    0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
    0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
    0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
    0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F,
};

const u16 gBrightenGreenTable[64] = {
    0x0020, 0x0040, 0x0060, 0x0080, 0x00A0, 0x00C0, 0x00E0, 0x0100,
    0x0120, 0x0140, 0x0160, 0x0180, 0x01A0, 0x01C0, 0x01E0, 0x0200,
    0x0220, 0x0240, 0x0260, 0x0280, 0x02A0, 0x02C0, 0x02E0, 0x0300,
    0x0320, 0x0340, 0x0360, 0x0380, 0x03A0, 0x03C0, 0x03E0, 0x03E0,
    0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0,
    0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0,
    0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0,
    0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0, 0x03E0,
};

const u16 gBrightenBlueTable[64] = {
    0x0400, 0x0800, 0x0C00, 0x1000, 0x1400, 0x1800, 0x1C00, 0x2000,
    0x2400, 0x2800, 0x2C00, 0x3000, 0x3400, 0x3800, 0x3C00, 0x4000,
    0x4400, 0x4800, 0x4C00, 0x5000, 0x5400, 0x5800, 0x5C00, 0x6000,
    0x6400, 0x6800, 0x6C00, 0x7000, 0x7400, 0x7800, 0x7C00, 0x7C00,
    0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
    0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
    0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
    0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
};

const u16 gDarkenRedTable[64] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
};

const u16 gDarkenGreenTable[64] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0020, 0x0040, 0x0060, 0x0080, 0x00A0, 0x00C0, 0x00E0,
    0x0100, 0x0120, 0x0140, 0x0160, 0x0180, 0x01A0, 0x01C0, 0x01E0,
    0x0200, 0x0220, 0x0240, 0x0260, 0x0280, 0x02A0, 0x02C0, 0x02E0,
    0x0300, 0x0320, 0x0340, 0x0360, 0x0380, 0x03A0, 0x03C0, 0x03E0,
};

const u16 gDarkenBlueTable[64] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0400, 0x0800, 0x0C00, 0x1000, 0x1400, 0x1800, 0x1C00,
    0x2000, 0x2400, 0x2800, 0x2C00, 0x3000, 0x3400, 0x3800, 0x3C00,
    0x4000, 0x4400, 0x4800, 0x4C00, 0x5000, 0x5400, 0x5800, 0x5C00,
    0x6000, 0x6400, 0x6800, 0x6C00, 0x7000, 0x7400, 0x7800, 0x7C00,
};

void (*const gPaletteEffectCallbacks[5])(struct PaletteEffect *) = {
    ApplyPaletteDarkening, ApplyPaletteBrightening, ApplyPaletteTableDarkening, ApplyPaletteRedTint, ApplyPaletteWhiteFill,
};
