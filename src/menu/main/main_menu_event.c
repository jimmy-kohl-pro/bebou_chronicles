/*
** EPITECH PROJECT, 2020
** menu_event.c
** File description:
** event of the menu
*/

#include "menu_h.h"

static int pressed_mouse(window_t *win, menu_t *menu, sfEvent event)
{
    if (sfFloatRect_contains(&menu->button_exit->img->hitbox, win->mouse.x,
                            win->mouse.y))
        sfRenderWindow_close(win->window);
    if (sfFloatRect_contains(&menu->button_play->img->hitbox, win->mouse.x,
                            win->mouse.y))
        if (!launch_game(win))
            return FAIL;
    if (sfFloatRect_contains(&menu->button_options->img->hitbox, win->mouse.x,
                            win->mouse.y))
        menu->state = OPTIONS;
    return SUCCESS;
}

static int pressed_key(window_t *win, menu_t *menu, sfEvent event)
{
    return SUCCESS;
}

static int released_key(window_t *win, menu_t *menu, sfEvent event)
{
    return SUCCESS;
}

int main_menu_event(window_t *win, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            if (!pressed_key(win, menu, win->event))
                return FAIL;
        if (win->event.type == sfEvtKeyReleased)
            if (!released_key(win, menu, win->event))
                return FAIL;
        if (win->event.type == sfEvtMouseButtonPressed)
            if (!pressed_mouse(win, menu, win->event))
                return FAIL;
    }
    return SUCCESS;
}