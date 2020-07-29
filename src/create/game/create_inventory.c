/*
** EPITECH PROJECT, 2020
** create_inventory.c
** File description:
** create inventory
*/

#include "game.h"
#include "tools.h"
#include "my.h"

text_t *create_text_struct_fight(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 40;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = NULL;
    name->pos = (sfVector2f) {win->mode.width / 2,
    win->mode.height / 2.1};
    name->color = sfWhite;
    return (name);
}

text_t *create_text_struct(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 50;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = NULL;
    name->pos = (sfVector2f) {win->mode.width / 2,
    win->mode.height / 2.1};
    name->color = sfWhite;
    return (name);
}

sprite_t *create_inventory(window_t *win)
{
    sprite_t *inventory = my_calloc(sizeof(sprite_t));

    inventory->clock = sfClock_create();
    inventory->texture = sfTexture_createFromFile(
                            "assets/image/inventory.png", NULL);
    inventory->sprite = sfSprite_create();
    inventory->rect.left = 0;
    inventory->rect.top = 0;
    inventory->rect.width = 960;
    inventory->rect.height = 783;
    inventory->pos.x = (float)win->mode.width / 2;
    inventory->pos.y = (float)win->mode.height / 2;
    if (!inventory->texture || !inventory->sprite)
        return NULL;
    inventory->hitbox = sfSprite_getGlobalBounds(inventory->sprite);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setTextureRect(inventory->sprite, inventory->rect);
    sfSprite_setPosition(inventory->sprite, inventory->pos);
    return inventory;
}

sprite_t *create_stats_bg(window_t *win)
{
    sprite_t *inventory = my_calloc(sizeof(sprite_t));

    inventory->clock = sfClock_create();
    inventory->texture = sfTexture_createFromFile(
                            "assets/image/profile.png", NULL);
    inventory->sprite = sfSprite_create();
    inventory->rect.left = 0;
    inventory->rect.top = 0;
    inventory->rect.width = 453;
    inventory->rect.height = 777;
    inventory->pos.x = (float)win->mode.width / 2;
    inventory->pos.y = (float)win->mode.height / 2;
    if (!inventory->texture || !inventory->sprite)
        return NULL;
    inventory->hitbox = sfSprite_getGlobalBounds(inventory->sprite);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setTextureRect(inventory->sprite, inventory->rect);
    sfSprite_setPosition(inventory->sprite, inventory->pos);
    return inventory;
}