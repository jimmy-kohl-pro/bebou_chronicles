/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_sound
*/

#include "menu_h.h"

void update_se(window_t *win, menu_t *menu)
{
    if (win->se_status) {
        menu->se_text->str = "OFF";
        menu->se_text->color = sfRed;
        win->se_status = 0;
    } else {
        menu->se_text->str = "ON";
        menu->se_text->color = sfGreen;
        win->se_status = 1;
    }
}

int but_se(window_t *win)
{
    sfMusic_stop(win->button_se);
    if (win->se_status)
        sfMusic_play(win->button_se);
    return SUCCESS;
}