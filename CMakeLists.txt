cmake_minimum_required(VERSION 3.26)
project(DoomDepthsC C)

set(CMAKE_C_STANDARD 11)

add_executable(main.c
        monster.c
        monster.h
        sprite.c
        sprite.h
        random.c
        random.h
        random.h
        save.c
        save.h
        sqlite3.c
        sqlite3.h
        sqlite3ext.h
        display.c
        fight.c
        game.c
        hero.c
        inventory.c
        main.c
        map.c
        map.h
        spell.c
        deplacement.c)
