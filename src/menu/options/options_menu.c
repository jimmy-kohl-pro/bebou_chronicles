/*
** EPITECH PROJECT, 2020
** option_menu.c
** File description:
** option menu
*/

#include "menu_h.h"
#include "tools.h"

static void options_menu_display(window_t *win, menu_t *menu)
{
    display_sprite_scl(win->window, menu->bg, fvec(
        (float)win->mode.width / (float)menu->bg->rect.width,
        (float)win->mode.height / (float)menu->bg->rect.height));
}

static void options_menu_update(window_t *win, menu_t *menu_s)
{
    win->mouse = sfMouse_getPositionRenderWindow(win->window);
    update_animclock_column(100, menu_s->bg, 2, 6);
}

int options_menu(window_t *win, menu_t *menu)
{
    options_menu_event(win, menu);
    options_menu_update(win, menu);
    options_menu_display(win, menu);
}