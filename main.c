#include <stdio.h>
#include <stdlib.h>
#include "game.h"


void clear_console();

void show_title();

int main() {   
    int running = 1;

    while (running) {
        show_title();

        //Menu
        printf("\n");
        printf("1 - START\n");
        printf("\n");
        printf("0 - QUIT\n");

        char input;
        scanf("%c", &input);
        switch (input) {
            case '1':
                launch();
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
