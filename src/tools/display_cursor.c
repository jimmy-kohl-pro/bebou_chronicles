/*
** EPITECH PROJECT, 2020
** display_cursor.c
** File description:
** display mouse
*/

#include "basic.h"
#include "particle_engine.h"

void display_cursor(window_t *win, float elapsed_time)
{
        sfSprite_setPosition(win->cursor,
        (sfVector2f){(float)win->mouse.x, (float)win->mouse.y});
        win->mouse_particle->pos = sfSprite_getPosition(win->cursor);
        manage_particle(win, win->mouse_particle, elapsed_time);
        sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
}