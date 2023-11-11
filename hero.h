#include "sprite.h"

#ifndef DOOMDEPTHSC_HERO_H
#define DOOMDEPTHSC_HERO_H

typedef struct {
    int level;
    int max_health_points;
    int health_points;
    int max_mana_points;
    int mana_points;
    int attack;
    int defense;
    int alive;
    Sprite *sprite;
} Hero;

Hero *new_hero(int level, int hp, int mp, int attack, int def, char* sprite_id);
Hero *get_saved_hero(int level, int max_hp, int hp, int max_mp, int mp, int attack, int def, int alive, char* sprite_id);

void free_hero(Hero *hero);

#endif
