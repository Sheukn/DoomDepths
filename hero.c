#include <stdlib.h>
#include "hero.h"

Hero *new_hero(int level, int hp, int mp, int attack, int def, char* sprite_id) {
    Hero *hero = calloc(1, sizeof(Hero));
    hero->level = level;
    hero->max_health_points = hp;
    hero->health_points = hp;
    hero->max_mana_points = mp;
    hero->mana_points = mp;
    hero->attack = attack;
    hero->defense = def;
    hero->alive = 1;
    hero->xp = 0;
    hero->xp_to_up = 100;
    hero->sprite = new_sprite(sprite_id);
    return hero;
}

Hero *get_saved_hero(int level, int max_hp, int hp, int max_mp, int mp, int attack, int def, int alive, int xp, int xp_to_up, char* sprite_id) {
    Hero *hero = calloc(1, sizeof(Hero));
    hero->level = level;
    hero->max_health_points = max_hp;
    hero->health_points = hp;
    hero->max_mana_points = max_mp;
    hero->mana_points = mp;
    hero->attack = attack;
    hero->defense = def;
    hero->alive = alive;
    hero->xp = xp;
    hero->xp_to_up = xp_to_up;
    hero->sprite = new_sprite(sprite_id);
    return hero;
}

int level_up(Hero* hero){
    hero->level++;
    hero->max_health_points += 5;
    hero->health_points += 5;
    hero->max_mana_points += 3;
    hero->mana_points += 3;
    hero->attack += 2;
    hero->defense += 1;
    hero->xp -= hero->xp_to_up;
    hero->xp_to_up += 50;
    return hero->level;
}

void free_hero(Hero *hero) {
    free_sprite(hero->sprite);
    free(hero);
}