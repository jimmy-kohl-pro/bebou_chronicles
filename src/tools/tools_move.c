/*
** EPITECH PROJECT, 2020
** tools_move.c
** File description:
** tools move
*/

#include "basic.h"
#include "math.h"

sfVector2f move_towards(sfVector2f pos, sfVector2f next_pos,
                            int speed, float elapsed_time)
{
    float x = next_pos.x - pos.x;
    float y = next_pos.y - pos.y;
    float M = sqrtf(powf(x, 2) + powf(y, 2));

    pos.x += (x / M) * (speed * elapsed_time);
    pos.y += (y / M) * (speed * elapsed_time);
    return pos;
}