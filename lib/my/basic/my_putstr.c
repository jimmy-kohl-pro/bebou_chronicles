/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** displays characters of a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
