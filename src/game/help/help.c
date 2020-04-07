/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** deals with help state
*/

#include "game.h"

int help_loop(window_t *win, game_t *game)
{
    pause_event(win, game);
    return SUCCESS;
}