/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_secondary
*/

#include "game.h"
#include "tools.h"
#include "my.h"
#include "quests.h"

sprite_t *create_cat_sprite(void)
{
    sprite_t *cat = my_calloc(sizeof(sprite_t));

    cat->clock = sfClock_create();
    cat->texture = sfTexture_createFromFile(
                        "assets/items/cat.png", NULL);
    cat->sprite = sfSprite_create();
    cat->pos = (sfVector2f) {5255, 2525};
    cat->rect.left = 0;
    cat->rect.top = 0;
    cat->rect.width = 2000;
    cat->rect.height = 500;
    if (!cat->texture || !cat->sprite)
        return FAIL;
    sfSprite_setTexture(cat->sprite,
        cat->texture, sfTrue);
    sfSprite_setTextureRect(cat->sprite,
        cat->rect);
    sfSprite_setPosition(cat->sprite,
        cat->pos);
    return cat;
}

sprite_t *create_baby_sprite(void)
{
    sprite_t *baby = my_calloc(sizeof(sprite_t));

    baby->clock = sfClock_create();
    baby->texture = sfTexture_createFromFile(
                        "assets/items/baby.png", NULL);
    baby->sprite = sfSprite_create();
    baby->pos = (sfVector2f) {50, 50};
    baby->rect.left = 0;
    baby->rect.top = 0;
    baby->rect.width = 141;
    baby->rect.height = 141;
    if (!baby->texture || !baby->sprite)
        return FAIL;
    sfSprite_setTexture(baby->sprite,
        baby->texture, sfTrue);
    sfSprite_setTextureRect(baby->sprite,
        baby->rect);
    sfSprite_setPosition(baby->sprite,
        baby->pos);
    return baby;
}

sprite_t *create_bandit_sprite(void)
{
    sprite_t *bandit = my_calloc(sizeof(sprite_t));

    bandit->clock = sfClock_create();
    bandit->texture = sfTexture_createFromFile(
                        "assets/image/bandit_sprite.png", NULL);
    bandit->sprite = sfSprite_create();
    bandit->pos = (sfVector2f) {9000, 100};
    bandit->rect.left = 0;
    bandit->rect.top = 0;
    bandit->rect.width = 74;
    bandit->rect.height = 96;
    if (!bandit->texture || !bandit->sprite)
        return FAIL;
    sfSprite_setTexture(bandit->sprite,
        bandit->texture, sfTrue);
    sfSprite_setTextureRect(bandit->sprite,
        bandit->rect);
    sfSprite_setPosition(bandit->sprite,
        bandit->pos);
    return bandit;
}