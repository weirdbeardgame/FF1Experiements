#include "main/gamemain.h"
#include "common/glob.h"

SYS_WRK sys_wrk;

OUTGAME_WRK outgame_wrk;
INGAME_WRK ingame_wrk;

int GameInitLoad()
{
}

void GameModeChange(u_char mode)
{
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
        }
        break;
    }
}