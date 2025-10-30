#include <stdio.h>
#include "main/gamemain.h"
#include "common/glob.h"
#include "outgame/title.h"
#include "outgame/outgame.h"

SYS_WRK sys_wrk;
TITLE_WRK title_wrk;
OUTGAME_WRK outgame_wrk;
INGAME_WRK ingame_wrk;

int GameInitLoad()
{
    return 1;
}

void GameModeChange(u_char mode)
{
    switch (mode)
    {
    case GMC_OUT_MENU_IN:
        // MovieInitWrk();
        sys_wrk.game_mode = GAME_MODE_INGAME;
        ingame_wrk.mode = INGAME_MODE_FIRST_LOAD;
        break;
    case GMC_IN_GAMEOVER_OUT:
        sys_wrk.game_mode = GAME_MODE_OUTGAME;
        if (ingame_wrk.game == INGAME_MODE_INIT)
        {
            title_wrk.mode = TITLE_INIT_FROM_IN;
            outgame_wrk.mode = OUTGAME_MODE_BATTLE;
            // BattleModeNext();
        }
        else
        {
            title_wrk.mode = TITLE_INIT_FROM_IN;
            outgame_wrk.mode = OUTGAME_MODE_TITLE_TOP;
        }
        // SetReverbVolume(0x2fff);
        break;
    case GMC_IN_GAMECLEAR_OUT:
        sys_wrk.game_mode = GAME_MODE_OUTGAME;
        if (ingame_wrk.game != INGAME_MODE_INIT)
        {
            title_wrk.mode = TITLE_INIT_FROM_IN;
        }
        // SetReverbVolume(0x2fff);
        break;
    case GMC_IN_GAMERETIRE_OUT:
        sys_wrk.game_mode = GAME_MODE_OUTGAME;
        title_wrk.mode = TITLE_INIT_FROM_IN;
        // SetReverbVolume(0x2fff);
        break;
    }
}

int GameInit()
{
    if (GameInitLoad())
    {
        // Initalize Renderer In here
        // gra3dInit();
        return 1;
    }
    return 0;
}

void GameMain()
{

    switch (sys_wrk.mode)
    {
    case GAME_MODE_INIT:
        if (GameInit())
        {
            printf("GAME_MODE_INIT\n");
            sys_wrk.game_mode = GAME_MODE_OUTGAME;
        }
        break;

    case GAME_MODE_MCCHECK:
        break;

    case GAME_MODE_OUTGAME:
        break;

    case GAME_MODE_INGAME:
        break;
    }
}