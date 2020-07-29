/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** secondary_quest
*/

#include "quests.h"
#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "my.h"

void secondary_quests_2(window_t *win, game_t *game)
{
    if (!my_strcmp(game->map->name, "village_map")
    && game->dialogue->prietress_dial)
        baby_quest(win, game);
    if (!game->dialogue->baby_quest && game->dialogue->baby_quest_launched
    && !my_strcmp(game->map->name, "north_map")
    && how_many_item(game->items_list, 7) == 0)
        take_baby(win, game);
}

void secondary_quests(window_t *win, game_t *game)
{
    if (!my_strcmp(game->map->name, "village_map")
    && game->dialogue->prietress_dial)
        cat_quest(win, game);
    if (!game->dialogue->cat_quest && game->dialogue->cat_quest_launched
    && !my_strcmp(game->map->name, "temple_map")
    && how_many_item(game->items_list, 3) == 0)
        take_cat(win, game);
    if (!my_strcmp(game->map->name, "village_map")
    && game->dialogue->prietress_dial)
        bandit_quest(win, game);
    if (game->dialogue->bandit_killed && game->stats->health > 0
    && how_many_item(game->items_list, 6) == 0) {
        update_inventory(game->items_list, 6, 1);
        add_xp(game->stats, 30);
    } if (!my_strcmp(game->map->name, "road_1")
    && game->dialogue->bandit_quest_launched && !game->dialogue->bandit_quest
    && !game->dialogue->bandit_killed)
        attack_bandit(win, game);
    secondary_quests_2(win, game);
}