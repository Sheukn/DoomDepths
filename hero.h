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
    int xp;
    int xp_to_up;
    Sprite *sprite;
} Hero;

Hero *new_hero(int level, int hp, int mp, int attack, int def, char* sprite_id);
Hero *get_saved_hero(int level, int max_hp, int hp, int max_mp, int mp, int attack, int def, int alive, int xp, int xp_to_up, char* sprite_id);
int level_up(Hero* hero);

void free_hero(Hero *hero);

#endif
