#include <stdlib.h>
#include "game.h"
#include "hero.h"
#include "monster.h"
#include "spell.h"
#include "inventory.h"

int hero_attack(Hero* hero, Monster* monster, Weapon* weapon){
    int damage = (hero->attack + weapon->damage )- monster->defense;
    if(damage < 1){
        damage = 1;
    }
    monster->health_points -= damage;
    if (monster->health_points <= 0){
        monster->alive = 0;
        hero->xp += monster->xp;
    }
    return damage;
}

int hero_spell(Hero* hero, Spell* spell, Monster *monster){
    hero->mana_points -= spell->mana_cost;
    monster->health_points -= spell->atk_pow;
    if (monster->health_points <= 0){
        monster->alive = 0;
        hero->xp += monster->xp;
    }
    return spell->atk_pow;
}

int monster_attack(Monster* monster, Hero* hero, int defending, Armor* armor){
    int damage = (monster->min_atk_pow + rand() % monster->max_atk_pow) - (hero->defense + armor->defense);
    if (defending == 1){
        damage = damage / 2;
    }
    if(damage < 0){
        damage = 0;
    }
    hero->health_points -= damage;
    if (hero->health_points <= 0){
        hero->alive = 0;
    }
    return damage;
}

int concentrate(Hero* hero, float ratio){
    int mana_regen = hero->max_mana_points * ratio;
    if((hero->mana_points + mana_regen)> hero->max_mana_points){
        mana_regen = hero->max_mana_points - hero->mana_points;
    }
    hero->mana_points += mana_regen;
    return mana_regen;
}

int health_rest(Hero* hero, float ratio){
    int health_regen = hero->max_health_points * ratio;
    if((hero->health_points + health_regen)> hero->max_health_points){
        health_regen = hero->max_health_points - hero->health_points;
    }
    hero->health_points += health_regen;
    return health_regen;
}