#include <stdlib.h>
#include "display.h"
#include "sprite.h"
#include "monster.h"

void clear_console() {
    system("clear");
    //system("cls");
}

void show_title() {
    printf(ANSI_COLOR_RED);
    Sprite *titleSprite = new_sprite("01");
    show_sprite(titleSprite, 3);
    free_sprite(titleSprite);

    printf("\n");
    printf(ANSI_COLOR_RED);
    printf("______ _____  ________  ________ ___________ _____ _   _  _____ \n");
    printf("|  _  \\  _  ||  _  |  \\/  |  _  \\  ___| ___ \\_   _| | | |/  ___|\n");
    printf(ANSI_COLOR_BRIGHT_RED);
    printf("| | | | | | || | | | .  . | | | | |__ | |_/ / | | | |_| |\\ `--. \n");
    printf("| | | | | | || | | | |\\/| | | | |  __||  __/  | | |  _  | `--. \\\n");
    printf(ANSI_COLOR_RESET);
    printf("| |/ /\\ \\_/ /\\ \\_/ / |  | | |/ /| |___| |     | | | | | |/\\__/ /\n");
    printf("|___/  \\___/  \\___/\\_|  |_/___/ \\____/\\_|     \\_/ \\_| |_/\\____/ \n");
    printf("\n");
}

void show_combat_choices(){
    printf("\n1 - ATTACK\n");
    printf("2 - SPELLS\n");
    printf("3 - CONCENTRATE\n");
    printf("4 - DEFEND\n");
    printf("5 - HERO'S STATS\n");
}

void show_monsters_life(Monster **monster_list, int nbr_monster){
    for(int k = 0; k<nbr_monster; k++){
        printf("\n");
        printf("MONSTER %c : %d HP.\n", 'A' + k, monster_list[k]->health_points);
    }
}