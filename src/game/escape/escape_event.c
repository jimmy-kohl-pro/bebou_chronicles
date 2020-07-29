/*
** EPITECH PROJECT, 2020
** escape_event.c
** File description:
** escape event
*/

#include "game.h"
#include "my.h"

static void pressed_key(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        game->state = IN_GAME;
        game->player->direction = 0;
    }
}

static void released_mouse(window_t *win, game_t *game, escape_t *esc)
{
    if (!game->end && sfFloatRect_contains(&esc->b_continue->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win)) {
        game->state = IN_GAME;
        game->player->direction = 0;
    }
    if (sfFloatRect_contains(&esc->b_opt->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        my_printf("No in-game options for now\n");
    do_nothing();
    if (sfFloatRect_contains(&esc->b_quit->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        game->end = sfTrue;
    if (sfFloatRect_contains(&esc->b_save->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        esc->state = SAVE_CHOICE;
}

int escape_event(window_t *win, game_t *game, escape_t *esc)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(game, win->event);
        if (win->event.type == sfEvtMouseButtonReleased)
            released_mouse(win, game, esc);
    }
    if (game->stats->health == 0)
        game->end = sfTrue;
    return SUCCESS;
}