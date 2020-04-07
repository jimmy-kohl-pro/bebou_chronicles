/*
** EPITECH PROJECT, 2020
** cs_position.c
** File description:
** position check functions csfml
*/

#include "csfml_basic.h"

void update_position(elem_t *elem, sfVector2f new_pos)
{
    elem->pos = new_pos;
    elem->hitbox = sfSprite_getGlobalBounds(elem->sprite);
}