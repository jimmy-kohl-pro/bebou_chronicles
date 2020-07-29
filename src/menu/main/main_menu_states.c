/*
** EPITECH PROJECT, 2020
** main_menu_states.c
** File description:
** check and apply didfferent states for buttons
*/

#include "menu_h.h"

void apply_menu_buttons_states(button_t *b_play, button_t *b_opt,
                                                button_t *b_exit)
{
    b_play->img->rect.left = (b_play->state * 290);
    sfSprite_setTextureRect(b_play->img->sprite, b_play->img->rect);
    b_opt->img->rect.left = (b_opt->state * 290);
    sfSprite_setTextureRect(b_opt->img->sprite, b_opt->img->rect);
    b_exit->img->rect.left = (b_exit->state * 290);
    sfSprite_setTextureRect(b_exit->img->sprite, b_exit->img->rect);
}

void check_menu_mouse_position(window_t *win,
button_t *b_play, button_t *b_opt, button_t *b_exit)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&b_play->img->hitbox, x, y)) {
        b_play->state = POINTED;
    } else
        b_play->state = NORMAL;
    if (sfFloatRect_contains(&b_opt->img->hitbox, x, y)) {
        b_opt->state = POINTED;
    } else
        b_opt->state = NORMAL;
    if (sfFloatRect_contains(&b_exit->img->hitbox, x, y)) {
        b_exit->state = POINTED;
    } else
        b_exit->state = NORMAL;
    apply_menu_buttons_states(b_play, b_opt, b_exit);
}