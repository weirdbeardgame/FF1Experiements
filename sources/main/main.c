#include <stdio.h>
#include "outgame/title.h"
#include "outgame/outgame.h"
#include "main/gamemain.h"
#include "common/glob.h"

static char *command;

u_int realtime_scene_flg;
u_int scene_bg_load_flg;

void InitGameFirst()
{
    sys_wrk.reset = 0;

    // Renderer Initalization Stuff
    // gra3dInitFirst();
    // gra2dInitBG();
    // MovieInitWrk();

    realtime_scene_flg = 0;
    sys_wrk.game_mode = 0;
    outgame_wrk.mode = 0;
    outgame_wrk.mode_next = OUTGAME_MODE_TITLE;
    memset(&ingame_wrk, 0, sizeof(INGAME_WRK));
    sys_wrk.sreset_ng = 0;
    opening_movie_type = 0;
}

int SoftResetChk()
{
    if (command == "EXIT")
    {
        return 1;
    }
    return 0;
}

int main()
{

    do
    {
        GameMain();
    } while (!SoftResetChk());

    return 0;
}