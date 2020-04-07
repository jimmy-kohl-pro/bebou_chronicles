/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** game loop
*/

#include "game.h"
#include <stdio.h>

int game_loop(window_t *win, game_t *game)
{
    game_event(win, game);
    update_game(win, game);
    display_game(win, game);
    display_hud(win, game);
    return SUCCESS;
}