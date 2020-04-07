/*
** EPITECH PROJECT, 2020
** delete_window.c
** File description:
** delete and free window and window_t struct
*/

#include "basic.h"
#include <stdlib.h>

void delete_window(window_t *win)
{
    sfRenderWindow_destroy(win->window);
    free(win);
    win = NULL;
}