/*
** EPITECH PROJECT, 2020
** options_menu_event.c
** File description:
** event of option menu
*/

#include "menu_h.h"

static void pressed_mouse(window_t *win, menu_t *menu)
{
    if (sfFloatRect_contains(&menu->button_opt_apply->img->hitbox,
                            win->mouse.x, win->mouse.y) && but_se(win)) {
        menu->state = MAIN;
        sfMusic_setVolume(win->button_se, win->volume);
        sfMusic_setVolume(menu->bg_sound, win->volume);
    } if (sfFloatRect_contains(&menu->button_volume_minus->img->hitbox,
                            win->mouse.x, win->mouse.y) && win->volume > 0
                            && but_se(win))
        win->volume = win->volume - 10;
    if (sfFloatRect_contains(&menu->button_volume_plus->img->hitbox,
                            win->mouse.x, win->mouse.y) && win->volume < 100
                            && but_se(win))
        win->volume = win->volume + 10;
    if (sfFloatRect_contains(&menu->button_opt_se->img->hitbox,
                            win->mouse.x, win->mouse.y) && but_se(win))
        update_se(win, menu);
}

void options_menu_event(window_t *win, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtMouseButtonPressed)
            pressed_mouse(win, menu);
    }
}