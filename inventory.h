#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#ifndef DOOMDEPTHSC_INVENTORY_H
#define DOOMDEPTHSC_INVENTORY_H

    typedef struct Weapon {
        char name[20];
        int damage;
    } Weapon;

    typedef struct Armor {
        char name[20];
        int defense;
    } Armor;

    typedef struct WeaponList {
        Weapon *weapon;
        struct WeaponList *next;
    } WeaponList;

    typedef struct ArmorList {
        Armor *armor;
        struct ArmorList *next;
    } ArmorList;

    typedef struct inventory {
        WeaponList *weaponList;
        ArmorList *armorList;
    } Inventory;

    void printInventory(Inventory *inventory);
    void printEquipped(Inventory *inventory);
    void printWeaponList(Inventory *inventory);
    void printArmorList(Inventory *inventory);
    int getWeaponListSize(Inventory *inventory);
    int getArmorListSize(Inventory *inventory);
    void selectWeapon(Inventory *inventory);
    void selectArmor(Inventory *inventory);
    void drop(Inventory *inventory);


#endif 