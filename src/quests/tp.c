/*
** EPITECH PROJECT, 2020
** rpg_bis
** File description:
** tp
*/

#include "quests.h"
#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "my.h"

void tp_temple_2(game_t *game)
{
    if (!my_strcmp(game->map->name, "road_1")
    && game->player->sprite->pos.x > 19600) {
        game->map = map_load("temple_map");
        game->player->sprite->pos = (sfVector2f) {240, 2458};
    } if (!my_strcmp(game->map->name, "temple_map")
    && game->player->sprite->pos.x < 100
    && game->player->sprite->pos.y > 1770) {
        game->map = map_load("road_1");
        game->player->sprite->pos = (sfVector2f) {19428, 732};
    }
}

void tp_temple_1(game_t *game)
{
    if (game->dialogue->ok_dial && !my_strcmp(game->map->name, "temple_map")
    && game->player->sprite->pos.x > 1850 && game->player->sprite->pos.x < 2800
    && game->player->sprite->pos.y < 100) {
        game->map = map_load("road_2");
        game->player->sprite->pos = (sfVector2f) {1787, 6720};
    } else if (!my_strcmp(game->map->name, "road_2")
    && game->player->sprite->pos.y > 20000) {
        game->map = map_load("temple_map");
        game->player->sprite->pos = (sfVector2f) {2200, 150};
    }
}

void tp_snow(game_t *game)
{
    if (!my_strcmp("village_map", game->map->name)
    && game->player->sprite->pos.y < 50) {
        game->map = map_load("north_map");
        game->player->sprite->pos.y =
        game->map->size.y - game->player->sprite->rect.height;
    } else if (!my_strcmp("north_map", game->map->name)
    && game->player->sprite->pos.y > game->map->size.y - 200) {
        game->map = map_load("village_map");
        game->player->sprite->pos.y = 100;
    }
}

void tp_village(game_t *game)
{
    if (!my_strcmp(game->map->name, "village_map") && game->dialogue->first_dial
    && game->player->sprite->pos.x > 5285 && game->player->sprite->pos.x < 5406
    && game->player->sprite->pos.y > 1770) {
        game->map = map_load("road_1");
        game->player->sprite->pos = (sfVector2f) {200, 800};
    } if (!my_strcmp(game->map->name, "road_1")
    && game->player->sprite->pos.x < 100) {
        game->map = map_load("village_map");
        game->player->sprite->pos = (sfVector2f) {5000, 2100};
    }
}

void tp(game_t *game)
{
    if (!my_strcmp(game->map->name, "road_2")
    && game->player->sprite->pos.y < 150) {
        game->map = map_load("palace_map");
        game->player->sprite->pos = (sfVector2f) {2709, 2733};
    }
    tp_village(game);
    tp_temple_1(game);
    tp_temple_2(game);
    tp_snow(game);
    tp_house(game);
}