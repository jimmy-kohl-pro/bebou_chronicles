/*
** EPITECH PROJECT, 2020
** particle_engine.h
** File description:
** particle engine
*/

#ifndef PARTICULE_ENGINE_H_H
#define PARTICULE_ENGINE_H_H

#include "basic.h"
#include <stdlib.h>

// Divergent, the area begin to the pos point and elarge to the range.
// Linear, range is to the pos point.
typedef enum type_n
{
    DIVERGENT,
    LINEAR
} type_e;

typedef enum variation_n
{
    NONE_VAR,
    RANDOM,
    FADE_IN_TIME
} variation_e;

typedef enum disappear_n
{
    POP,
    FADE
} disappear_e;

typedef struct particle_s
{
    sfVector2f destination;
    sfVector2f pos;
    sfSprite *sprite;
    struct particle_s *next;
} particle_t;

typedef struct sprite_link_s
{
    sfSprite *sprite;
    struct sprite_link_s *next;
} sprite_link_t;

typedef struct color_link_s
{
    sfColor color;
    struct color_link_s *next;
} color_link_t;

typedef struct particle_engine_s
{
    sfVector2f pos;
    float rotation;
    float range;
    type_e type;
    float range_shift;
    float distance;
    sprite_link_t *sprite_list;
    int sprite_nbr;
    float size_max;
    float size_min;
    variation_e size_variation;
    float rotate_speed;
    int particle_speed;
    color_link_t *color_list;
    int color_nbr;
    variation_e color_variation;
    particle_t *particle;
    sfClock *clock;
    int spawn_rate;
    disappear_e disappear;
} particle_engine_t;

// ****** Initialization ****** //

//  Create empty particle engine.
particle_engine_t *create_particle_system(void);

// ****** Set-up ****** //

void particle_set_origin(particle_engine_t *engine,
sfVector2f pos, type_e type, float rotation);

void particle_set_range(particle_engine_t *engine,
float range, float range_shift, float distance);

void particle_set_color_variation(particle_engine_t *engine,
                                variation_e variation);

void particle_set_move(particle_engine_t *engine,
float particle_speed, int spawn_rate, float rotate_speed);

void particle_set_sizerange(particle_engine_t *engine,
float min, float max, variation_e variation);

void particle_set_disappear(particle_engine_t *engine,
                                disappear_e disappear);

// ****** Add ****** //

void particle_add_sprite(particle_engine_t *engine, sfSprite *sprite);

void particle_add_color(particle_engine_t *engine, sfColor color);

void add_particle(particle_engine_t *engine);

// ****** Select ******* //

sfSprite *select_sprite(sprite_link_t *sprite_list, int sprite_nbr);

sfColor select_color(color_link_t *color_list, int color_nbr);

// ****** Manage ****** //

void manage_particle(window_t *win, particle_engine_t *engine,
                                                float elapsed_time);

void update_particle(particle_engine_t *engine, particle_t *particle,
                        float elapsed_time);

void delete_node(particle_t **particle, int node_nbr);

void draw_particle(sfRenderWindow *win, particle_t *particle);

// ****** Modify ******* //

void colorize_particle(particle_engine_t *engine, particle_t *particle);

void resize_particle(particle_engine_t *engine, particle_t *particle);

void disappear_particle(particle_engine_t *engine, particle_t *particle);

// ****** Delete ****** //

void check_delete_particle(particle_engine_t *engine, particle_t **particle);

#endif /* !PARTICULE_ENGINE_H_H */
