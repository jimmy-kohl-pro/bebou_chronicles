/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_menu_loop
*/

#include "menu_h.h"
#include "tools.h"

static void display_menu_save(window_t *win, menu_t *menu, file_save_t *saves)
{
    display_sprite_scl(win->window, menu->bg, fvec(
        (float)win->mode.width / (float)menu->bg->rect.width,
        (float)win->mode.height / (float)menu->bg->rect.height));
    display_sprite(win->window, menu->b_slot1->img);
    display_sprite(win->window, menu->b_slot2->img);
    display_sprite(win->window, menu->b_slot3->img);
    display_sprite(win->window, menu->b_ret->img);
    if (saves->slot1 && saves->slot1->empty)
        disp_text(win->window, saves->slot1->empty);
    if (saves->slot2 && saves->slot2->empty)
        disp_text(win->window, saves->slot2->empty);
    if (saves->slot3 && saves->slot3->empty)
        disp_text(win->window, saves->slot3->empty);
}

static void update_save(window_t *win, menu_t *menu_s)
{
    win->mouse = sfMouse_getPositionRenderWindow(win->window);
    update_animclock_column(100, menu_s->bg, 2, 6);
}

void check_save_mouse_position_and_apply(window_t *win, menu_t *menu)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&menu->b_ret->img->hitbox, x, y)) {
        menu->b_ret->state = POINTED;
    } else
        menu->b_ret->state = NORMAL;
    menu->b_ret->img->rect.left = \
        (menu->b_ret->state * 290);
    sfSprite_setTextureRect(menu->b_ret->img->sprite, \
        menu->b_ret->img->rect);
}

int menu_loop_save(window_t *win, menu_t *menu)
{
    check_save_mouse_position_and_apply(win, menu);
    menu_event_save(win, menu);
    update_save(win, menu);
    display_menu_save(win, menu, menu->saves);
    return SUCCESS;
}