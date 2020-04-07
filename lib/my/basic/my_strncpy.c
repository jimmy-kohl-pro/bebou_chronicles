/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** function that copies n char of a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (n > 0 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
        n--;
    }
    if (n > 0) {
        dest[i] = '\0';
        return (dest);
    }
}
