/*
** EPITECH PROJECT, 2020
** create_hud.c
** File description:
** create game hud
*/

#include "game.h"
#include "my.h"

hud_t *create_game_hud(window_t *win)
{
    hud_t *hud = my_calloc(sizeof(hud_t));

    hud->view = sfView_createFromRect((sfFloatRect){0, 0, win->mode.width,
    win->mode.height});
    return hud;
}