/*
** EPITECH PROJECT, 2020
** intro.c
** File description:
** intro functions
*/

#include "menu_h.h"
#include "tools.h"

void pressed_key_intro(window_t *win, intro_t *intro)
{
    if (win->event.key.code == sfKeySpace)
        intro->activated = (intro->activated + 1) % 2;
}

int check_event_intro(window_t *win, intro_t *intro)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key_intro(win, intro);
    }
    return SUCCESS;
}

void display_intro(window_t *win, intro_t *intro)
{
    sfClock_restart(intro->fade_clock);
    while (sfRenderWindow_isOpen(win->window) && intro->activated) {
        check_event_intro(win, intro);
        update_animclock_column(120, intro->bg, 3, 7);
        display_sprite_scl(win->window, intro->bg,
        fvec((float)win->mode.width / (float)intro->bg->rect.width,
        (float)win->mode.height / (float)intro->bg->rect.height));
        fade_black(win, intro);
        sfRenderWindow_display(win->window);
        sfRenderWindow_clear(win->window, sfBlack);
    }
}