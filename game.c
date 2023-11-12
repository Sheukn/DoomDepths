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

void launch(){
    clear_console();
    Hero *hero = new_hero(1, 20, 10, 6, 1, "HERO");
    Spell **spell_list = new_spell_list(new_spell("Ember", 10, 8));
    unsigned int nbr_monster = 3;
    unsigned int nbr_dead_monster;
    Monster **monster_list = new_monster_list(nbr_monster, hero->level);
    unsigned int action = 0;
    unsigned int already = 0;
    unsigned int defending = 0;
    while(hero->health_points > 0){
        printf("\nHERO'S TURN\n");
        printf("\nHERO LVL %d\n", hero->level);
        printf("HP : %d/%d\n", hero->health_points, hero->max_health_points);
        printf("MP : %d/%d\n", hero->mana_points, hero->max_mana_points);
        show_combat_choices();
        action = 0;
        already = 0;
        defending = 0;
        while(action < 2){
            char input;
            scanf("%c", &input);
            switch (input) {
                case '1':
                    //ATTACK
                    clear_console();
                    printf("Monster lost %d health.\n", hero_attack(hero, monster_list[0]));
                    action++;
                    break;
                case '2':
                    //SPELLS
                    if(spell_list[0]->mana_cost > hero->mana_points){
                        printf("I need more mana...\n");
                        break;
                    }
                    clear_console();
                    printf("Monster lost %d health from a spell.\n", hero_spell(hero, spell_list[0], monster_list[0]));
                    action++;
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
                    printf("XP : %d/%d\n", hero->xp, hero->xp_to_up);
                    printf("\nHP : %d/%d\n", hero->health_points, hero->max_health_points);
                    printf("MP : %d/%d\n", hero->mana_points, hero->max_mana_points);
                    printf("ATK : %d\n", hero->attack);
                    printf("DEF : %d\n", hero->defense);

                default:
                    break;
            }
            if(action == 1 && already == 0){
                printf("\nHERO'S SECOND TURN\n");
                printf("\nHERO LVL %d\n", hero->level);
                printf("HP : %d/%d\n", hero->health_points, hero->max_health_points);
                printf("MP : %d/%d\n", hero->mana_points, hero->max_mana_points);
                show_combat_choices();
                already = 1;
            }
            if(hero->xp >= hero->xp_to_up){
                printf("Hero is now level %d !", level_up(hero));
            }
            nbr_dead_monster = check_monster_list(monster_list, nbr_monster);
            if(nbr_dead_monster != 0){
                nbr_monster -= nbr_dead_monster;
                monster_list = rearrange_monster_list(monster_list, nbr_monster);

            }
            if(nbr_monster == 0){
                break;
            }
            
        }
        concentrate(hero, 0.2);
        if(nbr_monster == 0){
            printf("\nALL MONSTERS ARE DEAD, BUT OTHERS ARE COMING !\n");
            printf("\nThe short rest gave you %d hp.\n",health_rest(hero));
            printf("The short rest gave you %d mp.\n",concentrate(hero, 0.6));
            nbr_monster = 3;
            monster_list = new_monster_list(nbr_monster, hero->level);
        }
        else{
            printf("\nMONSTERS' TURN.\n\n");
            for(int k = 0; k < nbr_monster; k++){
                printf("Monster %c dealt %d damage to the Hero.\n", 'A' + k, monster_attack(monster_list[k], hero, defending));
            }
        }
    }
}
