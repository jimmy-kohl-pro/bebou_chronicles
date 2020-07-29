/*
** EPITECH PROJECT, 2020
** create_build_button.c
** File description:
** create build button
*/

#include "build_map.h"
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

button_t *create_button_save_build(window_t *win)
{
    button_t *btn = my_calloc(sizeof(button_t));

    btn->img = my_calloc(sizeof(sprite_t));
    btn->img->texture = sfTexture_createFromFile(
                            "assets/image/menu_buttons.png", NULL);
    btn->img->sprite = sfSprite_create();
    btn->img->rect.left = 0;
    btn->img->rect.top = 360;
    btn->img->rect.width = 290;
    btn->img->rect.height = 120;
    btn->img->pos.x = (float)win->mode.width / 10;
    btn->img->pos.y = (float)win->mode.height / 1.9 + 123 * 2;
    if (!btn->img->texture || !btn->img->sprite)
        return NULL;
    set_button(btn->img);
    btn->img->hitbox = sfSprite_getGlobalBounds(btn->img->sprite);
    return btn;
}

button_t *create_button_build(window_t *win)
{
    button_t *btn = my_calloc(sizeof(button_t));

    btn->img = my_calloc(sizeof(sprite_t));
    btn->img->texture = sfTexture_createFromFile(
                            "assets/image/menu_buttons.png", NULL);
    btn->img->sprite = sfSprite_create();
    btn->img->rect.left = 0;
    btn->img->rect.top = 360;
    btn->img->rect.width = 290;
    btn->img->rect.height = 120;
    btn->img->pos.x = (float)win->mode.width / 10;
    btn->img->pos.y = (float)win->mode.height / 1.9 + 123 * 2;
    if (!btn->img->texture || !btn->img->sprite)
        return NULL;
    set_button(btn->img);
    btn->img->hitbox = sfSprite_getGlobalBounds(btn->img->sprite);
    return btn;
}