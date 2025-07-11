cmake_minimum_required(VERSION 3.10)
project(TimerApp_Rpi)

# Add the folders for header files
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../LEDDisplay)


add_executable(AppTimerwithLED_rpi  
               ${CMAKE_SOURCE_DIR}/../main.c
               ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
               ${CMAKE_SOURCE_DIR}/../LEDDisplay/LEDDisplay.c)

# List binary executable files in release folder
target_compile_options(AppTimerwithLED_rpi PRIVATE 
                       -Wall -Wextra -Werror)
                       
set_target_properties(AppTimerwithLED_rpi PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../release)

