/*
** EPITECH PROJECT, 2020
** map_sort.c
** File description:
** map sort
*/

#include "map.h"

void insert_sort_y(props_t *new, props_t **head)
{
    props_t *temp = (*head);
    props_t *save = NULL;

    while ((temp) && (new->pos.y + new->hitbox.top >
    temp->pos.y + temp->hitbox.top)) {
        save = temp;
        temp = temp->next;
    }
    if (!save) {
        new->next = (*head);
        (*head) = new;
        return;
    }
    save->next = new;
    new->next = temp;
}
