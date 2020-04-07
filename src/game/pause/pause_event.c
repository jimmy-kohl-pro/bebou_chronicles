/*
** EPITECH PROJECT, 2020
** pause_event.c
** File description:
** game pause menu
*/

#include "game.h"

static int pressed_key(window_t *win, game_t *game, sfEvent event)
{
    return SUCCESS;
}

static int released_key(window_t *win, game_t *game, sfEvent event)
{
    return SUCCESS;
}

int pause_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            if (!pressed_key(win, game, win->event))
                return FAIL;
        if (win->event.type == sfEvtKeyReleased)
            if (!released_key(win, game, win->event))
                return FAIL;
    }
    return SUCCESS;
}