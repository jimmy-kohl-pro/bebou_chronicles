/*
** EPITECH PROJECT, 2020
** camera_move.c
** File description:
** camera movement
*/

#include "game.h"

void update_camera(camera_t *camera, player_t *player, sprite_t *map)
{
    camera->pos = player->sprite->pos;
    if (player->sprite->pos.x < camera->dim.x / 2)
        camera->pos.x = camera->dim.x / 2;
    if (player->sprite->pos.x > ((float)map->rect.width - (camera->dim.x / 2)))
        camera->pos.x = ((float)map->rect.width - (camera->dim.x / 2));
    if (player->sprite->pos.y < camera->dim.y / 2)
        camera->pos.y = camera->dim.y / 2;
    if (player->sprite->pos.y > ((float)map->rect.height - (camera->dim.y / 2)))
        camera->pos.y = ((float)map->rect.height - (camera->dim.y / 2));
    sfView_setCenter(camera->view, camera->pos);
}