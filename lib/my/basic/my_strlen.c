/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** counts and returns number of characters in string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
