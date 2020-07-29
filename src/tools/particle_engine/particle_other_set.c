/*
** EPITECH PROJECT, 2020
** particle_other_set.c
** File description:
** particle other setup
*/

#include "particle_engine.h"

void particle_set_disappear(particle_engine_t *engine,
                                disappear_e disappear)
{
    if (!engine)
        return ;
    engine->disappear = disappear;
}