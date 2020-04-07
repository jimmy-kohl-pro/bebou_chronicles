/*
** EPITECH PROJECT, 2020
** game_display.c
** File description:
** game display
*/

#include "game.h"
#include "tools.h"

void display_game(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->camera->view);
    display_sprite(win->window, game->map->sprite);
    display_sprite(win->window, game->player->sprite);
}