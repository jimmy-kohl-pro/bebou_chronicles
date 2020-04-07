/*
** EPITECH PROJECT, 2019
** my_printf_flag2.c
** File description:
** my_printf flag 2
*/

#include "../include/my.h"

int cflag(va_list list)
{
    char c = va_arg(list, int);

    my_putchar(c);
    return (2);
}

int sflag(va_list list)
{
    char *string = va_arg(list, char *);

    my_putstr(string);
    return (2);
}

int big_sflag(va_list list)
{
    char *str = va_arg(list, char *);
    int i = 0;

    while (i <= my_strlen(str)) {
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else if (str[i] < 32 || str[i] == 127) {
            my_putchar('\\');
            my_putzero(str[i]);
            my_putnbr_base(str[i], "01234567");
        }
    i++;
    }
    return (2);
}

int pflag(va_list list)
{
    long number = va_arg(list, long);

    my_putstr("0x");
    my_putnbr_base(number, "0123456789abcdef");
    return (2);
}

int bflag(va_list list)
{
    int number = va_arg(list, int);

    my_putnbr_base(number, "01");
    return (2);
}