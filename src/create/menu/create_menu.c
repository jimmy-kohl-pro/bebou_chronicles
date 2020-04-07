/*
** EPITECH PROJECT, 2020
** create_menu.c
** File description:
** create menu
*/

#include "menu_h.h"
#include "my.h"
#include "tools.h"

menu_t *create_menu(window_t *win)
{
    menu_t *menu = my_calloc(sizeof(menu_t));

    menu->state = MAIN;
    menu->intro = create_intro(win);
    menu->bg = create_menu_background(win);
    menu->button_play = create_menu_play(win);
    menu->button_exit = create_menu_exit(win);
    menu->button_options = create_menu_options(win);
    menu->button_map = create_menu_map(win);
    if (!menu || !menu->intro || !menu->bg || !menu->button_play ||
    !menu->button_exit)
        return NULL;
    return (menu);
}