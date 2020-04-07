/*
** EPITECH PROJECT, 2020
** create_game.c
** File description:
** create game objects
*/

#include "game.h"
#include "my.h"

game_t *create_game(window_t *win)
{
    game_t *game = my_calloc(sizeof(game_t));

    game->state = IN_GAME;
    game->map = create_game_map(win);
    game->player = create_game_player(win);
    game->camera = create_game_camera(win);
    game->hud = create_game_hud(win);
    game->clock_loop = sfClock_create();
    return game;
}