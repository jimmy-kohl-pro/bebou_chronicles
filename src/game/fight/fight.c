/*
** EPITECH PROJECT, 2020
** fight.c
** File description:
** deals with fight state
*/

#include "game.h"

int fight_loop(window_t *win, game_t *game)
{
    pause_event(win, game);
    return SUCCESS;
}