/*
** EPITECH PROJECT, 2020
** modify_particule.c
** File description:
** modify a particle
*/

#include <math.h>
#include "particle_engine.h"
#include "tools.h"

void turn_particle(sfSprite *sprite, float rotate_speed, float elapsed_time)
{
    sfSprite_rotate(sprite, rotate_speed * elapsed_time);
}

void colorize_particle(particle_engine_t *engine, particle_t *particle)
{
    if (engine->color_variation != FADE_IN_TIME)
        return;
    sfSprite_setColor(particle->sprite,
    sfColor_add(sfSprite_getColor(particle->sprite),
    (sfColor){0, 0, 0, (int)(255 - (0.3 * powf(1.1, dist_vec(particle->pos,
    particle->destination) - engine->distance / 1.5)))}));
}

void resize_particle(particle_engine_t *engine, particle_t *particle)
{
    float new_size = 0;
    float diff = 0;
    float distance;

    if (engine->size_variation != FADE_IN_TIME)
        return ;
    distance = engine->distance - dist_vec(particle->pos,
                                            particle->destination);
    diff = engine->size_max - engine->size_min;
    new_size = (-diff / pow(engine->distance, 2)) * pow(distance, 2) + diff;
    sfSprite_setScale(particle->sprite,
        fvec(new_size / engine->size_max, new_size / engine->size_max));
}

void disappear_particle(particle_engine_t *engine, particle_t *particle)
{
    int alpha = 0;
    float distance = 0;
    float distance_quarter = 0;

    if (engine->disappear != FADE)
        return;
    distance_quarter = (engine->distance / 4);
    distance = engine->distance - dist_vec(particle->pos,
                                            particle->destination);
    if (distance < distance_quarter * 3)
        return;
    alpha = (int)((-255 / pow(distance_quarter, 2)) *
                pow((distance - distance_quarter * 3), 2) + 255);
    if (alpha > 255)
        alpha = 255;
    if (alpha < 0)
        alpha = 0;
    sfSprite_setColor(particle->sprite,
    sfColor_modulate(sfSprite_getColor(particle->sprite),
                    (sfColor){255, 255, 255, alpha}));
}