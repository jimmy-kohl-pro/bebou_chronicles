/*
** EPITECH PROJECT, 2020
** options_menu_event.c
** File description:
** event of option menu
*/

#include "menu_h.h"

static void pressed_mouse(window_t *win, menu_t *menu, sfEvent event)
{
    ;
}

static void pressed_key(window_t *win, menu_t *menu, sfEvent event)
{
    ;
}

static void released_key(window_t *win, menu_t *menu, sfEvent event)
{
    ;
}

void options_menu_event(window_t *win, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(win, menu, win->event);
        if (win->event.type == sfEvtKeyReleased)
            released_key(win, menu, win->event);
        if (win->event.type == sfEvtMouseButtonPressed)
            pressed_mouse(win, menu, win->event);
    }
}