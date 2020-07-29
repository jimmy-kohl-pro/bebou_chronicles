/*
** EPITECH PROJECT, 2020
** create_custom_bg.c
** File description:
** blabla
*/

#include "menu_h.h"
#include "tools.h"
#include "my.h"

sprite_t *create_custom_bg(void)
{
    sprite_t *custom_bg = my_calloc(sizeof(sprite_t));

    custom_bg->clock = sfClock_create();
    custom_bg->texture = \
        sfTexture_createFromFile("assets/image/custom_bg.png", NULL);
    custom_bg->sprite = sfSprite_create();
    custom_bg->pos = ORIGIN;
    custom_bg->rect.left = 0;
    custom_bg->rect.top = 0;
    custom_bg->rect.width = 1280;
    custom_bg->rect.height = 720;
    if (!custom_bg->texture || !custom_bg->sprite)
        return FAIL;
    sfSprite_setTexture(custom_bg->sprite, custom_bg->texture, sfTrue);
    sfSprite_setTextureRect(custom_bg->sprite, custom_bg->rect);
    return (custom_bg);
}

sprite_t *create_chara_bg(void)
{
    sprite_t *chara_bg = my_calloc(sizeof(sprite_t));

    chara_bg->clock = sfClock_create();
    chara_bg->texture = sfTexture_createFromFile("assets/image/back_custom.png",
                NULL);
    chara_bg->sprite = sfSprite_create();
    chara_bg->pos.x = 710;
    chara_bg->pos.y = 265;
    chara_bg->rect.left = 0;
    chara_bg->rect.top = 0;
    chara_bg->rect.width = 412;
    chara_bg->rect.height = 508;
    if (!chara_bg->texture || !chara_bg->sprite)
        return FAIL;
    sfSprite_setTexture(chara_bg->sprite, chara_bg->texture, sfTrue);
    sfSprite_setTextureRect(chara_bg->sprite, chara_bg->rect);
    return (chara_bg);
}