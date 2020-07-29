/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** menu loop
*/

#include "menu_h.h"
#include "tools.h"

static void stop_music(window_t *win, menu_t *menu)
{
    sfMusic_stop(menu->bg_sound);
    sfMusic_destroy(menu->bg_sound);
    sfMusic_destroy(win->button_se);
}

int menu(window_t *win)
{
    menu_t *menu_s = create_menu(win);
    int (*display_menu[])(window_t *win, menu_t *menu_s) = {main_menu,
        options_menu, menu_loop_save};

    if (!menu_s || !check_save_folder())
        return FAIL;
    display_intro(win, menu_s->intro);
    sfMusic_play(menu_s->bg_sound);
    while (sfRenderWindow_isOpen(win->window)) {
        get_elapsed_time(&menu_s->time_elapsed, menu_s->clock_loop);
        sfRenderWindow_setView(win->window,
        sfRenderWindow_getDefaultView(win->window));
        display_menu[menu_s->state](win, menu_s);
        display_cursor(win, menu_s->time_elapsed);
        sfRenderWindow_display(win->window);
        sfRenderWindow_clear(win->window, sfBlack);
    }
    stop_music(win, menu_s);
    return SUCCESS;
}