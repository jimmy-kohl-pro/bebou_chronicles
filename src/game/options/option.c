/*
** EPITECH PROJECT, 2020
** option.c
** File description:
** deals with option state
*/

#include "game.h"

int option_loop(window_t *win, game_t *game)
{
    pause_event(win, game);
    return SUCCESS;
}