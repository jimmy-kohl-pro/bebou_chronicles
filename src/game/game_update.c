/*
** EPITECH PROJECT, 2020
** game_update.c
** File description:
** game update
*/

#include "game.h"

void update_game(window_t *win, game_t *game)
{
    manage_fps(win, win->fps);
    check_player_move(game->player, game->time_elapsed);
    update_camera(game->camera, game->player, game->map->sprite);
}