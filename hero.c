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
    hero->sprite = new_sprite(sprite_id);
    return hero;
}

Hero *get_saved_hero(int level, int max_hp, int hp, int max_mp, int mp, int attack, int def, int alive, char* sprite_id) {
    Hero *hero = calloc(1, sizeof(Hero));
    hero->level = level;
    hero->max_health_points = max_hp;
    hero->health_points = hp;
    hero->max_mana_points = max_mp;
    hero->mana_points = mp;
    hero->attack = attack;
    hero->defense = def;
    hero->alive = alive;
    hero->sprite = new_sprite(sprite_id);
    return hero;
}

void free_hero(Hero *hero) {
    free_sprite(hero->sprite);
    free(hero);
}