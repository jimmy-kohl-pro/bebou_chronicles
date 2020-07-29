/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_begin
*/

#include "game.h"
#include "tools.h"
#include "my.h"
#include "map.h"

static void choose_ennemy_to_fight(game_t *game, int random_ennemy)
{
    game->fight->id = 0;
    if (game->stats->level >= 2 && game->stats->level < 4) {
        if (random_ennemy > 4)
            game->fight->id = 1;
    } if (game->stats->level >= 4 && game ->stats->level < 6) {
        if (random_ennemy > 6)
            game->fight->id = 1;
        if (random_ennemy < 4)
            game->fight->id = 2;
    do_nothing();
    } if (game->stats->level >= 6) {
        if (random_ennemy > 6)
            game->fight->id = 1;
        if (random_ennemy > 0 && random_ennemy < 5)
            game->fight->id = 2;
        if (random_ennemy < 1)
            game->fight->id = 3;
    }
}

void check_fight(game_t *game)
{
    int random_luck_fight = rand() % 600;
    int random_ennemy = rand() % 10;

    choose_ennemy_to_fight(game, random_ennemy);
    if (game->player->direction != NONE && random_luck_fight == 0
    && (!my_strcmp(game->map->name, "road_1")
    || !my_strcmp(game->map->name, "road_2"))) {
        game->player->direction = NONE;
        game->state = IN_FIGHT;
        game->player->is_sprint = 0;
        game->player->speed_move = 6 + game->stats->speed_bonus;
    }
}

void launch_fight(game_t *game, int id)
{
    game->fight->id = id;
    game->fight->game_launched = 1;
    game->player->speed_move = 6;
    game->player->direction = NONE;
    game->state = IN_FIGHT;
}