/*
** EPITECH PROJECT, 2020
** tools_fps.c
** File description:
** tools fps
*/

#include "basic.h"
#include "my.h"

void manage_fps(window_t *win, fps_t *fps)
{
    if (!fps->activated)
        return ;
    fps->nbr++;
    if (sfTime_asSeconds(sfClock_getElapsedTime(fps->clock)) >= 1) {
        sfText_setString(fps->text, int_str(fps->nbr));
        fps->nbr = 0;
        sfClock_restart(fps->clock);
    }
    sfRenderWindow_drawText(win->window, fps->text, NULL);
}