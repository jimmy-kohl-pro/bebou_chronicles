/*
** EPITECH PROJECT, 2020
** load_var_game.c
** File description:
** load var game
*/

#include "game.h"
#include "my.h"
#include "map.h"

int load_quest(dialogue_t *dial, char **save)
{
    dial->first_dial = my_getnbr(get_var("first_dial", save));
    dial->prietress_dial = my_getnbr(get_var("prietress_dial", save));
    dial->ok_dial = my_getnbr(get_var("ok_dial", save));
    dial->emperor_dead = my_getnbr(get_var("emperor_dead", save));
    dial->cat_quest = my_getnbr(get_var("cat_quest", save));
    dial->cat_quest_launched = my_getnbr(get_var("cat_quest_launched", save));
    dial->bandit_quest_launched = my_getnbr(get_var("bandit_quest_launched", save));
    dial->bandit_killed = my_getnbr(get_var("bandit_killed", save));
    dial->bandit_quest = my_getnbr(get_var("bandit_quest", save));
    dial->baby_quest_launched = my_getnbr(get_var("baby_quest_launched", save));
    dial->baby_quest = my_getnbr(get_var("baby_quest", save));
    return SUCCESS;
}

int load_items(items_list_t **items_list, char **save)
{
    items_list_t *element = *items_list;

    while (element) {
        element->nb = my_getnbr(get_var(element->name, save));
        element = element->next;
    }
    return SUCCESS;
}