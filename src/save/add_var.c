/*
** EPITECH PROJECT, 2020
** add_var.c
** File description:
** add var
*/

#include "save.h"
#include "my.h"
#include "map.h"

static void add_quest_var(dialogue_t *dial, char ***save)
{
    new_var("first_dial", int_str(dial->first_dial), save);
    new_var("prietress_dial", int_str(dial->prietress_dial), save);
    new_var("ok_dial", int_str(dial->ok_dial), save);
    new_var("emperor_dead", int_str(dial->emperor_dead), save);
    new_var("cat_quest_launched", int_str(dial->cat_quest_launched), save);
    new_var("cat_quest", int_str(dial->cat_quest), save);
    new_var("bandit_quest_launched", int_str(dial->bandit_quest_launched), save);
    new_var("bandit_killed", int_str(dial->bandit_killed), save);
    new_var("bandit_quest", int_str(dial->bandit_quest), save);
    new_var("baby_quest_launched", int_str(dial->baby_quest_launched), save);
    new_var("baby_quest", int_str(dial->baby_quest), save);
}

void add_all_var(game_t *game, char ***save)
{
    items_list_t *items_list = game->items_list;

    new_var("pos", my_strthreecat(float_str(game->player->sprite->pos.x, 2),
                    ",", float_str(game->player->sprite->pos.y, 2)), save);
    new_var("map", game->map->name, save);
    new_var("custom", my_strthreecat(my_strthreecat(int_str(game->player->
    custom->face_id), ":", int_str(game->player->custom->hair_id)),
    ":", int_str(game->player->custom->shirt_id)), save);
    new_var("level", int_str(game->stats->level), save);
    new_var("xp", int_str(game->stats->xp), save);
    new_var("health", int_str(game->fight->ennemy_health_int), save);
    new_var("perk_points", int_str(game->stats->perk_points), save);
    new_var("skill_unlock", int_str(game->stats->skill->skill_unlock), save);
    while (items_list) {
        new_var(items_list->name, int_str(items_list->nb), save);
        items_list = items_list->next;
    }
    add_quest_var(game->dialogue, save);
}