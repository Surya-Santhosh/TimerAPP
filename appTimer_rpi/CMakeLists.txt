cmake_minimum_required(VERSION 3.10)
project(TimerApp_Rpi)

# Add the folders for header files
include_directories(${CMAKE_SOURCE_DIR}/..
                    ${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../LEDDisplay
                    ${CMAKE_SOURCE_DIR}/../GPIOControl
                    ${CMAKE_SOURCE_DIR}/../rpi64/include)


add_executable(AppTimerwithLED_rpi  
               ${CMAKE_SOURCE_DIR}/../main.c
               ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
               ${CMAKE_SOURCE_DIR}/../LEDDisplay/LEDDisplay.c
               ${CMAKE_SOURCE_DIR}/../GPIOControl/GPIOControl.c)


# List binary executable files in release folder

target_compile_options(AppTimerwithLED_rpi PRIVATE -DENABLE_LED_ON_RPI
                         -g -O0 -Wall -Wextra -Werror -fanalyzer)

target_link_directories(AppTimerwithLED_rpi PRIVATE 
                        ${CMAKE_SOURCE_DIR}/../rpi64/lib)

target_link_libraries(AppTimerwithLED_rpi PRIVATE 
                        ${CMAKE_SOURCE_DIR}/../rpi64/lib/libgpiod.so)

set_target_properties(AppTimerwithLED_rpi PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../release)

