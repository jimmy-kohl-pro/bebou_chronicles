/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_move
*/

#include "game.h"
#include "tools.h"

static void move_sprite(player_t *player, int direction, float elapsed_time)
{
    if (direction == UP)
        player->sprite->pos.y -= player->speed_move * elapsed_time;
    if (direction == DOWN)
        player->sprite->pos.y += player->speed_move * elapsed_time;
    if (direction == LEFT)
        player->sprite->pos.x -= player->speed_move * elapsed_time;
    if (direction == RIGHT)
        player->sprite->pos.x += player->speed_move * elapsed_time;
}

int check_player_move(player_t *player, float elapsed_time)
{
    if (player->direction != NONE) {
        player->sprite->rect.top = player->sprite->rect.height *
                                            (player->direction - 1);
        update_animclock(player->speed_anim / player->speed_move,
                        player->sprite, 7);
        move_sprite(player, player->direction, elapsed_time);
    } else {
        player->sprite->rect.left = 0;
        sfSprite_setTextureRect(player->sprite->sprite, player->sprite->rect);
    }
    return SUCCESS;
}