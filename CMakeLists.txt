cmake_minimum_required(VERSION 4.1.2)
project(PCPort C)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/main/main.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/main/gamemain.c 
${CMAKE_CURRENT_SOURCE_DIR}/sources/outgame/title.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/outgame/outgame.c
${CMAKE_CURRENT_SOURCE_DIR}/sources/main/glob.c ${CMAKE_CURRENT_SOURCE_DIR}/sources/os/system.c)

add_executable(PCPort ${SOURCES})

target_include_directories(PCPort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)