/*
** EPITECH PROJECT, 2019
** creat_window.c
** File description:
** main of MyHunter, just start the game
*/

#include "csfml_basic.h"

sfText *init_text(char *text_content, sfFont *font, sfColor color)
{
    sfText *text = sfText_create();

    if (!text || font || !text_content) {
        my_printf("%s[ERR]%s Fail to create text%s\n", BOLDRED, YELLOW, RESET);
        return FAIL;
    }
    sfText_setString(text, text_content);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    return (text);
}

void print_text(sfText *text, sfVector2f pos, window_t *win, unsigned int size)
{
    if (!text || !win->font) {
        my_printf("%s[ERR]%s Fail to print text%s\n", BOLDRED, YELLOW, RESET);
        return ;
    }
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(win->window, text, NULL);
}

