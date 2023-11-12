#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef DOOMDEPTHSC_MAP_H
#define DOOMDEPTHSC_MAP_H

typedef struct {
    char type;
    int event;
} Cell;

void freeMap(int size, Cell ***map);
void createMap(Cell** map);
void getEntry(Cell **map, int *x, int *y);
void printMap(Cell **map);

#endif
