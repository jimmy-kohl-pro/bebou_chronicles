/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** returns number
*/

#include "my.h"
#include "math.h"

long negativenumber(long number, long neg)
{
    if (neg % 2 != 0)
        number = number * -1;
    return (number);
}

long numbergetnbr(char *str, int i, long neg, long number)
{
    int j = 0;
    int d = 0;

    while (str[i] != '\0') {
        while (str[i] == '+' || str[i] == '-') {
            if (str [i] == '-')
                neg++;
            i++;
        }
        while (str[i] >= 48 && str[i] <= 57 && d == 0) {
            number = number * 10 + (str[i] - 48);
            i++;
            j = 1;
        }
        if (j != 0)
            break;
        d++;
        i++;
    }
    return (negativenumber(number, neg));
}

int my_getnbr(char *str)
{
    int i = 0;
    int d = 0;
    long fneg = 0;
    long fnumber = 0;
    int finalnumber = 0;
    long number = numbergetnbr(str, i, fneg, fnumber);

    if (number < 2147483647 && number > -2147483647) {
        finalnumber = number;
        return (finalnumber);
    } else
        return (0);
}

float my_getfloat(char *str, int decimal)
{
    float nbr = 0;
    int in = my_getnbr(str);
    float fn = (float)0;

    str_begin_last(&str, '.');
    fn = (float)my_getnbr(str);
    if (fn == (float)0 || decimal == 0)
        return (float)in;
    else
        return (float)in + (float)(fn / pow(10, decimal));
}