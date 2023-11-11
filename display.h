#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

#ifndef DOOMDEPTHSC_DISPLAY_H
#define DOOMDEPTHSC_DISPLAY_H
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_BRIGHT_RED   "\x1b[1;31m"
#define ANSI_COLOR_RESET        "\x1b[0m"

void clear_console();
void show_title();
void show_combat_choices();
void show_monsters_life(Monster **monster_list, int nbr_monster);

#endif