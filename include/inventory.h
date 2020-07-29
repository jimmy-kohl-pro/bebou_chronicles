/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "basic.h"

#ifndef INVENTORY_H_
#define INVENTORY_H_

typedef struct items_list
{
    int id;
    char *name;
    char *path;
    int nb;
    sprite_t *sprite;
    struct items_list *next;
    text_t stack;
} items_list_t;

//create the inventory linked list
items_list_t *make_inventory_list(void);
//add or remove an item in the player's inventory
int update_inventory(items_list_t *items_list, int id, int nb);
//set a nb of item in the inventory
int set_in_inventory(items_list_t *items_list, int id, int nb);
//return the number of items given as parameter
int how_many_item(items_list_t *items_list, int id);

#endif /* !INVENTORY_H_ */
