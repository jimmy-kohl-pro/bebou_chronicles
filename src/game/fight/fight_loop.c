/*
** EPITECH PROJECT, 2020
** fight.c
** File description:
** deals with fight state
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static void check_end_game(game_t *game)
{
    if (game->fight->end_message)
        return;
    if (game->fight->ennemy_health_int <= 0 && !game->fight->infos->str) {
        game->fight->infos->str = my_strthreecat("You won !\n\nYou earned ",
                int_str(game->fight->ennemy_attack * game->fight->bonus_gold),
                " coins !");
        update_inventory(game->items_list, 5,
        game->fight->ennemy_attack * game->fight->bonus_gold);
                game->fight->end_message = 1;
    } if (game->stats->health <= 0 && !game->fight->infos->str) {
        game->fight->infos->str = "You died !";
        game->fight->end_message = 1;
    } if (game->fight->try_escape && !game->fight->infos->str) {
        if (game->fight->success_escape)
            game->fight->infos->str = "You escaped !";
        else
            game->fight->infos->str = "You failed escaping !";
        game->fight->try_escape = 0;
    }
    sfClock_restart(game->fight->clock_infos);
}

static void ennemy_attack(game_t *game, int random)
{
    if (game->fight->infos->str || game->fight->ennemy_played
        || game->fight->ennemy_health_int <= 0)
        return;
    if (random < 6) {
        game->fight->infos->str = "The ennemy hit you !";
        update_life(game->stats, -game->fight->ennemy_attack);
        game->fight->is_attack_right = 1;
    } else
        game->fight->infos->str = "The ennemy missed you !";
    sfClock_restart(game->fight->clock_infos);
    game->fight->ennemy_played++;
}

static void player_attack(fight_t *fight, stats_t *stats, int random)
{
    if (fight->cursor == ATTACK_LOW) {
        if (random < 8) {
            fight->infos->str = "You hit low !";
            fight->ennemy_health_int = fight->ennemy_health_int \
            - 3 * (stats->attack + stats->attack_bonus);
            fight->is_attack_left = 1;
        } else
            fight->infos->str = "You missed !";
        sfClock_restart(fight->clock_infos);
    } if (fight->cursor == ATTACK_HIGH) {
        if (random < 4) {
            fight->infos->str = "You hit high !";
            fight->ennemy_health_int = fight->ennemy_health_int \
            - 8 * stats->attack_bonus;
            fight->is_attack_left = 1;
        } else
            fight->infos->str = "You missed !";
        sfClock_restart(fight->clock_infos);
    } if (fight->cursor == ESCAPE && (fight->try_escape = 1) && random < 9)
        fight->success_escape = 1;
}

static void fight_turns(game_t *game)
{
    player_attack(game->fight, game->stats, rand() % 10);
    if (game->fight->cursor == HEAL) {
        if (how_many_item(game->items_list, 2) > 0) {
            game->fight->infos->str = "You drinked a potion !";
            update_life(game->stats, 15);
            update_inventory(game->items_list, 2, -1);
        } else
            game->fight->infos->str = "You don't have any potion,\ndumb man !";
        sfClock_restart(game->fight->clock_infos);
    }
    ennemy_attack(game, rand() % 10);
    check_end_game(game);
    if (game->fight->cursor != NO_ATTACK)
        game->fight->cursor = NO_ATTACK;
    if (game->fight->infos->str == NULL) {
        game->fight->turn = PLAYER_TURN;
        game->fight->cursor = ATTACK_LOW;
        game->fight->ennemy_played = 0;
        game->fight->end_message = 0;
    }
}

int fight_loop(window_t *win, game_t *game)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_setView(win->window, game->hud->view);
    if (!game->fight->init_fight) {
        init_fight(game);
        game->fight->init_fight = 1;
    }
    game->fight->elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(
    game->fight->clock_infos));
    update_fight_time_message(game);
    show_cursor(game);
    display_fight(win, game);
    display_ennemies(win, game);
    if (game->fight->turn == ENNEMY_TURN)
        fight_turns(game);
    fight_event(win, game);
    return SUCCESS;
}