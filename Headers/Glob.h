#pragma once
#include "Types.h"

typedef struct
{ // 0x20
    /* 0x00 */ u_long count;
    /* 0x08 */ sceCdCLOCK rtc;
    /* 0x10 */ u_int sreset_count;
    /* 0x14 */ u_char sreset_ng;
    /* 0x15 */ u_char reset;
    /* 0x16 */ u_char pause;
    /* 0x17 */ u_char game_mode;
    /* 0x18 */ u_char mode;
    /* 0x19 */ u_char init;
    /* 0x1a */ u_char load;
    /* 0x1b */ u_char load_mode;
    /* 0x1c */ u_int padding;
} SYS_WRK;

typedef struct
{
    int load_id;
    u_char mode;
    u_char mode_next;
    u_int padding;
} OUTGAME_WRK;

typedef struct
{
    u_char game;
    u_char mode;
    u_char init_flg;
    u_char stts;
    u_char msn_no;
    u_char difficult;
    u_char clear_count;
    u_char rg_pht_cnt;
    u_short ghost_cnt;
    u_int pht_cnt;
    u_int high_score;
    u_int total_point;
    u_int padding;
} INGAME_WRK;

extern SYS_WRK sys_wrk;