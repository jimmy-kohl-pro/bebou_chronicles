/*
** EPITECH PROJECT, 2019
** creat_window.c
** File description:
** main of MyHunter, just start the game
*/

#include "csfml_basic.h"

window_t *init_window(int height, float ratio, char *name, int bar)
{
    window_t *win = my_calloc(sizeof(window_t));

    if (!win)
        return (NULL);
    if (bar == -1)
        bar = sfClose | sfResize | sfTitlebar;
    win->font = NULL;
    win->mode.bitsPerPixel = 32;
    win->mode.height = height;
    win->mode.width = height * ratio;
    win->window = sfRenderWindow_create(win->mode, name, bar, NULL);
    if (!win->window) {
        my_printf("%s[ERR]%s Cannot create window.%s\n",
        BOLDRED, YELLOW, RESET);
        return (NULL);
    }
    return (win);
}