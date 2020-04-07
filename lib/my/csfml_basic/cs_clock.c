/*
** EPITECH PROJECT, 2020
** cs_clock.c
** File description:
** manage clock in csfml
*/

#include "csfml_basic.h"

int update_animclock(int intervl, elem_t *element, int max)
{
    int clock = fcomp(element, "CLOCK_ANIM");

    if (sfClock_getElapsedTime(element->comp[clock]->clock).microseconds
    > intervl) {
        element->i_rect.left += element->i_rect.width;
        sfSprite_setTextureRect(element->sprite, element->i_rect);
        sfClock_restart(element->comp[clock]->clock);
    }
    if (element->i_rect.left >= element->i_rect.width * max)
        element->i_rect.left = 0;
}

int update_animclock_column(int intervl, elem_t *element, int max, int column)
{
    int clock = fcomp(element, "CLOCK_ANIM");

    if (sfClock_getElapsedTime(element->comp[clock]->clock).microseconds
    > intervl) {
        if (element->i_rect.left >= element->i_rect.width * max) {
            element->i_rect.left = 0;
            element->i_rect.top += element->i_rect.height;
        } else
            element->i_rect.left += element->i_rect.width;
        sfSprite_setTextureRect(element->sprite, element->i_rect);
        sfClock_restart(element->comp[clock]->clock);
    }
    if (element->i_rect.left >= element->i_rect.width * max
    && element->i_rect.top >= element->i_rect.height * column) {
        element->i_rect.left = 0;
        element->i_rect.top = 0;
    }
}