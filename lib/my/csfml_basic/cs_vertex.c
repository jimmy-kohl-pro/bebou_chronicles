/*
** EPITECH PROJECT, 2020
** cs_vertex.c
** File description:
** vertex functions
*/

#include "csfml_basic.h"

sfVertex newvertex(sfVector2f pos, sfColor color, sfVector2f texture_pos)
{
    sfVertex vertex;

    vertex.position = pos;
    vertex.color = color;
    vertex.texCoords = texture_pos;
    return (vertex);
}