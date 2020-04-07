/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** string n cmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n - 1 && s1[i] == s2[i] && s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}