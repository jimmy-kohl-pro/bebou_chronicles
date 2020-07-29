/*
** EPITECH PROJECT, 2020
** map_collision.c
** File description:
** map collision
*/

#include "map.h"
#include "my.h"
#include "game.h"

int is_collide(sprite_t *player, props_t *props, sfVector2f offset)
{
    props_t *save_head = props;

    offset.x += player->pos.x;
    offset.y += player->pos.y;
    for (; props; props = props->next) {
        if (sfFloatRect_intersects(&(sfFloatRect){
        offset.x + player->hitbox.left, offset.y + player->hitbox.top,
        player->hitbox.width, player->hitbox.height}, &(sfFloatRect){
        props->pos.x + props->hitbox.left, props->pos.y + props->hitbox.top,
        props->hitbox.width, props->hitbox.height}, NULL))
            return SUCCESS;
    }
    props = save_head;
    return FAIL;
}

int is_click(struct props_s *props, sfVector2f mouse, char *name)
{
    props_t *save_head = props;
    sfFloatRect hitbox_global;

    for (; props && my_strcmp(props->name, name); props = props->next);
    if (!props) {
        props = save_head;
        return FAIL;
    }
    hitbox_global = sfSprite_getGlobalBounds(props->sprite);
    props = save_head;
    if (sfFloatRect_contains(&hitbox_global, mouse.x, mouse.y))
        return SUCCESS;
    return FAIL;
}