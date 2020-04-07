/*
** EPITECH PROJECT, 2019
** my_printf_flag3.c
** File description:
** my_printf flag 3
*/

#include "../include/my.h"

int perflag(va_list list)
{
    my_putchar('%');

    return (2);
}

int my_putzero(char str)
{
    if (str == 0)
        my_putstr("000");
    if (str <= 7)
        my_putstr("00");
    if (str <= 31)
        my_putchar('0');
}