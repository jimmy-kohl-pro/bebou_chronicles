/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** menu loop
*/

#include "menu_h.h"
#include "tools.h"

int menu(window_t *win)
{
    menu_t *menu_s = create_menu(win);
    int (*display_menu[])(window_t *win, menu_t *menu_s) = {main_menu,
        options_menu};

    if (!menu_s)
        return FAIL;
    display_intro(win, menu_s->intro);
    while (sfRenderWindow_isOpen(win->window)) {
        display_menu[menu_s->state](win, menu_s);
        sfRenderWindow_display(win->window);
        sfRenderWindow_clear(win->window, sfBlack);
    }
    return SUCCESS;
}