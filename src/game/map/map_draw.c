/*
** EPITECH PROJECT, 2020
** map_draw.c
** File description:
** draw map
*/

#include "map.h"
#include "game.h"
#include "tools.h"

static void manage_sprint_player(window_t *win, game_t *game)
{
    if (!game->player->is_sprint || game->player->direction == NONE)
        return;
    game->run_particle->pos = game->player->sprite->pos;
    game->run_particle->pos.x += 100;
    game->run_particle->pos.y += 420;
    if (!game->player->ninja_activated)
        manage_particle(win, game->run_particle, game->time_elapsed);
    game->player->speed_move = 10 + game->stats->speed_bonus;
}

void display_player(window_t *win, player_t *player, game_t *game)
{
    update_custom_hair_and_face(player, player->custom->hair_id, \
        player->custom->face_id);
    update_custom_shirt_and_pants(player, player->custom->shirt_id, \
        player->custom->pants_id);
    update_custom_shoes(player, player->custom->shoes_id);
    manage_sprint_player(win, game);
    display_sprite(win->window, player->sprite);
    display_sprite(win->window, player->custom->face[player->custom->face_id]);
    display_sprite(win->window, player->custom->hair[player->custom->hair_id]);
    display_sprite(win->window, \
        player->custom->shoes[player->custom->shoes_id]);
    display_sprite(win->window, \
        player->custom->pants[player->custom->pants_id]);
    display_sprite(win->window, \
    player->custom->shirt[player->custom->shirt_id]);
}

void display_pattern(sfRenderWindow *win, pattern_t *pattern)
{
    pattern_t *save_head = pattern;

    for (; pattern; pattern = pattern->next) {
        if (!pattern->sprite)
            continue;
        sfRenderWindow_drawSprite(win, pattern->sprite, NULL);
    }
    pattern = save_head;
}

void display_props(window_t *win, props_t *props, game_t *game)
{
    props_t *save_head = props;
    float pos_y = game->player->sprite->pos.y
                + game->player->sprite->hitbox.top;

    if (!props) {
        display_player(win, game->player, game);
        return;
    } if (pos_y < props->pos.y + props->hitbox.top)
        display_player(win, game->player, game);
    for (; props->next; props = props->next) {
        if (!props->sprite)
            continue;
        sfRenderWindow_drawSprite(win->window, props->sprite, NULL);
        if (pos_y >= props->pos.y + props->hitbox.top
        && pos_y <= props->next->pos.y + props->next->hitbox.top)
            display_player(win, game->player, game);
    }
    sfRenderWindow_drawSprite(win->window, props->sprite, NULL);
    if (pos_y > props->pos.y + props->hitbox.top)
        display_player(win, game->player, game);
    props = save_head;
}

void display_map(window_t *win, game_t *game)
{
    display_pattern(win->window, game->map->pattern);
    display_props(win, game->map->props, game);
}