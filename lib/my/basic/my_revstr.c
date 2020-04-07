/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverse a string
*/

#include "my.h"

int my_satan_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int save = 0;
    int end = my_strlen(str) - 1;

    while (i < end) {
        save = str[i];
        str[i] = str[end];
        str[end] = save;
        i++;
        end--;
    }
    return (str);
}
