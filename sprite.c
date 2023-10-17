#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"

int get_nbRows(FILE *f) {
    long cursorPos = ftell(f);
    rewind(f);
    int nbRows = 1;
    int c = fgetc(f);
    while (c != EOF) {
        if (c == '\n') {
            nbRows++;
        }
        c = fgetc(f);
    }
    fseek(f,cursorPos,SEEK_SET);
    return nbRows;
}

int get_nbChars(FILE *f) {
    long cursorPos = ftell(f);
    int nbChars = 1;
    int c = fgetc(f);
    while (c != '\n' && c != EOF) {
        nbChars++;
        c = fgetc(f);
    }
    fseek(f,cursorPos,SEEK_SET);
    return nbChars;
}

void set_sprite(Sprite *sprite, const char *sprite_id) {
    char fileName[16] = "../sprite-";
    strcat(fileName, sprite_id);
    strcat(fileName, ".txt");
    FILE *f = fopen(fileName, "rb");
    if (f == NULL) {
        return;
    }
    sprite->y_size = get_nbRows(f);
    if (sprite->y_size > 0) {
        sprite->sprite = calloc(sprite->y_size, sizeof(char *));
        for (int y = 0; y < sprite->y_size; y++) {
            int nbChars = get_nbChars(f);
            sprite->sprite[y] = calloc(nbChars + 1, sizeof(char));
            for (int x = 0; x < nbChars - 1; x++) {
                char c = (char) fgetc(f);
                sprite->sprite[y][x] = c;
            }
            sprite->sprite[y][nbChars] = '\0';
            fseek(f, 1, SEEK_CUR);
        }
    }
    fclose(f);
}

Sprite *new_sprite(const char *sprite_id) {
    Sprite *sprite = calloc(1, sizeof(Sprite));
    set_sprite(sprite, sprite_id);
    return sprite;
}

void free_sprite(Sprite *sprite) {
    for (int y = 0; y < sprite->y_size; y++) {
        free(sprite->sprite[y]);
    }
    free(sprite->sprite);
    free(sprite);
}

void show_sprite(const Sprite *sprite,unsigned int offset) {
    for (int i = 0; i < sprite->y_size; i++) {
        for (int j = 0; j < offset; j++) {
            printf(" ");
        }
        printf("%s\n", sprite->sprite[i]);
    }
}
