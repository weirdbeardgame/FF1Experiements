#include "ingame.h"
#include "ig_init.h"
#include "../main/glob.h"

void InGameInit()
{
    if (sys_wrk.load == 1 && mc_msn_flg == 1)
    {
        // InitModelLoad();
        InitPlyr2(plyr_wrk.film_no);
    }
    else
    {
        // InitModelLoad();
        InitPlyr();
    }
}

void InGameCtrl()
{
    switch (ingame_wrk.mode)
    {

    case INGAME_MODE_FIRST_LOAD:
        ingame_wrk.mode = INGAME_MODE_INIT;
        break;

    case INGAME_MODE_INIT:
        InGameInit();
        break;
    }
}