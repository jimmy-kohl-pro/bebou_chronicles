/*
** EPITECH PROJECT, 2020
** other_tp.c
** File description:
** other tp
*/

#include "game.h"
#include "map.h"
#include "my.h"

void tp_house(game_t *game)
{
    if (!my_strcmp(game->map->name, "village_map") &&
    sfFloatRect_contains(&(sfFloatRect){3700, 639, 300, 11},
    game->player->sprite->pos.x, game->player->sprite->pos.y)) {
        game->map = map_load("my_house");
        game->player->sprite->pos =
        (sfVector2f) {game->map->size.x / 2, game->map->size.y - 400};
    } if (!my_strcmp(game->map->name, "my_house")
    && game->player->sprite->pos.y > game->map->size.y - 300) {
        game->map = map_load("village_map");
        game->player->sprite->pos = (sfVector2f) {3700, 739};
    }
}