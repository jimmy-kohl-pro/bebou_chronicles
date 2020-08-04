/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** string cat
*/

#include "my.h"
#include <stdarg.h>

char *my_strmasscat(int nbr_str, char const *str, ...)
{
    va_list list;
    char *cat = NULL;
    char *new_str = NULL;

    va_start(list, str);
    cat = my_strdup(str);
    for (int i = 1; i < nbr_str; i++) {
        new_str = va_arg(list, char *);
        cat = my_strcat(cat, new_str);
    }
    va_end(list);
    return cat;
}

char *my_strthreecat(char const *src1, char const *src2, char const *src3)
{
    char *str = NULL;
    int i = 0;
    int i_s = 0;

    if (!src1 || !src2 || !src3)
        return (NULL);
    str = malloc(sizeof(char) *
    (my_strlen(src1) + my_strlen(src2) + my_strlen(src3) + 1));
    while (src1[i_s] != '\0')
        str[i++] = src1[i_s++];
    i_s = 0;
    while (src2[i_s] != '\0')
        str[i++] = src2[i_s++];
    i_s = 0;
    while (src3[i_s] != '\0')
        str[i++] = src3[i_s++];
    str[i] = '\0';
    return (str);
}

char *my_strcat(char const *src1, char const *src2)
{
    char *str = NULL;
    int i = 0;
    int i_s = 0;

    if (!src1 || !src2)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 1));
    while (src1[i_s] != '\0')
        str[i++] = src1[i_s++];
    i_s = 0;
    while (src2[i_s] != '\0')
        str[i++] = src2[i_s++];
    str[i] = '\0';
    return (str);
}
