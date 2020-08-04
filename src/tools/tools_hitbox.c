/*
** EPITECH PROJECT, 2020
** tools_hitbox.c
** File description:
** hitbox
*/

#include "game.h"
#include "map.h"
#include "tools.h"

void append_hitbox(sfVertexArray *array, sfVector2f pos, sfFloatRect hitbox)
{
        sfVertexArray_append(array, (sfVertex){fvec(pos.x + hitbox.left,
        pos.y + hitbox.top + hitbox.height), sfRed, ORIGIN});
        sfVertexArray_append(array, (sfVertex){fvec(pos.x + hitbox.left,
        pos.y + hitbox.top), sfRed, ORIGIN});
        sfVertexArray_append(array, (sfVertex){fvec(pos.x + hitbox.left
        + hitbox.width, pos.y + hitbox.top), sfRed, ORIGIN});
        sfVertexArray_append(array, (sfVertex){fvec(pos.x + hitbox.left
        + hitbox.width, pos.y + hitbox.top + hitbox.height), sfRed, ORIGIN});
}

void display_hitbox(window_t *win, objects_t *objects, player_t *player)
{
    objects_t *temp_objects = objects;
    sfVertexArray *array = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(array, sfQuads);
    for (; objects; objects = objects->next)
        append_hitbox(array, objects->pos, objects->hitbox);
    append_hitbox(array, player->sprite->pos, player->sprite->hitbox);
    sfRenderWindow_drawVertexArray(win->window, array, NULL);
    sfVertexArray_destroy(array);
    objects = temp_objects;
}