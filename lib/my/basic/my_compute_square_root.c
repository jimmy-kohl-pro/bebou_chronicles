/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** returns square root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 1;

    while (i * i != nb) {
        i++;
        if (nb <= i) {
            return (0);
        }
    }
    return (i);
}
