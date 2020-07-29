/*
** EPITECH PROJECT, 2020
** create_opt_button.c
** File description:
** create options buttons
*/

#include <stdlib.h>
#include "menu_h.h"
#include "tools.h"
#include "my.h"

static void set_button(sprite_t *sprite_button)
{
    sfSprite_setTexture(sprite_button->sprite, sprite_button->texture,
        sfTrue);
    sfSprite_setTextureRect(sprite_button->sprite, sprite_button->rect);
    sfSprite_setOrigin(sprite_button->sprite,
                        fvec((float)sprite_button->rect.width / 2,
                        (float)sprite_button->rect.height / 2));
    sfSprite_setPosition(sprite_button->sprite, sprite_button->pos);
}

button_t *create_volume_minus(window_t *win)
{
    button_t *volume = my_calloc(sizeof(button_t));

    volume->img = malloc(sizeof(sprite_t));
    volume->img->texture = sfTexture_createFromFile(
                                    "assets/image/button_volume_m.png", NULL);
    volume->img->sprite = sfSprite_create();
    volume->img->rect = (sfIntRect) {0, 0, 108, 107};
    volume->img->pos.x = (float) win->mode.width / 2;
    volume->img->pos.y = (float) win->mode.height / 2.2;
    if (!volume->img->texture || !volume->img->sprite)
        return NULL;
    set_button(volume->img);
    volume->img->hitbox = sfSprite_getGlobalBounds(volume->img->sprite);
    return volume;
}

button_t *create_volume_plus(window_t *win)
{
    button_t *volume = my_calloc(sizeof(button_t));

    volume->img = malloc(sizeof(sprite_t));
    volume->img->texture = sfTexture_createFromFile(
                                    "assets/image/button_volume_p.png", NULL);
    volume->img->sprite = sfSprite_create();
    volume->img->rect = (sfIntRect) {0, 0, 108, 107};
    volume->img->pos.x = (float) win->mode.width / 1.8;
    volume->img->pos.y = (float) win->mode.height / 2.2;
    if (!volume->img->texture || !volume->img->sprite)
        return NULL;
    set_button(volume->img);
    volume->img->hitbox = sfSprite_getGlobalBounds(volume->img->sprite);
    return volume;
}

button_t *create_apply_options(window_t *win)
{
    button_t *apply = my_calloc(sizeof(button_t));

    apply->img = malloc(sizeof(sprite_t));
    apply->img->texture = sfTexture_createFromFile(
                                    "assets/image/menu_buttons_2.png", NULL);
    apply->img->sprite = sfSprite_create();
    apply->img->rect = (sfIntRect) {0, 120, 290, 120};
    apply->img->pos.x = (float) win->mode.width / 1.25;
    apply->img->pos.y = (float) win->mode.height / 1.5;
    if (!apply->img->texture || !apply->img->sprite)
        return NULL;
    set_button(apply->img);
    apply->img->hitbox = sfSprite_getGlobalBounds(apply->img->sprite);
    return apply;
}

button_t *create_se_options(window_t *win)
{
    button_t *apply = my_calloc(sizeof(button_t));

    apply->img = malloc(sizeof(sprite_t));
    apply->img->texture = NULL;
    apply->img->sprite = sfSprite_create();
    apply->img->rect = (sfIntRect) {0, 0, 286, 100};
    apply->img->pos.x = (float) win->mode.width / 1.8;
    apply->img->pos.y = (float) win->mode.height / 1.75;
    if (!apply->img->sprite)
        return NULL;
    set_button(apply->img);
    apply->img->hitbox = sfSprite_getGlobalBounds(apply->img->sprite);
    return apply;
}