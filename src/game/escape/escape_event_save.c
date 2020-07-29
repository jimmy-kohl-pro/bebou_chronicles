/*
** EPITECH PROJECT, 2020
** escape_event_save.c
** File description:
** escape event save
*/

#include "game.h"
#include "save.h"

static void pressed_key(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        game->esc_menu->state = ESC;
    }
}

static void released_mouse(window_t *win, game_t *game, escape_t *esc)
{
    if (sfFloatRect_contains(&esc->b_slot1->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win)) {
        save(game, 1);
        game->saves = load_slot(esc->b_slot1, esc->b_slot2, esc->b_slot3);
    } if (sfFloatRect_contains(&esc->b_slot2->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win)) {
        save(game, 2);
        game->saves = load_slot(esc->b_slot1, esc->b_slot2, esc->b_slot3);
    do_nothing();
    } if (sfFloatRect_contains(&esc->b_slot3->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win)) {
        save(game, 3);
        game->saves = load_slot(esc->b_slot1, esc->b_slot2, esc->b_slot3);
    } if (sfFloatRect_contains(&esc->b_ret->img->hitbox,
                                win->mouse.x, win->mouse.y) && but_se(win))
        esc->state = ESC;
}

int escape_event_save(window_t *win, game_t *game, escape_t *esc)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(game, win->event);
        if (win->event.type == sfEvtMouseButtonReleased)
            released_mouse(win, game, esc);
    }
    return SUCCESS;
}