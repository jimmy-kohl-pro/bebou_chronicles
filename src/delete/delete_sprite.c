/*
** EPITECH PROJECT, 2020
** delete_sprite.c
** File description:
** delete sprite and free
*/

#include "basic.h"

void delete_sprite(sprite_t *sprite)
{
    sfClock_destroy(sprite->clock);
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
    sprite = NULL;
}