#include <stdlib.h>
#include "game.h"
#include "hero.h"
#include "monster.h"

int hero_attack(Hero* hero, Monster* monster){
    int damage = hero->attack - monster->defense;
    if(damage < 1){
        damage = 1;
    }
    monster->health_points -= damage;
    if (monster->health_points <= 0){
        monster->alive = 0;
    }
    return damage;
}

int monster_attack(Monster* monster, Hero* hero){
    int damage = (monster->max_atk_pow + monster->min_atk_pow) / 2 - hero->defense;
    if(damage < 0){
        damage = 0;
    }
    hero->health_points -= damage;
    if (hero->health_points <= 0){
        hero->alive = 0;
    }
    return damage;
}

int concentrate(Hero* hero){
    int mana_regen = hero->max_mana_points * 0.2;
    if((hero->mana_points + mana_regen)> hero->max_mana_points){
        mana_regen = hero->max_mana_points - hero->mana_points;
    }
    hero->mana_points += mana_regen;
    return mana_regen;
}