/*
** EPITECH PROJECT, 2020
** game_update.c
** File description:
** game update
*/

#include "game.h"
#include "map.h"

void update_game(window_t *win, game_t *game)
{
    manage_fps(win, win->fps);
    if (!game->fight->game_launched)
        check_fight(game);
    if (!game->dialogue->activated)
        check_player_move(game->player, game->map->size,
                    game->map->objects, game->time_elapsed);
    update_camera(game->camera, game->player, game->map->size);
    ninja_skill(game->player, game->fight);
}