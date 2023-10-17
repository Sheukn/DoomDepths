#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "sprite.h"

#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_BRIGHT_RED   "\x1b[1;31m"
#define ANSI_COLOR_RESET        "\x1b[0m"

void clear_console();

void show_title();

int main() {
    int running = 1;

    while (running) {
        show_title();

        //Menu
        printf("\n");
        printf("1 - Start\n");
        printf("\n");
        printf("0 - Quit\n");

        char input;
        scanf("%c", &input);
        switch (input) {
            case '1':
                break;
            case '0':
                running = 0;
                break;
            default:
                break;
        }
        clear_console();
    }

    return 0;
}

void clear_console() {
    system("cls");
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
