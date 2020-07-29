/*
** EPITECH PROJECT, 2020
** mouse_events.c
** File description:
** contains functions that deals with mouse events
*/

#include "game.h"
#include "menu_h.h"
#include "tools.h"

static void check_custom_mouse_position_2(window_t *win, custom_t *custom)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&custom->c_buttons->b_pants->img->hitbox, x, y))
        custom->c_buttons->b_pants->state = POINTED;
    else
        custom->c_buttons->b_pants->state = NORMAL;
    if (sfFloatRect_contains(&custom->c_buttons->b_shoes->img->hitbox, x, y))
        custom->c_buttons->b_shoes->state = POINTED;
    else
        custom->c_buttons->b_shoes->state = NORMAL;
}

int check_custom_mouse_position_1(window_t *win, custom_t *custom)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&custom->c_buttons->b_head->img->hitbox, x, y))
        custom->c_buttons->b_head->state = POINTED;
    else
        custom->c_buttons->b_head->state = NORMAL;
    if (sfFloatRect_contains(&custom->c_buttons->b_face->img->hitbox, x, y))
        custom->c_buttons->b_face->state = POINTED;
    else
        custom->c_buttons->b_face->state = NORMAL;
    if (sfFloatRect_contains(&custom->c_buttons->b_shirt->img->hitbox, x, y))
        custom->c_buttons->b_shirt->state = POINTED;
    else
        custom->c_buttons->b_shirt->state = NORMAL;
    check_custom_mouse_position_2(win, custom);
    return SUCCESS;
}

static void mouse_events_cursor(custom_t *custom, int x, int y)
{
    int check = 0;
    int (*player_modifier_mouse[])(custom_t *custom, int check) = \
        {&custom_command_mouse_hair, &custom_command_mouse_face, \
        &custom_command_mouse_shirt, &custom_command_mouse_pants, \
        &custom_command_mouse_shoes, NULL};

    if (sfFloatRect_contains(&custom->c_buttons->c_left->img->hitbox, x, y))
        check = 1;
    if (sfFloatRect_contains(&custom->c_buttons->c_right->img->hitbox, x, y))
        check = 2;
    player_modifier_mouse[custom->which_part](custom, check);
    update_buttons(custom, custom->which_part);
}

void mouse_events(custom_t *custom, window_t *win)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&custom->c_buttons->b_head->img->hitbox, x, y))
        custom->which_part = 0;
    if (sfFloatRect_contains(&custom->c_buttons->b_face->img->hitbox, x, y))
        custom->which_part = 1;
    if (sfFloatRect_contains(&custom->c_buttons->b_shirt->img->hitbox, x, y))
        custom->which_part = 2;
    if (sfFloatRect_contains(&custom->c_buttons->b_pants->img->hitbox, x, y))
        custom->which_part = 3;
    if (sfFloatRect_contains(&custom->c_buttons->b_shoes->img->hitbox, x, y))
        custom->which_part = 4;
    mouse_events_cursor(custom, x, y);
}