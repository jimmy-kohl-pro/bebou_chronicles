/*
** EPITECH PROJECT, 2020
** game_event.c
** File description:
** game event
*/

#include "game.h"

static int pressed_direction_key(window_t *win, player_t *player,
sfEvent event)
{
    int new_direction = player->direction;

    if (event.key.code == sfKeyZ)
        new_direction = UP;
    if (event.key.code == sfKeyQ && new_direction == player->direction)
        new_direction = LEFT;
    if (event.key.code == sfKeyS && new_direction == player->direction)
        new_direction = DOWN;
    if (event.key.code == sfKeyD && new_direction == player->direction)
        new_direction = RIGHT;
    if (event.key.code == sfKeyLShift)
        player->speed_move += 1;
    return new_direction;
}

static int pressed_key(window_t *win, game_t *game, sfEvent event)
{
    game->player->direction = pressed_direction_key(win, game->player, event);
    if (event.key.code == sfKeyF)
        win->fps->activated = (win->fps->activated + 1) % 2;
    return SUCCESS;
}

static int released_key(window_t *win, game_t *game, sfEvent event)
{
    if ((event.key.code == sfKeyZ && game->player->direction == UP)
    || (event.key.code == sfKeyQ && game->player->direction == LEFT)
    || (event.key.code == sfKeyS && game->player->direction == DOWN)
    || (event.key.code == sfKeyD && game->player->direction == RIGHT))
        game->player->direction = NONE;
    if (event.key.code == sfKeyLShift)
        game->player->speed_move -= 1;
    return SUCCESS;
}

int game_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            if (!pressed_key(win, game, win->event))
                return FAIL;
        if (win->event.type == sfEvtKeyReleased) {
            if (!released_key(win, game, win->event))
                return FAIL;
        }
    }
    return SUCCESS;
}