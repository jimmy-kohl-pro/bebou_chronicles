/*
** EPITECH PROJECT, 2019
** my_str_islower.c
** File description:
** string is lower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
