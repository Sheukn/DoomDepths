#include "map.h"

void freeMap(int size, Cell ***map) {
    for (int i = 0; i < size; i++) {
        free((*map)[i]);
    }
    free(*map);
}

void createMap(Cell** map) {
    FILE* mapFile;
    srand((unsigned int)time(NULL));
    int mapNumber = rand() % 3;
    switch (mapNumber)
    {
    case 0:
        mapFile = fopen("map_1.txt", "r");
        break;
    case 1:
        mapFile = fopen("map_2.txt", "r");
        break;
    case 2:
        mapFile = fopen("map_3.txt", "r");
        break;
    default:
        break;
    }
    if(mapFile == NULL)
        printf("Error: map file not found");

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c = fgetc(mapFile);
            if (c == EOF || c == '\n') {                
                break;
            }

            if (c == '-'){
                map[i][j].type = ' ';
            }
            else
                map[i][j].type = c;

            int event = rand() % 5;
                switch (event)
                {
                case 0:
                    map[i][j].event = 0;
                    break;
                case 1:
                    map[i][j].event = 1;
                    break;
                case 2:
                    map[i][j].event = 3;
                    break;
                default:
                    map[i][j].event = 2;
                    break;
                }
            if (c == 'B'){
                map[i][j].event = 4;
            }
            if (c == 'H'){
                map[i][j].event = 0;
            }
            if (c == 'O'){
                map[i][j].event = 5;
            }
        }
        int newline = fgetc(mapFile);
    }
    fclose(mapFile);
}

void printMap(Cell **map) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", map[i][j].type);
        }
        printf("\n");
    }
}

void getEntry(Cell **map, int *x, int *y) {

    if (map[1][0].type == 'H'){
        *x = 1;
        *y = 0;
    }
    else if(map[7][8].type == 'H'){
        *x = 7;
        *y = 8;
    }
    else if  (map[0][4].type == 'H'){
        *x = 0;
        *y = 4;
    }
    else{
        printf("Error: no entry found");
    }
}
