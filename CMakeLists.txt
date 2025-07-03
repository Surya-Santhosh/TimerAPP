cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 17)
project(AppTimer)

# Add the folders for header files
include_directories(${CMAKE_SOURCE_DIR} appTimer LEDDisplay)

# List all source files
set(SOURCES main.c appTimer/appTimer.c LEDDisplay/LEDDisplay.c)

# List executable files in release folder
add_executable(AppTimer ${SOURCES})
target_compile_options(AppTimer PRIVATE -Wall -Wextra -Werror)
set_target_properties(AppTimer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release)

# List debug files in debug folder
add_executable(AppTimer_Debug ${SOURCES})
target_compile_options(AppTimer_Debug PRIVATE -g -O0 -c)
set_target_properties(AppTimer_Debug PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/debug)
