/*
** EPITECH PROJECT, 2020
** create_text_dialogue.c
** File description:
** my_rpg
*/

#include "game.h"
#include "my.h"
#include "tools.h"

text_t *create_text_struct_dialogue(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 30;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = NULL;
    name->pos = (sfVector2f) {win->mode.width / 2,
    win->mode.height / 2.1};
    name->color = sfBlack;
    return (name);
}