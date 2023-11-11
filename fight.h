#include "hero.h"
#include "monster.h"
#include "sprite.h"

#ifndef DOOMDEPTHSC_FIGHT_H
#define DOOMDEPTHSC_FIGHT_H

int hero_attack(Hero* hero, Monster* monster);
int monster_attack(Monster* monster, Hero* hero);
int concentrate(Hero* hero);

#endif