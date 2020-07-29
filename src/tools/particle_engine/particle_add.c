/*
** EPITECH PROJECT, 2020
** particle_add.c
** File description:
** particle add component
*/

#include "tools.h"
#include "particle_engine.h"
#include "my.h"
#include "math.h"

void particle_add_sprite(particle_engine_t *engine, sfSprite *sprite)
{
    sprite_link_t *temp_list;

    if (!engine)
        return ;
    temp_list = my_calloc(sizeof(sprite_link_t));
    temp_list->sprite = sprite;
    temp_list->next = engine->sprite_list;
    engine->sprite_list = temp_list;
    engine->sprite_nbr += 1;
}

void particle_add_color(particle_engine_t *engine, sfColor color)
{
    color_link_t *temp_list;

    if (!engine)
        return ;
    temp_list = my_calloc(sizeof(color_link_t));
    temp_list->color = color;
    temp_list->next = engine->color_list;
    engine->color_list = temp_list;
    engine->color_nbr += 1;
}

void set_newpos_particle(particle_t *temp_par, particle_engine_t *engine)
{
    int lower = (engine->pos.x - (engine->range / 2));
    int upper = (engine->pos.x + (engine->range / 2));

    if (engine->type == DIVERGENT) {
        temp_par->pos = engine->pos;
        temp_par->destination.x = (cosf(engine->rotation) * engine->range_shift
        + -sinf(engine->rotation) * engine->distance) +
        (rand() % (upper - lower + 1) + lower);
        temp_par->destination.y = (sinf(engine->rotation) * engine->range_shift
        + cosf(engine->rotation) * engine->distance) + temp_par->pos.y;
    } else if (engine->type == LINEAR) {
        temp_par->pos.x = (rand() % (upper - lower + 1) + lower);
        temp_par->pos.y = engine->pos.y;
        temp_par->destination.x = (cosf(engine->rotation) * engine->range_shift
        + -sinf(engine->rotation) * engine->distance) + temp_par->pos.x;
        temp_par->destination.y = (sinf(engine->rotation) * engine->range_shift
        + cosf(engine->rotation) * engine->distance) + temp_par->pos.y;
    }
    sfSprite_setPosition(temp_par->sprite, fvec(temp_par->pos.x,
                                                temp_par->pos.y));
}

static void set_size(particle_t *temp_par, particle_engine_t *engine)
{
    float orig_size = sfSprite_getGlobalBounds(temp_par->sprite).width;
    float ratio;

    if (engine->size_min != engine->size_max
    && engine->size_variation == RANDOM)
        ratio = rand() % ((int)engine->size_max - (int)engine->size_min + 1)
                + (int)engine->size_min;
    else
        ratio = engine->size_max;
    sfSprite_setScale(temp_par->sprite, fvec(ratio / orig_size,
                                            ratio / orig_size));
}

void add_particle(particle_engine_t *engine)
{
    particle_t *temp_par = my_calloc(sizeof(particle_t));

    temp_par->sprite = sfSprite_copy(select_sprite(engine->sprite_list,
                                rand() % (engine->sprite_nbr + 1)));
    set_newpos_particle(temp_par, engine);
    if (engine->size_min != 0 || engine->size_max != 0)
        set_size(temp_par, engine);
    if (engine->color_nbr != 0 && engine->color_variation == RANDOM)
        sfSprite_setColor(temp_par->sprite, select_color(engine->color_list,
                                rand() % (engine->color_nbr + 1)));
    temp_par->next = engine->particle;
    engine->particle = temp_par;
}