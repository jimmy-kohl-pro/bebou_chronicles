/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_opt_text
*/

#include <stdlib.h>
#include "menu_h.h"
#include "tools.h"
#include "my.h"

text_t *create_volume_text(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 140;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = int_str(win->volume);
    name->pos = (sfVector2f) {win->mode.width / 1.65,
    win->mode.height / 2.8};
    name->color = sfBlack;
    return (name);
}

text_t *create_volume_name(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 140;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = "Volume :";
    name->pos = (sfVector2f) {win->mode.width / 8,
    win->mode.height / 2.8};
    name->color = sfBlack;
    return (name);
}

text_t *create_se_text(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 140;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = "ON";
    name->pos = (sfVector2f) {win->mode.width / 2,
    win->mode.height / 2.1};
    name->color = sfGreen;
    return (name);
}

text_t *create_se_name(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 140;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = "Se :";
    name->pos = (sfVector2f) {win->mode.width / 3.5,
    win->mode.height / 2.1};
    name->color = sfBlack;
    return (name);
}