#pragma once
#include "common/types.h"
#include <stdio.h>

#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

#define debug_print(fmt, ...)                  \
    do                                         \
    {                                          \
        if (DEBUG)                             \
            fprintf(stderr, fmt, __VA_ARGS__); \
    } while (0)

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

typedef struct
{ // 0x20
    /* 0x00 */ sceVu0FVECTOR direction;
    /* 0x10 */ sceVu0FVECTOR diffuse;
} PARARELL_WRK;

typedef struct
{ // 0x30
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ sceVu0FVECTOR diffuse;
    /* 0x20 */ float power;
    /* 0x24 */ float pad[3];
} POINT_WRK;

typedef struct
{ // 0x40
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ sceVu0FVECTOR direction;
    /* 0x20 */ sceVu0FVECTOR diffuse;
    /* 0x30 */ float intens;
    /* 0x34 */ float power;
    /* 0x38 */ float pad[2];
} SPOT_WRK;

typedef struct
{ // 0x1d0
    /* 0x000 */ int parallel_num;
    /* 0x004 */ int point_num;
    /* 0x008 */ int spot_num;
    /* 0x00c */ int pad;
    /* 0x010 */ sceVu0FVECTOR ambient;
    /* 0x020 */ PARARELL_WRK parallel[3];
    /* 0x080 */ POINT_WRK point[3];
    /* 0x110 */ SPOT_WRK spot[3];
} LIGHT_PACK;

typedef union
{ // 0x8
    /* 0x0 */ u_char *pu8;
    /* 0x0 */ u_short *pu16;
    /* 0x0 */ u_int *pu32;
    /* 0x0 */ u_long *pu64;
    /* 0x0 */ char *ps8;
    /* 0x0 */ short *ps16;
    /* 0x0 */ int *ps32;
    /* 0x0 */ long *ps64;
    /* 0x0 */ long int wrk;
} P_INT;

typedef struct
{ // 0x90
    /* 0x00 */ u_char job_no;
    /* 0x01 */ u_char pos_no;
    /* 0x02 */ u_char wait_time;
    /* 0x03 */ u_char idx;
    /* 0x04 */ u_short loop;
    /* 0x06 */ u_short reserve;
    /* 0x08 */ int se;
    /* 0x10 */ sceVu0FVECTOR pos;
    /* 0x20 */ sceVu0FVECTOR tpos;
    /* 0x30 */ sceVu0FVECTOR spd;
    /* 0x40 */ sceVu0FVECTOR rot;
    /* 0x50 */ sceVu0FVECTOR rspd;
    /* 0x60 */ sceVu0FVECTOR trot;
    /* 0x70 */ sceVu0FVECTOR pos_mid;
    /* 0x80 */ P_INT comm_add;
    /* 0x88 */ long int comm_add_top;
} MOVE_BOX;

typedef struct
{ // 0x1c
    /* 0x00 */ u_char se_foot;
    /* 0x01 */ u_char room_no;
    /* 0x02 */ u_char room_old;
    /* 0x03 */ u_char pad;
    /* 0x04 */ u_short camera_no;
    /* 0x06 */ u_short camera_no_old;
    /* 0x08 */ u_short camera_btl;
    /* 0x0a */ u_short camera_btl_old;
    /* 0x0c */ u_short camera_drm;
    /* 0x0e */ u_short camera_drm_old;
    /* 0x10 */ u_short camera_door;
    /* 0x12 */ u_short camera_door_old;
    /* 0x14 */ u_short camera_door_did;
    /* 0x16 */ u_char camera_door_rid;
    /* 0x17 */ u_char cam_type;
    /* 0x18 */ float hight;
} PROOM_INFO;

typedef struct
{ // 0x20
    /* 0x00 */ u_short door_id;
    /* 0x02 */ u_char flag;
    /* 0x03 */ u_char room_no;
    /* 0x10 */ sceVu0FVECTOR dov;
} DOPEN_POS;

typedef struct
{ // 0x400
    /* 0x000 */ u_int sta;
    /* 0x004 */ u_int mvsta;
    /* 0x008 */ u_char mode;
    /* 0x009 */ u_char cam_type;
    /* 0x00a */ u_char anime_no;
    /* 0x00b */ u_char cond;
    /* 0x00c */ u_short cond_tm;
    /* 0x00e */ u_short flash_tm;
    /* 0x010 */ u_short aphoto_tm;
    /* 0x012 */ u_short dmg;
    /* 0x014 */ u_short hp;
    /* 0x016 */ u_short ap_timer;
    /* 0x018 */ u_short dwalk_tm;
    /* 0x01a */ u_short fh_no;
    /* 0x01c */ float fh_deg;
    /* 0x020 */ float spd;
    /* 0x024 */ float spd_ud;
    /* 0x028 */ float prot;
    /* 0x02c */ float frot_x;
    /* 0x030 */ float charge_deg;
    /* 0x034 */ float charge_rate;
    /* 0x038 */ u_char charge_num;
    /* 0x039 */ u_char rock_trgt;
    /* 0x03a */ u_char film_no;
    /* 0x03b */ u_char dmg_cam_flag;
    /* 0x03c */ u_char hp_num;
    /* 0x03d */ u_char mode_save;
    /* 0x03e */ u_char move_mot;
    /* 0x03f */ u_char atk_no;
    /* 0x040 */ u_char near_ene_no;
    /* 0x041 */ u_char photo_charge;
    /* 0x042 */ u_char dmg_type;
    /* 0x043 */ u_char spe1_dir;
    /* 0x044 */ char pr_set;
    /* 0x045 */ char po_set;
    /* 0x046 */ u_char reserve[2];
    /* 0x050 */ sceVu0FVECTOR mv;
    /* 0x060 */ sceVu0FVECTOR op;
    /* 0x070 */ sceVu0FVECTOR rock_adj;
    /* 0x080 */ sceVu0FVECTOR bwp;
    /* 0x090 */ sceVu0FVECTOR cp_old;
    /* 0x0a0 */ sceVu0FVECTOR soulp;
    /* 0x0b0 */ sceVu0FVECTOR spot_rot;
    /* 0x0c0 */ sceVu0FVECTOR spot_pos;
    /* 0x0d0 */ sceVu0FVECTOR shadow_direction;
    /* 0x0e0 */ sceVu0FVECTOR psave;
    /* 0x0f0 */ sceVu0FVECTOR fhp[5];
    /* 0x140 */ short int fp[2];
    /* 0x150 */ MOVE_BOX move_box;
    /* 0x1e0 */ LIGHT_PACK mylight;
    /* 0x3b0 */ PROOM_INFO pr_info;
    /* 0x3d0 */ DOPEN_POS dop;
    /* 0x3f0 */ int se_deadly;
    /* 0x3f4 */ u_int padding;
} PLYR_WRK;

extern u_char mc_language;
extern u_char mc_start_flg;
extern u_char mc_msn_flg;
extern u_int scene_bg_load_flg;
extern u_int realtime_scene_flg;

extern SYS_WRK sys_wrk;
extern INGAME_WRK ingame_wrk;
extern OUTGAME_WRK outgame_wrk;
extern PLYR_WRK plyr_wrk;