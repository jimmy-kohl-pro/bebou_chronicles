/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** game loop
*/

#include "game.h"
#include <stdio.h>

static void get_elapsed_time(game_t *game)
{
    game->time_elapsed = sfTime_asMicroseconds(
                        sfClock_getElapsedTime(game->clock_loop));
    sfClock_restart(game->clock_loop);
    game->time_elapsed /= 10000;
}

int game_state(window_t *win, game_t *game)
{
    int (*choose_state[])(window_t *win, game_t *game) = {&pause_loop, \
        &option_loop, &help_loop, &game_loop, &fight_loop, NULL};

    while (sfRenderWindow_isOpen(win->window)) {
        get_elapsed_time(game);
        choose_state[game->state](win, game);
        sfRenderWindow_display(win->window);
        sfRenderWindow_clear(win->window, sfBlack);
    }
    return SUCCESS;
}