/*
** EPITECH PROJECT, 2020
** game_init.c
** File description:
** game initialization
*/

#include "game.h"
#include "save.h"
#include "tools.h"

int launch_game(window_t *win, int slot)
{
    game_t *game = create_game(win);

    if (!game)
        return FAIL;
    if (slot != -1)
        load_save(game, slot);
    else {
        game->letter->activated = 1;
        game->state = CUSTOM;
    }
    if (!game_state(win, game))
        return FAIL;
    return SUCCESS;
}