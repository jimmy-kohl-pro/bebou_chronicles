/*
** EPITECH PROJECT, 2020
** escape_event_save.c
** File description:
** escape event save
*/

#include "game.h"
#include "save.h"

static void pressed_key(window_t *win, game_t *game, sfEvent event)
{
    if (event.key.code != sfKeyLShift && event.key.code != sfKeyQ
        && event.key.code != sfKeyZ && event.key.code != sfKeyS
        && event.key.code != sfKeyD && event.key.code != sfKeyUp
        && event.key.code != sfKeyDown && event.key.code != sfKeyLeft
        && event.key.code != sfKeyRight)
        game->fight->pass_text = 1;
    if (event.key.code == sfKeyEnter && game->fight->infos->str == NULL
        && but_se(win))
        game->fight->turn = ENNEMY_TURN;
    if ((event.key.code == sfKeyZ || event.key.code == sfKeyUp)
    && game->fight->cursor > ATTACK_LOW
    && !game->fight->infos->str && but_se(win))
        game->fight->cursor = game->fight->cursor - 1;
    if ((event.key.code == sfKeyS || event.key.code == sfKeyDown)
    && game->fight->cursor < ESCAPE
    && !game->fight->infos->str && but_se(win))
        game->fight->cursor = game->fight->cursor + 1;
    if ((game->fight->ennemy_health_max == 120
    || game->fight->ennemy_health_max == 40) && game->fight->cursor == ESCAPE)
        game->fight->cursor = HEAL;
}

void update_fight_time_message(game_t *game)
{
    if (game->fight->elapsed_time > 5.000000 || game->fight->pass_text) {
        game->fight->infos->str = NULL;
        sfClock_restart(game->fight->clock_infos);
        game->fight->pass_text = 0;
        game->fight->is_attack_left = 0;
        game->fight->is_attack_right = 0;
    }
}

int fight_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(win, game, win->event);
    }
    if ((game->stats->health <= 0 || game->fight->ennemy_health_int <= 0
        || game->fight->success_escape)
        && game->fight->infos->str == NULL) {
        if (game->stats->health > 0 && !game->fight->success_escape)
            add_xp(game->stats, 20);
        game->state = IN_GAME;
        game->fight->init_fight = 0;
        game->fight->success_escape = 0;
        game->fight->game_launched = 0;
        game->fight->ennemy_health_int = 1;
    }
    return SUCCESS;
}