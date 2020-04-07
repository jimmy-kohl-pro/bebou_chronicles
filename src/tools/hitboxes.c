/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** hitboxes
*/

#include "basic.h"

int mouse_hitbox_no_sprite(window_t *win, sfVector2f pos, sfIntRect rect)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->window);

    if (mouse_pos.x >= pos.x
    && mouse_pos.x <= pos.x + rect.width
    && mouse_pos.y >= pos.y
    && mouse_pos.y <= pos.y + rect.height)
        return 1;
    return 0;
}

int mouse_hitbox(window_t *win, sprite_t sprite)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f sprite_scale = sfSprite_getScale(sprite.sprite);

    if (mouse_pos.x >= sprite.pos.x
    && mouse_pos.x <= sprite.pos.x + sprite.hitbox.width * sprite_scale.x
    && mouse_pos.y >= sprite.pos.y
    && mouse_pos.y <= sprite.pos.y + sprite.hitbox.height * sprite_scale.y)
        return 1;
    return 0;
}