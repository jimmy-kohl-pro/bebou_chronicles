/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stats_in_fight
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static void set_stats_in_fight(game_t *game)
{
    char *potion_text = my_strcat("potions :   ",
                                int_str(how_many_item(game->items_list, 2)));
    char *sword = NULL;
    char *sword_text = NULL;

    if (how_many_item(game->items_list, 8))
        sword = "Katana\n            en or";
    else if (how_many_item(game->items_list, 1))
        sword = "Katana\n      en pierre";
    else
        sword = "Katana\n         en bois";
    sword_text = my_strcat("\nArme : ", sword);
    game->fight->player_health->str = my_strthreecat(
    int_str(game->stats->health), " / ", int_str(game->stats->health_max));
    game->fight->ennemy_health->str = my_strthreecat(
                                int_str(game->fight->ennemy_health_int), " / ",
                                int_str(game->fight->ennemy_health_max));
    game->fight->other_stats->str = my_strcat(potion_text, sword_text);
    free(potion_text);
    free(sword_text);
}

void display_stats_in_fight(window_t *win, game_t *game)
{
    ennemies_t *ennemies = game->fight->ennemies;

    set_stats_in_fight(game);
    while (ennemies) {
        if (game->fight->id == ennemies->id)
            game->fight->ennemy_name->str = ennemies->name;
        ennemies = ennemies->next;
    }
    disp_text(win->window, game->fight->musachi_name);
    disp_text(win->window, game->fight->ennemy_name);
    disp_text(win->window, game->fight->player_health);
    disp_text(win->window, game->fight->ennemy_health);
    if (!game->fight->infos->str && game->fight->turn == PLAYER_TURN) {
        disp_text(win->window, game->fight->other_stats);
    }
}