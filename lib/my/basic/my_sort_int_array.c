/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** sort int array
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int tmp = 0;
    int i = 0;

    while (i != size) {
        if (i > 0 && array[i] < array[i - 1]) {
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            i -= 2;
        }
        i++;
    }
}
