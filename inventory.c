#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int damage;
} Weapon;

typedef struct WeaponList {
    Weapon *weapon;
    struct WeaponList *next;
} WeaponList;

typedef struct {
    char name[20];
    int defense;
} Armor;

typedef struct ArmorList {
    Armor *armor;
    struct ArmorList *next;
} ArmorList;

typedef struct {
    WeaponList *weaponList;
    ArmorList *armorList;
} Inventory;

void printInventory(Inventory *inventory) {
    WeaponList *weaponList = inventory->weaponList;
    ArmorList *armorList = inventory->armorList;

    if (weaponList == NULL) {
        printf("No weapons dropped\n");
    } else {
        printf("Weapons:\n");
        while (weaponList != NULL) {
            printf("%s: %d\n", weaponList->weapon->name, weaponList->weapon->damage);
            weaponList = weaponList->next;
        }
    }

    if (armorList == NULL) {
        printf("No armor dropped\n");
    } else {
        printf("Armor:\n");
        while (armorList != NULL) {
            printf("%s: %d\n", armorList->armor->name, armorList->armor->defense);
            armorList = armorList->next;
        }
    }

    while (getchar() != '\n');
}

void printEquipped(Inventory *inventory) {
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

    while (getchar() != '\n');
}

void printWeaponList(Inventory *inventory) {
    WeaponList *weaponList = inventory->weaponList;
    int i = 0;
    while (weaponList != NULL) {
        printf("%d - %s: %d\n", i, weaponList->weapon->name, weaponList->weapon->damage);
        weaponList = weaponList->next;
        i++;
    }
}

void printArmorList(Inventory *inventory) {
    ArmorList *armorList = inventory->armorList;
    int i = 0;
    while (armorList != NULL) {
        printf("%d - %s: %d\n", i, armorList->armor->name, armorList->armor->defense);
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

void addWeapon(WeaponList **weaponList, Weapon *weapon, int equip) {
    WeaponList *newWeapon = malloc(sizeof(WeaponList));
    newWeapon->weapon = weapon;
    newWeapon->next = NULL;

    if (*weaponList == NULL) {
        *weaponList = newWeapon;
        return;
    }

    if (equip) {
        newWeapon->next = *weaponList;
        *weaponList = newWeapon;
        return;
    }

    WeaponList *current = *weaponList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newWeapon;
}

void addArmor(ArmorList **armorList, Armor *armor, int equip) {
    ArmorList *newArmor = malloc(sizeof(ArmorList));
    newArmor->armor = armor;
    newArmor->next = NULL;

    if (*armorList == NULL) {
        *armorList = newArmor;
        return;
    }

    if (equip) {
        newArmor->next = *armorList;
        *armorList = newArmor;
        return;
    }

    ArmorList *current = *armorList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newArmor;
}

void selectWeapon(Inventory *inventory) {
    WeaponList *weaponList = inventory->weaponList;
    printWeaponList(inventory);
    int size = getWeaponListSize(inventory);
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Invalid input, size = %d\n", size);
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
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Invalid input, size = %d\n", size);
        return;
    }

    for (int i = 0; i < index; i++) {
        armorList = armorList->next;
    }

    armorList->next = inventory->armorList;
    inventory->armorList = armorList;
    printEquipped(inventory);
}

void drop(Inventory *inventory) {
    char *weaponName[] = {"Sword", "Axe", "Bow", "Dagger", "Mace", "Spear", "Staff", "Wand"};
    char *armorName[] = {"Helmet", "Chestplate", "Leggings", "Boots"};
    srand((unsigned int)time(NULL));
    int type = rand() % 2;

    if (type == 0) {
        int randWeapon = rand() % 8;
        Weapon *weapon = malloc(sizeof(Weapon));
        strcpy(weapon->name, weaponName[randWeapon]);
        weapon->damage = 1 + rand() % 10;

        printf("You looted %s: %d\n", weapon->name, weapon->damage);
        printf("Want to equip it? (y/n)\n");

        char resp;
        scanf(" %c", &resp);

        if (resp == 'y') {
            addWeapon(&(inventory->weaponList), weapon, 1);
        } else {
            addWeapon(&(inventory->weaponList), weapon, 0);
        }
    } else {
        int randArmor = rand() % 4;
        Armor *armor = malloc(sizeof(Armor));
        strcpy(armor->name, armorName[randArmor]);
        armor->defense = 1 + rand() % 10;

        printf("You looted %s: %d\n", armor->name, armor->defense);
        printf("Want to equip it? (y/n)\n");

        char response;
        scanf(" %c", &response);

        if (response == 'y') {
            addArmor(&(inventory->armorList), armor, 1);
        } else {
            addArmor(&(inventory->armorList), armor, 0);
        }
    }
}
