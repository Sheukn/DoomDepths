#include <stdlib.h>
#include "sprite.h"
#include "monster.h"

Monster *new_monster(int hp, int power_min, int power_max, int def, char* sprite_id) {
    Monster *monster = calloc(1, sizeof(Monster));
    monster->health_points = hp;
    monster->min_atk_pow = power_min;
    monster->max_atk_pow = power_max;
    monster->defense = def;
    monster->sprite = new_sprite(sprite_id);
    return monster;
}

void free_monster(Monster *monster) {
    free_sprite(monster->sprite);
    free(monster);
}
