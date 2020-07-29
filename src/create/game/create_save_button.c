/*
** EPITECH PROJECT, 2020
** create_save_button.c
** File description:
** create save button
*/

#include "game.h"
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

button_t *create_b_slot1(window_t *win)
{
    button_t *slot1 = my_calloc(sizeof(button_t));

    slot1->img = my_calloc(sizeof(sprite_t));
    slot1->img->texture = sfTexture_createFromFile(
                                    "assets/image/save_slot.png", NULL);
    slot1->img->sprite = sfSprite_create();
    slot1->img->rect.left = 0;
    slot1->img->rect.top = 0;
    slot1->img->rect.width = 570;
    slot1->img->rect.height = 250;
    slot1->img->pos.x = (float)win->mode.width / 2;
    slot1->img->pos.y = (float)win->mode.height / 2 - 260;
    if (!slot1->img->texture || !slot1->img->sprite)
        return NULL;
    set_button(slot1->img);
    slot1->img->hitbox = sfSprite_getGlobalBounds(slot1->img->sprite);
    return slot1;
}

button_t *create_b_slot2(window_t *win)
{
    button_t *slot2 = my_calloc(sizeof(button_t));

    slot2->img = my_calloc(sizeof(sprite_t));
    slot2->img->texture = sfTexture_createFromFile(
                            "assets/image/save_slot.png", NULL);
    slot2->img->sprite = sfSprite_create();
    slot2->img->rect.left = 0;
    slot2->img->rect.top = 0;
    slot2->img->rect.width = 570;
    slot2->img->rect.height = 250;
    slot2->img->pos.x = (float)win->mode.width / 2;
    slot2->img->pos.y = (float)win->mode.height / 2;
    if (!slot2->img->texture || !slot2->img->sprite)
        return NULL;
    set_button(slot2->img);
    slot2->img->hitbox = sfSprite_getGlobalBounds(slot2->img->sprite);
    return slot2;
}

button_t *create_b_slot3(window_t *win)
{
    button_t *slot3 = my_calloc(sizeof(button_t));

    slot3->img = my_calloc(sizeof(sprite_t));
    slot3->img->texture = sfTexture_createFromFile(
                            "assets/image/save_slot.png", NULL);
    slot3->img->sprite = sfSprite_create();
    slot3->img->rect.left = 0;
    slot3->img->rect.top = 0;
    slot3->img->rect.width = 570;
    slot3->img->rect.height = 250;
    slot3->img->pos.x = (float)win->mode.width / 2;
    slot3->img->pos.y = (float)win->mode.height / 2 + 260;
    if (!slot3->img->texture || !slot3->img->sprite)
        return NULL;
    set_button(slot3->img);
    slot3->img->hitbox = sfSprite_getGlobalBounds(slot3->img->sprite);
    return slot3;
}

button_t *create_b_ret(window_t *win)
{
    button_t *ret = my_calloc(sizeof(button_t));

    ret->img = my_calloc(sizeof(sprite_t));
    ret->img->texture = sfTexture_createFromFile(
                            "assets/image/menu_buttons_2.png", NULL);
    ret->img->sprite = sfSprite_create();
    ret->img->rect.left = 0;
    ret->img->rect.top = 0;
    ret->img->rect.width = 290;
    ret->img->rect.height = 120;
    ret->img->pos.x = (float)win->mode.width / 10;
    ret->img->pos.y = (float)win->mode.height / 1.9 + 123 * 2;
    if (!ret->img->texture || !ret->img->sprite)
        return NULL;
    set_button(ret->img);
    ret->img->hitbox = sfSprite_getGlobalBounds(ret->img->sprite);
    return ret;
}