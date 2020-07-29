/*
** EPITECH PROJECT, 2020
** particle_set_origin.c
** File description:
** set origin particle system
*/

#include "particle_engine.h"

void particle_set_origin(particle_engine_t *engine,
sfVector2f pos, type_e type, float rotation)
{
    if (!engine)
        return ;
    engine->pos = pos;
    engine->type = type;
    engine->rotation = rotation;
}

void particle_set_range(particle_engine_t *engine,
float range, float range_shift, float distance)
{
    if (!engine)
        return ;
    engine->range = range;
    engine->range_shift = range_shift;
    engine->distance = distance;
}

void particle_set_color_variation(particle_engine_t *engine,
                                variation_e variation)
{
    if (!engine)
        return ;
    engine->color_variation = variation;
}

void particle_set_move(particle_engine_t *engine,
float particle_speed, int spawn_rate, float rotate_speed)
{
    if (!engine)
        return ;
    engine->particle_speed = particle_speed;
    engine->spawn_rate = spawn_rate;
    engine->rotate_speed = rotate_speed;
}

void particle_set_sizerange(particle_engine_t *engine,
float min, float max, variation_e variation)
{
    if (!engine)
        return ;
    engine->size_min = min;
    engine->size_max = max;
    engine->size_variation = variation;
}