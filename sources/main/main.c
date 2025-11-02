#include <stdio.h>
#include <string.h>
#include "gamemain.h"
#include "../outgame/title.h"
#include "../outgame/outgame.h"
#include "../os/system.h"
#include "../ingame/ingame.h"

static u_char reset = 0x0;

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
    if (reset)
    {
        return 1;
    }
    return 0;
}

int main()
{
    InitSystem();

    do
    {
        InitGameFirst();
        do
        {
            GameMain();
        } while (!SoftResetChk());
    } while (1);
    return 0;
}