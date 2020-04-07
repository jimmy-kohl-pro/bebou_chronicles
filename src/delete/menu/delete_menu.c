/*
** EPITECH PROJECT, 2020
** delete_menu.c
** File description:
** delete and free menu objects
*/

#include "menu_h.h"

static void delete_buttons(button_t *play, button_t *exit, button_t *options)
{
    delete_sprite(play->img);
    delete_sprite(exit->img);
    delete_sprite(options->img);
    free(play);
    free(exit);
    free(options);
    play = NULL;
    exit = NULL;
    options = NULL;
}

static void delete_intro(intro_t *intro)
{
    delete_sprite(intro->bg);
    intro->bg = NULL;
    sfRectangleShape_destroy(intro->fade);
    sfClock_destroy(intro->fade_clock);
    sfText_destroy(intro->name->text);
    sfFont_destroy(intro->name->font);
    free(intro->name->str);
    free(intro->name);
    intro->name = NULL;
    free(intro);
    intro = NULL;
}

void delete_menu(menu_t *menu)
{
    delete_intro(menu->intro);
    delete_sprite(menu->bg);
    delete_menu_buttons(menu->button_play, menu->button_exit,
                    menu->button_options);
    free(menu);
    menu = NULL;
}