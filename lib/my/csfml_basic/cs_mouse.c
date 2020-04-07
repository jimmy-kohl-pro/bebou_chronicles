/*
** EPITECH PROJECT, 2019
** creat_window.c
** File description:
** main of MyHunter, just start the game
*/

#include "csfml_basic.h"

sfVector2i mouse_setpos(window_t *window)
{
    if (window != NULL)
        window->mouse = sfMouse_getPositionRenderWindow(window->window);
    return (window->mouse);
}