/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** find str
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int end = my_strlen(to_find);

    if (*str == '\0')
        return (NULL);
    while (str[i] != to_find[i] && str[i] != '\0')
        str++;
    if (str[i] != '\0')
        while (str[i] == to_find[i] && str[i] != '\0' && to_find[i] != '\0') {
            i++;
            if (i == end)
                return (str);
            else if (str[i] != '\0')
                return (my_strstr(str + 1, to_find));
            else
                return (NULL);
        } else
        return (NULL);
}
