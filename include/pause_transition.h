#ifndef GUARD_PAUSE_TRANSITION_H
#define GUARD_PAUSE_TRANSITION_H

#include "global.h"

void ResetPauseScreenTransition(void);
bool32 CanStartPauseScreenTransition(void);
void StartPauseScreenTransition(u16 screen);
void FinishPauseScreen(void);
void sub_080396BC(void);
void StartWorldMapUnlockMoonlightMansion(void);
void StartWorldMapUnlockRainbowRouteEast(void);
void StartWorldMapUnlockRainbowRouteSouth(void);
void StartWorldMapUnlockCabbageCavernCenter(void);
void StartWorldMapUnlockRainbowRouteWest(void);
void StartWorldMapUnlockCarrotCastle(void);
void StartWorldMapUnlockRainbowRouteNorth(void);
void StartWorldMapUnlockMustardMountain(void);
void StartWorldMapUnlockCabbageCavernWest(void);
void StartWorldMapUnlockRadishRuins(void);
void StartWorldMapUnlockPeppermintPalaceEast(void);
void StartWorldMapUnlockPeppermintPalaceWest(void);
void StartWorldMapUnlockCabbageCavernEast(void);
void StartWorldMapUnlockOliveOcean(void);
void StartWorldMapUnlockCandyConstellation(void);

#endif
