/*
** EPITECH PROJECT, 2020
** create_window.c
** File description:
** create window
*/

#include "basic.h"
#include "colors.h"
#include "my.h"

window_t *create_window(int height, float ratio, char *name, int bar)
{
    window_t *win = my_calloc(sizeof(window_t));

    if (!win)
        return (NULL);
    if (bar == -1)
        bar = sfClose | sfResize | sfTitlebar;
    win->mode.bitsPerPixel = 32;
    win->mode.height = height;
    win->mode.width = height * ratio;
    win->window = sfRenderWindow_create(win->mode, name, bar, NULL);
    win->fps = create_fps();
    if (!win->window) {
        my_printf("%s[ERR]%s Cannot create window.%s\n",
        BOLDRED, YELLOW, RESET);
        return (NULL);
    }
    sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
    sfRenderWindow_setFramerateLimit(win->window, 90);
    return (win);
}