#include "sprite.h"

#ifndef DOOMDEPTHSC_MONSTER_H
#define DOOMDEPTHSC_MONSTER_H

typedef struct {
    int health_points;
    int min_atk_pow;
    int max_atk_pow;
    int defense;
    int alive;
    int xp;
    Sprite *sprite;
} Monster;

Monster *new_monster(int level, int type);
Monster **new_monster_list(int nbr_monster, int level);
Monster **new_boss_list(int level);
int check_monster_list(Monster **monster_list, int nbr_monster);
Monster **rearrange_monster_list(Monster **monster_list, int nbr_monster_to_keep);

void free_monster(Monster *monster);

#endif
