/*
** EPITECH PROJECT, 2020
** delete_particle2.c
** File description:
** delete parti
*/

#include "particle_engine.h"
#include <math.h>

int is_to_delete(particle_t **particle, particle_engine_t *engine)
{
    if (sqrtf(powf((*particle)->destination.x - (*particle)->pos.x, 2)
    + powf((*particle)->destination.y - (*particle)->pos.y, 2))
    <= engine->particle_speed)
        return SUCCESS;
    return FAIL;
}

void before_delete(particle_engine_t *engine, particle_t **particle,
                particle_t **node_delete, particle_t **save_particle)
{
    if (is_to_delete(particle, engine)) {
        *node_delete = (*particle);
        *save_particle = (*particle)->next;
        (*node_delete)->next = NULL;
        sfSprite_destroy((*node_delete)->sprite);
        free(*node_delete);
    }
}

void in_delete(particle_engine_t *engine, particle_t **particle,
                particle_t **node_delete, particle_t **new_next)
{
    if (is_to_delete(particle, engine)) {
        (*node_delete) = (*particle)->next;
        (*new_next) = (*particle)->next->next;
        (*particle)->next = (*new_next);
        (*node_delete)->next = NULL;
        sfSprite_destroy((*node_delete)->sprite);
        free((*node_delete));
    }
}

void after_delete(particle_engine_t *engine, particle_t **particle,
                particle_t **node_delete)
{
    if (is_to_delete(particle, engine)) {
        (*node_delete) = (*particle)->next;
        (*particle)->next = NULL;
        (*node_delete)->next = NULL;
        sfSprite_destroy((*node_delete)->sprite);
        free((*node_delete));
    }
}

void check_delete_particle(particle_engine_t *engine, particle_t **particle)
{
    particle_t *save_particle = *particle;
    particle_t *new_next = NULL;
    particle_t *node_delete = NULL;

    if (!*particle)
        return ;
    before_delete(engine, particle, &node_delete, &save_particle);
    while ((*particle)->next) {
        if (!(*particle)->next->next)
            break;
        in_delete(engine, particle, &node_delete, &new_next);
        (*particle) = (*particle)->next;
    }
    if (!(*particle)->next) {
        (*particle) = save_particle;
        return;
    }
    after_delete(engine, particle, &node_delete);
    (*particle) = save_particle;
}