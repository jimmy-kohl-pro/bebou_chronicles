/*
** EPITECH PROJECT, 2020
** tools_vector.c
** File description:
** vector xy
*/

#include <SFML/Graphics.h>

sfVector2f fvec(float x, float y)
{
    sfVector2f xy;

    xy.x = x;
    xy.y = y;
    return (xy);
}

sfVector2i ivec(int x, int y)
{
    sfVector2i xy;

    xy.x = x;
    xy.y = y;
    return (xy);
}

sfVector2u uvec(unsigned int x, unsigned int y)
{
    sfVector2u xy;

    xy.x = x;
    xy.y = y;
    return (xy);
}