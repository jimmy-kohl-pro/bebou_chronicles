/*
** EPITECH PROJECT, 2019
** cs_spritearea.c
** File description:
** select area for sprite
*/

#include "csfml_basic.h"

sfIntRect int_area(int x, int y, int w, int h)
{
    sfIntRect area;

    area.left = x;
    area.top = y;
    area.width = w;
    area.height = h;
    return (area);
}

sfFloatRect f_rec(float x, float y, float w, float h)
{
    sfFloatRect area;

    area.left = x;
    area.top = y;
    area.width = w;
    area.height = h;
    return (area);
}