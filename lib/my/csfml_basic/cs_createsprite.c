/*
** EPITECH PROJECT, 2019
** creat_window.c
** File description:
** main of MyHunter, just start the game
*/

#include "csfml_basic.h"

void put_sprite(sfRenderWindow *window, sfSprite *sprite, sfVector2f pos)
{
    if (!sprite || !window) {
        my_printf("Impossible de mettre le sprite\n");
        return ;
    }
    sfSprite_setScale(sprite, fpos(1, 1));
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void put_sprite_scale(sfRenderWindow *window, sfSprite *sprite,
            sfVector2f pos, sfVector2f resize)
{
    if (!sprite || !window) {
        my_printf("Impossible de mettre le sprite\n");
        return;
    }
    sfSprite_setScale(sprite, resize);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}