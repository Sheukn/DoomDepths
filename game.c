#include <stdio.h>

#include <stdlib.h>

#include "game.h"

#include "hero.h"

#include "monster.h"

#include "fight.h"

#include "display.h"

#include "sprite.h"

#include "spell.h"

#include "inventory.h"

#include "map.h"

#include "deplacement.h"

void combat(Hero * hero, int nbr_monster, Monster ** monster_list, Spell ** spell_list) {
    clear_console();
    int nbr_dead_monster;
    while (hero -> alive == 1 &&nbr_monster != 0) {
        printf("\n");
        printf("MONSTERS' REMAINING %d\n", nbr_monster);
        show_monsters_life(monster_list, nbr_monster);
        printf("\nHERO'S TURN\n");
        printf("\nHERO LVL %d\n", hero -> level);
        printf("HP : %d/%d\n", hero -> health_points, hero -> max_health_points);
        printf("MP : %d/%d\n", hero -> mana_points, hero -> max_mana_points);
        show_combat_choices();
        unsigned int action = 0;
        unsigned int already = 0;
        unsigned int defending = 0;
        unsigned int choice = 0;
        while (action < 2) {
            char input;
            scanf("%c", &input);
            switch (input) {
                case '1':
                    choice = 0;
                    //ATTACK
                    while (choice == 0) {
                        clear_console();
                        printf("Which monster ?\n");
                        printf("Enter the letter or the number of the targeted monster.\n");
                        show_monsters_life(monster_list, nbr_monster);
                        char choose;
                        scanf("%c", &choose);
                        switch (choose) {
                            case '1':
                            case 'a':
                            case 'A':
                                printf("Monster lost %d health.\n", hero_attack(hero, monster_list[0]));
                                action++;
                                choice++;
                                break;
                            case '2':
                            case 'b':
                            case 'B':
                                if (nbr_monster > 1) {
                                    printf("Monster lost %d health.\n", hero_attack(hero, monster_list[1]));
                                    action++;
                                    choice++;
                                } else {
                                    printf("Monster B is not here...");
                                }
                                break;
                            case '3':
                            case 'c':
                            case 'C':
                                if (nbr_monster > 2) {
                                    printf("Monster lost %d health.\n", hero_attack(hero, monster_list[2]));
                                    action++;
                                    choice++;
                                } else {
                                    printf("Monster C is not here...");
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case '2':
                    //SPELLS
                    if (spell_list[0] -> mana_cost > hero -> mana_points) {
                        printf("I need more mana...\n");
                        break;
                    }
                    choice = 0;
                    while (choice == 0) {
                        clear_console();
                        printf("Which monster ?\n");
                        printf("Enter the letter or the number of the targeted monster.\n");
                        show_monsters_life(monster_list, nbr_monster);
                        char choose;
                        scanf("%c", &choose);
                        switch (choose) {
                            case '1':
                            case 'a':
                            case 'A':
                                printf("Monster lost %d health from a spell.\n", hero_spell(hero, spell_list[0], monster_list[0]));
                                action++;
                                choice++;
                                break;
                            case '2':
                            case 'b':
                            case 'B':
                                if (nbr_monster > 1) {
                                    printf("Monster lost %d health from a spell.\n", hero_spell(hero, spell_list[0], monster_list[1]));
                                    action++;
                                    choice++;
                                } else {
                                    printf("Monster B is not here...");
                                }
                                break;
                            case '3':
                            case 'c':
                            case 'C':
                                if (nbr_monster > 2) {
                                    printf("Monster lost %d health from a spell.\n", hero_spell(hero, spell_list[0], monster_list[2]));
                                    action++;
                                    choice++;
                                } else {
                                    printf("Monster C is not here...");
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case '3':
                    //CONCENTRATE
                    clear_console();
                    printf("Hero regained %d mana.\n", concentrate(hero, 0.4));
                    action++;
                    break;
                case '4':
                    //DEFEND
                    clear_console();
                    printf("Hero is defending.\n");
                    defending = 1;
                    action = 2;
                    break;
                case '5':
                    //SHOW STATS
                    printf("XP : %d/%d\n", hero -> xp, hero -> xp_to_up);
                    printf("\nHP : %d/%d\n", hero -> health_points, hero -> max_health_points);
                    printf("MP : %d/%d\n", hero -> mana_points, hero -> max_mana_points);
                    printf("ATK : %d\n", hero -> attack);
                    printf("DEF : %d\n", hero -> defense);

                default:
                    break;
            }
            if (action == 1 &&already == 0) {
                printf("\nHERO'S SECOND TURN\n");
                printf("\nHERO LVL %d\n", hero -> level);
                printf("HP : %d/%d\n", hero -> health_points, hero -> max_health_points);
                printf("MP : %d/%d\n", hero -> mana_points, hero -> max_mana_points);
                show_combat_choices();
                already = 1;
            }
            if (hero -> xp >= hero -> xp_to_up) {
                printf("Hero is now level %d !", level_up(hero));
            }
            nbr_dead_monster = check_monster_list(monster_list, nbr_monster);
            if (nbr_dead_monster != 0) {
                nbr_monster -= nbr_dead_monster;
                monster_list = rearrange_monster_list(monster_list, nbr_monster);

            }
            if (nbr_monster == 0) {
                break;
            }

        }
        concentrate(hero, 0.2);
        // if(nbr_monster == 0){
        //     printf("\nALL MONSTERS ARE DEAD, BUT OTHERS ARE COMING !\n");
        //     printf("\nThe short rest gave you %d hp.\n",health_rest(hero));
        //     printf("The short rest gave you %d mp.\n",concentrate(hero, 0.6));
        //     nbr_monster = 3;
        //     monster_list = new_monster_list(nbr_monster, hero->level);
        // }
        // else{

        printf("\nMONSTERS' TURN.\n\n");
        for (int k = 0; k < nbr_monster; k++) {
            printf("Monster %c dealt %d damage to the Hero.\n", 'A' + k, monster_attack(monster_list[k], hero, defending));
        }
    }
}


void launch() {

    Hero * hero = new_hero(1, 20, 10, 6, 1, "HERO");
    Spell ** spell_list = new_spell_list(new_spell("Ember", 10, 8));
    Inventory * inventory = malloc(sizeof(Inventory));
    inventory -> weaponList = NULL;
    inventory -> armorList = NULL;

    // INIT MAP AND HERO POSITION
    Position position;
    position.x = 0;
    position.y = 0;
    Cell ** map;
    
    map = malloc(sizeof(Cell) * 10);
    for (int i = 0; i < 10; i++) {
        map[i] = malloc(sizeof(Cell) * 9);

    }
    createMap(map);
    getEntry(map, &position.x, &position.y);

    while (hero -> alive == 1) {
        clear_console();
        printMap(map);
        printf("\nHERO LVL %d\n", hero -> level);
        printf("HP : %d/%d\n", hero -> health_points, hero -> max_health_points);
        printf("MP : %d/%d\n\n", hero -> mana_points, hero -> max_mana_points);
        printf("Show Inventory - 1\n");
        printf("Show Equipped - 2\n");
        printf("Change Weapon - 3\n");
        printf("Change Armor - 4\n");
        printf("Force Drop - 5\n");
        char input;
        scanf("%c", &input);
        switch (input) {
            case '1':
                printInventory(inventory);
                while (getchar() != '\n');
                break;
            case '2':
                printEquipped(inventory);
                while (getchar() != '\n');
                break;
            case '3':
                selectWeapon(inventory);
                while (getchar() != '\n');
                break;
            case '4':
                selectArmor(inventory);
                while (getchar() != '\n');
                break;
            case '5':
                drop(inventory);
                while (getchar() != '\n');
                break;
            default:
                moveHero(map, &position, input);
                break;
        }
    
    switch (map[position.x][position.y].event) {
        case 1: {
            printf("\nYour regenarated %d\n", health_rest(hero, 0.6));
            map[position.x][position.y].event = 0;
            char input;
            scanf("%c", &input);
            break;
        }

        case 2: {
            unsigned int nbr_monster = rand() % 3 + 1;
            unsigned int nbr_dead_monster = 0;
            Monster ** monster_list = new_monster_list(nbr_monster, hero -> level);
            combat(hero, nbr_monster, monster_list, spell_list);
            map[position.x][position.y].event = 0;
            clear_console();
            printMap(map);
            drop(inventory);
            while (getchar() != '\n');
            break;
        }
        case 3: {
            int random = rand() % 3;
            switch (random) {
                case 0: {
                    printf("You found a treasure!\n");
                    map[position.x][position.y].event = 0;
                    drop(inventory);
                    while (getchar() != '\n');
                    break;
                }
                case 1: {
                    unsigned int nbr_monster = rand() % 3 + 1;
                    unsigned int nbr_dead_monster = 0;
                    Monster ** monster_list = new_monster_list(nbr_monster, hero -> level);
                    combat(hero, nbr_monster, monster_list, spell_list);
                    map[position.x][position.y].event = 0;
                    clear_console();
                    printMap(map);
                    drop(inventory);
                    while (getchar() != '\n');
                    break;
                }
                case 3: {
                    printf("Your regenarated %d\n", health_rest(hero, 0.6));
                    map[position.x][position.y].event = 0;
                    char input;
                    scanf("%c", &input);
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case 4: {
            Monster ** boss_combat = new_boss_list(hero -> level);
            combat(hero, 3, boss_combat, spell_list);
            map[position.x][position.y].event = 0;
            clear_console();
            printMap(map);
            drop(inventory);
            while (getchar() != '\n');
            break;
            break;
        }

        case 5: {
            printf("You Cleared the floor!\n");
            map[position.x][position.y].event = 0;
            createMap(map);
            getEntry(map, &position.x, &position.y);
            char input;
            scanf("%c", &input);
            break;
        }
        default:
            break;
    }

    }
}