project (Fatal_Frame_1)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main/main.c ${CMAKE_CURRENT_SOURCE_DIR}/main/gamemain.c 
${CMAKE_CURRENT_SOURCE_DIR}/outgame/title.c ${CMAKE_CURRENT_SOURCE_DIR}/outgame/outgame.c
${CMAKE_CURRENT_SOURCE_DIR}/main/glob.c ${CMAKE_CURRENT_SOURCE_DIR}/os/system.c
${CMAKE_CURRENT_SOURCE_DIR}/ingame/ig_init.c ${CMAKE_CURRENT_SOURCE_DIR}/ingame/ingame.c
)

set(HEADERS 
${CMAKE_CURRENT_SOURCE_DIR}/main ${CMAKE_CURRENT_SOURCE_DIR}/common
${CMAKE_CURRENT_SOURCE_DIR}/ingame ${CMAKE_CURRENT_SOURCE_DIR}/os
${CMAKE_CURRENT_SOURCE_DIR}/outgame
)

add_library(Fatal_Frame_1 ${SOURCES})

target_include_directories(Fatal_Frame_1 PUBLIC ${HEADERS})

set_target_properties(Fatal_Frame_1 PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")