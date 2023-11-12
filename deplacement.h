#include "map.h"



#ifndef DOOMDEPTHSC_DEPLACEMENT_H
#define DOOMDEPTHSC_DEPLACEMENT_H

typedef struct Position {
    int x; // x coordinate
    int y; // y coordinate
}Position;

void moveHero(Cell** map, Position* pos, char move);

#endif