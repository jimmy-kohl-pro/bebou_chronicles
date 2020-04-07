/*
** EPITECH PROJECT, 2020
** create_menu_bg.c
** File description:
** create menu background
*/

#include "menu_h.h"
#include "tools.h"
#include "my.h"

sprite_t *create_menu_background(window_t *win)
{
    sprite_t *bg = my_calloc(sizeof(sprite_t));

    bg->clock = sfClock_create();
    bg->texture = sfTexture_createFromFile("assets/image/menu_background.png",
                NULL);
    bg->sprite = sfSprite_create();
    bg->pos = ORIGIN;
    bg->rect.left = 0;
    bg->rect.top = 0;
    bg->rect.width = 500;
    bg->rect.height = 279;
    if (!bg->texture || !bg->sprite)
        return FAIL;
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    sfSprite_setTextureRect(bg->sprite, bg->rect);
    return (bg);
}