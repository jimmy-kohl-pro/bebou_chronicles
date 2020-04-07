/*
** EPITECH PROJECT, 2020
** my_stradvanced.c
** File description:
** str advanced functions
*/

#include "my.h"

int count_ascii(char *str, char c)
{
    int i = -1;
    int count = 0;

    while (str[++i])
        if (str[i] == c)
            count++;
    return (count);
}

int where_last_char(char *str, char c)
{
    int i = 0;
    int len = 0;

    while (str[i++] != '\0')
        if (str[i] == c)
            len = i;
    return (len);
}

int str_begin_last(char **str, char c)
{
    int len = 0;
    int i = 0;
    char *result = NULL;

    while ((*str)[i++] != '\0')
        if ((*str)[i] == c)
            len = i;
    i = 0;
    while (i++ <= len && **str != '\0')
        (*str)++;
    return (0);
}

char *str_until_last(char *str, char c)
{
    int len = 0;
    int i = 0;
    char *result = NULL;

    while (str[i++] != '\0')
        if (str[i] == c)
            len = i;
    i = -1;
    result = malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    while (++i < len)
        result[i] = str[i];
    result[i] = '\0';
    return (result);
}