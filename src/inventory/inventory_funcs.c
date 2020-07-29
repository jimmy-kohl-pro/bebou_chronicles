/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_funcs
*/

#include "my.h"
#include "inventory.h"

int how_many_item(items_list_t *items_list, int id)
{
    items_list_t *element = items_list;

    while (element && element->id != id) {
        element = element->next;
    }
    return element->nb;
}

int update_inventory(items_list_t *items_list, int id, int nb)
{
    items_list_t *element = items_list;
    int nb_of_items = 0;

    while (element) {
        if (element->nb)
            nb_of_items++;
        element = element->next;
    }
    element = items_list;
    while (element && element->id != id) {
        element = element->next;
    }
    if (!element || element->nb + nb < 0 || (nb > 0 && nb_of_items == 20
    && element->nb == 0))
        return 0;
    element->nb = element->nb + nb;
    return 1;
}

int set_in_inventory(items_list_t *items_list, int id, int nb)
{
    items_list_t *element = items_list;
    int nb_of_items = 0;

    while (element) {
        if (element->nb)
            nb_of_items++;
        element = element->next;
    }
    element = items_list;
    while (element && element->id != id) {
        element = element->next;
    }
    if (!element || nb < 0 || (nb > 0 && nb_of_items == 20
    && element->nb == 0))
        return 0;
    element->nb = nb;
    return 1;
}