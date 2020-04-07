/*
** EPITECH PROJECT, 2020
** intro_fade.c
** File description:
** fade animation of intro
*/

#include "menu_h.h"
#include "tools.h"

static void animation_fade(window_t *win, intro_t *intro)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(intro->fade_clock)) < 3 &&
    intro->color.a > 0) {
        intro->color.a -= 1;
        sfRectangleShape_setFillColor(intro->fade, intro->color);
    }
    else if (sfTime_asSeconds(sfClock_getElapsedTime(intro->fade_clock)) > 4) {
        intro->color.a += 1;
        sfRectangleShape_setFillColor(intro->fade, intro->color);
    }
}

void fade_black(window_t *win, intro_t *intro)
{
    animation_fade(win, intro);
    disp_text(win->window, intro->name);
    sfRenderWindow_drawRectangleShape(win->window, intro->fade, NULL);
    if (intro->color.a >= 255)
        intro->activated = (intro->activated + 1) % 2;
}