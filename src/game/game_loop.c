/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** game loop
*/

#include "game.h"
#include "map.h"
#include "my.h"
#include <stdio.h>

static void check_shop(game_t *game)
{
    if (game->player->sprite->pos.x > 14190
    && game->player->sprite->pos.x < 14405
    && game->player->sprite->pos.y < 408) {
        game->player->sprite->pos.y = game->player->sprite->pos.y + 100;
        game->state = IN_SHOP;
    }
}

int game_loop(window_t *win, game_t *game)
{
    game_event(win, game);
    update_game(win, game);
    display_game(win, game);
    display_hud(win, game);
    main_quest(win, game);
    secondary_quests(win, game);
    check_shop(game);
    return SUCCESS;
}