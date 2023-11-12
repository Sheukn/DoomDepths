#include <stdlib.h>
#include <stdio.h>
#include "sprite.h"
#include "monster.h"

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
    return new_monster_list;
}

void free_monster(Monster *monster) {
    free_sprite(monster->sprite);
    free(monster);
}
void free_monster_list(Monster **monster_list){

}
