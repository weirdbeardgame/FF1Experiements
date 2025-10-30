#pragma once
#include "common/types.h"

enum TITLE_MODE
{
    TITLE_INIT = 0,
    TITLE_WAIT = 1,
    TITLE_TITLE = 2,
    TITLE_TITLE_WAIT = 3,
    TITLE_TITLE_WAIT2 = 4,
    TITLE_TITLE_SEL = 5,
    TITLE_LOAD_PRE = 6,
    TITLE_MEMCA_LOAD_WAIT = 7,
    TITLE_MEMCA_LOAD = 8,
    TITLE_MODE_SEL = 9, // Debug menu?
    TITLE_DIFF_SEL = 10,
    TITLE_INIT_FROM_IN = 11,
    TITLE_WAIT_FROM_IN = 12,
    TITLE_MODE_SELECT = 13,
    TITLE_ALBM_LOAD_PRE = 14,
    TITLE_ALBM_LOAD1 = 15,
    TITLE_ALBM_LOAD2 = 16,
    TITLE_ALBM_MAIN_PRE = 17,
    TITLE_ALBM_MAIN = 18,
    TITLE_ALBM_SAVE_PRE = 19,
    TITLE_ALBM_SAVE = 20,
    TITLE_ALBM_LOAD_MODE_PRE = 21,
    TITLE_ALBM_LOAD_MODE = 22,
    TITLE_TITLE_SEL_INIT = 23,
    TITLE_TITLE_SEL_BGMREQ = 24,
    TITLE_ALBM_LOAD0 = 25,
    TITLE_INIT_FROM_IN_BGMREQ = 26,
    TITLE_MODE_SEL_BGMREQ = 27,
    TITLE_MOVIE_STEP1 = 28,
    TITLE_MOVIE_STEP2 = 29,
    TITLE_MOVIE_STEP3 = 30
};

typedef struct
{ // 0xc
    /* 0x0 */ int load_id;
    /* 0x4 */ u_char mode;
    /* 0x5 */ u_char sub_mode;
    /* 0x6 */ u_char next_mode;
    /* 0x7 */ u_char csr;
    /* 0x8 */ u_char load_side;
} TITLE_WRK;

extern TITLE_WRK title_wrk;

extern int opening_movie_type;