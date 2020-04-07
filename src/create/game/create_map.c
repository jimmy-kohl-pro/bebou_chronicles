/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** create map
*/

#include "game.h"
#include "my.h"
#include "tools.h"

sprite_t *create_sprite_map(window_t *win)
{
    sprite_t *map = my_calloc(sizeof(sprite_t));

    map->clock = sfClock_create();
    map->texture = sfTexture_createFromFile("assets/image/map.png",
                NULL);
    map->sprite = sfSprite_create();
    map->pos = ORIGIN;
    map->rect.left = 0;
    map->rect.top = 0;
    map->rect.width = 2000;
    map->rect.height = 1503;
    if (!map->texture || !map->sprite)
        return FAIL;
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setTextureRect(map->sprite, map->rect);
    return map;
}

map_t *create_game_map(window_t *win)
{
    map_t *map = my_calloc(sizeof(map_t));

    map->sprite = create_sprite_map(win);
    return map;
}