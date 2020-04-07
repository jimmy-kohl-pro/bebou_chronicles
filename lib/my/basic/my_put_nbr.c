/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays the number given as parameter
*/

#include "my.h"

int get_char_nbr(int nbr)
{
    int div = 1;
    int power = 10;
    int char_nbr = 0;

    if (nbr < 0)
        char_nbr = -1;
    while (div != 0) {
        div = nbr / power;
        power *= 10;
        char_nbr++;
    }
    return (char_nbr);
}

int power(int nbr, int char_nbr)
{
    int i = 1;

    while (i < char_nbr) {
        nbr *= 10;
        i++;
    }
    return (nbr);
}

int neg(int nbr)
{
    if (nbr < 0) {
        nbr *= -1;
        my_putchar('-');
    }
    return (nbr);
}

int my_put_nbr(int nbr)
{
    nbr = neg(nbr);
    int i = 0;
    int char_nbr = get_char_nbr(nbr);
    int divider = power(1, char_nbr);
    int modified = nbr;

    while (i < char_nbr) {
        i++;
        my_putchar(48 + (modified / divider));
        modified = nbr - ((nbr / divider) * divider);
        divider = divider / 10;
        if (i == char_nbr) {
        }
    }
    return (0);
}

int my_putnbr_base(long number, char const *base)
{
    long rest = number;
    int i = 0;
    int len = my_strlen(base);
    char *result = malloc(sizeof(char const *) * my_intlen(number) * 3);

    while (rest > 0) {
        number = rest % len;
        rest /= len;
        result[i] = base[number];
        i++;
    }
    my_putstr(my_revstr(result));
    free(result);
    return (2);
}
