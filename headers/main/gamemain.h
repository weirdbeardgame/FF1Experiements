#pragma once
#include "common/types.h"

enum GAME_MODE
{
    GAME_MODE_INIT = 0,
    GAME_MODE_MCCHECK = 1,
    GAME_MODE_OUTGAME = 2,
    GAME_MODE_INGAME = 3
};

enum GAME_MODE_CHANGE
{
    GMC_OUT_MENU_IN = 0,
    GMC_IN_GAMEOVER_OUT = 1,
    GMC_IN_GAMECLEAR_OUT = 2,
    GMC_IN_GAMERETIRE_OUT = 3
};

extern int GameInit();
extern void GameMain();
extern int GameInitLoad();
extern void GameModeChange(u_char mode);