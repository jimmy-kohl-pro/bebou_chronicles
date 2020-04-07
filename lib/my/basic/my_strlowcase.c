/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** string is upper
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;
    int up = 'a' - 'A';

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += up;
        i++;
    }
    return (str);
}
