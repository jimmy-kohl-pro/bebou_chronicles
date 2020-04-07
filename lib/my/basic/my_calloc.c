/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** return number
*/

#include "my.h"

void *my_memset(char *ptr, int value, int size)
{
    int i = 0;

    if (ptr == NULL)
        return (NULL);
    while (i < size)
        ptr[i++] = value;
    return (ptr);
}

void *my_calloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL)
        return (NULL);
    ptr = my_memset(ptr, 0, size);
    return (ptr);
}