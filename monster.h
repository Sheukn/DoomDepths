#include "sprite.h"

#ifndef DOOMDEPTHSC_MONSTER_H
#define DOOMDEPTHSC_MONSTER_H

typedef struct {
    int health_points;
    int min_atk_pow;
    int max_atk_pow;
    int defense;
    Sprite *sprite;
} Monster;

Monster *new_monster(int hp, int power_min, int power_max, int def, char* sprite_id);

void free_monster(Monster *monster);

#endif
