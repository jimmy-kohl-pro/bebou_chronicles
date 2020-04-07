/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** string is upper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (1);
    }
    return (1);
}
