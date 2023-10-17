#include <stdio.h>

#ifndef DOOMDEPTHSC_SPRITE_H
#define DOOMDEPTHSC_SPRITE_H

typedef struct {
    char **sprite;
    int y_size;
} Sprite;

int get_nbRows(FILE *f);

int get_nbChars(FILE *f);

void set_sprite(Sprite *sprite, const char *sprite_id);

Sprite *new_sprite(const char *sprite_id);

void free_sprite(Sprite *sprite);

void show_sprite(const Sprite *sprite, unsigned int offset);

#endif
