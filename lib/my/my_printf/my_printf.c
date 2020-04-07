/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** coding my_printf function of lib C
*/

#include "../include/my.h"

int is_flag(const char *str, int j)
{
    char *flags = "dioxXucsSp%b";
    int i = -1;
    int save = 0;

    while (str[j + 1] == ' ') {
        j++;
        save = 1;
    }
    if (save == 1)
        my_putchar(' ');
    while (flags[++i]) {
        if (flags[i] == str[j + 1])
            return (i);
    }
    return (-1);
}

int my_printf(const char *str, ...)
{
    int i = 0;
    int number;
    int len = my_strlen(str);
    char *string;
    va_list list;
    int (*fs[13])(va_list list) = {&dflag, &dflag, &oflag, &xflag, &big_xflag,
    &uflag, &cflag, &sflag, &big_sflag, &pflag, &perflag, &bflag, 0};

    va_start(list, str);
    while (i < len) {
        while (str[i] == '%' && is_flag(str, i) != -1) {
            while (str[i + 1] == ' ')
                i++;
        i += (*fs[is_flag(str, i)])(list);
    }
    my_putchar(str[i]);
    i++;
    }
    va_end(list);
}
