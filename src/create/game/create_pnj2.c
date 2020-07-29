/*
** EPITECH PROJECT, 2020
** create_pnj2.c
** File description:
** my_rpg
*/

#include "game.h"
#include "my.h"
#include "tools.h"

sprite_t *create_samurai_sprite(void)
{
    sprite_t *samu_sprite = my_calloc(sizeof(sprite_t));

    samu_sprite->clock = sfClock_create();
    samu_sprite->texture = sfTexture_createFromFile(
                        "assets/pnj/samurai.png", NULL);
    samu_sprite->sprite = sfSprite_create();
    samu_sprite->pos = ORIGIN;
    samu_sprite->rect.left = -2500;
    samu_sprite->rect.top = -1000;
    samu_sprite->rect.width = 2735;
    samu_sprite->rect.height = 1491;
    samu_sprite->hitbox =
        sfSprite_getGlobalBounds(samu_sprite->sprite);
    if (!samu_sprite->texture || !samu_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(samu_sprite->sprite, samu_sprite->texture, sfTrue);
    sfSprite_setTextureRect(samu_sprite->sprite, samu_sprite->rect);
    sfSprite_setPosition(samu_sprite->sprite, samu_sprite->pos);
    return samu_sprite;
}

sprite_t *create_noble_sprite(void)
{
    sprite_t *noble_sprite = my_calloc(sizeof(sprite_t));

    noble_sprite->clock = sfClock_create();
    noble_sprite->texture = sfTexture_createFromFile(
                        "assets/pnj/noble.png", NULL);
    noble_sprite->sprite = sfSprite_create();
    noble_sprite->pos = ORIGIN;
    noble_sprite->rect.left = -2900;
    noble_sprite->rect.top = -1000;
    noble_sprite->rect.width = 3067;
    noble_sprite->rect.height = 1476;
    noble_sprite->hitbox =
        sfSprite_getGlobalBounds(noble_sprite->sprite);
    if (!noble_sprite->texture || !noble_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(noble_sprite->sprite, noble_sprite->texture, sfTrue);
    sfSprite_setTextureRect(noble_sprite->sprite, noble_sprite->rect);
    sfSprite_setPosition(noble_sprite->sprite, noble_sprite->pos);
    return noble_sprite;
}