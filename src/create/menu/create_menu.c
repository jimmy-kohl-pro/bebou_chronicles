/*
** EPITECH PROJECT, 2020
** create_menu.c
** File description:
** create menu
*/

#include "menu_h.h"
#include "my.h"
#include "tools.h"

static void create_sound(window_t *win, menu_t *menu)
{
    menu->bg_sound =
        sfMusic_createFromFile("assets/sound/garden_ambient.ogg");
    sfMusic_setVolume(win->button_se, win->volume);
    sfMusic_setVolume(menu->bg_sound, win->volume);
    sfMusic_setLoop(menu->bg_sound, sfTrue);
}

static void create_button(window_t *win, menu_t *menu)
{
    menu->help = create_menu_help(win);
    menu->button_play = create_menu_play(win);
    menu->button_exit = create_menu_exit(win);
    menu->button_options = create_menu_options(win);
    menu->button_map = create_menu_map(win);
    menu->button_volume_minus = create_volume_minus(win);
    menu->button_volume_plus = create_volume_plus(win);
    menu->button_opt_apply = create_apply_options(win);
    menu->button_opt_se = create_se_options(win);
    menu->b_slot1 = create_b_slot1(win);
    menu->b_slot2 = create_b_slot2(win);
    menu->b_slot3 = create_b_slot3(win);
    menu->b_ret = create_b_ret(win);
}

menu_t *create_menu(window_t *win)
{
    menu_t *menu = my_calloc(sizeof(menu_t));

    menu->state = MAIN;
    menu->intro = create_intro(win);
    menu->bg = create_menu_background();
    menu->logo = create_logo();
    create_button(win, menu);
    menu->help_page = create_help();
    menu->volume = create_volume_text(win);
    menu->volume_name = create_volume_name(win);
    menu->se_name = create_se_name(win);
    menu->se_text = create_se_text(win);
    menu->clock_loop = sfClock_create();
    create_sound(win, menu);
    if (!menu || !menu->intro || !menu->bg || !menu->button_play ||
    !menu->button_exit)
        return NULL;
    return (menu);
}