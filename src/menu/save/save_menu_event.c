/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_menu_event
*/

#include "menu_h.h"
#include "save.h"

static int init_launch_game(window_t *win, menu_t *menu, int slot)
{
        sfMusic_stop(menu->bg_sound);
        menu->state = MAIN;
        if (!launch_game(win, slot))
            return FAIL;
        sfMusic_play(menu->bg_sound);
        return SUCCESS;
}

static void released_key(menu_t *menu, sfEvent event)
{
    if (event.key.code == sfKeyNum1) {
        delete_save(1);
        menu->saves = load_slot(menu->b_slot1, menu->b_slot2, menu->b_slot3);
    }
    if (event.key.code == sfKeyNum2) {
        delete_save(2);
        menu->saves = load_slot(menu->b_slot1, menu->b_slot2, menu->b_slot3);
    }
    if (event.key.code == sfKeyNum3) {
        delete_save(3);
        menu->saves = load_slot(menu->b_slot1, menu->b_slot2, menu->b_slot3);
    }
}

static int released_mouse(window_t *win, menu_t *menu)
{
    if (sfFloatRect_contains(&menu->b_slot1->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        if (!init_launch_game(win, menu, check_save_file(1)))
            return FAIL;
    if (sfFloatRect_contains(&menu->b_slot2->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        if (!init_launch_game(win, menu, check_save_file(2)))
            return FAIL;
    do_nothing();
    if (sfFloatRect_contains(&menu->b_slot3->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        if (!init_launch_game(win, menu, check_save_file(3)))
            return FAIL;
    if (sfFloatRect_contains(&menu->b_ret->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        menu->state = MAIN;
    return SUCCESS;
}

int menu_event_save(window_t *win, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyReleased)
            released_key(menu, win->event);
        if (win->event.type == sfEvtMouseButtonReleased)
            return released_mouse(win, menu) ? SUCCESS : FAIL;
    }
    return SUCCESS;
}