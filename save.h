#include "sqlite3.h"

#ifndef DOOMDEPTHSC_SAVE_H
#define DOOMDEPTHSC_SAVE_H

void save(const Hero *hero, const Inventory *inventory/*, const Monster **monster_list*/);

void load(Hero *hero, Inventory *inventory/*, Monster **monster_list, unsigned  int *nbr_monster*/);

#endif
