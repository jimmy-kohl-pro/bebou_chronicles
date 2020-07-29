/*
** EPITECH PROJECT, 2020
** create_pnj.c
** File description:
** my_rpg
*/

#include "game.h"
#include "my.h"
#include "tools.h"

static sprite_t *create_ronin_sprite(void)
{
    sprite_t *ronin_sprite = my_calloc(sizeof(sprite_t));

    ronin_sprite->clock = sfClock_create();
    ronin_sprite->texture = sfTexture_createFromFile(
                        "assets/pnj/ronin.png", NULL);
    ronin_sprite->sprite = sfSprite_create();
    ronin_sprite->pos = ORIGIN;
    ronin_sprite->rect.left = -2300;
    ronin_sprite->rect.top = -1800;
    ronin_sprite->rect.width = 2569;
    ronin_sprite->rect.height = 2256;
    ronin_sprite->hitbox =
        sfSprite_getGlobalBounds(ronin_sprite->sprite);
    if (!ronin_sprite->texture || !ronin_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(ronin_sprite->sprite, ronin_sprite->texture, sfTrue);
    sfSprite_setTextureRect(ronin_sprite->sprite, ronin_sprite->rect);
    sfSprite_setPosition(ronin_sprite->sprite, ronin_sprite->pos);
    return ronin_sprite;
}

static sprite_t *create_woman_sprite(void)
{
    sprite_t *woman_sprite = my_calloc(sizeof(sprite_t));

    woman_sprite->clock = sfClock_create();
    woman_sprite->texture = sfTexture_createFromFile(
                        "assets/pnj/woman.png", NULL);
    woman_sprite->sprite = sfSprite_create();
    woman_sprite->pos = ORIGIN;
    woman_sprite->rect.left = -500;
    woman_sprite->rect.top = -2300;
    woman_sprite->rect.width = 674;
    woman_sprite->rect.height = 2779;
    woman_sprite->hitbox =
        sfSprite_getGlobalBounds(woman_sprite->sprite);
    if (!woman_sprite->texture || !woman_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(woman_sprite->sprite, woman_sprite->texture, sfTrue);
    sfSprite_setTextureRect(woman_sprite->sprite, woman_sprite->rect);
    sfSprite_setPosition(woman_sprite->sprite, woman_sprite->pos);
    return woman_sprite;
}

static sprite_t *create_man_sprite(void)
{
    sprite_t *man_sprite = my_calloc(sizeof(sprite_t));

    man_sprite->clock = sfClock_create();
    man_sprite->texture = sfTexture_createFromFile(
                        "assets/pnj/man.png", NULL);
    man_sprite->sprite = sfSprite_create();
    man_sprite->pos = ORIGIN;
    man_sprite->rect.left = -4100;
    man_sprite->rect.top = -1700;
    man_sprite->rect.width = 4286;
    man_sprite->rect.height = 2170;
    man_sprite->hitbox =
        sfSprite_getGlobalBounds(man_sprite->sprite);
    if (!man_sprite->texture || !man_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(man_sprite->sprite, man_sprite->texture, sfTrue);
    sfSprite_setTextureRect(man_sprite->sprite, man_sprite->rect);
    sfSprite_setPosition(man_sprite->sprite, man_sprite->pos);
    return man_sprite;
}

static sprite_t *create_priestess_sprite(void)
{
    sprite_t *priestess_sprite = my_calloc(sizeof(sprite_t));

    priestess_sprite->clock = sfClock_create();
    priestess_sprite->texture = sfTexture_createFromFile(
                        "assets/pnj/priestess.png", NULL);
    priestess_sprite->sprite = sfSprite_create();
    priestess_sprite->pos = ORIGIN;
    priestess_sprite->rect.left = -1700;
    priestess_sprite->rect.top = -2400;
    priestess_sprite->rect.width = 1890;
    priestess_sprite->rect.height = 2867;
    priestess_sprite->hitbox =
        sfSprite_getGlobalBounds(priestess_sprite->sprite);
    if (!priestess_sprite->texture || !priestess_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(priestess_sprite->sprite,
        priestess_sprite->texture, sfTrue);
    sfSprite_setTextureRect(priestess_sprite->sprite, priestess_sprite->rect);
    sfSprite_setPosition(priestess_sprite->sprite, priestess_sprite->pos);
    return priestess_sprite;
}

pnj_t *create_pnj(void)
{
    pnj_t *pnj = my_calloc(sizeof(pnj_t));

    pnj->ronin = create_ronin_sprite();
    pnj->woman = create_woman_sprite();
    pnj->man = create_man_sprite();
    pnj->priestess = create_priestess_sprite();
    pnj->samurai = create_samurai_sprite();
    pnj->noble = create_noble_sprite();
    return pnj;
}