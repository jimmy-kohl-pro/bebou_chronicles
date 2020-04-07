/*
** EPITECH PROJECT, 2020
** display_hud.c
** File description:
** display hud
*/

#include "game.h"

void display_hud(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    manage_fps(win, win->fps);
}