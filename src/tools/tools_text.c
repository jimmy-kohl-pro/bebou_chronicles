/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** text
*/

#include "basic.h"

void disp_text(sfRenderWindow *win, text_t *text)
{
    sfText_setString(text->text, text->str);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setColor(text->text, text->color);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, text->pos);
    sfRenderWindow_drawText(win, text->text, NULL);
}