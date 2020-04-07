/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** string cat
*/

#include "my.h"

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
