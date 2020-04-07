/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** swaps the content of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int save = 0;

    save = *a;
    *a = *b;
    *b = save;
}
