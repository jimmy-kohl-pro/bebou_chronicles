/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
**  put *str to a **str with a separator
*/

#include "my.h"

int is_char(char *str)
{
    if (*str >= 32 && *str <= 126)
        return (1);
    return (0);
}

int is_separator(char *str, char *separators)
{
    register int i = 0;

    while (separators[i] != '\0')
        if (*str == separators[i++])
            return (1);
    return (0);
}

char **my_str_to_word_array(char *str, char *separators)
{
    char **result = my_calloc(sizeof(char *) * (my_strlen(str) + 1));
    int i = 0;
    char *temp_str = str;
    int c = 0;
    int w = -1;

    while (*temp_str != '\0') {
        result[++w] = my_calloc(sizeof(char) * my_strlen(str) + 1);
        while (is_separator(temp_str, separators) && *temp_str != '\0')
            *temp_str++;
        for (c = 0; !is_separator(temp_str, separators) &&
        *temp_str != '\0'; *temp_str++)
            result[w][c++] = *temp_str;
        while (is_separator(temp_str, separators) && *temp_str != '\0')
            *temp_str++;
        result[w][c] = '\0';
    }
    result[w + 1] = NULL;
    return (result);
}