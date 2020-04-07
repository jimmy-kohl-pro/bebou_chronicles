/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** string cat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i + j] != '\0') {
        while (dest[i] != '\0') {
            i++;
        }
        while (j != nb) {
            dest[i + j] = src[j];
            j++;
        }
        dest[i + j] = '\0';
        return (dest);
    }
}
