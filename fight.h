#include "hero.h"
#include "monster.h"
#include "sprite.h"
#include "spell.h"
#include "inventory.h"

#ifndef DOOMDEPTHSC_FIGHT_H
#define DOOMDEPTHSC_FIGHT_H

int hero_attack(Hero* hero, Monster* monster, Weapon* weapon);
int monster_attack(Monster* monster, Hero* hero, int defending, Armor* armor);
int concentrate(Hero* hero, float ratio);
int mana_rest(Hero* hero);
int health_rest(Hero* hero, float ratio);
int hero_spell(Hero* hero, Spell* spell, Monster *monster);

#endif