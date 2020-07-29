/*
** EPITECH PROJECT, 2020
** custom_events.c
** File description:
** blabla
*/

#include "game.h"
#include "menu_h.h"
#include "tools.h"

static int key_released_custom(game_t *game, sfEvent event)
{
    int (*player_modifier[])(game_t *game, sfEvent event) = \
        {&custom_command_hair, &custom_command_face, \
        &custom_command_shirt, &custom_command_pants, \
        &custom_command_shoes, NULL};

    if (event.key.code == sfKeyS || event.key.code == sfKeyDown)
        game->player->custom->which_part += 1;
    if (event.key.code == sfKeyZ || event.key.code == sfKeyUp)
        game->player->custom->which_part -= 1;
    if (game->player->custom->which_part < 0)
        game->player->custom->which_part = 0;
    if (game->player->custom->which_part > 4)
        game->player->custom->which_part = 4;
    player_modifier[game->player->custom->which_part](game, event);
    update_buttons(game->player->custom, game->player->custom->which_part);
    return SUCCESS;
}

static int key_pressed_custom(window_t *win, game_t *game, sfEvent event)
{
    if (win->event.type == sfEvtClosed || (event.key.code == sfKeyEscape))
        sfRenderWindow_close(win->window);
    if (event.key.code == sfKeyEnter)
        game->state = IN_GAME;
    return SUCCESS;
}

int custom_event(window_t *win, game_t *game)
{
    check_custom_mouse_position_1(win, game->player->custom);
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtKeyPressed)
            key_pressed_custom(win, game, win->event);
        if (win->event.type == sfEvtKeyReleased)
            key_released_custom(game, win->event);
        if (win->event.type == sfEvtMouseButtonPressed)
            mouse_events(game->player->custom, win);
    }
    return SUCCESS;
}