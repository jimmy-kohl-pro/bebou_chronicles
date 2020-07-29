/*
** EPITECH PROJECT, 2019
** int_str.c
** File description:
** my_hunter
*/

#include <stdlib.h>
#include "my.h"
#include <math.h>

char *int_str(int n)
{
    char *str = NULL;
    int i = 0;
    int tmp = n;

    while (n > 0) {
        n /= 10;
        i++;
    }
    if (i == 0)
        return my_strdup("0");
    str = malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    while (--i >= 0) {
        str[i] = tmp % 10 + 48;
        tmp /= 10;
    }
    return (str);
}

char *float_str(float n, int decimal)
{
    char *str = NULL;
    int in = (float)n;
    float fn = n - (int)in;
    register int i = 0;

    if (fn == (float)0 || decimal == 0)
        return int_str(in);
    else
        return my_strthreecat(int_str(in), ".",
                                int_str((int)(fn * pow(10, decimal))));
}