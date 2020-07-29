/*
** EPITECH PROJECT, 2020
** menu_main.c
** File description:
** main menu
*/

#include "menu_h.h"
#include "tools.h"

static void display_main(window_t *win, menu_t *menu_s)
{
    display_sprite_scl(win->window, menu_s->bg, fvec(
        (float)win->mode.width / (float)menu_s->bg->rect.width,
        (float)win->mode.height / (float)menu_s->bg->rect.height));
    display_sprite_scl(win->window, menu_s->logo, fvec(0.4, 0.4));
    display_sprite(win->window, menu_s->button_play->img);
    display_sprite(win->window, menu_s->button_options->img);
    display_sprite(win->window, menu_s->button_exit->img);
    display_sprite(win->window, menu_s->button_map->img);
    display_sprite(win->window, menu_s->help->img);
    if (menu_s->help_page->activated == 1)
        display_sprite(win->window, menu_s->help_page->sprite);
}

static void update_main(window_t *win, menu_t *menu_s)
{
    win->mouse = sfMouse_getPositionRenderWindow(win->window);
    update_animclock_column(100, menu_s->bg, 2, 6);
}

int main_menu(window_t *win, menu_t *menu)
{
    check_menu_mouse_position(win, menu->button_play,
                        menu->button_options, menu->button_exit);
    if (!main_menu_event(win, menu))
        return FAIL;
    update_main(win, menu);
    display_main(win, menu);
    return SUCCESS;
}