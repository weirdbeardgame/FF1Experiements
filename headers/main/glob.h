#pragma once
#include "common/types.h"
#include <stdio.h>

#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

typedef struct
{ // 0x20
    /* 0x00 */ u_long count;
    // sceCdCLOCK rtc;
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

enum
{
    INGAME_MODE_FIRST_LOAD = 0,
    INGAME_MODE_INIT = 1,
    INGAME_MODE_WAIT = 2,
    INGAME_MODE_NEW_GAME = 3,
    INGAME_MODE_LOAD_START = 4,
    INGAME_MODE_MSN_TITLE = 5,
    INGAME_MODE_NOMAL = 6,
    INGAME_MODE_EVENT = 7,
    INGAME_MODE_SPECIAL_EVENT = 8,
    INGAME_MODE_AREA_MOVE = 9,
    INGAME_MODE_MENU = 10,
    INGAME_MODE_PAUSE = 11,
    INGAME_MODE_SPD_MAP = 12,
    INGAME_MODE_SPD_OPT = 13,
    INGAME_MODE_GET_ITEM = 14,
    INGAME_MODE_WANDER_SOUL = 15,
    INGAME_MODE_SAVE_POINT = 16,
    INGAME_MODE_PHOTO_AFTER = 17,
    INGAME_MODE_GHOST_DEAD = 18,
    INGAME_MODE_SGST_DISP = 19,
    INGAME_MODE_GAME_OVER = 20,
    INGAME_MODE_GAME_OVER_ALBUM = 21,
    INGAME_MODE_INTER_MSN = 22,
    INGAME_MODE_ENDING = 23,
    INGAME_MODE_WAIT_MSN0 = 24
};

extern u_char mc_language;
extern u_char mc_start_flg;
extern u_int scene_bg_load_flg;
extern u_int realtime_scene_flg;

extern SYS_WRK sys_wrk;
extern INGAME_WRK ingame_wrk;
extern OUTGAME_WRK outgame_wrk;