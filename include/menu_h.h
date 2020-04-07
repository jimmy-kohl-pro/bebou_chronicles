/*
** EPITECH PROJECT, 2019
** menu.h
** File description:
** menu header
*/

#ifndef MENU_H_
#define MENU_H_

#include "basic.h"

typedef enum state_n
{
    MAIN,
    OPTIONS,
} state_e;

typedef struct intro_s
{
    sfBool activated;
    sprite_t *bg;
    sfRectangleShape *fade;
    sfColor color;
    sfClock *fade_clock;
    text_t *name;
} intro_t;

typedef struct button_s
{
    sprite_t *img;
} button_t;

typedef struct menu_s
{
    intro_t *intro;
    sprite_t *bg;
    button_t *button_play;
    button_t *button_exit;
    button_t *button_options;
    button_t *button_map;
    state_e state;
} menu_t;

//************ CREATE MENU AND INTRO ************//

// Initialization of the windows
window_t *create_window(int height, float ratio, char *name, int bar);
// Return a menu_t with all the value inside
menu_t *create_menu(window_t *win);
// Create intro
intro_t *create_intro(window_t *win);

sprite_t *create_menu_background(window_t *win);

button_t *create_menu_play(window_t *win);

button_t *create_menu_options(window_t *win);

button_t *create_menu_exit(window_t *win);

button_t *create_menu_map(window_t *win);

//************ INTRO ************//

// Display intro
void display_intro(window_t *win, intro_t *intro);
// Intro fade
void fade_black(window_t *win, intro_t *intro);


//************ MENU ************//

// Menu loop
int menu(window_t *win);
// Main menu
int main_menu(window_t *win, menu_t *menu);
// Event main menu
int main_menu_event(window_t *win, menu_t *menu_s);
// Options menu
int options_menu(window_t *win, menu_t *menu);
// Options event menu
void options_menu_event(window_t *win , menu_t *menu);

#endif  /* MENU_H */
