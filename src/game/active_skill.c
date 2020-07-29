/*
** EPITECH PROJECT, 2020
** active_skill.c
** File description:
** active skill
*/

#include "game.h"

void alpha_player(player_t *player, int alpha)
{
    sfColor alpha_color = sfColor_fromRGBA(255, 255, 255, alpha);

    sfSprite_setColor(player->sprite->sprite, alpha_color);
    if (sfSprite_getColor(player->custom->
    hair[player->custom->hair_id]->sprite).a != 0)
        sfSprite_setColor(player->custom->
        hair[player->custom->hair_id]->sprite, alpha_color);
    if (sfSprite_getColor(player->custom->
    face[player->custom->face_id]->sprite).a != 0)
        sfSprite_setColor(player->custom->
        face[player->custom->face_id]->sprite, alpha_color);
    if (sfSprite_getColor(player->custom->
    shirt[player->custom->shirt_id]->sprite).a != 0)
        sfSprite_setColor(player->custom->
        shirt[player->custom->shirt_id]->sprite, alpha_color);
}

void ninja_skill(player_t *player, fight_t *fight)
{
    if (player->ninja_activated)
        alpha_player(player, 100);
    if (player->ninja_cooldown &&
    sfTime_asSeconds(sfClock_getElapsedTime(player->ninja_clock)) >= 40) {
        sfClock_restart(player->ninja_clock);
        player->ninja_cooldown = 0;
    }
    else if (player->ninja_activated && !player->ninja_cooldown &&
    sfTime_asSeconds(sfClock_getElapsedTime(player->ninja_clock)) >= 20) {
        sfClock_restart(player->ninja_clock);
        player->ninja_activated = 0;
        fight->game_launched = 0;
        player->ninja_cooldown = 1;
        alpha_player(player, 255);
    }
}

void display_torch(window_t *win, game_t *game)
{
    if (!game->player->torch_active)
        return;
    game->fire->pos = (sfVector2f){game->player->sprite->pos.x + 150,
                                    game->player->sprite->pos.y + 290};
    manage_particle(win, game->fire, game->time_elapsed);
}