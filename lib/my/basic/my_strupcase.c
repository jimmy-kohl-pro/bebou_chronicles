/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** string is upper
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;
    int up = 'A' - 'a';

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += up;
        i++;
    }
    return (str);
}
