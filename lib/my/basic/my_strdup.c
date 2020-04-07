/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** allocate memory and copy string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int len = my_strlen(src);

    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    while (i < len)  {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
