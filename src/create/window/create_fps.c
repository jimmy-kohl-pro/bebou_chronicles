/*
** EPITECH PROJECT, 2020
** create_fps.c
** File description:
** create fps
*/

#include "basic.h"
#include "my.h"

fps_t *create_fps(void)
{
    fps_t *fps = my_calloc(sizeof(fps_t));
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");

    sfText_setFillColor(text, sfYellow);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, (float)1);
    sfText_setCharacterSize(text, 23);
    sfText_setFont(text, font);
    sfText_setString(text, "0");
    fps->text = text;
    fps->activated = 0;
    fps->clock = sfClock_create();
    fps->nbr = 0;
    return (fps);
}