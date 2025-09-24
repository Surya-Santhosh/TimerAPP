cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 17)
project(TimerApp_GCC)

# Add the folders for header files
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer
                    ${CMAKE_SOURCE_DIR}/../LEDDisplay
                    ${CMAKE_SOURCE_DIR}/../rpi/include)

add_executable(AppTimerwithLED_gcc 
               ${CMAKE_SOURCE_DIR}/../main.c
               ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
               ${CMAKE_SOURCE_DIR}/../LEDDisplay/LEDDisplay.c)
              

# List executable files in release folder

target_compile_options(AppTimerwithLED_gcc PRIVATE 
                       -g -O0 -Wall -Wextra -Werror -fanalyzer)

set_target_properties(AppTimerwithLED_gcc PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../release)

# List debug files in debug folder
add_executable(AppTimerwithLED_Debug 
               ${CMAKE_SOURCE_DIR}/../main.c
               ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
               ${CMAKE_SOURCE_DIR}/../LEDDisplay/LEDDisplay.c)

target_compile_options(AppTimerwithLED_Debug PRIVATE -g -O0 -c -fanalyzer)

set_target_properties(AppTimerwithLED_Debug PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../debug)
