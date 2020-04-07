/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** counts and returns number of characters in string
*/

#include "my.h"

int my_maxline(char *str)
{
    int i = 0;
    int max = 0;
    int count;

    while (str[i] != '\0') {
        count = 0;
        while (str[i] != '\n') {
            i++;
            count++;
        }
        if (count > max)
            max = count;
        i++;
    }
    return (max);
}

int my_linenbr(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int *my_lenline(char *str)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int *line_len = malloc(sizeof(int) * my_linenbr(str));

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            line_len[j] = count;
            count = 0;
            j++;
        }
        count++;
        i++;
    }
    return (line_len);
}
