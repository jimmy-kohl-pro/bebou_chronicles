/*
** EPITECH PROJECT, 2020
** my_array.c
** File description:
** array managment
*/

#include "my.h"

int my_arraylen(char **array)
{
    int i = -1;

    while (array[++i]);
    return (i);
}

int my_print_array(char **array)
{
    int i = -1;

    while (array[++i]) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
    return (0);
}

int free_array(char **array)
{
    int i = -1;

    if (!array)
        return 0;
    while (array[++i])
        free(array[i]);
    free(array[i]);
    return (0);
}