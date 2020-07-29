/*
** EPITECH PROJECT, 2020
** option.c
** File description:
** deals with option state
*/

#include "game.h"
#include "tools.h"
#include "menu_h.h"

static void manage_background(window_t *win, escape_t *esc)
{
    update_animclock(100, esc->bg, 10);
    display_sprite_scl(win->window, esc->bg, fvec(
        (float)win->mode.width / (float)esc->bg->rect.width,
        (float)win->mode.height / (float)esc->bg->rect.height));
}

int escape_loop(window_t *win, game_t *game)
{
    static int (*esc_state[])(window_t *win, game_t *game) =
    {&escape_loop_menu, &escape_loop_save, NULL};

    check_menu_mouse_position(win, game->esc_menu->b_continue,
                            game->esc_menu->b_opt, game->esc_menu->b_quit);
    sfRenderWindow_setView(win->window,
    sfRenderWindow_getDefaultView(win->window));
    manage_background(win, game->esc_menu);
    esc_state[game->esc_menu->state](win, game);
    return SUCCESS;
}

static void display_esc(window_t *win, escape_t *esc)
{
    display_sprite(win->window, esc->b_continue->img);
    display_sprite(win->window, esc->b_opt->img);
    display_sprite(win->window, esc->b_quit->img);
    display_sprite(win->window, esc->b_save->img);
}

int escape_loop_menu(window_t *win, game_t *game)
{
    escape_event(win, game, game->esc_menu);
    display_esc(win, game->esc_menu);
    return SUCCESS;
}