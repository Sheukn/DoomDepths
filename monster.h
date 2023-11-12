#include "random.h"
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

typedef struct {
    int size;
    Monster **monster_array;
} Monster_Array;

Monster *new_monster_full(int hp, int power_min, int power_max, int def, int alive, int xp, char *sprite_id);
Monster *new_monster(int level, int type);
Monster **new_monster_list(int nbr_monster, int level);
Monster **new_boss_list(int level);
int check_monster_list(Monster **monster_list, int nbr_monster);
Monster **rearrange_monster_list(Monster **monster_list, int nbr_monster_to_keep);

Monster *new_random_monster();

void free_monster(Monster *monster);
void free_monster_list(Monster **monster);

Monster_Array *new_monster_array(int size);

void free_monster_array(Monster_Array *monsterArray);

Monster_Array *random_monster_array(int size);

#endif
