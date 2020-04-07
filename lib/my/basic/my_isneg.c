/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** N if negative P if negaftive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else if (n < 0) {
        my_putchar('N');
    }
}
