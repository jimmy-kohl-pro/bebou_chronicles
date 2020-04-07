/*
** EPITECH PROJECT, 2020
** game_init.c
** File description:
** game initialization
*/

#include "game.h"

int launch_game(window_t *win)
{
    game_t *game = create_game(win);

    if (!game || !game_state(win, game))
        return FAIL;
}