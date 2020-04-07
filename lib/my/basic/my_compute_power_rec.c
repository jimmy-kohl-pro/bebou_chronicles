/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** return number
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int value;

    if (p < 0 || p >= 13)
        return (0);
    if (p == 0)
        return (1);
    value = nb * my_compute_power_rec(nb, p - 1);
    return (value);
}
