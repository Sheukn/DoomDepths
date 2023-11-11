
#ifndef DOOMDEPTHSC_SPELL_H
#define DOOMDEPTHSC_SPELL_H

typedef struct {
    char* name;
    int atk_pow;
    int mana_cost;
} Spell;

Spell *new_spell(char *name, int atk, int mana);
Spell **new_spell_list();
Spell **add_spell(Spell **spell_list, int spell_list_size, Spell *spell);

void free_spell(Spell *spell);

#endif