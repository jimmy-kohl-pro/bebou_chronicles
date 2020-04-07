/*
** EPITECH PROJECT, 2019
** check_alloc.c
** File description:
** check if there is error memory
*/

#include "csfml_basic.h"

int error_alloc(void)
{
    my_printf("%d[ERR]%dMemory Error%d", RED, BOLDYELLOW, RESET);
    return (84);
}

int check_alloc(void **ptrs, int total)
{
    int i = 0;

    if (ptrs == NULL)
        return (error_alloc());
    while (i < total) {
        if (ptrs[i] == NULL)
            return (error_alloc());
        i++;
    }
    return (0);
}