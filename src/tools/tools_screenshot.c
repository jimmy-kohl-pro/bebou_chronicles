/*
** EPITECH PROJECT, 2020
** tools_screenshot.c
** File description:
** tools for screenshots
*/

#include "basic.h"
#include "tools.h"
#include "my.h"
#include <stdlib.h>

void take_screenshot(window_t *win)
{
    sfTexture *texture = sfTexture_create(win->mode.width, win->mode.height);
    sfImage *img = sfImage_create(win->mode.width, win->mode.height);
    char *filename = my_strthreecat("screenshots/shot", int_str(rand() % 1000),
    ".png");

    sfTexture_updateFromRenderWindow(texture, win->window, 0, 0);
    img = sfTexture_copyToImage(texture);
    sfImage_saveToFile(img, filename);
    sfTexture_destroy(texture);
    sfImage_destroy(img);
    free(filename);
}

sprite_t *window_to_sprite(window_t *win)
{
    sprite_t *p_sprite = my_calloc(sizeof(sprite_t));

    p_sprite->sprite = sfSprite_create();
    p_sprite->texture = sfTexture_create(win->mode.width, win->mode.height);
    p_sprite->pos = ORIGIN;
    p_sprite->rect.left = 0;
    p_sprite->rect.top = 0;
    p_sprite->rect.width = win->mode.width;
    p_sprite->rect.height = win->mode.height;
    sfTexture_updateFromRenderWindow(p_sprite->texture, win->window, 0, 0);
    sfSprite_setTexture(p_sprite->sprite, p_sprite->texture, sfTrue);
    return p_sprite;
}