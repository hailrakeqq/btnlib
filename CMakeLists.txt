cmake_minimum_required(VERSION 3.26)
project(btnlib C)

set(MCU "atmega328p")
set(F_CPU 16000000)

set(CMAKE_C_STANDARD 11)

include_directories("/home/hailrake/.arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino/")
include_directories("/usr/avr/include")
include_directories("/home/hailrake/.arduino15/packages/arduino/hardware/avr/1.8.6/variants/micro/")

add_library(bntlib src/btnlib.c)
