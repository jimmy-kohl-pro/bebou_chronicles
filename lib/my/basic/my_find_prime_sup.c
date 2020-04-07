/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** find prime
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = 2;

    while (i < nb) {
        if (nb % i == 0) {
            nb++;
            i = 2;
        } else {
            i++;
        }
    }
    return (nb);
}
