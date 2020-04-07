/*
** EPITECH PROJECT, 2020
** pause_loop.c
** File description:
** game menu loop
*/

#include "game.h"

int pause_loop(window_t *win, game_t *game)
{
    pause_event(win, game);
    return SUCCESS;
}