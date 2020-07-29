/*
** EPITECH PROJECT, 2020
** escape_loop_save.c
** File description:
** escape loop save
*/

#include "game.h"
#include "tools.h"
#include "save.h"

static void display_esc_save(window_t *win, escape_t *esc, file_save_t *saves)
{
    display_sprite(win->window, esc->b_slot1->img);
    display_sprite(win->window, esc->b_slot2->img);
    display_sprite(win->window, esc->b_slot3->img);
    display_sprite(win->window, esc->b_ret->img);
    if (saves->slot1 && saves->slot1->empty)
        disp_text(win->window, saves->slot1->empty);
    if (saves->slot2 && saves->slot2->empty)
        disp_text(win->window, saves->slot2->empty);
    if (saves->slot3 && saves->slot3->empty)
        disp_text(win->window, saves->slot3->empty);
}

int escape_loop_save(window_t *win, game_t *game)
{
    escape_event_save(win, game, game->esc_menu);
    display_esc_save(win, game->esc_menu, game->saves);
    return SUCCESS;
}