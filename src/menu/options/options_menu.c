/*
** EPITECH PROJECT, 2020
** option_menu.c
** File description:
** option menu
*/

#include "menu_h.h"
#include "tools.h"
#include "my.h"

static void options_menu_display(window_t *win, menu_t *menu)
{
    display_sprite_scl(win->window, menu->bg, fvec(
        (float)win->mode.width / (float)menu->bg->rect.width,
        (float)win->mode.height / (float)menu->bg->rect.height));
    display_sprite(win->window, menu->button_volume_minus->img);
    display_sprite(win->window, menu->button_volume_plus->img);
    display_sprite(win->window, menu->button_opt_apply->img);
    menu->volume->str = int_str(win->volume);
    if (win->volume == 0)
        menu->volume->str = "0";
    disp_text(win->window, menu->volume);
    disp_text(win->window, menu->volume_name);
    disp_text(win->window, menu->se_text);
    disp_text(win->window, menu->se_name);
}

static void options_menu_update(window_t *win, menu_t *menu_s)
{
    win->mouse = sfMouse_getPositionRenderWindow(win->window);
    update_animclock_column(100, menu_s->bg, 2, 6);
}

void check_options_mouse_position_and_apply(window_t *win, menu_t *menu)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&menu->button_opt_apply->img->hitbox, x, y)) {
        menu->button_opt_apply->state = POINTED;
    } else
        menu->button_opt_apply->state = NORMAL;
    menu->button_opt_apply->img->rect.left = \
        (menu->button_opt_apply->state * 290);
    sfSprite_setTextureRect(menu->button_opt_apply->img->sprite, \
        menu->button_opt_apply->img->rect);
}

int options_menu(window_t *win, menu_t *menu)
{
    check_options_mouse_position_and_apply(win, menu);
    options_menu_event(win, menu);
    options_menu_update(win, menu);
    options_menu_display(win, menu);
    return SUCCESS;
}