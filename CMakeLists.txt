cmake_minimum_required(VERSION 4.1.2)
project(PCPort C)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.c ${CMAKE_CURRENT_SOURCE_DIR}/Sources/GameMain.c)

add_executable(PCPort ${SOURCES})

target_include_directories(PCPort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Headers)