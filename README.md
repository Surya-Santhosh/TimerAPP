# TimerApp

A cross-platform C project that builds a timer application for both Linux and 
Raspberry Pi, using either **CMake** or **Make**.C Program to display date and 
time in UTC,IST,PST and LED ON, LED OFF in every seconds.

## Features

The executable, object, Assembly files are in **release** and debug files are in 
**debug**.
Cross-compilation support for Raspberry Pi (aarch64)


## Prerequisites

**CMake** ≥ 3.10
**Make**
**GCC** (for Linux build)
**aarch64-linux-gnu-gcc** (for Raspberry Pi cross-compilation)


## Building with Make

### 1. Linux (Release)

$ make linux

Output: release/main.o
        realease/main.s
        release/appTimer.o
        realease/appTimer.s
        release/LEDDisplay.o
        realease/LEDDisplay.s


### 2. Linux (Debug)

$ make debug

Output: debug/main.o
        debug/appTimer.o
        debug/LEDDisplay.o


### 3. Raspberry Pi (Release, cross-compile)

$ make rpi

Output: release/AppTimerBinary


### 5. Build All

$ make all

Builds both linux and rpi.

### 6. Clean Build Artifacts

$ make clean

Removes all files from release/ and debug/ folders.

## Building with Make

### 1. Release Build

$ mkdir build && cd build
$ cmake ..
$ make


## Building with CMake

## Using gcc Compiler
Output: release/AppTimerwithLED_gcc

## Using aarch64-linux-gnu-gcc
Output: release/AppTimerwithLED_rpi

### 1. Release Build

$ cmake -B build 
$ cmake --build



