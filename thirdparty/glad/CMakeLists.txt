cmake_minimum_required(VERSION 4.1.2)
project(Glad)

add_library(glad ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/gl.h ${CMAKE_CURRENT_SOURCE_DIR}/src/gl.c)
target_include_directories(glad PUBLIC include/)