/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_move
*/

#include "game.h"
#include "tools.h"
#include "map.h"

static void move_sprite(player_t *player, sfVector2f map_size,
                                    props_t *props, float offset)
{
    if (player->direction & UP && player->sprite->pos.y > 0
    && !is_collide(player->sprite, props, fvec(0, -offset)))
        player->sprite->pos.y -= offset;
    if (player->direction & DOWN && player->sprite->pos.y < map_size.y
    && !is_collide(player->sprite, props, fvec(0, offset)))
        player->sprite->pos.y += offset;
    if (player->direction & LEFT && player->sprite->pos.x > 0
    && !is_collide(player->sprite, props, fvec(-offset, 0)))
        player->sprite->pos.x -= offset;
    if (player->direction & RIGHT && player->sprite->pos.x < map_size.x
    && !is_collide(player->sprite, props, fvec(offset, 0)))
        player->sprite->pos.x += offset;
}

int sprite_direction(int dir)
{
    if (dir == 12 ||  dir == 13 || dir == 15)
        return 1;
    if (dir == 14)
        return 2;
    if (dir == 4 || dir == 6 || dir == 5)
        return 3;
    if (dir == 8 || dir == 10 || dir == 9)
        return 4;
    return dir;
}

int check_player_move(player_t *player, sfVector2f map_size,
                            props_t *props, float elapsed_time)
{
    if (player->direction != NONE) {
        player->sprite->rect.top = player->sprite->rect.height *
                                    (sprite_direction(player->direction) - 1);
        update_animclock(player->speed_anim / player->speed_move,
                        player->sprite, 7);
        move_sprite(player, map_size, props,
                    player->speed_move * elapsed_time);
        sfSprite_setTextureRect(player->sprite->sprite, player->sprite->rect);
    } else {
        player->sprite->rect.left = 0;
        sfSprite_setTextureRect(player->sprite->sprite, player->sprite->rect);
    }
    return SUCCESS;
}