#pragma once
#include "types.h"

typedef struct
{ // 0x8
    /* 0x0 */ u_char mode;
    /* 0x1 */ u_char count;
    /* 0x2 */ u_char lock;
    /* 0x4 */ int load_id;
} LOAD_START_WRK;

extern LOAD_START_WRK load_start_wrk;

extern void InitPlyr();
extern void InitPlyrAfterLoad();
extern void InitPlyr2(int film_no); // Used on loading game
