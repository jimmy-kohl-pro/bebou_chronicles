/*
** EPITECH PROJECT, 2019
** my_printf_flag1.c
** File description:
** flag 1
*/

#include "../include/my.h"

int dflag(va_list list)
{
    int number = va_arg(list, int);

    my_put_nbr(number);
    return (2);
}

int oflag(va_list list)
{
    int number = va_arg(list, int);

    my_putnbr_base(number, "01234567");
    return (2);
}

int xflag(va_list list)
{
    int number = va_arg(list, int);

    my_putnbr_base(number, "0123456789abcdef");
    return (2);
}

int big_xflag(va_list list)
{
    int number = va_arg(list, int);

    my_putnbr_base(number, "0123456789ABCDEF");
    return (2);
}

int uflag(va_list list)
{
    unsigned long int number = va_arg(list, unsigned long int);

    my_putnbr_base(number, "0123456789");
    return (2);
}