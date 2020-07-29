/*
** EPITECH PROJECT, 2020
** tools_transform
** File description:
** tools_transform
*/

#include "basic.h"

sfSprite *sprite_turn_horizontally(sfSprite *original)
{
    const sfTexture *texture = sfSprite_getTexture(original);
    sfImage *image = sfTexture_copyToImage(texture);
    sfTexture *new_texture = NULL;
    sfSprite *new_sprite = sfSprite_create();

    sfImage_flipHorizontally(image);
    new_texture = sfTexture_createFromImage(image, NULL);
    sfSprite_setTexture(new_sprite, new_texture, sfTrue);
    return new_sprite;
}