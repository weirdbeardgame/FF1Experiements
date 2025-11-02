cmake_minimum_required(VERSION 4.1.2)
project(PCPort C CXX)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/main/main.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/main/gamemain.c 
${CMAKE_CURRENT_SOURCE_DIR}/sources/outgame/title.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/outgame/outgame.c
${CMAKE_CURRENT_SOURCE_DIR}/sources/main/glob.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/os/system.c
${CMAKE_CURRENT_SOURCE_DIR}/sources/ingame/ig_init.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/ingame/ingame.c
)

set(HEADERS 
${CMAKE_CURRENT_SOURCE_DIR}/sources/main ${CMAKE_CURRENT_SOURCE_DIR}/sources/common
${CMAKE_CURRENT_SOURCE_DIR}/sources/ingame ${CMAKE_CURRENT_SOURCE_DIR}/sources/os
${CMAKE_CURRENT_SOURCE_DIR}/sources/outgame

)

add_executable(PCPort ${SOURCES})


target_include_directories(PCPort PUBLIC ${HEADERS})