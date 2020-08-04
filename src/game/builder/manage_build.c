/*
** EPITECH PROJECT, 2020
** manage_build.c
** File description:
** manage_build.c
*/

#include "build_map.h"
#include "tools.h"

int how_many_objects(objects_list_t *items_list, int id)
{
    objects_list_t *element = items_list;

    while (element && element->id != id) {
        element = element->next;
    }
    return element->nb;
}

int update_catalog(objects_list_t *items_list, int id, int nb)
{
    objects_list_t *element = items_list;
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

int set_in_catalog(objects_list_t *items_list, int id, int nb)
{
    objects_list_t *element = items_list;
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

objects_to_del_t find_click_objects(sfVector2f mouse, objects_t *objects)
{
    objects_t *temp_objects = objects;
    sfFloatRect rect;
    objects_to_del_t to_del;

    to_del.pos = (sfVector2f){0, 0};
    while (temp_objects) {
        rect = sfSprite_getGlobalBounds(temp_objects->sprite);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
            to_del.name = temp_objects->name;
            to_del.pos = temp_objects->pos;
            return to_del;
        }
        temp_objects = temp_objects->next;
    }
    return ((objects_to_del_t){"null", ORIGIN});
}