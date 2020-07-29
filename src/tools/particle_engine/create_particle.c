/*
** EPITECH PROJECT, 2020
** create_particle.c
** File description:
** create_particle.c
*/

#include "particle_engine.h"
#include "tools.h"

void fill_empty_origin(particle_engine_t *engine)
{
    engine->pos = ORIGIN;
    engine->rotation = 0;
    engine->range = 0;
    engine->type = LINEAR;
    engine->range_shift = 0;
    engine->distance = 0;
}

void fill_empty_sprite(particle_engine_t *engine)
{
    engine->sprite_list = NULL;
    engine->sprite_nbr = 0;
    engine->size_max = 0;
    engine->size_min = 0;
    engine->size_variation = NONE_VAR;
}

void fill_empty_color(particle_engine_t *engine)
{
    engine->color_list = NULL;
    engine->color_nbr = 0;
    engine->color_variation = NONE_VAR;
}

particle_engine_t *create_particle_system(void)
{
    particle_engine_t *engine = malloc(sizeof(particle_engine_t));

    fill_empty_origin(engine);
    fill_empty_sprite(engine);
    fill_empty_color(engine);
    engine->rotate_speed = 0;
    engine->particle_speed = 0;
    engine->spawn_rate = 0;
    engine->particle = NULL;
    engine->disappear = POP;
    engine->clock = sfClock_create();
    return engine;
}