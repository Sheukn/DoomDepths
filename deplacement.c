#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "deplacement.h"

void moveHero(Cell** map, Position* pos, char move){
    switch (move){
        case 'w':
        case 'z':
            if (map[pos->x-1][pos->y].type != '#'){
                map[pos->x][pos->y].type = ' ';
                map[pos->x-1][pos->y].type = 'H';
                pos->x--;
            }
            break;
        case 's':
            if (map[pos->x+1][pos->y].type != '#'){
                map[pos->x][pos->y].type = ' ';
                map[pos->x+1][pos->y].type = 'H';
                pos->x++;
            }
            break;
        case 'a':
        case 'q':
            if (map[pos->x][pos->y-1].type != '#'){
                map[pos->x][pos->y].type = ' ';
                map[pos->x][pos->y-1].type = 'H';
                pos->y--;
            }
            break;
        case 'd':
            if (map[pos->x][pos->y+1].type != '#'){
                map[pos->x][pos->y].type = ' ';
                map[pos->x][pos->y+1].type = 'H';
                pos->y++;
            }
            break;  
    }
}
   