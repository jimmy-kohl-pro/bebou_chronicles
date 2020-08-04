/*
** EPITECH PROJECT, 2020
** map_collision.c
** File description:
** map collision
*/

#include "map.h"
#include "my.h"
#include "game.h"

int is_collide(sprite_t *player, objects_t *objects, sfVector2f offset)
{
    objects_t *save_head = objects;

    offset.x += player->pos.x;
    offset.y += player->pos.y;
    for (; objects; objects = objects->next) {
        if (sfFloatRect_intersects(&(sfFloatRect){
        offset.x + player->hitbox.left, offset.y + player->hitbox.top,
        player->hitbox.width, player->hitbox.height}, &(sfFloatRect){
        objects->pos.x + objects->hitbox.left, objects->pos.y + objects->hitbox.top,
        objects->hitbox.width, objects->hitbox.height}, NULL))
            return SUCCESS;
    }
    objects = save_head;
    return FAIL;
}

int is_click(struct objects_s *objects, sfVector2f mouse, char *name)
{
    objects_t *save_head = objects;
    sfFloatRect hitbox_global;

    for (; objects && my_strcmp(objects->name, name); objects = objects->next);
    if (!objects) {
        objects = save_head;
        return FAIL;
    }
    hitbox_global = sfSprite_getGlobalBounds(objects->sprite);
    objects = save_head;
    if (sfFloatRect_contains(&hitbox_global, mouse.x, mouse.y))
        return SUCCESS;
    return FAIL;
}