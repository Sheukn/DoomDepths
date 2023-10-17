cmake_minimum_required(VERSION 3.26)
project(DoomDepthsC C)

set(CMAKE_C_STANDARD 11)

add_executable(DoomDepthsC main.c
        monster.c
        monster.h
        sprite.c
        sprite.h)
