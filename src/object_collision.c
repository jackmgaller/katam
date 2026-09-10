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

void sub_0804A728(struct Kirby *);
void sub_0804E09C(struct Kirby *);
void sub_080853C8(struct Kirby *, u16);
void sub_08053DAC(struct Kirby *, u8);
void sub_08054414(struct Kirby *, u8);
void sub_080566E0(struct Kirby *);
u8 KirbyCanContactOther(struct Kirby *, struct Kirby *);
void sub_08088F84(struct Kirby *, s16, s16);
bool8 sub_080A1804(struct Object *, struct Kirby *);
bool32 sub_080AC5E0(struct Object *, struct ObjectHeader *);
bool8 sub_080B0758(struct Object *, struct Kirby *);
bool8 sub_080B6368(struct Object *, struct Kirby *);
void UpdateObjectCollisions(void);
void ProcessObjectCollisionLists(void);
void ProcessKirbyContacts(void);
void ResolveSolidObjectCollision(struct ObjectBase *, struct Object *);
void ObjectCollisionTaskDestructor(struct Task *);

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

void UpdateObjectCollisions(void)
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

// TODO: The attack and target pointers use different callee-saved registers; damage/grab branch sharing remains unresolved.
#ifndef NONMATCHING
NAKED s32 HandleObjectCollision(struct ObjectBase *attack, struct ObjectBase *other)
{
    asm(".include \"asm/nonmatching/HandleObjectCollision.inc\"");
}
#else
s32 HandleObjectCollision(struct ObjectBase *attack, struct ObjectBase *other)
{
    struct Object *object = (struct Object *)other;
    struct ObjectBase *parent;
    s32 attackFlags;
    u32 flags, defense, vulnerableTypes;
    if (attack->header.kind == 2) {
        if (object->type == 0x46 && attack->xspeed < 0)
            return 0;
        if (attack->header.kind == 2 && attack->parent == object)
            return 0;
    }
    if (object->base.flags & 0x1000000) {
        if (attack->flags & 0x40000)
            return 0;
        if (attack->unk68 & 0x80)
            return 0;
    }
    parent = attack->parent;
    if (parent != NULL && parent->header.kind == 0 && attack->unk56 == gLocalPlayerId)
        TryTrackHudEnemy(object);
    attackFlags = attack->unk68;
    if (!(attackFlags & 0x20)) {
        flags = attack->flags;
        defense = object->base.unk5C;
        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
        if (!(flags & 0x10000) && !(object->base.flags & 0x20000)) {
            if (!(flags & 0x100000) && !(object->base.flags & 0x200000)) {
                object->base.flags |= 0x40000;
                object->base.unk6C = attack;
            } else if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
                object->base.flags |= 0x40000;
                object->base.unk6C = attack;
            }
        }
        if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7) && !(object->base.flags & 0x8000)) {
            if (attackFlags & 0x8000)
                sub_0809C6D0(object);
            else
                sub_0809B1E4(object);
            if (!(object->base.unk68 & 0x20000000))
                return 1;
            return 0;
        }
        if ((object->base.flags & 0x40000) && !(attackFlags & 0x800000)) {
            if ((u8)(object->type - 0x38) > 0x1A) {
                if (object->type != 0x6D || !(attackFlags & 0x80))
                    sub_0808845C(object, 10);
                if (!(object->base.flags & 0x8000))
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
    parent = attack->parent;
    if (parent == NULL)
        return 0;
    if (parent->header.kind == 1) {
        u8 type = ((struct Object *)parent)->type;
        if (type != 7 && type != 14)
            return 0;
        if ((u8)(object->type - 0x5E) > 14)
            return 0;
        if (!(attack->flags & 0x10000)) {
            object->base.flags |= 0x40000;
            object->base.unk6C = parent;
        }
        sub_0809CFC4(object);
        return 1;
    }
    if (attack->unk56 >= gNumHumanPlayers) {
        if ((u8)(object->type - 0x5E) <= 14 || object->type == 0xA4
            || (object->type == 0xA3 && object->base.unk56 < gNumHumanPlayers))
            return 0;
    }
    flags = attack->flags;
    if (!(flags & 0x10000) && !(object->base.flags & 0x20000)) {
        if ((flags & 0x100000) || (object->base.flags & 0x200000)) {
            defense = object->base.unk5C;
            vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
            if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
                object->base.flags |= 0x40000;
                object->base.unk6C = parent;
            }
        } else {
            object->base.flags |= 0x40000;
            object->base.unk6C = parent;
        }
    }
    if (attackFlags == 0x20000023)
        object->unk90 = (object->unk90 & ~(3 << (attack->unk56 * 2))) | (2 << (attack->unk56 * 2));
    else
        object->unk90 = (object->unk90 & ~(3 << (attack->unk56 * 2))) | (1 << (attack->unk56 * 2));
    defense = object->base.unk5C;
    if (defense & 0x20) {
        if (object->type <= 0xD4 || !(attackFlags & 0x200000))
            return 0;
    }
    if ((attackFlags & 0x200000) && (u8)(object->type - 0x5E) <= 14) {
        attack->flags = flags & ~0x40000;
    } else {
        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
        if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
            attack->flags = flags | 0x40000;
            object->base.unk6C = parent;
            sub_0809C380(object);
        } else if (!(gUnk_03000510.unk4 & ((1 << object->base.unk56) | 0x10))) {
            object->base.objBase54 += (gUnk_0203AD40 & 2) * 2;
        }
    }
    return 0;
}
#endif

// TODO: The grab-handler switch and damage path share different return tails; the original branch topology remains unresolved.
#ifndef NONMATCHING
NAKED s32 HandleAttackObjectCollision(struct ObjectBase *other, struct ObjectBase *attack)
{
    asm(".include \"asm/nonmatching/HandleAttackObjectCollision.inc\"");
}
#else
s32 HandleAttackObjectCollision(struct ObjectBase *other, struct ObjectBase *attack)
{
    struct ObjectBase *parent;
    s32 attackFlags;
    u32 flags, defense, vulnerableTypes;
    if (other->header.kind == 1 && ((struct Object *)other)->type == 0x46 && attack->xspeed < 0)
        return 0;
    parent = attack->parent;
    if (parent == other)
        return 0;
    if (other->header.kind == 1 && (other->flags & 0x1000000) && (attack->flags & 0x40000))
        return 0;
    attackFlags = attack->unk68;
    if (attackFlags & 0x20) {
        attack->unk6C = other;
        defense = other->unk5C;
        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
        if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)
            && !(other->flags & 0x8000)) {
            struct Object *object = (struct Object *)parent;
            if (parent != NULL) {
                parent->unkC &= ~0x40;
                if (parent->header.kind == 1) {
                    bool8 handled;
                    switch (object->type) {
                    case 0x32:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080A049C(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x33:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080A1804(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x38:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080CC6F0(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x9E:
                    case 0xAE:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080B6368(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x3A:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080CE94C(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 15:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080B0758(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x48:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080E588C((struct Gobbler *)object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x9F:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080E74E4(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x3E:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080D4004(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x47:
                    case 0x4D:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080E1B8C((struct CrazyHand *)object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 0x3C:
                        if (other->flags & 0x8000) return 0;
                        handled = sub_080C8548(object, (struct Kirby *)other);
                        if (handled) break;
                        return 0;
                    case 7:
                    case 14:
                        handled = sub_080AC5E0(object, &other->header);
                        if (handled) break;
                        return 0;
                    default:
                        return 0;
                    }
                    return 1;
                }
            }
        }
    } else {
        flags = other->flags;
        if (!(flags & 0x10000)) {
            u32 attackObjectFlags = attack->flags;
            if (!(attackObjectFlags & 0x20000)) {
                if (!(flags & 0x100000) && !(attackObjectFlags & 0x200000)) {
                    attack->flags = attackObjectFlags | 0x4000000;
                    attack->unk6C = other;
                } else {
                    defense = other->unk5C;
                    vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                    if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)) {
                        attack->flags = attackObjectFlags | 0x4000000;
                        attack->unk6C = other;
                    }
                }
            }
        }
        if ((attackFlags & 0x10000000) && !(flags & 0x400000) && !(flags & 0x10000)) {
            if (flags & 0x100000) {
                defense = other->unk5C;
                vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
                if (!(vulnerableTypes & attackFlags))
                    return 0;
                if ((u32)(attackFlags & 7) < (defense & 7))
                    goto CheckDamage;
            }
            if (!(attackFlags & 0x400000) || !(other->unk5C & 0x400000))
                sub_080853C8((struct Kirby *)parent, 4);
        }
CheckDamage:
        defense = other->unk5C;
        attackFlags = attack->unk68;
        vulnerableTypes = 0x3FFFF8 & ~(defense & ~7);
        if ((vulnerableTypes & attackFlags) && (u32)(attackFlags & 7) >= (defense & 7)
            && !(other->flags & 0x8000) && !(attackFlags & 0x20000000))
            return 1;
    }
    return 0;
}
#endif

// TODO: The tile scan needs 40 rather than 48 stack bytes; clipping coordinates and row/column lifetimes remain unresolved.
#ifndef NONMATCHING
NAKED void ProcessAttackTileCollisions(struct ObjectBase *attack)
{
    asm(".include \"asm/nonmatching/ProcessAttackTileCollisions.inc\"");
}
#else
void ProcessAttackTileCollisions(struct ObjectBase *attack)
{
    s8 bounds[4];
    u8 width, height, row, column;
    u16 tileX, tileY;
    if (attack->unk68 & 0x20) {
        s8 direction = 1;
        s16 minX, maxX, minY, maxY;
        const struct LevelInfo *level;
        if (attack->flags & 0x40000)
            return;
        level = &gCurLevelInfo[attack->unk56];
        maxX = level->levelMaxPosition.x >> 12;
        maxY = level->levelMaxPosition.y >> 12;
        minX = level->levelMinPosition.x >> 12;
        minY = level->levelMinPosition.y >> 12;
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
                for (column = width; column != 0 && tileX <= maxX && tileX >= minX; --column) {
                    if ((gCollisionAttributes[GetCollisionTile(attack->unk56, tileX, tileY)] & 0xF01000) == 0x1000) {
                        sub_08001408(attack->unk56, sub_080025AC(attack->unk56, tileX, tileY), NULL, NULL);
                        sub_08088F84(attack->parent, tileX, tileY);
                        attack->flags |= 0x80000;
                        return;
                    }
                    tileX += direction;
                }
                if (row & 1)
                    tileY = tileY + 1 + row;
                else
                    tileY = tileY - 1 - row;
            }
        }
    } else {
        s16 clip;
        const struct LevelInfo *level;
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
        level = &gCurLevelInfo[attack->unk56];
        clip = (level->levelMaxPosition.x >> 12) - (width + tileX);
        if (clip < 0) {
            width += clip;
            if (width & 0x80)
                return;
        }
        clip = tileX - (level->levelMinPosition.x >> 12);
        if (clip < 0) {
            if (width + clip < 0)
                return;
            tileX -= clip;
            width += clip;
        }
        clip = (level->levelMaxPosition.y >> 12) - (tileY + height);
        if (clip < 0) {
            height += clip;
            if (height & 0x80)
                return;
        }
        clip = tileY - (level->levelMinPosition.y >> 12);
        if (clip < 0) {
            if (height + clip < 0)
                return;
            tileY -= clip;
            height += clip;
        }
        for (row = height + 1; row != 0;) {
            --row;
            for (column = width + 1; column != 0;) {
                u8 x, y;
                u32 attributes;
                --column;
                y = row + tileY;
                attributes = gCollisionAttributes[GetCollisionTile(attack->unk56, tileX + column, y)];
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
                    x = column + tileX;
                    if (attributes & 0x20) {
                        sub_08001408(attack->unk56, sub_080025AC(attack->unk56, x, y), NULL, NULL);
                        sub_0800E0E4((struct Object *)attack, x, y);
                        PlaySfx(attack, SE_BLOCK_BREAK);
                    } else {
                        struct EffectObject *effect;
                        sub_08001408(attack->unk56, sub_080025AC(attack->unk56, x, y), NULL, NULL);
                        effect = CreateEffectObject(attack, 0, 0x28D, 0);
                        effect->x = (x * 0x1000) + 0x800;
                        effect->y = (y * 0x1000) + 0x800;
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
#endif

extern s32 (*const gObjectCollisionCallbacks[3])(struct ObjectBase *, struct ObjectBase *);

static inline bool32 AttackOverlapsObject(struct ObjectBase *attack, s32 ax, s32 ay,
    struct ObjectBase *other, bool32 requireArea)
{
    s32 bx, by;
    if (other->flags & 1)
        bx = (other->x >> 8) - other->unk38 - other->unk3A * 2;
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

// TODO: The dispatcher needs 48 rather than 24 stack bytes; list cursors, callback results, and cached hitbox lifetimes remain unresolved.
#ifndef NONMATCHING
NAKED void ProcessObjectCollisionLists(void)
{
    asm(".include \"asm/nonmatching/ProcessObjectCollisionLists.inc\"");
}
#else
void ProcessObjectCollisionLists(void)
{
    u8 group;
    for (group = 0; group < gNumKirbys; ++group) {
        struct Object **solidSlot = gUnk_02022EC0[group];
        struct ObjectBase **attackSlot;
        struct ObjectBase **otherSlot;
        u8 remaining, otherRemaining, player;
        for (remaining = gUnk_02022F40[group]; remaining != 0; --remaining, ++solidSlot) {
            if (*solidSlot != NULL) {
                for (player = 0; player < gNumKirbys; ++player) {
                    struct ObjectBase *kirby = &gKirbys[player].base;
                    if ((*solidSlot)->base.roomId == kirby->roomId && !(kirby->flags & 0x100))
                        ResolveSolidObjectCollision(kirby, *solidSlot);
                }
                otherSlot = &gUnk_02022F50[group * 64];
                for (otherRemaining = gUnk_02022EB0[group][0]; otherRemaining != 0; --otherRemaining, ++otherSlot) {
                    struct ObjectBase *other = *otherSlot;
                    if ((other->unkC & 0x1000) && (*solidSlot)->base.roomId == other->roomId && !(other->flags & 0x100))
                        ResolveSolidObjectCollision(other, *solidSlot);
                }
            }
        }
        attackSlot = &gUnk_02022F50[(group * 64) | 32];
        for (remaining = gUnk_02022EB0[group][1]; remaining != 0; --remaining, ++attackSlot) {
            struct ObjectBase *attack = *attackSlot;
            s32 ax, ay;
            if (attack == NULL)
                continue;
            if (attack->flags & 1)
                ax = (attack->x >> 8) - attack->unk38 - attack->unk3A * 2;
            else
                ax = (attack->x >> 8) + attack->unk38;
            ay = (attack->y >> 8) + attack->unk39;
            if (attack->flags & 0x20000000) {
                otherSlot = &gUnk_02022F50[group * 64];
                for (otherRemaining = gUnk_02022EB0[group][0]; otherRemaining != 0; --otherRemaining, ++otherSlot) {
                    struct ObjectBase *other = *otherSlot;
                    if (other == NULL)
                        continue;
                    if (attack->flags & 0x200)
                        break;
                    if (!(other->flags & 0x200) && AttackOverlapsObject(attack, ax, ay, other, TRUE)) {
                        u8 consumed = gObjectCollisionCallbacks[(*attackSlot)->header.kind](other, *attackSlot);
                        if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*attackSlot, *otherSlot))
                            *otherSlot = NULL;
                        attack = *attackSlot;
                        if (consumed) {
                            CommitAttackContact(attack);
                            *attackSlot = NULL;
                            break;
                        }
                    }
                }
                attack = *attackSlot;
                if (attack == NULL)
                    continue;
                CommitAttackContact(attack);
            }
            if (attack->flags & 0x10000000) {
                for (player = 0; player < gNumKirbys; ++player) {
                    struct ObjectBase *kirby = &gKirbys[player].base;
                    if (attack->roomId != kirby->roomId)
                        continue;
                    if (attack->flags & 0x200)
                        break;
                    if (!(kirby->flags & 0x200) && AttackOverlapsObject(attack, ax, ay, kirby, TRUE)) {
                        u8 consumed = gObjectCollisionCallbacks[(*attackSlot)->header.kind](kirby, *attackSlot);
                        gObjectCollisionCallbacks[kirby->header.kind](*attackSlot, kirby);
                        attack = *attackSlot;
                        if (consumed) {
                            CommitAttackContact(attack);
                            *attackSlot = NULL;
                            break;
                        }
                    }
                }
                attack = *attackSlot;
                if (attack == NULL)
                    continue;
                CommitAttackContact(attack);
            }
            if (attack->flags & 0x40000000) {
                otherSlot = &gUnk_02022F50[(group * 64) | 32];
                for (otherRemaining = gUnk_02022EB0[group][1]; otherRemaining != 0; --otherRemaining, ++otherSlot) {
                    struct ObjectBase *other = *otherSlot;
                    if (other == NULL)
                        continue;
                    attack = *attackSlot;
                    if (other == attack)
                        continue;
                    if (attack->flags & 0x200)
                        break;
                    if (!(other->flags & 0x200) && AttackOverlapsObject(attack, ax, ay, other, FALSE)) {
                        u8 consumed = gObjectCollisionCallbacks[(*attackSlot)->header.kind](other, *attackSlot);
                        if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*attackSlot, *otherSlot)) {
                            *otherSlot = NULL;
                            break;
                        }
                        if (consumed) {
                            *attackSlot = NULL;
                            break;
                        }
                    }
                }
                attack = *attackSlot;
                if (attack == NULL)
                    continue;
                CommitAttackContact(attack);
            }
            if ((s32)attack->flags < 0)
                ProcessAttackTileCollisions(attack);
        }
        attackSlot = &gUnk_02022F50[group * 64];
        for (remaining = gUnk_02022EB0[group][0]; remaining != 0; --remaining, ++attackSlot) {
            struct ObjectBase *attack = *attackSlot;
            s32 ax, ay;
            if (attack == NULL)
                continue;
            if (attack->flags & 1)
                ax = (attack->x >> 8) - attack->unk38 - attack->unk3A * 2;
            else
                ax = (attack->x >> 8) + attack->unk38;
            ay = (attack->y >> 8) + attack->unk39;
            if (attack->flags & 0x20000000) {
                otherSlot = &gUnk_02022F50[group * 64];
                for (otherRemaining = gUnk_02022EB0[group][0]; otherRemaining != 0; --otherRemaining, ++otherSlot) {
                    struct ObjectBase *other = *otherSlot;
                    if (other == NULL)
                        continue;
                    attack = *attackSlot;
                    if (other == attack)
                        continue;
                    if (attack->flags & 0x200)
                        break;
                    if (!(other->flags & 0x200) && AttackOverlapsObject(attack, ax, ay, other, FALSE)) {
                        u8 consumed = gObjectCollisionCallbacks[(*attackSlot)->header.kind](other, *attackSlot);
                        if ((u16)gObjectCollisionCallbacks[(*otherSlot)->header.kind](*attackSlot, *otherSlot)) {
                            *otherSlot = NULL;
                            break;
                        }
                        if (consumed) {
                            *attackSlot = NULL;
                            break;
                        }
                    }
                }
                attack = *attackSlot;
                if (attack == NULL)
                    continue;
            }
            if (attack->flags & 0x10000000) {
                for (player = 0; player < gNumKirbys; ++player) {
                    struct ObjectBase *kirby = &gKirbys[player].base;
                    if (attack->roomId == kirby->roomId) {
                        if (attack->flags & 0x200)
                            break;
                        if (!(kirby->flags & 0x200) && AttackOverlapsObject(attack, ax, ay, kirby, FALSE)) {
                            u8 consumed = gObjectCollisionCallbacks[(*attackSlot)->header.kind](kirby, *attackSlot);
                            if ((u16)gObjectCollisionCallbacks[kirby->header.kind](*attackSlot, kirby))
                                break;
                            if (consumed) {
                                *attackSlot = NULL;
                                break;
                            }
                        }
                    }
                    attack = *attackSlot;
                }
                attack = *attackSlot;
                if (attack == NULL)
                    continue;
            }
            if ((s32)attack->flags < 0 && !(attack->flags & 0x40000))
                ProcessAttackTileCollisions(attack);
        }
    }
}
#endif

// TODO(match): The collision scratch uses 40 rather than 36 stack bytes; direct bounds arrays and position records did not recover the original lifetimes.
#ifndef NONMATCHING
NAKED void ResolveSolidObjectCollision(struct ObjectBase *object, struct Object *solid)
{
    asm(".include \"asm/nonmatching/ResolveSolidObjectCollision.inc\"");
}
#else
void ResolveSolidObjectCollision(struct ObjectBase *object, struct Object *solid)
{
    s8 a[4], b[4];
    u8 widthA, widthB, heightA, heightB;
    bool32 previousX, previousY, overlapX, overlapY;
    u32 solidFlags;
    s32 tolerance;

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
    if (solidFlags & 1) {
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
    previousX = COLLISION_AXIS_OVERLAP(object->unk48 + a[0] * 256, widthA * 256, solid->base.unk48 + b[0] * 256, widthB * 256);
    previousY = COLLISION_AXIS_OVERLAP(object->unk4C + a[1] * 256, heightA * 256, solid->base.unk4C + b[1] * 256, heightB * 256);
    overlapX = COLLISION_AXIS_OVERLAP(object->x + a[0] * 256, widthA * 256, solid->base.x + b[0] * 256, widthB * 256);
    overlapY = COLLISION_AXIS_OVERLAP(object->y + a[1] * 256, heightA * 256, solid->base.y + b[1] * 256, heightB * 256);
    if (overlapX && overlapY) {
        if (solidFlags & 0x80) {
            object->unk62 |= 0x10;
            object->unk6C = solid;
            return;
        }
        if (previousX && !previousY
            && object->x != solid->base.x + (b[2] - a[0]) * 256
            && object->x != solid->base.x + (b[0] - a[2]) * 256) {
            if (object->yspeed > 0) {
                tolerance = object->yspeed + 0x300;
                if (abs((object->y + a[1] * 256) - (solid->base.y + b[3] * 256)) < tolerance) {
                    object->unk62 |= 8;
                    solid->base.unk62 |= 4;
                    object->y = solid->base.y + (b[3] - a[1]) * 256 + 0x100 + solid->base.yspeed;
                    object->yspeed = 0;
                }
                if (object->yspeed <= 0 || solid->base.yspeed != 0) {
                    tolerance = 0x300 - object->yspeed;
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
            } else {
                tolerance = 0x300 - object->yspeed;
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
        if (!previousX && previousY) {
            tolerance = 0x200 - object->yspeed;
            if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) > tolerance) {
                if (object->x > solid->base.x) {
                    s32 distance = (solid->base.xspeed + 0x400) - object->xspeed;
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
                    s32 distance = object->xspeed - (solid->base.xspeed - 0x400);
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
        if (!previousX && !previousY) {
            if (object->y > solid->base.y) {
                if (object->yspeed > 0) {
                    tolerance = object->yspeed + 0x300;
                    if (abs((object->y + a[1] * 256) - (solid->base.y + b[3] * 256)) < tolerance) {
                        object->unk62 |= 8;
                        solid->base.unk62 |= 4;
                        object->y = solid->base.y + (b[3] - a[1]) * 256 + 0x100 + solid->base.yspeed;
                        object->yspeed = 0;
                    }
                }
            } else if (object->yspeed <= 0) {
                tolerance = 0x300 - object->yspeed;
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
                    s32 distance = (solid->base.xspeed + 0x400) - object->xspeed;
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
                    s32 distance = object->xspeed - (solid->base.xspeed - 0x400);
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
        if (previousX && previousY) {
            if (object->x != solid->base.x + (b[2] - a[0]) * 256
                && object->x != solid->base.x + (b[0] - a[2]) * 256) {
                tolerance = 0x300 - object->yspeed;
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
                    tolerance = object->yspeed + 0x300;
                    if (abs((object->y + a[1] * 256) - (solid->base.y + b[3] * 256)) < tolerance) {
                        object->unk62 |= 8;
                        solid->base.unk62 |= 4;
                        object->y = solid->base.y + (b[3] - a[1]) * 256 + 0x100 + solid->base.yspeed;
                        object->yspeed = 0;
                    }
                }
            }
            tolerance = 0x200 - object->yspeed;
            if (abs((object->y + a[3] * 256) - (solid->base.y + b[1] * 256)) > tolerance) {
                if (object->x > solid->base.x) {
                    s32 distance = (solid->base.xspeed + 0x400) - object->xspeed;
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
                    s32 distance = object->xspeed - (solid->base.xspeed - 0x400);
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
#endif

static inline bool32 CanFirstKirbyShare(struct Kirby *kirby)
{
    if (kirby->ability != KIRBY_ABILITY_UFO) {
        if ((kirby->animationIndex == 0x19 || kirby->animationIndex == 0x2F)
            && kirby->animationIndex != 0xD)
            return TRUE;
        if ((u16)(kirby->animationIndex - 0x38) <= 7)
            return TRUE;
    }
    if (kirby->ability == KIRBY_ABILITY_UFO
        && (kirby->animationIndex <= 0x12 || (u16)(kirby->animationIndex - 0x21) <= 13))
        return TRUE;
    return FALSE;
}

static inline bool32 CanSecondKirbyShare(struct Kirby *kirby)
{
    if (kirby->ability != KIRBY_ABILITY_UFO) {
        if ((kirby->animationIndex <= 0x15 || kirby->animationIndex == 0x19 || kirby->animationIndex == 0x2F)
            && kirby->animationIndex != 0xD)
            return TRUE;
        if ((u16)(kirby->animationIndex - 0x38) <= 7)
            return TRUE;
    }
    if (kirby->ability == KIRBY_ABILITY_UFO
        && (kirby->animationIndex <= 0x12 || (u16)(kirby->animationIndex - 0x21) <= 13))
        return TRUE;
    return FALSE;
}

// TODO: The outer Kirby loop is rotated to a bottom test; explicit entry checks and index-width variants did not recover the original branch layout.
#ifndef NONMATCHING
NAKED void ProcessKirbyContacts(void)
{
    asm(".include \"asm/nonmatching/ProcessKirbyContacts.inc\"");
}
#else
void ProcessKirbyContacts(void)
{
    u8 firstId, secondId;
    for (firstId = 0; firstId < gNumKirbys; ++firstId) {
        struct Kirby *first = &gKirbys[firstId];
        if ((gUnk_03000510.unk4 & (0x10 | (1 << firstId)))
            || (first->base.flags & 0x3800F00) || first->stateFn == sub_080566E0
            || (u16)(first->animationIndex - 0x4A) <= 15 || first->base.sprite.animId == 0x220)
            continue;
        for (secondId = firstId + 1; secondId < gNumKirbys; ++secondId) {
            struct Kirby *second = &gKirbys[secondId];
            bool8 overlap;
            // The original repeats the first Kirby's animation check here.
            if ((second->base.flags & 0x3800F00) || second->stateFn == sub_080566E0
                || (u16)(first->animationIndex - 0x4A) <= 15 || second->base.sprite.animId == 0x220
                || second->base.roomId != first->base.roomId)
                continue;
            overlap = KirbyCanContactOther(first, second);
            if (overlap && first->ability != KIRBY_ABILITY_MINI && second->ability != KIRBY_ABILITY_MINI) {
                if (first->unkE5 != 0 && !((first->unkE1 >> secondId) & 1)) {
                    if (CanFirstKirbyShare(first) && CanSecondKirbyShare(second)
                        && (first->base.unk56 < gNumHumanPlayers || second->base.unk56 < gNumHumanPlayers)) {
                        sub_08053DAC(first, secondId);
                        sub_08054414(second, firstId);
                        first->unkE1 |= 1 << secondId;
                    }
                } else if (second->unkE5 != 0 && !((second->unkE1 >> firstId) & 1)) {
                    if (CanFirstKirbyShare(first) && CanSecondKirbyShare(second)
                        && (first->base.unk56 < gNumHumanPlayers || second->base.unk56 < gNumHumanPlayers)) {
                        sub_08053DAC(second, firstId);
                        sub_08054414(first, secondId);
                        second->unkE1 |= 1 << firstId;
                    }
                }
            }
            if ((first->base.unk62 & 4) && (second->base.unk62 & 4)) {
                if (overlap) {
                    if (first->base.x > second->base.x) {
                        if ((!(first->base.unk62 & 1) || (first->base.flags & 1))
                            && (!(first->base.unk62 & 2) || !(first->base.flags & 1)))
                            first->unkF4 += 0x80;
                        // Both pushes use the first Kirby's wall-contact flags.
                        if ((!(first->base.unk62 & 1) || !(first->base.flags & 1))
                            && (!(first->base.unk62 & 2) || (first->base.flags & 1)))
                            second->unkF4 -= 0x40;
                    } else {
                        if ((!(first->base.unk62 & 1) || !(first->base.flags & 1))
                            && (!(first->base.unk62 & 2) || (first->base.flags & 1)))
                            first->unkF4 -= 0x80;
                        if ((!(first->base.unk62 & 1) || (first->base.flags & 1))
                            && (!(first->base.unk62 & 2) || !(first->base.flags & 1)))
                            second->unkF4 += 0x40;
                    }
                } else {
                    first->unk104 |= 7 << (secondId * 4);
                }
            } else {
                u32 shift = secondId * 4;
                if ((first->unk104 & (7 << shift)) && overlap) {
                    if (first->base.y < second->base.y) {
                        first->base.unkC |= 0x100;
                        first->base.unk62 |= 4;
                        first->base.yspeed = 0;
                        first->unk104 -= 1 << shift;
                    } else {
                        first->base.objBase55++;
                    }
                }
                if (!overlap) {
                    u16 contacts = first->unk104;
                    u32 mask = 7 << shift;
                    if ((contacts & mask) != mask) {
                        if (first->base.y > second->base.y - 0x1000)
                            contacts &= ~mask;
                        else
                            contacts |= mask;
                    } else {
                        contacts |= contacts & mask;
                    }
                    first->unk104 = contacts;
                }
                overlap = KirbyCanContactOther(second, first);
                shift = firstId * 4;
                if ((second->unk104 & (7 << shift)) && overlap) {
                    if (first->base.y > second->base.y) {
                        second->base.unkC |= 0x100;
                        second->base.unk62 |= 4;
                        second->base.yspeed = 0;
                        second->unk104 -= 1 << shift;
                    } else {
                        second->base.objBase55++;
                    }
                }
                if (!overlap) {
                    u16 contacts = second->unk104;
                    u32 mask = 7 << shift;
                    if ((contacts & mask) != mask) {
                        if (second->base.y > first->base.y - 0x1000)
                            contacts &= ~mask;
                        else
                            contacts |= mask;
                    } else {
                        contacts |= contacts & mask;
                    }
                    second->unk104 = contacts;
                }
            }
        }
    }
}
#endif

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

s32 ObjectHitboxOverlapsRect(struct ObjectBase *object, s32 x, s32 y, s16 xOffset, s16 yOffset, u16 width, u16 height)
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

void ObjectCollisionTaskDestructor(struct Task *task UNUSED)
{
}

s32 (*const gObjectCollisionCallbacks[3])(struct ObjectBase *, struct ObjectBase *) = {
    HandleKirbyCollision, HandleObjectCollision, HandleAttackObjectCollision,
};
