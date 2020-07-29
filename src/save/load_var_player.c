/*
** EPITECH PROJECT, 2020
** load_var.c
** File description:
** load var
*/

#include "game.h"
#include "my.h"
#include "map.h"

int load_skill(stats_t *stats, char **save)
{
    stats->perk_points = my_getnbr(get_var("perk_points", save));
    stats->skill->skill_unlock = my_getnbr(get_var("skill_unlock", save));
    return SUCCESS;
}

int load_player_stats(game_t  *game, char **save)
{
    game->stats->level = my_getnbr(get_var("level", save));
    game->stats->xp = my_getnbr(get_var("xp", save));
    game->fight->ennemy_health_int = my_getnbr(get_var("health", save));
    return SUCCESS;
}

int load_player_custom(player_t *player, char *custom_brut)
{
    char **custom_id = custom_brut ?
                    my_str_to_word_array(custom_brut, ":") : NULL;

    if (!custom_id || my_arraylen(custom_id) != 3)
        return FAIL;
    player->custom->face_id = my_getnbr(custom_id[0]);
    player->custom->hair_id = my_getnbr(custom_id[1]);
    player->custom->shirt_id = my_getnbr(custom_id[2]);
    free_array(custom_id);
    return SUCCESS;
}

int load_player_pos(player_t *player, map_t **map, char *var_pos, char *var_map)
{
    char **str_pos = NULL;

    if (!var_pos || !var_map)
        return FAIL;
    str_pos = my_str_to_word_array(var_pos, ",");
    if (my_arraylen(str_pos) != 2)
        return FAIL;
    player->sprite->pos.x = my_getfloat(str_pos[0], 2);
    player->sprite->pos.y = my_getfloat(str_pos[1], 2);
    (*map) = map_load(var_map);
    return SUCCESS;
}