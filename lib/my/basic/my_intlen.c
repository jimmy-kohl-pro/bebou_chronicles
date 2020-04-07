/*
** EPITECH PROJECT, 2019
** my_intlen.c
** File description:
** return len of an int
*/

int my_intlen(int number)
{
    int end = 0;

    while (number > 0) {
        number /= 10;
        end++;
    }
    return (end);
}