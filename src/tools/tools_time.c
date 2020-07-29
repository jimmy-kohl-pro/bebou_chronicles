/*
** EPITECH PROJECT, 2020
** tools_time.c
** File description:
** tools time
*/

#include "basic.h"

void get_elapsed_time(float *time_elapsed, sfClock *clock)
{
    *time_elapsed = sfTime_asMicroseconds(
                        sfClock_restart(clock));
    *time_elapsed /= 10000;
}