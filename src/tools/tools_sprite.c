/*
** EPITECH PROJECT, 2020
** tools_sprite.c
** File description:
** tools sprite
*/

#include "basic.h"

void display_sprite_scl(sfRenderWindow *win, sprite_t *sprite,
sfVector2f scale)
{
    sfSprite_setScale(sprite->sprite, scale);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfRenderWindow_drawSprite(win, sprite->sprite, NULL);
}

void display_sprite(sfRenderWindow *win, sprite_t *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfRenderWindow_drawSprite(win, sprite->sprite, NULL);
}