#include <stdio.h>
#include <stdlib.h>
#include "hero.h"
#include "inventory.h"
#include "monster.h"
#include "sqlite3.h"
#include "save.h"

char *int_to_string(int value) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "%d", value);
    return buf;
}

void save_hero(sqlite3 *db, const Hero *hero) {
    char *zErrMsg = 0;
    sqlite3_exec(db, "DELETE from hero;", 0, 0, &zErrMsg);
    char *sql = calloc(1024, sizeof(char));
    strcat(sql, "INSERT INTO hero (level,max_health_points,health_points,"
                "max_mana_points,mana_points,attack,defense,alive,"
                "xp,xp_to_up) VALUES(");
    strcat(sql, int_to_string(hero->level));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->max_health_points));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->health_points));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->max_mana_points));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->mana_points));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->attack));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->defense));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->alive));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->xp));
    strcat(sql, ",");
    strcat(sql, int_to_string(hero->xp_to_up));
    strcat(sql, ");");
    sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    free(sql);
}

void save_inventory(sqlite3 *db, Inventory *inventory) {
    char *zErrMsg = 0;
    sqlite3_exec(db, "DELETE from armor;", 0, 0, &zErrMsg);
    sqlite3_exec(db, "DELETE from weapon;", 0, 0, &zErrMsg);
    while (inventory->armorList != NULL && inventory->armorList->armor != NULL) {
        char *sql1 = calloc(1024, sizeof(char));
        strcat(sql1, "INSERT INTO armor(name,defense) VALUES('");
        strcat(sql1, inventory->armorList->armor->name);
        strcat(sql1, "',");
        strcat(sql1, int_to_string(inventory->armorList->armor->defense));
        strcat(sql1, ");");
        sqlite3_exec(db, sql1, 0, 0, &zErrMsg);
        free(sql1);
        inventory->armorList = inventory->armorList->next;
    }
    while (inventory->weaponList != NULL && inventory->weaponList->weapon != NULL) {
        char *sql2 = calloc(1024, sizeof(char));
        strcat(sql2, "INSERT INTO weapon(name,damage) VALUES('");
        strcat(sql2, inventory->weaponList->weapon->name);
        strcat(sql2, "',");
        strcat(sql2, int_to_string(inventory->weaponList->weapon->damage));
        strcat(sql2, ");");
        sqlite3_exec(db, sql2, 0, 0, &zErrMsg);
        free(sql2);
        inventory->weaponList = inventory->weaponList->next;
    }
}

void save_monsters(sqlite3 *db, const Monster **monster_list) {
    char *zErrMsg = 0;
    sqlite3_exec(db, "DELETE from monster;", 0, 0, &zErrMsg);
    int i = 0;
    while (monster_list[i] != NULL) {
        char *sql = calloc(1024, sizeof(char));
        strcat(sql, "INSERT INTO monster (health_points,min_atk_pow,max_atk_pow,defense,alive,xp,sprite_id) VALUES(");
        strcat(sql, int_to_string(monster_list[i]->health_points));
        strcat(sql, ",");
        strcat(sql, int_to_string(monster_list[i]->min_atk_pow));
        strcat(sql, ",");
        strcat(sql, int_to_string(monster_list[i]->max_atk_pow));
        strcat(sql, ",");
        strcat(sql, int_to_string(monster_list[i]->defense));
        strcat(sql, ",");
        strcat(sql, int_to_string(monster_list[i]->alive));
        strcat(sql, ",");
        strcat(sql, int_to_string(monster_list[i]->xp));
        strcat(sql, ",'");
        strcat(sql, monster_list[i]->sprite->sprite_id);
        strcat(sql, "');");
        sqlite3_exec(db, sql, 0, 0, &zErrMsg);
        free(sql);
        i++;
    }
}

void save(const Hero *hero, const Inventory *inventory/*, const Monster **monster_list*/) {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("doomdepthc.db", &db);
    if (rc == SQLITE_OK) {
        save_hero(db, hero);
        save_inventory(db, inventory);
        //save_monsters(db, monster_list);
    }
}

Hero load_hero(sqlite3 *db) {
    sqlite3_stmt *res;
    const char *tail;
    sqlite3_prepare_v2(db, "SELECT * FROM hero;", 128, &res, &tail);
    sqlite3_step(res);
    Hero const *hero = new_hero(
            sqlite3_column_int(res, 0),
            sqlite3_column_int(res, 1),
            sqlite3_column_int(res, 2),
            sqlite3_column_int(res, 3),
            sqlite3_column_int(res, 4),
            "HERO"
    );
    sqlite3_finalize(res);
    return *hero;
}

int get_nb_monster(sqlite3 *db) {
    int count = 0;
    sqlite3_stmt *res;
    const char *tail;
    sqlite3_prepare_v2(db, "SELECT * FROM monster;", 128, &res, &tail);
    while (sqlite3_step(res) == SQLITE_ROW) {
        count++;
    }
    sqlite3_finalize(res);
    return count;
}

Monster *load_monster_list(sqlite3 *db) {
    sqlite3_stmt *res;
    const char *tail;
    sqlite3_prepare_v2(db, "SELECT * FROM monster;", 128, &res, &tail);
    int nb_monster = get_nb_monster(db);
    Monster **monster_list = calloc(nb_monster, sizeof(Monster));
    for (int i = 0; i < nb_monster; i++) {
        sqlite3_step(res);
        monster_list[i] = new_monster_full(
                sqlite3_column_int(res, 0),
                sqlite3_column_int(res, 1),
                sqlite3_column_int(res, 2),
                sqlite3_column_int(res, 3),
                sqlite3_column_int(res, 4),
                sqlite3_column_int(res, 5),
                sqlite3_column_text(res, 6)
        );
    }
    sqlite3_finalize(res);
    return *monster_list;
}

void load(Hero *hero, Inventory *inventory/*, Monster **monster_list, unsigned int *nbr_monster*/) {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("doomdepthc.db", &db);
    if (rc == SQLITE_OK) {
        *hero = load_hero(db);
        //*monster_list = load_monster_list(db);
    }
}
