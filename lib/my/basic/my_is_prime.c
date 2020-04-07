/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** returns square root
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    while ((nb % i) != 0) {
        i++;
    }
    if (i == nb) {
        return (1);
    } else {
        return (0);
    }
}
