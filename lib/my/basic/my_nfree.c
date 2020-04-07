/*
** EPITECH PROJECT, 2019
** nfree.c
** File description:
** free and NULL
*/

#include "my.h"

void nfree(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
}