#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "inventory.h"


void printInventory(Inventory *inventory) {
    system("clear");
    WeaponList *weaponList = inventory->weaponList;
    ArmorList *armorList = inventory->armorList;
    printf("Weapons:\n");
    while (weaponList != NULL) {
        printf("%s: %d\n", weaponList->weapon->name, weaponList->weapon->damage);
        weaponList = weaponList->next;
    }
    printf("Armor:\n");
    while (armorList != NULL) {
        printf("%s: %d\n", armorList->armor->name, armorList->armor->defense);
        armorList = armorList->next;
    }
}

void printEquipped(Inventory *inventory) {
    system("clear");
    WeaponList *weaponList = inventory->weaponList;
    ArmorList *armorList = inventory->armorList;
    if (weaponList == NULL) {
        printf("No weapon equipped\n");
    } else {
        printf("Equipped weapon: %s: %d\n", weaponList->weapon->name, weaponList->weapon->damage);
    }
    if (armorList == NULL) {
        printf("No armor equipped\n");
    } else {
        printf("Equipped armor: %s: %d\n", armorList->armor->name, armorList->armor->defense);
    }
}

void printWeaponList(Inventory *inventory) {
    system("clear");
    WeaponList *weaponList = inventory->weaponList;
    int i = 0;
    while (weaponList != NULL){
        printf("%d - %s: %d\n", i, weaponList->weapon->name, weaponList->weapon->damage);
        weaponList = weaponList->next;
        i++;
    }
}

void printArmorList(Inventory *inventory){
    system("clear");
    ArmorList *armorList = inventory->armorList;
    int i = 0;
    while (armorList != NULL) {
        printf("%d -  %s: %d\n", i, armorList->armor->name, armorList->armor->defense);
        armorList = armorList->next;
        i++;
    }
}

int getWeaponListSize(Inventory *inventory) {
    WeaponList *weaponList = inventory->weaponList;
    int i = 0;
    while (weaponList != NULL) {
        weaponList = weaponList->next;
        i++;
    }
    return i;
}

int getArmorListSize(Inventory *inventory) {
    ArmorList *armorList = inventory->armorList;
    int i = 0;
    while (armorList != NULL) {
        armorList = armorList->next;
        i++;
    }
    return i;
}


void addWeapon(Inventory *inventory, Weapon *weapon, int equip){
    WeaponList *weaponList = inventory->weaponList;
    if (weaponList == NULL) {
        weaponList = malloc(sizeof(weaponList));
        weaponList->weapon = weapon;
        weaponList->next = NULL;
        inventory->weaponList = weaponList;
        return;
    }
    if(equip){
        weaponList->weapon = weapon;
        return;
    }
    while (weaponList->next != NULL) {
        weaponList = weaponList->next;
    }
    WeaponList *newWeapon = malloc(sizeof(weaponList));
    newWeapon->weapon = weapon;
    newWeapon->next = NULL;
    weaponList->next = newWeapon;
}

void addArmor(Inventory *inventory, Armor *armor, int equip) {
    ArmorList *armorList = inventory->armorList;
    if (armorList == NULL) {
        armorList = malloc(sizeof(armorList));
        armorList->armor = armor;
        armorList->next = NULL;
        inventory->armorList = armorList;
        return;
    }
    if(equip){
        armorList->armor = armor;
        return;
    }
    while (armorList->next != NULL) {
        armorList = armorList->next;
    }
    ArmorList *newArmor = malloc(sizeof(armorList));
    newArmor->armor = armor;
    newArmor->next = NULL;
    armorList->next = newArmor;    
}

void selectWeapon(Inventory *inventory) {
    WeaponList *weaponList = inventory->weaponList;
    printWeaponList(inventory);
    int size = getWeaponListSize(inventory);
    char c = getchar();
    int index = c - '0';
    if (index < 0 || index >= size) {
        printf("Invalid input size = %d\n", size);
        return;
    }
    WeaponList *selectedWeapon = weaponList;
    for (int i = 0; i < index; i++) {
        selectedWeapon = selectedWeapon->next;
    }
    if (selectedWeapon == weaponList) {
        printEquipped(inventory);
        return;
    }
    WeaponList *prevWeapon = weaponList;
    while (prevWeapon->next != selectedWeapon) {
        prevWeapon = prevWeapon->next;
    }
    prevWeapon->next = selectedWeapon->next;
    selectedWeapon->next = weaponList;
    inventory->weaponList = selectedWeapon;
    printEquipped(inventory);
}

void selectArmor(Inventory *inventory) {
    ArmorList *armorList = inventory->armorList;
    printArmorList(inventory);
    int size = getArmorListSize(inventory);
    char c = getchar();
    int index = c - '0';
    if (index < 0 || index >= size) {
        printf("Invalid input size = %d\n", size);
        return;
    }
    for (int i = 0; i < index; i++) {
        armorList = armorList->next;
    }
    armorList->next = inventory->armorList;
    inventory->armorList = armorList;
    printEquipped(inventory);
}

void drop(Inventory *inventory){
    char *weaponName[] = {"Sword", "Axe", "Bow", "Dagger", "Mace", "Spear", "Staff", "Wand"};
    char *armorName[] = {"Helmet", "Chestplate", "Leggings", "Boots"};
    int type = rand() % 2;
    if (type == 0) {
    int randWeapon = rand() % 8;
    Weapon *weapon = malloc(sizeof(Weapon));
    strcpy(weapon->name, weaponName[randWeapon]);
    weapon->damage = rand() % 10;
    system("clear");
    printf("You looted %s: %d\n", weapon->name, weapon->damage);
    printf("Want to equip it? (y/n)\n");
    char resp = getchar();
    getchar();
    if (resp == 'y') 
        addWeapon(inventory, weapon, 1);
        else 
       addWeapon(inventory, weapon, 0);
    } else {
        int randArmor = rand() % 4;
        Armor *armor = malloc(sizeof(Armor));
        strcpy(armor->name, armorName[randArmor]);
        armor->defense = rand() % 10;
        system("clear");
        printf("You looted %s: %d\n", armor->name, armor->defense);
        printf("Want to equip it? (y/n)\n");
        char response = getchar();
        getchar();
        if (response == 'y')
            addArmor(inventory, armor, 1);
        else 
            addArmor(inventory, armor, 0);
    }
}