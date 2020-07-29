/*
** EPITECH PROJECT, 2020
** manage_particle.c
** File description:
** manage particle
*/

#include "particle_engine.h"
#include "tools.h"
#include "math.h"

void draw_particle(sfRenderWindow *win, particle_t *particle)
{
    particle_t *temp_particle = particle;

    for (; particle; particle = particle->next) {
        if (!particle->sprite)
            continue;
        sfRenderWindow_drawSprite(win, particle->sprite, NULL);
    }
    particle = temp_particle;
}

void update_particle(particle_engine_t *engine, particle_t *particle,
                        float elapsed_time)
{
    particle_t *save_particle = particle;

    while (particle) {
        if (engine->rotate_speed)
            sfSprite_rotate(particle->sprite, engine->rotate_speed
                                                    * elapsed_time);
        if (engine->color_nbr)
            colorize_particle(engine, particle);
        if (engine->size_max != engine->size_min)
            resize_particle(engine, particle);
        particle->pos = move_towards(particle->pos, particle->destination,
                                    engine->particle_speed, elapsed_time);
        sfSprite_setPosition(particle->sprite, particle->pos);
        disappear_particle(engine, particle);
        particle = particle->next;
    }
    particle = save_particle;
}

void manage_particle(window_t *win, particle_engine_t *engine,
                                                float elapsed_time)
{
    if (sfClock_getElapsedTime(engine->clock).microseconds
                                            >= engine->spawn_rate) {
        add_particle(engine);
        sfClock_restart(engine->clock);
    }
    update_particle(engine, engine->particle, elapsed_time);
    draw_particle(win->window, engine->particle);
    check_delete_particle(engine, &engine->particle);
}