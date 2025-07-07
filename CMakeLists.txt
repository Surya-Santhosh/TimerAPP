cmake_minimum_required(VERSION 3.10)
project(AppTimer)

include(ExternalProject)

# Using gcc compiler.
ExternalProject_Add(AppTimer_gcc
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/appTimer_gcc
    BINARY_DIR ${CMAKE_BINARY_DIR}/build_gcc
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
    INSTALL_COMMAND "" 
)

# Raspberry Pi Cross-Compilation
ExternalProject_Add(AppTimer_rpi
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/appTimer_rpi
    BINARY_DIR ${CMAKE_BINARY_DIR}/build_rpi
    CMAKE_ARGS
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}/toolchain.cmake
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
    INSTALL_COMMAND ""  
)

