/*
** EPITECH PROJECT, 2020
** menu_event.c
** File description:
** event of the menu
*/

#include "menu_h.h"
#include "tools.h"

static int pressed_mouse(window_t *win, menu_t *menu)
{
    if (sfFloatRect_contains(&menu->button_exit->img->hitbox, win->mouse.x,
                            win->mouse.y) && but_se(win))
        sfRenderWindow_close(win->window);
    if (sfFloatRect_contains(&menu->button_play->img->hitbox, win->mouse.x,
                            win->mouse.y) && but_se(win)) {
        menu->button_play->state = CLICKED;
        menu->state = SAVE;
        menu->saves = load_slot(menu->b_slot1, menu->b_slot2, menu->b_slot3);
    }
    if (sfFloatRect_contains(&menu->button_options->img->hitbox, win->mouse.x,
                            win->mouse.y) && but_se(win)) {
        menu->button_options->state = CLICKED;
        menu->state = OPTIONS;
        }
    if (sfFloatRect_contains(&menu->help->img->hitbox, win->mouse.x,
    win->mouse.y))
        menu->help_page->activated = 1;
    apply_menu_buttons_states(menu->button_play,
    menu->button_options, menu->button_exit);
    return SUCCESS;
}

static int released_mouse(window_t *win, menu_t *menu)
{
    if (!sfFloatRect_contains(&menu->help->img->hitbox, win->mouse.x,
    win->mouse.y))
        menu->help_page->activated = 0;
    return SUCCESS;
}

int main_menu_event(window_t *win, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtMouseButtonPressed)
            return pressed_mouse(win, menu) ? SUCCESS : FAIL;
        if (win->event.type == sfEvtMouseButtonReleased)
            return released_mouse(win, menu) ? SUCCESS : FAIL;
    }
    return SUCCESS;
}