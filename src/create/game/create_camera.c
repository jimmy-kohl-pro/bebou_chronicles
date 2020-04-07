/*
** EPITECH PROJECT, 2020
** create_camera.c
** File description:
** create camera game object
*/

#include "game.h"
#include "my.h"
#include "tools.h"

camera_t *create_game_camera(window_t *win)
{
    camera_t *camera = my_calloc(sizeof(camera_t));

    camera->dim = fvec((float)win->mode.width / 3, (float)win->mode.height / 3);
    camera->pos = ORIGIN;
    camera->view = sfView_createFromRect((sfFloatRect){camera->pos.x,
                        camera->pos.y, camera->dim.x, camera->dim.y});
    return camera;
}
