#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "deplacement.h"
#include "display.h"

void clear_console();

void show_title();

int main() {

    // Position pos;
    // pos.x = 0;
    // pos.y = 0;

    // Cell **map;
    //     map = malloc(sizeof(Cell) * 10);
    //     for(int i = 0; i < 10; i++){
    //         map[i] = malloc(sizeof(Cell) * 9);

    //     }
    //     createMap(map);
    //     getEntry(map, &pos.x, &pos.y);

    // while(1){
    //     printMap(map);
    //     printf("\n");
    //     printf("posX = %d posY = %d", pos.x, pos.y);
    //     moveHero(map, &pos);
    //     clear_console();
    // }
    
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
