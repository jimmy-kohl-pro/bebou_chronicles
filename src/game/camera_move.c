/*
** EPITECH PROJECT, 2020
** camera_move.c
** File description:
** camera movement
*/

#include "game.h"
#include "tools.h"

void update_camera(camera_t *camera, player_t *player, sfVector2f map)
{
    sfVector2f middle_pos = fvec(player->sprite->pos.x +
    (player->sprite->hitbox.width / 2),
    player->sprite->pos.y + (player->sprite->hitbox.height / 2));

    camera->pos = middle_pos;
    if (middle_pos.x < camera->dim.x / 2)
        camera->pos.x = camera->dim.x / 2;
    if (middle_pos.x > (map.x + 200 - (camera->dim.x / 2)))
        camera->pos.x = (map.x + 200 - (camera->dim.x / 2));
    if (middle_pos.y < camera->dim.y / 2)
        camera->pos.y = camera->dim.y / 2;
    if (middle_pos.y > (map.y + 200 - (camera->dim.y / 2)))
        camera->pos.y = (map.y + 200 - (camera->dim.y / 2));
    if (map.x < camera->dim.x)
        camera->pos.x = map.x / 2;
    if (map.y < camera->dim.y)
        camera->pos.y = map.y / 2;
    sfView_setCenter(camera->view, camera->pos);
}