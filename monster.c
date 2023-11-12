#include <stdlib.h>
#include "random.h"
#include <stdio.h>
#include "sprite.h"
#include "monster.h"

Monster *new_monster_full(int hp, int power_min, int power_max, int def, int alive, int xp, char *sprite_id) {
    Monster *monster = calloc(1, sizeof(Monster));
    monster->health_points = hp;
    monster->min_atk_pow = power_min;
    monster->max_atk_pow = power_max;
    monster->defense = def;
    monster->alive = alive;
    monster->xp = xp;
    monster->sprite = new_sprite(sprite_id);
    return monster;
}

Monster *new_monster(int level, int type) {
    Monster *monster = calloc(1, sizeof(Monster));
    switch (type)
    {
    case 1 :
    {
        monster->health_points = 6 + (level - 1) * 3;
        monster->min_atk_pow = 2 + level - 1;
        monster->max_atk_pow = 3 + level - 1;
        monster->defense = 3 + (level - 1) * 2;
        monster->alive = 1;
        monster->xp = 30;
        monster->sprite = new_sprite("SLIME");
        break;
    }

    case 2 :
    {
        monster->health_points = 4 + level - 1;
        monster->min_atk_pow = 3 + (level - 1) * 2 ;
        monster->max_atk_pow = 3 + (level - 1) * 2 ;
        monster->defense = 1 + (level - 1);
        monster->alive = 1;
        monster->xp = 40;
        monster->sprite = new_sprite("RAT");
        break;
    }

    case 3 :
    {
        monster->health_points = 5 + (level - 1) * 2;
        monster->min_atk_pow = 3 + level - 1;
        monster->max_atk_pow = 4 + (level - 1) * 3;
        monster->defense = 2 + level - 1;
        monster->alive = 1;
        monster->xp = 50;
        monster->sprite = new_sprite("GOBLIN");
        break;
    }

    case 4 :
    {
        monster->health_points = 30 + (level - 1) * 10;
        monster->min_atk_pow = 6 + (level - 1) * 2;
        monster->max_atk_pow = 12 + (level - 1) * 4;
        monster->defense = 6 + level - 1;
        monster->alive = 1;
        monster->xp = 200;
        monster->sprite = new_sprite("BOSS");
        break;
    }
    default:
        break;
    }

    return monster;
}

Monster *new_random_monster() {
    Monster *random_monster = calloc(1, sizeof(Monster));
    random_monster->health_points = random_range(10, 50);
    random_monster->min_atk_pow = random_range(2, 6);
    random_monster->max_atk_pow = random_range(8, 20);
    random_monster->defense = random_range(5, 20);
    random_monster->sprite = new_sprite("01");
    return random_monster;
}

Monster **new_monster_list(int nbr_monster, int level){
    Monster **monster_list = calloc(nbr_monster, sizeof(Monster));
    for(int k = 0; k < nbr_monster; k++){
        monster_list[k] = new_monster(level, k+1);
    }
    return monster_list;
}

Monster **new_boss_list(int level){
    Monster **monster_list = calloc(3, sizeof(Monster));
        monster_list[0] = new_monster(level, 3);
        monster_list[1] = new_monster(level, 4);
        monster_list[2] = new_monster(level, 3);
    return monster_list;
}


int check_monster_list(Monster **monster_list, int nbr_monster){
    int nbr_dead = 0;
    for(int k = 0 ; k < nbr_monster; k++){
        if(monster_list[k]->alive == 0){
            nbr_dead++;
        }
    }
    return nbr_dead;
}

Monster **rearrange_monster_list(Monster **monster_list, int nbr_monster_to_keep){
    int k = 0;
    int l = 0;
    Monster **new_monster_list = calloc(nbr_monster_to_keep, sizeof(Monster));
    while(l != nbr_monster_to_keep){
        if(monster_list[k]->alive == 1){
            new_monster_list[l] = monster_list[k];
            l++;
        }
        k++;
    }
    free_monster_list(monster_list);
    return new_monster_list;
}

void free_monster(Monster *monster) {
    free_sprite(monster->sprite);
    free(monster);
}
void free_monster_list(Monster **monster_list){
    free(monster_list);
}

Monster_Array *new_monster_array(int size) {
    Monster_Array *monsterArray = calloc(1, sizeof(Monster_Array));
    monsterArray->size = size;
    monsterArray->monster_array = calloc(size, sizeof(Monster));
    return monsterArray;
}

void free_monster_array(Monster_Array *monsterArray) {
    for (int i = 0; i < monsterArray->size; i++) {
        free_monster(monsterArray->monster_array[i]);
    }
    free(monsterArray->monster_array);
    free(monsterArray);
}

Monster_Array *random_monster_array(int size) {
    Monster_Array *randomMonsterArray = new_monster_array(size);
    for (int i = 0; i < randomMonsterArray->size; i++) {
        randomMonsterArray->monster_array[i] = new_random_monster();
    }
    return randomMonsterArray;
}
