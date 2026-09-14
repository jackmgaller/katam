#include "hud.h"
#include "object_collision.h"
#include "global.h"
#include "data.h"
#include "functions.h"
#include "kirby.h"
#include "object.h"
#include "task.h"
#include "code_0806F780.h"
#include "box_boxer.h"
#include "crazy_hand.h"
#include "droppy.h"
#include "gobbler.h"
#include "master_hand.h"
#include "mr_frosty.h"
#include "phan_phan.h"
#include "code_0800E0E4.h"
#include "level.h"
#include "gba/m4a.h"
#include "constants/songs.h"
#include "constants/kirby.h"
#include "prank.h"
#include "soarar.h"

u8 KirbyCanContactOther(struct Kirby *, struct Kirby *);
static void UpdateObjectCollisions(void);
static void ProcessObjectCollisionLists(void);
static void ProcessKirbyContacts(void);
void ResolveSolidObjectCollision(struct ObjectBase *, struct Object *);
static void ObjectCollisionTaskDestructor(struct Task *);

#define COLLISION_AXIS_OVERLAP(a, aSize, b, bSize) \
    (((a) <= (b) && (a) + (aSize) >= (b)) || ((a) >= (b) && (b) + (bSize) >= (a)))

static inline void ClearCollisionCounts(void)
{
    gUnk_02022EB0[0][0] = 0;
    gUnk_02022EB0[0][1] = 0;
    gUnk_02022EB0[1][0] = 0;
    gUnk_02022EB0[1][1] = 0;
    gUnk_02022EB0[2][0] = 0;
    gUnk_02022EB0[2][1] = 0;
    gUnk_02022EB0[3][0] = 0;
    gUnk_02022EB0[3][1] = 0;
    gUnk_02022F40[0] = 0;
    gUnk_02022F40[1] = 0;
    gUnk_02022F40[2] = 0;
    gUnk_02022F40[3] = 0;
}

void CreateObjectCollisionTask(void)
{
    TaskCreate(UpdateObjectCollisions, sizeof(u32), 0xFFFD, 0, ObjectCollisionTaskDestructor);
    gUnk_0203AD40 = 0;
    ClearCollisionCounts();
}

static void UpdateObjectCollisions(void)
{
    ProcessObjectCollisionLists();
    ProcessKirbyContacts();
    sub_0808838C();
    ClearCollisionCounts();
    gUnk_02022F50[0] = NULL;
    gUnk_02022F50[64] = NULL;
    gUnk_02022F50[128] = NULL;
    gUnk_02022F50[192] = NULL;
    gUnk_02022EC0[0][0] = NULL;
    gUnk_02022EC0[1][0] = NULL;
    gUnk_02022EC0[2][0] = NULL;
    gUnk_02022EC0[3][0] = NULL;
    gUnk_0203AD40++;
}

s32 HandleKirbyCollision(struct ObjectBase *attack, struct ObjectBase *other)
{
    u32 flags = other->flags;
    if (!(flags & 0x200)) {
        struct ObjectBase *parent = attack->parent;
        if (parent != other) {
            s32 attackFlags = attack->unk68;
            if (attackFlags & 0x20) {
                // TODO: The original dereferences parent before its null check; preserve that ordering.
                if (!(parent->flags & 0x200)) {
                    u32 defense = other->unk5C;
                    u32 vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                    if ((vulnerableTypes & attackFlags)
                        && (u32)(attackFlags & 7) >= (defense & 7) && !(flags & 0x8000)
                        && (parent == NULL || parent->header.kind != 1 || ((struct Object *)parent)->type != 0x32 || ((struct Kirby *)other)->ability != 0)) {
                        other->unk6C = parent;
                        if (parent == NULL)
                            other->unk6C = attack;
                        other->flags |= 0x40000;
                        sub_0804E09C((struct Kirby *)other);
                    }
                }
            } else {
                u32 defense;
                u32 vulnerableTypes;
                other->unk6C = attack;
                other->flags = flags | 0x40000;
                defense = other->unk5C;
                vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                if ((vulnerableTypes & attackFlags)
                    && (u32)(attackFlags & 7) >= (defense & 7) && !(other->flags & 0x8000)
                    && !(attackFlags & 0x800000))
                    sub_0804A728((struct Kirby *)other);
            }
        }
    }
    return 0;
}

s32 HandleObjectCollision(struct ObjectBase *attack, struct ObjectBase *other)
{
    struct ObjectBase *parent;
    s32 attackFlags, loadedAttackFlags;
    u32 grab;
    u32 flags, defense;
    if (attack->header.kind == 2) {
        if (((struct Object *)other)->type == 0x46 && attack->xspeed < 0)
            return 0;
        if (attack->header.kind == 2 && attack->parent == other)
            return 0;
    }
    if (other->flags & 0x1000000) {
        if (attack->flags & 0x40000)
            return 0;
        if (attack->unk68 & 0x80)
            return 0;
    }
    parent = attack->parent;
    if (parent != NULL && parent->header.kind == 0 && attack->unk56 == gLocalPlayerId)
        TryTrackHudEnemy((struct Object *)other);
    loadedAttackFlags = attack->unk68;
    grab = loadedAttackFlags & 0x20;
    attackFlags = loadedAttackFlags;
    if (grab) {
        struct Object *object = (struct Object *)other;
        struct ObjectBase *parent;
        u32 flags, loadedFlags, noContact;
        u32 loadedDefense, resistant;
        parent = attack->parent;
        if (parent == NULL)
            return 0;
        if (parent->header.kind == 1) {
            u8 type = ((struct Object *)parent)->type;
            if (type != 7 && type != 14)
                return 0;
            if ((u8)(((struct Object *)other)->type - 0x5E) > 14)
                return 0;
            if (!(attack->flags & 0x10000)) {
                other->flags |= 0x40000;
                other->unk6C = parent;
            }
            sub_0809CFC4((struct Object *)other);
            return 1;
        }
        if (attack->unk56 >= gNumHumanPlayers) {
            if ((u8)(((struct Object *)other)->type - 0x5E) <= 14 || ((struct Object *)other)->type == 0xA4
                || (((struct Object *)other)->type == 0xA3 && other->unk56 < gNumHumanPlayers))
                return 0;
        }
        loadedFlags = attack->flags;
        noContact = loadedFlags & 0x10000;
        flags = loadedFlags;
        if (!noContact && !(other->flags & 0x20000)) {
            if ((flags & 0x100000) || (other->flags & 0x200000)) {
                u32 defense = other->unk5C;
                u32 vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
                    object->base.flags |= 0x40000;
                    object->base.unk6C = parent;
                }
            } else {
                object->base.flags |= 0x40000;
                object->base.unk6C = parent;
            }
        }
        if (attackFlags == 0x20000023) {
            object->unk90 &= ~(3 << (attack->unk56 * 2));
            object->unk90 |= 2 << (attack->unk56 * 2);
        } else {
            object->unk90 &= ~(3 << (attack->unk56 * 2));
            object->unk90 |= 1 << (attack->unk56 * 2);
        }
        loadedDefense = other->unk5C;
        resistant = loadedDefense & 0x20;
        defense = loadedDefense;
        if (resistant) {
            if (object->type <= 0xD4 || !(attackFlags & 0x200000))
                return 0;
        }
        if ((attackFlags & 0x200000) && (u8)(object->type - 0x5E) <= 14) {
            attack->flags = flags & ~0x40000;
        } else {
            u32 vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
            if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
                attack->flags = flags | 0x40000;
                object->base.unk6C = parent;
                sub_0809C380(object);
            } else if (!(gUnk_03000510.unk4 & ((1 << other->unk56) | 0x10))) {
                other->objBase54 += (gUnk_0203AD40 & 2) * 2;
            }
        }
        return 0;
    }
    {
        u32 attackStateFlags = attack->flags;
        u32 noContact = attackStateFlags & 0x10000;
        u32 vulnerableTypes, damageTypes;
        defense = other->unk5C;
        if (!noContact) {
            u32 initialOtherFlags = other->flags;
            u32 intangible = initialOtherFlags & 0x20000;
            flags = initialOtherFlags;
            if (!intangible) {
                if ((attackStateFlags & 0x100000) || (flags & 0x200000)) {
                    u32 vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                    if (!(vulnerableTypes & attackFlags))
                        goto contactEffects;
                    if ((u32)(attackFlags & 7) >= (defense & 7)) {
                        other->flags = flags | 0x40000;
                        other->unk6C = attack;
                    }
                } else {
                    other->flags = flags | 0x40000;
                    other->unk6C = attack;
                }
            }
        }
        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
        damageTypes = vulnerableTypes & attackFlags;
        flags = other->flags;
        if (damageTypes && (u32)(attackFlags & 7) >= (defense & 7) && !(flags & 0x8000)) {
            if (attackFlags & 0x8000)
                sub_0809C6D0((struct Object *)other);
            else
                sub_0809B1E4((struct Object *)other);
            if (!(other->unk68 & 0x20000000))
                return 1;
            return 0;
        }
    }
contactEffects:
    if (flags & 0x40000) {
        struct Object *object = (struct Object *)other;
        if (attackFlags & 0x800000) return 0;
        if ((u8)(object->type - 0x38) > 0x1A) {
            if (object->type != 0x6D || !(attackFlags & 0x80))
                sub_0808845C(object, 10);
            if (!(other->flags & 0x8000))
                sub_0808520C(object, 16);
        } else {
            sub_0808845C(object, 10);
            if (!(object->base.flags & 0x8000))
                sub_0808520C(object, 16);
        }
        if (attack->unk68 & 0x10000)
            sub_080884C4(object);
    }
    return 0;
}

s32 HandleAttackObjectCollision(struct ObjectBase *other, struct ObjectBase *attack)
{
    struct ObjectBase *parent;
    // TODO(match): Shift each returned byte before the shared test; a bool8 temporary adds an LSR after the shared LSL.
    u32 handled;
    s32 attackFlags, initialFlags;
    u32 grab;
    u32 flags, defense, vulnerableTypes;
    u32 initialOtherFlags, intangible;
    if (other->header.kind == 1 && ((struct Object *)other)->type == 0x46 && attack->xspeed < 0)
        return 0;
    parent = attack->parent;
    if (parent == other)
        return 0;
    if (other->header.kind == 1 && (other->flags & 0x1000000) && (attack->flags & 0x40000))
        return 0;
    initialFlags = attack->unk68;
    grab = initialFlags & 0x20;
    attackFlags = initialFlags;
    if (grab) {
        attack->unk6C = other;
        defense = other->unk5C;
        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
        if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)
            && !(other->flags & 0x8000)) {
            struct Object *object = (struct Object *)parent;
            if (parent != NULL) {
                parent->unkC &= ~0x40;
                if (parent->header.kind == 1) {
                    switch (((struct Object *)parent)->type) {
                    case 0x32:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080A049C((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x33:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080A1804((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x38:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080CC6F0((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x9E:
                    case 0xAE:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080B6368(object, (struct Kirby *)other) << 24;
                        break;
                    case 0x3A:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080CE94C((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 15:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080B0758((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x48:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080E588C((struct Gobbler *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x9F:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080E74E4((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x3E:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080D4004((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 0x47:
                    case 0x4D:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080E1B8C((struct CrazyHand *)object, (struct Kirby *)other) << 24;
                        break;
                    case 0x3C:
                        if (other->flags & 0x8000)
                            return 0;
                        handled = (u32)sub_080C8548((struct Object *)parent, (struct Kirby *)other) << 24;
                        break;
                    case 7:
                    case 14:
                        handled = (u32)sub_080AC5E0(object, &other->header) << 24;
                        break;
                    default:
                        return 0;
                    }
                    if (handled)
                        return 1;
                    return 0;
                }
            }
        }
    } else {
        initialOtherFlags = other->flags;
        intangible = initialOtherFlags & 0x10000;
        flags = initialOtherFlags;
        if (!intangible) {
            u32 attackObjectFlags = attack->flags;
            if (!(attackObjectFlags & 0x20000)) {
                if (!(flags & 0x100000) && !(attackObjectFlags & 0x200000)) {
                    attack->flags = attackObjectFlags | 0x4000000;
                    attack->unk6C = other;
                } else {
                    u32 defense = other->unk5C;
                    vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                    if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
                        attack->flags = attackObjectFlags | 0x4000000;
                        attack->unk6C = other;
                    }
                }
            }
        }
        {
            s32 interactionFlags = attackFlags;
            // TODO(match): Keep the interaction test in a separate register from the attack flags used afterward.
            asm("" : "+r"(interactionFlags));
            if (interactionFlags & 0x10000000) {
                u32 attackTypeMask = 0x400000;
                if (!(flags & attackTypeMask) && !(flags & 0x10000)) {
                    if (flags & 0x100000) {
                        defense = other->unk5C;
                        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                        if (!(vulnerableTypes & interactionFlags))
                            return 0;
                        if ((u32)(interactionFlags & 7) < (defense & 7))
                            goto CheckDamage;
                    }
                    if (!(attackFlags & attackTypeMask) || !(other->unk5C & attackTypeMask))
                        sub_080853C8((struct Kirby *)parent, 4);
                }
            }
        }
CheckDamage:
        {
            s32 damageFlags;
            defense = other->unk5C;
            vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
            damageFlags = attack->unk68;
            if ((vulnerableTypes & damageFlags) && (u32)(damageFlags & 7) >= (defense & 7)
                && !(other->flags & 0x8000) && !(damageFlags & 0x20000000))
                return 1;
        }
    }
    return 0;
}

void ProcessAttackTileCollisions(struct ObjectBase *attack)
{
    s8 bounds[4];
    u8 row, width, height, column;
    u16 tileX, tileY;
    if (attack->unk68 & 0x20) {
        s16 maxX, minX, maxY, minY;
        s8 direction = 1;
        if (attack->flags & 0x40000)
            return;
        maxX = gCurLevelInfo[attack->unk56].levelMaxPosition.x >> 12;
        maxY = gCurLevelInfo[attack->unk56].levelMaxPosition.y >> 12;
        minX = gCurLevelInfo[attack->unk56].levelMinPosition.x >> 12;
        minY = gCurLevelInfo[attack->unk56].levelMinPosition.y >> 12;
        if (attack->flags & 1) {
            bounds[2] = -attack->unk3C;
            bounds[0] = -attack->unk3E;
        } else {
            bounds[0] = attack->unk3C;
            bounds[2] = attack->unk3E;
        }
        bounds[1] = attack->unk3D;
        bounds[3] = attack->unk3F;
        if (attack->flags & 1)
            direction = -1;
        width = ((abs(bounds[2] - bounds[0]) + ((attack->x >> 8) & 15)) >> 4) + 1;
        height = (abs(bounds[3] - bounds[1]) + (((attack->y >> 8) + bounds[1]) & 15)) >> 4;
        tileY = attack->y >> 12;
        for (row = 0; row <= height; ++row) {
            if (tileY <= maxY && tileY >= minY) {
                tileX = attack->x >> 12;
                for (column = width; column != 0; ) {
                    --column;
                    if (tileX > maxX)
                        break;
                    if (tileX < minX)
                        break;
                    if ((gCollisionAttributes[GetCollisionTile(attack->unk56, tileX, tileY)] & 0xF01000) == 0x1000) {
                        sub_08001408(attack->unk56, sub_080025AC(attack->unk56, tileX, tileY), NULL, NULL);
                        sub_08088F84(attack->parent, tileX, tileY);
                        attack->flags |= 0x80000;
                        return;
                    }
                    tileX += direction;
                }
                if (row & 1)
                    tileY += row + 1;
                else
                    tileY = (u16)(tileY - 1) - row;
            }
        }
    } else {
        s16 clip;
        if (attack->flags & 1) {
            bounds[2] = -attack->unk3C;
            bounds[0] = -attack->unk3E;
        } else {
            bounds[0] = attack->unk3C;
            bounds[2] = attack->unk3E;
        }
        bounds[1] = attack->unk3D;
        bounds[3] = attack->unk3F;
        width = (abs(bounds[2] - bounds[0]) + (((attack->x >> 8) + bounds[0]) & 15)) >> 4;
        height = (abs(bounds[3] - bounds[1]) + (((attack->y >> 8) + bounds[1]) & 15)) >> 4;
        tileX = ((attack->x >> 8) + bounds[0]) >> 4;
        tileY = ((attack->y >> 8) + bounds[1]) >> 4;
        clip = (gCurLevelInfo[attack->unk56].levelMaxPosition.x >> 12) - (width + tileX);
        if (clip & 0x8000) {
            width += clip;
            if (width & 0x80)
                return;
        }
        clip = tileX - (gCurLevelInfo[attack->unk56].levelMinPosition.x >> 12);
        if (clip & 0x8000) {
            if (width < -clip)
                return;
            tileX -= clip;
            width += clip;
        }
        clip = (gCurLevelInfo[attack->unk56].levelMaxPosition.y >> 12) - (tileY + height);
        if (clip & 0x8000) {
            height += clip;
            if (height & 0x80)
                return;
        }
        clip = tileY - (gCurLevelInfo[attack->unk56].levelMinPosition.y >> 12);
        if (clip & 0x8000) {
            if (height < -clip)
                return;
            tileY -= clip;
            height += clip;
        }
        for (row = height + 1; row != 0;) {
            --row;
            for (column = width + 1; column != 0;) {
                u32 attributes;
                --column;
                attributes = gCollisionAttributes[GetCollisionTile(attack->unk56, tileX + column, row + tileY)];
                // TODO(match): Three input references prioritize attack over column in agbcc; two swap r6/r7.
                asm("" : : "r"(attack), "r"(attack), "r"(attack));
                if (attributes & 0x1000) {
                    switch (attributes & 0xF00000) {
                    case 0x200000:
                        if (!(attack->unk68 & 0x1000)) continue;
                        break;
                    case 0x300000:
                        if (!(attack->unk68 & 0x4000)) continue;
                        break;
                    case 0x400000:
                        if (!(attack->unk68 & 0x800)) continue;
                        break;
                    }
                    if (attributes & 0x20) {
                        sub_08001408(attack->unk56, sub_080025AC(attack->unk56, column + tileX, row + tileY), NULL, NULL);
                        sub_0800E0E4((struct Object *)attack, column + tileX, row + tileY);
                        PlaySfx(attack, SE_BLOCK_BREAK);
                    } else {
                        struct EffectObject *effect;
                        sub_08001408(attack->unk56, sub_080025AC(attack->unk56, column + tileX, row + tileY), NULL, NULL);
                        effect = CreateEffectObject(attack, 0, 0x28D, 0);
                        effect->x = ((column + tileX) * 0x1000) + 0x800;
                        effect->y = ((row + tileY) * 0x1000) + 0x800;
                        PlaySfx(attack, SE_BLOCK_BREAK);
                        if (attack->unk68 & 0x10000000) {
                            sub_08085328(attack->parent);
                            RequestScreenShake(2, attack);
                        }
                    }
                    attack->flags |= 0x80000;
                }
            }
        }
    }
}

extern s32 (*const gObjectCollisionCallbacks[3])(struct ObjectBase *, struct ObjectBase *);

static inline bool32 AttackOverlapsObject(struct ObjectBase *attack, s32 ax, s32 ay,
    struct ObjectBase *other, bool32 requireArea)
{
    s32 bx, by;
    if (other->flags & 1)
        bx = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
    else
        bx = (other->x >> 8) + other->unk38;
    by = (other->y >> 8) + other->unk39;
    if ((!requireArea || (attack->unk3A != 0 && attack->unk3B != 0))
        && COLLISION_AXIS_OVERLAP(ax, attack->unk3A * 2, bx, other->unk3A * 2)
        && COLLISION_AXIS_OVERLAP(ay, attack->unk3B * 2, by, other->unk3B * 2))
        return TRUE;
    if (attack->sprite.unk20[0].unk0 == 0) {
        s32 left = (attack->x >> 8) + attack->sprite.unk20[0].unk4;
        s32 top = (attack->y >> 8) + attack->sprite.unk20[0].unk5;
        if (COLLISION_AXIS_OVERLAP(left, attack->sprite.unk20[0].unk6 - attack->sprite.unk20[0].unk4,
                bx, other->unk3A * 2)
            && COLLISION_AXIS_OVERLAP(top, attack->sprite.unk20[0].unk7 - attack->sprite.unk20[0].unk5,
                by, other->unk3B * 2))
            return TRUE;
    }
    return FALSE;
}

static inline void CommitAttackContact(struct ObjectBase *attack)
{
    if (attack->flags & 0x4000000)
        attack->flags = (attack->flags | 0x40000) & ~0x4000000;
}

// TODO(match): The frame is 48 rather than 24 bytes: ax, ay and the attack cursor spill
// instead of living in r8, r9 and r7, and the Kirby hit body is emitted once, not twice.
#ifndef NONMATCHING
static NAKED void ProcessObjectCollisionLists(void)
{
    asm(".include \"asm/nonmatching/ProcessObjectCollisionLists.inc\"");
}
#else
static void ProcessObjectCollisionLists(void)
{
    u8 group;
    u8 count;
    u8 otherCount;
    struct ObjectBase **slot;
    struct ObjectBase **otherSlot;
    struct ObjectBase *other;
    s32 ax, ay;
    s32 bx, by;
    for (group = 0; group < gNumKirbys; ++group) {
        slot = (struct ObjectBase **)gUnk_02022EC0[group];
        for (count = gUnk_02022F40[group]; count != 0; --count, ++slot) {
            if (*slot != NULL) {
                for (otherCount = 0; otherCount < gNumKirbys; ++otherCount) {
                    other = &gKirbys[otherCount].base;
                    if ((*slot)->roomId == other->roomId && !(other->flags & 0x100))
                        ResolveSolidObjectCollision(other, (struct Object *)*slot);
                }
                otherSlot = &gUnk_02022F50[group << 6];
                for (otherCount = gUnk_02022EB0[0][group * 2]; otherCount != 0; --otherCount, ++otherSlot) {
                    struct ObjectBase *object = *otherSlot;
                    if ((object->unkC & 0x1000) && (*slot)->roomId == object->roomId && !(object->flags & 0x100))
                        ResolveSolidObjectCollision(object, (struct Object *)*slot);
                }
            }
        }
        slot = &gUnk_02022F50[(group * 64) | 32];
        for (count = gUnk_02022EB0[0][group * 2 + 1]; count != 0; --count, ++slot) {
            if (*slot == NULL)
                continue;
            if ((*slot)->flags & 1)
                ax = ((*slot)->x >> 8) + (-(*slot)->unk38 - (*slot)->unk3A * 2);
            else
                ax = ((*slot)->x >> 8) + (*slot)->unk38;
            ay = ((*slot)->y >> 8) + (*slot)->unk39;
            if ((*slot)->flags & 0x20000000) {
                otherSlot = &gUnk_02022F50[group * 64];
                for (otherCount = gUnk_02022EB0[0][group * 2]; otherCount != 0; --otherCount, ++otherSlot) {
                    other = *otherSlot;
                    if (other == NULL)
                        continue;
                    if ((*slot)->flags & 0x200)
                        break;
                    if (other->flags & 0x200)
                        continue;
                    if (other->flags & 1)
                        bx = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
                    else
                        bx = (other->x >> 8) + other->unk38;
                    by = (other->y >> 8) + other->unk39;
                    if (((*slot)->unk3A != 0 && (*slot)->unk3B != 0 && COLLISION_AXIS_OVERLAP(ax, (*slot)->unk3A * 2, bx, other->unk3A * 2) && COLLISION_AXIS_OVERLAP(ay, (*slot)->unk3B * 2, by, other->unk3B * 2))
                        || ((*slot)->sprite.unk20[0].unk0 == 0 && COLLISION_AXIS_OVERLAP(((*slot)->x >> 8) + (*slot)->sprite.unk20[0].unk4, (*slot)->sprite.unk20[0].unk6 - (*slot)->sprite.unk20[0].unk4, bx, other->unk3A * 2) && COLLISION_AXIS_OVERLAP(((*slot)->y >> 8) + (*slot)->sprite.unk20[0].unk5, (*slot)->sprite.unk20[0].unk7 - (*slot)->sprite.unk20[0].unk5, by, other->unk3B * 2))) {
                        u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                        if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*slot, *otherSlot))
                            *otherSlot = NULL;
                        if (consumed) {
                            CommitAttackContact(*slot);
                            *slot = NULL;
                            break;
                        }
                    }
                }
                if (*slot == NULL)
                    continue;
                CommitAttackContact(*slot);
            }
            if ((*slot)->flags & 0x10000000) {
                for (otherCount = 0; otherCount < gNumKirbys; ++otherCount) {
                    other = &gKirbys[otherCount].base;
                    if ((*slot)->roomId != other->roomId)
                        continue;
                    if ((*slot)->flags & 0x200)
                        break;
                    if (other->flags & 0x200)
                        continue;
                    if (other->flags & 1)
                        bx = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
                    else
                        bx = (other->x >> 8) + other->unk38;
                    by = (other->y >> 8) + other->unk39;
                    if ((*slot)->unk3A != 0 && (*slot)->unk3B != 0
                        && COLLISION_AXIS_OVERLAP(ax, (*slot)->unk3A * 2, bx, other->unk3A * 2)
                        && COLLISION_AXIS_OVERLAP(ay, (*slot)->unk3B * 2, by, other->unk3B * 2)) {
                        u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                        if ((u16)gObjectCollisionCallbacks[other->header.kind](*slot, other))
                            other = NULL;
                        if (consumed) {
                            CommitAttackContact(*slot);
                            *slot = NULL;
                            break;
                        }
                    } else if ((*slot)->sprite.unk20[0].unk0 == 0) {
                        s32 left = ((*slot)->x >> 8) + (*slot)->sprite.unk20[0].unk4;
                        if (COLLISION_AXIS_OVERLAP(left, (*slot)->sprite.unk20[0].unk6 - (*slot)->sprite.unk20[0].unk4, bx, other->unk3A * 2)) {
                            s32 top = ((*slot)->y >> 8) + (*slot)->sprite.unk20[0].unk5;
                            if (COLLISION_AXIS_OVERLAP(top, (*slot)->sprite.unk20[0].unk7 - (*slot)->sprite.unk20[0].unk5, by, other->unk3B * 2)) {
                                u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                                if ((u16)gObjectCollisionCallbacks[other->header.kind](*slot, other))
                                    other = NULL;
                                if (consumed) {
                                    CommitAttackContact(*slot);
                                    *slot = NULL;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (*slot == NULL)
                    continue;
                CommitAttackContact(*slot);
            }
            if ((*slot)->flags & 0x40000000) {
                otherSlot = &gUnk_02022F50[(group * 64) | 32];
                for (otherCount = gUnk_02022EB0[0][group * 2 + 1]; otherCount != 0; --otherCount, ++otherSlot) {
                    other = *otherSlot;
                    if (other == NULL)
                        continue;
                    if (other == *slot)
                        continue;
                    if ((*slot)->flags & 0x200)
                        break;
                    if (other->flags & 0x200)
                        continue;
                    if (other->flags & 1)
                        bx = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
                    else
                        bx = (other->x >> 8) + other->unk38;
                    by = (other->y >> 8) + other->unk39;
                    if (COLLISION_AXIS_OVERLAP(ax, (*slot)->unk3A * 2, bx, other->unk3A * 2)
                        && COLLISION_AXIS_OVERLAP(ay, (*slot)->unk3B * 2, by, other->unk3B * 2)) {
                        u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                        if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*slot, *otherSlot)) {
                            *otherSlot = NULL;
                            break;
                        }
                        if (consumed) {
                            *slot = NULL;
                            break;
                        }
                    } else if ((*slot)->sprite.unk20[0].unk0 == 0) {
                        s32 left = ((*slot)->x >> 8) + (*slot)->sprite.unk20[0].unk4;
                        if (COLLISION_AXIS_OVERLAP(left, (*slot)->sprite.unk20[0].unk6 - (*slot)->sprite.unk20[0].unk4, bx, other->unk3A * 2)) {
                            s32 top = ((*slot)->y >> 8) + (*slot)->sprite.unk20[0].unk5;
                            if (COLLISION_AXIS_OVERLAP(top, (*slot)->sprite.unk20[0].unk7 - (*slot)->sprite.unk20[0].unk5, by, other->unk3B * 2)) {
                                u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                                if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*slot, *otherSlot)) {
                                    *otherSlot = NULL;
                                    break;
                                }
                                if (consumed) {
                                    *slot = NULL;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (*slot == NULL)
                    continue;
                CommitAttackContact(*slot);
            }
            if ((s32)(*slot)->flags < 0)
                ProcessAttackTileCollisions(*slot);
        }
        slot = &gUnk_02022F50[group * 64];
        for (count = gUnk_02022EB0[0][group * 2]; count != 0; --count, ++slot) {
            if (*slot == NULL)
                continue;
            if ((*slot)->flags & 1)
                ax = ((*slot)->x >> 8) + (-(*slot)->unk38 - (*slot)->unk3A * 2);
            else
                ax = ((*slot)->x >> 8) + (*slot)->unk38;
            ay = ((*slot)->y >> 8) + (*slot)->unk39;
            if ((*slot)->flags & 0x20000000) {
                otherSlot = &gUnk_02022F50[group * 64];
                for (otherCount = gUnk_02022EB0[0][group * 2]; otherCount != 0; --otherCount, ++otherSlot) {
                    other = *otherSlot;
                    if (other == NULL)
                        continue;
                    if (other == *slot)
                        continue;
                    if ((*slot)->flags & 0x200)
                        break;
                    if (other->flags & 0x200)
                        continue;
                    if (other->flags & 1)
                        bx = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
                    else
                        bx = (other->x >> 8) + other->unk38;
                    by = (other->y >> 8) + other->unk39;
                    if (COLLISION_AXIS_OVERLAP(ax, (*slot)->unk3A * 2, bx, other->unk3A * 2)
                        && COLLISION_AXIS_OVERLAP(ay, (*slot)->unk3B * 2, by, other->unk3B * 2)) {
                        u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                        if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*slot, *otherSlot)) {
                            *otherSlot = NULL;
                            break;
                        }
                        if (consumed) {
                            *slot = NULL;
                            break;
                        }
                    } else if ((*slot)->sprite.unk20[0].unk0 == 0) {
                        s32 left = ((*slot)->x >> 8) + (*slot)->sprite.unk20[0].unk4;
                        if (COLLISION_AXIS_OVERLAP(left, (*slot)->sprite.unk20[0].unk6 - (*slot)->sprite.unk20[0].unk4, bx, other->unk3A * 2)) {
                            s32 top = ((*slot)->y >> 8) + (*slot)->sprite.unk20[0].unk5;
                            if (COLLISION_AXIS_OVERLAP(top, (*slot)->sprite.unk20[0].unk7 - (*slot)->sprite.unk20[0].unk5, by, other->unk3B * 2)) {
                                u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                                if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*slot, *otherSlot)) {
                                    *otherSlot = NULL;
                                    break;
                                }
                                if (consumed) {
                                    *slot = NULL;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (*slot == NULL)
                    continue;
            }
            if ((*slot)->flags & 0x10000000) {
                for (otherCount = 0; otherCount < gNumKirbys; ++otherCount) {
                    other = &gKirbys[otherCount].base;
                    if ((*slot)->roomId == other->roomId) {
                        if ((*slot)->flags & 0x200)
                            break;
                        if (!(other->flags & 0x200)) {
                            if (other->flags & 1)
                                bx = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
                            else
                                bx = (other->x >> 8) + other->unk38;
                            by = (other->y >> 8) + other->unk39;
                            if (COLLISION_AXIS_OVERLAP(ax, (*slot)->unk3A * 2, bx, other->unk3A * 2)
                                && COLLISION_AXIS_OVERLAP(ay, (*slot)->unk3B * 2, by, other->unk3B * 2)) {
                                u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                                if ((u16)gObjectCollisionCallbacks[other->header.kind](*slot, other))
                                    break;
                                if (consumed) {
                                    *slot = NULL;
                                    break;
                                }
                            } else if ((*slot)->sprite.unk20[0].unk0 == 0) {
                                s32 left = ((*slot)->x >> 8) + (*slot)->sprite.unk20[0].unk4;
                                if (COLLISION_AXIS_OVERLAP(left, (*slot)->sprite.unk20[0].unk6 - (*slot)->sprite.unk20[0].unk4, bx, other->unk3A * 2)) {
                                    s32 top = ((*slot)->y >> 8) + (*slot)->sprite.unk20[0].unk5;
                                    if (COLLISION_AXIS_OVERLAP(top, (*slot)->sprite.unk20[0].unk7 - (*slot)->sprite.unk20[0].unk5, by, other->unk3B * 2)) {
                                        u8 consumed = gObjectCollisionCallbacks[(*slot)->header.kind](other, *slot);
                                        if ((u16)gObjectCollisionCallbacks[other->header.kind](*slot, other))
                                            break;
                                        if (consumed) {
                                            *slot = NULL;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (*slot == NULL)
                    continue;
            }
            if ((s32)(*slot)->flags < 0 && !((*slot)->flags & 0x40000))
                ProcessAttackTileCollisions(*slot);
        }
    }
}
#endif

void ResolveSolidObjectCollision(struct ObjectBase *object, struct Object *solid)
{
    s8 a[4], b[4];
    bool32 previousOverlap[2];
    u8 widthA, widthB, heightA, heightB;
    bool8 overlapX, overlapY;
    u32 solidFlags, savedFlags, facing;

    if (object->flags & 1) {
        a[2] = -object->unk3C;
        a[0] = -object->unk3E;
    } else {
        a[0] = object->unk3C;
        a[2] = object->unk3E;
    }
    a[1] = object->unk3D;
    a[3] = object->unk3F;
    solidFlags = solid->base.flags;
    facing = solidFlags & 1;
    savedFlags = solidFlags;
    if (facing) {
        b[2] = -solid->base.unk3C;
        b[0] = -solid->base.unk3E;
    } else {
        b[0] = solid->base.unk3C;
        b[2] = solid->base.unk3E;
    }
    b[1] = solid->base.unk3D;
    b[3] = solid->base.unk3F;
    widthA = a[2] - a[0];
    widthB = b[2] - b[0];
    heightA = a[3] - a[1];
    heightB = b[3] - b[1];
    previousOverlap[0] = COLLISION_AXIS_OVERLAP(object->unk48 + a[0] * 256, widthA * 256, solid->base.unk48 + b[0] * 256, widthB * 256);
    previousOverlap[1] = COLLISION_AXIS_OVERLAP(object->unk4C + a[1] * 256, heightA * 256, solid->base.unk4C + b[1] * 256, heightB * 256);
    overlapX = COLLISION_AXIS_OVERLAP(object->x + a[0] * 256, widthA * 256, solid->base.x + b[0] * 256, widthB * 256);
    overlapY = COLLISION_AXIS_OVERLAP(object->y + a[1] * 256, heightA * 256, solid->base.y + b[1] * 256, heightB * 256);
    if (overlapX && overlapY) {
        if (savedFlags & 0x80) {
            object->unk62 |= 0x10;
            object->unk6C = solid;
            return;
        }
        if (previousOverlap[0] && !previousOverlap[1]
            && object->x != solid->base.x + (b[2] - a[0]) * 256
            && object->x != solid->base.x + (b[0] - a[2]) * 256) {
            if (object->yspeed > 0) {
                s32 tolerance = object->yspeed + 0x300;
                if (abs((object->y + a[1] * 256) - (solid->base.y + b[3] * 256)) < tolerance) {
                    object->unk62 |= 8;
                    solid->base.unk62 |= 4;
                    object->y = solid->base.y + (b[3] - a[1]) * 256 + (solid->base.yspeed + 0x100);
                    object->yspeed = 0;
                }
            }
            if (object->yspeed <= 0 || solid->base.yspeed != 0) {
                s32 tolerance = 0x300 - object->yspeed;
                if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) < tolerance) {
                    object->unk62 |= 4;
                    solid->base.unk62 |= 8;
                    object->y = solid->base.y + (b[1] - a[3] + 1) * 256;
                    if ((object->flags & 0x40) && object->yspeed > 0)
                        object->yspeed &= 0xFF;
                    else
                        object->yspeed = 0;
                    object->kirby2 = (struct Kirby *)solid;
                }
            }
        }
        if (!previousOverlap[0] && previousOverlap[1]) {
            s32 tolerance = 0x200 - object->yspeed;
            if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) > tolerance) {
                if (object->x > solid->base.x) {
                    s32 distance = solid->base.xspeed - (object->xspeed - 0x400);
                    if (abs((object->x + a[0] * 256) - (solid->base.x + b[2] * 256)) < distance) {
                        if (object->flags & 1)
                            object->unk62 |= 1;
                        else
                            object->unk62 |= 2;
                        if (solid->base.flags & 1)
                            solid->base.unk62 |= 2;
                        else
                            solid->base.unk62 |= 1;
                        object->x = solid->base.x + (b[2] - a[0]) * 256;
                    } else if (object->yspeed == 0) {
                        object->x += 0x100;
                    }
                } else {
                    s32 distance = (object->xspeed + 0x400) - solid->base.xspeed;
                    if (abs((object->x + a[2] * 256) - (solid->base.x + b[0] * 256)) < distance) {
                        if (object->flags & 1)
                            object->unk62 |= 2;
                        else
                            object->unk62 |= 1;
                        if (solid->base.flags & 1)
                            solid->base.unk62 |= 1;
                        else
                            solid->base.unk62 |= 2;
                        object->x = solid->base.x + (b[0] - a[2]) * 256;
                    } else if (object->yspeed == 0) {
                        object->x -= 0x100;
                    }
                }
            }
        }
        if (!previousOverlap[0] && !previousOverlap[1]) {
            s32 tolerance;

            if (object->y > solid->base.y) {
                if (object->yspeed > 0) {
                    s32 tolerance = object->yspeed + 0x300;
                    if (abs((object->y + a[1] * 256) - (solid->base.y + b[3] * 256)) < tolerance) {
                        object->unk62 |= 8;
                        solid->base.unk62 |= 4;
                        object->y = solid->base.y + (b[3] - a[1]) * 256 + (solid->base.yspeed + 0x100);
                        object->yspeed = 0;
                    }
                }
            } else if (object->yspeed <= 0) {
                s32 tolerance = 0x300 - object->yspeed;
                if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) < tolerance) {
                    object->unk62 |= 4;
                    solid->base.unk62 |= 8;
                    object->y = solid->base.y + (b[1] - a[3] + 1) * 256;
                    if ((object->flags & 0x40) && object->yspeed > 0)
                        object->yspeed &= 0xFF;
                    else
                        object->yspeed = 0;
                    object->kirby2 = (struct Kirby *)solid;
                }
            }
            tolerance = 0x200 - object->yspeed;
            if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) > tolerance) {
                if (object->x > solid->base.x) {
                    s32 distance = solid->base.xspeed - (object->xspeed - 0x400);
                    if (abs((object->x + a[0] * 256) - (solid->base.x + b[2] * 256)) < distance) {
                        if (object->flags & 1)
                            object->unk62 |= 1;
                        else
                            object->unk62 |= 2;
                        if (solid->base.flags & 1)
                            solid->base.unk62 |= 2;
                        else
                            solid->base.unk62 |= 1;
                        object->x = solid->base.x + (b[2] - a[0]) * 256;
                    } else if (object->yspeed == 0) {
                        object->x += 0x100;
                    }
                } else {
                    s32 distance = (object->xspeed + 0x400) - solid->base.xspeed;
                    if (abs((object->x + a[2] * 256) - (solid->base.x + b[0] * 256)) < distance) {
                        if (object->flags & 1)
                            object->unk62 |= 2;
                        else
                            object->unk62 |= 1;
                        if (solid->base.flags & 1)
                            solid->base.unk62 |= 1;
                        else
                            solid->base.unk62 |= 2;
                        object->x = solid->base.x + (b[0] - a[2]) * 256;
                    } else if (object->yspeed == 0) {
                        object->x -= 0x100;
                    }
                }
            }
        }
        if (previousOverlap[0] && previousOverlap[1]) {
            s32 tolerance;

            if (object->x != solid->base.x + (b[2] - a[0]) * 256
                && object->x != solid->base.x + (b[0] - a[2]) * 256) {
                s32 tolerance = 0x300 - object->yspeed;
                if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) < tolerance) {
                    object->unk62 |= 4;
                    solid->base.unk62 |= 8;
                    object->y = solid->base.y + (b[1] - a[3] + 1) * 256;
                    if ((object->flags & 0x40) && object->yspeed > 0)
                        object->yspeed &= 0xFF;
                    else
                        object->yspeed = 0;
                    object->kirby2 = (struct Kirby *)solid;
                } else if (object->yspeed > 0) {
                    s32 tolerance = object->yspeed + 0x300;
                    if (abs((object->y + a[1] * 256) - (solid->base.y + b[3] * 256)) < tolerance) {
                        object->unk62 |= 8;
                        solid->base.unk62 |= 4;
                        object->y = solid->base.y + (b[3] - a[1]) * 256 + (solid->base.yspeed + 0x100);
                        object->yspeed = 0;
                    }
                }
            }
            tolerance = 0x200 - object->yspeed;
            if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) > tolerance) {
                if (object->x > solid->base.x) {
                    s32 distance = solid->base.xspeed - (object->xspeed - 0x400);
                    if (abs((object->x + a[0] * 256) - (solid->base.x + b[2] * 256)) < distance) {
                        if (object->flags & 1)
                            object->unk62 |= 1;
                        else
                            object->unk62 |= 2;
                        if (solid->base.flags & 1)
                            solid->base.unk62 |= 2;
                        else
                            solid->base.unk62 |= 1;
                        object->x = solid->base.x + (b[2] - a[0]) * 256;
                    } else if (object->yspeed == 0) {
                        object->x += 0x100;
                    }
                } else {
                    s32 distance = (object->xspeed + 0x400) - solid->base.xspeed;
                    if (abs((object->x + a[2] * 256) - (solid->base.x + b[0] * 256)) < distance) {
                        if (object->flags & 1)
                            object->unk62 |= 2;
                        else
                            object->unk62 |= 1;
                        if (solid->base.flags & 1)
                            solid->base.unk62 |= 1;
                        else
                            solid->base.unk62 |= 2;
                        object->x = solid->base.x + (b[0] - a[2]) * 256;
                    } else if (object->yspeed == 0) {
                        object->x -= 0x100;
                    }
                }
            }
        }
    }
}

#define CanKirbyShare(kirby) \
    (((kirby)->ability != KIRBY_ABILITY_UFO \
        && ((((kirby)->animationIndex <= 0x15 || (kirby)->animationIndex == 0x19 || (kirby)->animationIndex == 0x2F) \
                && (kirby)->animationIndex != 0xD) \
            || (u16)((kirby)->animationIndex - 0x38) <= 7)) \
        || ((kirby)->ability == KIRBY_ABILITY_UFO \
            && ((kirby)->animationIndex <= 0x12 || (u16)((kirby)->animationIndex - 0x21) <= 13)))

static inline bool32 CanKirbyShareIndex(struct Kirby *kirbys, s32 index)
{
    if (kirbys[index].ability != KIRBY_ABILITY_UFO) {
        if ((kirbys[index].animationIndex <= 0x15 || kirbys[index].animationIndex == 0x19 || kirbys[index].animationIndex == 0x2F)
            && kirbys[index].animationIndex != 0xD)
            return TRUE;
        if ((u16)(kirbys[index].animationIndex - 0x38) <= 7)
            return TRUE;
    }
    if (kirbys[index].ability == KIRBY_ABILITY_UFO
        && (kirbys[index].animationIndex <= 0x12 || (u16)(kirbys[index].animationIndex - 0x21) <= 13))
        return TRUE;
    return FALSE;
}

static inline bool32 CanKirbyShareIndexLoaded(struct Kirby *kirbys, s32 index, u8 ability)
{
    if (ability != KIRBY_ABILITY_UFO) {
        if ((kirbys[index].animationIndex <= 0x15 || kirbys[index].animationIndex == 0x19 || kirbys[index].animationIndex == 0x2F)
            && kirbys[index].animationIndex != 0xD)
            return TRUE;
        {
            struct Kirby *current = kirbys;
            if ((u16)(current[index].animationIndex - 0x38) <= 7)
                return TRUE;
            if (current[index].ability != KIRBY_ABILITY_UFO)
                return FALSE;
        }
    }
    if (kirbys[index].animationIndex <= 0x12 || (u16)(kirbys[index].animationIndex - 0x21) <= 13)
        return TRUE;
    return FALSE;
}

static void ProcessKirbyContacts(void)
{
    u8 firstId, secondId;
    for (firstId = 0; firstId < gNumKirbys; ++firstId) {
        struct ObjectBase *firstBase = &gKirbys[firstId].base;
        struct Kirby *first = (struct Kirby *)firstBase;
        if ((gUnk_03000510.unk4 & (0x10 | (1 << firstId)))
            || (firstBase->flags & 0x3800F00) || first->stateFn == sub_080566E0
            || (u16)(first->animationIndex - 0x4A) <= 15 || firstBase->sprite.animId == 0x220)
            continue;
        for (secondId = firstId + 1; secondId < gNumKirbys; ++secondId) {
            struct Kirby *second = &gKirbys[secondId];
            bool8 overlap;
            // The original repeats the first Kirby's animation check here.
            if ((second->base.flags & 0x3800F00) || gKirbys[secondId].stateFn == sub_080566E0
                || (u16)(first->animationIndex - 0x4A) <= 15 || second->base.sprite.animId == 0x220
                || second->base.roomId != firstBase->roomId)
                continue;
            overlap = KirbyCanContactOther((struct Kirby *)firstBase, second);
            if (overlap && first->ability != KIRBY_ABILITY_MINI) {
                if (gKirbys[secondId].ability != KIRBY_ABILITY_MINI
                    && first->unkE5 != 0 && !((first->unkE1 >> secondId) & 1)) {
                    if (CanKirbyShare(first)) {
                        u8 ability = gKirbys[secondId].ability;
                        struct Kirby *kirbys = gKirbys;
                        if (CanKirbyShareIndexLoaded(kirbys, secondId, ability)
                            && (first->base.unk56 < gNumHumanPlayers || kirbys[secondId].base.unk56 < gNumHumanPlayers)) {
                            sub_08053DAC(first, secondId);
                            sub_08054414(&gKirbys[secondId], firstId);
                            first->unkE1 |= 1 << secondId;
                            continue;
                        }
                    }
                } else if (first->ability != KIRBY_ABILITY_MINI) {
                    u8 ability = gKirbys[secondId].ability;
                    struct Kirby *kirbys = gKirbys;
                    if (ability != KIRBY_ABILITY_MINI
                        && gKirbys[secondId].unkE5 != 0 && !((gKirbys[secondId].unkE1 >> firstId) & 1)) {
                        if (CanKirbyShare(first)) {
                            if (CanKirbyShareIndex(kirbys, secondId)
                                && (first->base.unk56 < gNumHumanPlayers || kirbys[secondId].base.unk56 < gNumHumanPlayers)) {
                                u32 offset = secondId * sizeof(struct Kirby);
                                // TODO(match): Typed pointer arithmetic reverses the ADD operands (r3, r4 instead of r4, r3).
                                sub_08053DAC((struct Kirby *)(offset + (u32)kirbys), firstId);
                                sub_08054414(first, secondId);
                                kirbys[secondId].unkE1 |= 1 << firstId;
                                continue;
                            }
                        }
                    }
                }
            }
            if ((firstBase->unk62 & 4) && (second->base.unk62 & 4)) {
                if (overlap) {
                    if (firstBase->x > second->base.x) {
                        if ((!(firstBase->unk62 & 1) || (firstBase->flags & 1))
                            && (!(firstBase->unk62 & 2) || !(firstBase->flags & 1)))
                            first->unkF4 += 0x80;
                        // Both pushes use the first Kirby's wall-contact flags.
                        if ((!(firstBase->unk62 & 1) || !(firstBase->flags & 1))
                            && (!(firstBase->unk62 & 2) || (firstBase->flags & 1)))
                            second->unkF4 -= 0x40;
                    } else {
                        if ((!(firstBase->unk62 & 1) || !(firstBase->flags & 1))
                            && (!(firstBase->unk62 & 2) || (firstBase->flags & 1)))
                            first->unkF4 -= 0x80;
                        if ((!(firstBase->unk62 & 1) || (firstBase->flags & 1))
                            && (!(firstBase->unk62 & 2) || !(firstBase->flags & 1)))
                            second->unkF4 += 0x40;
                    }
                } else {
                    first->unk104 |= 7 << (secondId * 4);
                }
            } else {
                u32 shift, testShift, contactBits;
                contactBits = first->unk104;
                testShift = secondId * 4;
                contactBits &= 7 << testShift;
                shift = testShift;
                if (contactBits && overlap) {
                    if (firstBase->y < second->base.y) {
                        firstBase->unkC |= 0x100;
                        firstBase->unk62 |= 4;
                        firstBase->yspeed = 0;
                        first->unk104 -= 1 << shift;
                    } else {
                        firstBase->objBase55++;
                    }
                }
                if (!overlap) {
                    u16 *contactField = &first->unk104;
                    u32 contacts = *contactField;
                    u32 mask = 7 << shift;
                    if ((contacts & mask) != mask) {
                        if (firstBase->y > second->base.y - 0x1000)
                            contacts &= ~mask;
                        else
                            contacts |= mask;
                    } else {
                        contacts |= contacts & mask;
                    }
                    *contactField = contacts;
                }
                overlap = KirbyCanContactOther(second, (struct Kirby *)firstBase);
                contactBits = gKirbys[secondId].unk104;
                testShift = firstId * 4;
                contactBits &= 7 << testShift;
                shift = testShift;
                if (contactBits && overlap) {
                    if (firstBase->y > second->base.y) {
                        second->base.unkC |= 0x100;
                        second->base.unk62 |= 4;
                        second->base.yspeed = 0;
                        gKirbys[secondId].unk104 -= 1 << shift;
                    } else {
                        second->base.objBase55++;
                    }
                }
                if (!overlap) {
                    struct Kirby *contactKirby = &gKirbys[secondId];
                    u16 *contactField = &contactKirby->unk104;
                    u32 contacts = *contactField;
                    u32 mask = 7 << shift;
                    if ((contacts & mask) != mask) {
                        if (second->base.y > firstBase->y - 0x1000)
                            contacts &= ~mask;
                        else
                            contacts |= mask;
                    } else {
                        contacts |= contacts & mask;
                    }
                    *contactField = contacts;
                }
            }
            // TODO(match): Six input references keep secondId in r5; five allocate r6 and change 116 instruction entries.
            asm("" : : "r"(secondId), "r"(secondId), "r"(secondId), "r"(secondId), "r"(secondId), "r"(secondId));
        }
    }
}

u8 KirbyCanContactOther(struct Kirby *first, struct Kirby *second)
{
    s8 a[4], b[4];
    s32 ax, ay, bx, by;
    if (first->base.flags & 1) {
        a[2] = -first->base.unk3C;
        a[0] = -first->base.unk3E;
    } else {
        a[0] = first->base.unk3C;
        a[2] = first->base.unk3E;
    }
    a[1] = first->base.unk3D;
    a[3] = first->base.unk3F;
    if (second->base.flags & 1) {
        b[2] = -second->base.unk3C;
        b[0] = -second->base.unk3E;
    } else {
        b[0] = second->base.unk3C;
        b[2] = second->base.unk3E;
    }
    b[1] = second->base.unk3D;
    b[3] = second->base.unk3F;
    ax = first->base.x + a[0] * 256;
    bx = second->base.x + b[0] * 256;
    if (COLLISION_AXIS_OVERLAP(ax, (a[2] - a[0]) * 256, bx, (b[2] - b[0]) * 256)) {
        ay = first->base.y + a[1] * 256;
        by = second->base.y + b[1] * 256;
        if (COLLISION_AXIS_OVERLAP(ay, (a[3] - a[1]) * 256, by, (b[3] - b[1]) * 256)) {
            if (first->base.yspeed <= 0)
                return TRUE;
        }
    }
    return FALSE;
}

u8 ObjectHitboxesOverlap(struct ObjectBase *first, struct ObjectBase *second)
{
    s32 ax, ay, bx, by;
    if (first->flags & 1)
        ax = (first->x >> 8) + (-first->unk38 - first->unk3A * 2);
    else
        ax = (first->x >> 8) + first->unk38;
    ay = (first->y >> 8) + first->unk39;
    if (second->flags & 1)
        bx = (second->x >> 8) + (-second->unk38 - second->unk3A * 2);
    else
        bx = (second->x >> 8) + second->unk38;
    by = (second->y >> 8) + second->unk39;
    if (COLLISION_AXIS_OVERLAP(ax, first->unk3A * 2, bx, second->unk3A * 2)) {
        if (COLLISION_AXIS_OVERLAP(ay, first->unk3B * 2, by, second->unk3B * 2))
            return TRUE;
    }
    return FALSE;
}

static s32 ObjectHitboxOverlapsRect(struct ObjectBase *object, s32 x, s32 y, s16 xOffset, s16 yOffset, u16 width, u16 height)
{
    s32 ax, ay, bx, by;
    if (object->flags & 1)
        ax = (object->x >> 8) + (-object->unk38 - object->unk3A * 2);
    else
        ax = (object->x >> 8) + object->unk38;
    ay = (object->y >> 8) + object->unk39;
    bx = (x >> 8) + xOffset;
    by = (y >> 8) + yOffset;
    if (COLLISION_AXIS_OVERLAP(ax, object->unk3A * 2, bx, width)) {
        if (COLLISION_AXIS_OVERLAP(ay, object->unk3B * 2, by, height))
            return TRUE;
    }
    return FALSE;
}

u8 ObjectOriginOverlapsRect(struct ObjectBase *object, s32 x, s32 y, s16 xOffset, s16 yOffset, u16 width, u16 height)
{
    s32 rectX, rectY;
    s32 objectX, objectY;
    rectX = (x >> 8) + xOffset;
    rectY = (y >> 8) + yOffset;
    objectX = object->x >> 8;
    if (COLLISION_AXIS_OVERLAP(objectX, 1, rectX, width)) {
        objectY = object->y >> 8;
        if (COLLISION_AXIS_OVERLAP(objectY, 1, rectY, height))
            return TRUE;
    }
    return FALSE;
}

struct ObjectBase **GetRoomObjectCollisionList(struct ObjectBase *object)
{
    u8 group;
    if (object->unk56 != 0xFF)
        group = gCurLevelInfo[object->unk56].unk65E;
    else
        // TODO: The original returns an out-of-range list for the 0xFF sentinel.
        group = 0xFF;
    return &gUnk_02022F50[group * 64];
}

struct Object **GetRoomSolidCollisionList(struct ObjectBase *object)
{
    u8 group;
    if (object->unk56 != 0xFF)
        group = gCurLevelInfo[object->unk56].unk65E;
    else
        // TODO: The original returns an out-of-range list for the 0xFF sentinel.
        group = 0xFF;
    return gUnk_02022EC0[group];
}

static void ObjectCollisionTaskDestructor(struct Task *task UNUSED)
{
}

s32 (*const gObjectCollisionCallbacks[3])(struct ObjectBase *, struct ObjectBase *) = {
    HandleKirbyCollision, HandleObjectCollision, HandleAttackObjectCollision,
};
