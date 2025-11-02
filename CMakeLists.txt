cmake_minimum_required(VERSION 4.1.2)
project(PCPort)

include(FetchContent)

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

if ((NOT DEFINED BT_GLAD_LIBS) OR (NOT DEFINED BT_GLAD_INCLUDE_DIRS))
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        658f48e72aee3c6582e80b05ac0f8787a64fe6bb #v2.0.6
    GIT_PROGRESS   TRUE
    SOURCE_SUBDIR  cmake
)
FetchContent_MakeAvailable(glad)
glad_add_library(glad_gl_core_43 STATIC REPRODUCIBLE LOADER API gl:core=4.3)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad)

if(WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL3)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

add_executable(PCPort ${SOURCES})

target_include_directories(PCPort PUBLIC ${SDL3_INCLUDE_DIRS} ${HEADERS})

target_link_libraries(PCPort PUBLIC SDL3::SDL3 glad_gl_core_43 glad)