/*
** EPITECH PROJECT, 2020
** escape_buttons_states.c
** File description:
** deals with differents states of escape escape buttons
*/

#include "game.h"

void apply_escape_buttons_states(escape_t *esc_menu)
{
    esc_menu->b_opt->img->rect.left = (esc_menu->b_opt->state * 290);
    sfSprite_setTextureRect(esc_menu->b_opt->img->sprite, \
        esc_menu->b_opt->img->rect);
    esc_menu->b_quit->img->rect.left = (esc_menu->b_quit->state * 290);
    sfSprite_setTextureRect(esc_menu->b_quit->img->sprite, \
        esc_menu->b_quit->img->rect);
    esc_menu->b_save->img->rect.left = (esc_menu->b_save->state * 290);
    sfSprite_setTextureRect(esc_menu->b_save->img->sprite, \
        esc_menu->b_save->img->rect);
}

void check_escape_mouse_position(window_t *win, escape_t *esc_menu)
{
    int x = win->mouse.x;
    int y = win->mouse.y;

    if (sfFloatRect_contains(&esc_menu->b_opt->img->hitbox, x, y)) {
        esc_menu->b_opt->state = POINTED;
    } else
        esc_menu->b_opt->state = NORMAL;
    if (sfFloatRect_contains(&esc_menu->b_quit->img->hitbox, x, y)) {
        esc_menu->b_quit->state = POINTED;
    } else
        esc_menu->b_quit->state = NORMAL;
    do_nothing();
    if (sfFloatRect_contains(&esc_menu->b_save->img->hitbox, x, y)) {
        esc_menu->b_save->state = POINTED;
    } else
        esc_menu->b_save->state = NORMAL;
    apply_escape_buttons_states(esc_menu);
}