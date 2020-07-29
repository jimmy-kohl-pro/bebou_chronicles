/*
** EPITECH PROJECT, 2020
** delete_particle.c
** File description:
** delete particle
*/

#include "particle_engine.h"
#include <math.h>

void delete_node(particle_t **particle, int node_nbr)
{
    register int i = 0;
    particle_t *temp = *particle;
    particle_t *next;

    if (node_nbr == 0) {
        *particle = temp->next;
        free(temp);
        return;
    }
    for (i = 0; temp && i < node_nbr - 1; i++)
        temp = temp->next;
    next = temp->next->next;
    sfSprite_destroy(temp->next->sprite);
    free(temp->next);
    temp = next;
}

int check_a_particle(int particle_speed, particle_t *particle)
{
    particle_t *new_next = NULL;

    if (!particle)
        return FAIL;
    if (sqrtf(powf(particle->destination.x - particle->pos.x, 2)
    + powf(particle->destination.y - particle->pos.y, 2))
    <= particle_speed) {
        new_next = particle->next;
        sfSprite_destroy(particle->sprite);
        free(particle);
        particle = new_next;
        return SUCCESS;
    }
    return FAIL;
}