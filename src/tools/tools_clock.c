/*
** EPITECH PROJECT, 2020
** tools_clock.c
** File description:
** clock functions
*/

#include "basic.h"

void update_animclock(int intervl, sprite_t *elem, int max)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(elem->clock)) > intervl) {
        elem->rect.left += elem->rect.width;
        sfSprite_setTextureRect(elem->sprite, elem->rect);
        sfClock_restart(elem->clock);
    }
    if (elem->rect.left >= elem->rect.width * max)
        elem->rect.left = 0;
}

void update_animclock_column(int intervl, sprite_t *elem, int max, int column)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(elem->clock)) > intervl) {
        if (elem->rect.left >= elem->rect.width * max) {
            elem->rect.left = 0;
            elem->rect.top += elem->rect.height;
        } else
            elem->rect.left += elem->rect.width;
        sfSprite_setTextureRect(elem->sprite, elem->rect);
        sfClock_restart(elem->clock);
    }
    if (elem->rect.left >= elem->rect.width * max
    && elem->rect.top >= elem->rect.height * column) {
        elem->rect.left = 0;
        elem->rect.top = 0;
    }
}