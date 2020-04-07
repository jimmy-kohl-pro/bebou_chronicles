/*
** EPITECH PROJECT, 2019
** int_str.c
** File description:
** my_hunter
*/

#include <stdlib.h>

char *int_str(int n)
{
    char *str;
    int i = 0;
    int tmp = n;

    while (n > 0) {
        n /= 10;
        i++;
    }
    str = malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    while (--i >= 0) {
        str[i] = tmp % 10 + 48;
        tmp /= 10;
    }
    return (str);
}