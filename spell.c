#include <stdlib.h>
#include "spell.h"

Spell *new_spell(char *name, int atk, int mana) {
    Spell *spell = calloc(1, sizeof(Spell));
    spell->name = name;
    spell->atk_pow = atk;
    spell->mana_cost = mana;
    return spell;
}

Spell **new_spell_list(Spell * spell){
    Spell **spell_list = calloc(1, sizeof(Spell));
    spell_list[0] = spell;
    return spell_list;
}

Spell **add_spell(Spell **spell_list, int spell_list_size, Spell *spell){
    spell_list = realloc(spell_list, (spell_list_size + 1) * sizeof(Spell));
    spell_list[spell_list_size] = spell;
    return spell_list;
}

void free_spell(Spell *spell) {
    free(spell);
}

void free_spell_list(Spell *spell_list){

}