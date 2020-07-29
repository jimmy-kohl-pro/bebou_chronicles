/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_fight
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static void display_attack(window_t *win, game_t *game)
{
    if (game->fight->is_attack_left) {
        game->fight->attack_anim->pos = (sfVector2f) {300, 500};
        display_sprite(win->window, game->fight->attack_anim);
        update_animclock_column(120, game->fight->attack_anim, 4, 1);
    } if (game->fight->is_attack_right) {
        game->fight->attack_anim->pos = (sfVector2f) {1300, 500};
        display_sprite(win->window, game->fight->attack_anim);
        update_animclock_column(120, game->fight->attack_anim, 4, 1);
    }
}

void show_cursor(game_t *game)
{
    if (game->fight->infos->str)
        return;
    if (game->fight->cursor == ATTACK_LOW) {
        game->fight->attack_low->color = sfYellow;
        game->fight->attack_high->color = sfWhite;
        game->fight->heal->color = sfWhite;
        game->fight->escape->color = sfWhite;
    } if (game->fight->cursor == ATTACK_HIGH) {
        game->fight->attack_low->color = sfWhite;
        game->fight->attack_high->color = sfYellow;
        game->fight->heal->color = sfWhite;
    } if (game->fight->cursor == HEAL) {
        game->fight->attack_high->color = sfWhite;
        game->fight->heal->color = sfYellow;
        game->fight->escape->color = sfWhite;
    } if (game->fight->cursor == ESCAPE) {
        game->fight->heal->color = sfWhite;
        game->fight->escape->color = sfYellow;
    }
}

void display_ennemies(window_t *win, game_t *game)
{
    ennemies_t *ennemies = game->fight->ennemies;

    while (ennemies) {
        if (game->fight->id == ennemies->id &&
        game->fight->nb_ennemies == 1) {
            ennemies->sprite->pos = (sfVector2f) {1350, 300};
            display_sprite(win->window, ennemies->sprite);
        }
        if (game->fight->id == ennemies->id &&
        game->fight->nb_ennemies == 2) {
            ennemies->sprite->pos = (sfVector2f) {1350, 100};
            display_sprite(win->window, ennemies->sprite);
            ennemies->sprite->pos = (sfVector2f) {1350, 500};
            display_sprite(win->window, ennemies->sprite);
        }
        ennemies = ennemies->next;
    }
    display_attack(win, game);
}

void display_fight(window_t *win, game_t *game)
{
    display_sprite(win->window, game->fight->bg);
    display_sprite(win->window, game->fight->player);
    display_sprite(win->window, game->fight->fight_hud);
    if (game->fight->infos->str)
        disp_text(win->window, game->fight->infos);
    else if (game->fight->turn == PLAYER_TURN) {
        disp_text(win->window, game->fight->attack_high);
        disp_text(win->window, game->fight->attack_low);
        disp_text(win->window, game->fight->heal);
        disp_text(win->window, game->fight->escape);
    }
    display_stats_in_fight(win, game);
}

void init_fight(game_t *game)
{
    ennemies_t *ennemies = game->fight->ennemies;

    game->stats->health_max = 25 + 5 * game->stats->level +\
    game->stats->health_bonus;
    if (how_many_item(game->items_list, 8))
        game->stats->attack = 2;
    else if (how_many_item(game->items_list, 1))
        game->stats->attack = 1;
    else
        game->stats->attack = 0;
    while (ennemies) {
        if (game->fight->id == ennemies->id) {
            game->fight->ennemy_health_int = ennemies->health;
            game->fight->ennemy_health_max = ennemies->health;
            game->fight->ennemy_attack = ennemies->attack;
            game->fight->infos->str = my_strcat(
                                        ennemies->name, " vous attaque !");
            sfClock_restart(game->fight->clock_infos);
        } ennemies = ennemies->next;
    }
}