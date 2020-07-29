/*
** EPITECH PROJECT, 2020
** select_list.c
** File description:
** select list
*/

#include "particle_engine.h"

sfSprite *select_sprite(sprite_link_t *sprite_list, int sprite_nbr)
{
    register int i = 0;
    sprite_link_t *save_list = sprite_list;
    sfSprite *sprite = NULL;

    for (i = 0; i < sprite_nbr - 1; i++)
        sprite_list = sprite_list->next;
    sprite = sprite_list->sprite;
    sprite_list = save_list;
    return sprite;
}

sfColor select_color(color_link_t *color_list, int color_nbr)
{
    register int i = 0;
    color_link_t *save_list = color_list;
    sfColor color;

    for (i = 0; i < color_nbr - 1; i++)
        color_list = color_list->next;
    color = color_list->color;
    color_list = save_list;
    return color;
}