cmake_minimum_required(VERSION 4.0.2)
project(PCPort)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Fatal_Frame_1)

if(WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL3)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

add_executable(PCPort "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_include_directories(PCPort PUBLIC ${SDL3_INCLUDE_DIRS} ${HEADERS})

target_link_libraries(PCPort PUBLIC SDL3::SDL3 glad Fatal_Frame_1)
