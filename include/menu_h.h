/*
** EPITECH PROJECT, 2019
** menu.h
** File description:
** menu header
*/

#ifndef MENU_H_
#define MENU_H_

#include "basic.h"
#include "save.h"

typedef enum state_n
{
    MAIN,
    OPTIONS,
    SAVE
} state_e;

typedef struct intro_s
{
    sfBool activated;
    sprite_t *bg;
    sfRectangleShape *fade;
    sfColor color;
    sfClock *fade_clock;
    text_t *name;
    sfMusic *bg_sound;
    sfClock *clock_loop;
    float time_elapsed;
} intro_t;

typedef struct msg_s
{
    sfSprite *background;
    button_t *button_1;
    button_t *button_2;
    text_t *content;
    int activated;
    int param;
} msg_t;

typedef struct help_s
{
    sprite_t *sprite;
    int activated;
} help_t;

typedef struct menu_s
{
    intro_t *intro;
    sprite_t *bg;
    sprite_t *logo;
    button_t *help;
    button_t *button_play;
    button_t *button_exit;
    button_t *button_options;
    button_t *button_map;
    button_t *button_volume_minus;
    button_t *button_volume_plus;
    button_t *button_opt_apply;
    button_t *button_opt_se;
    button_t *b_slot1;
    button_t *b_slot2;
    button_t *b_slot3;
    button_t *b_ret;
    text_t *volume;
    text_t *volume_name;
    text_t *se_text;
    text_t *se_name;
    sfMusic *bg_sound;
    msg_t *msg;
    file_save_t *fsave;
    state_e state;
    file_save_t *saves;
    help_t *help_page;
    float time_elapsed;
    sfClock *clock_loop;
} menu_t;

//************ CREATE MENU AND INTRO ************//

// Initialization of the windows
window_t *create_window(int height, float ratio, char *name, int bar);
// Return a menu_t with all the value inside
menu_t *create_menu(window_t *win);
// Create intro
intro_t *create_intro(window_t *win);

sprite_t *create_menu_background(void);

sprite_t *create_logo(void);

button_t *create_menu_play(window_t *win);

button_t *create_menu_custom(window_t *win);

button_t *create_menu_options(window_t *win);

button_t *create_menu_exit(window_t *win);

button_t *create_menu_map(window_t *win);

help_t *create_help(void);

button_t *create_volume_minus(window_t *win);

button_t *create_volume_plus(window_t *win);

button_t *create_apply_options(window_t *win);

button_t *create_se_options(window_t *win);

text_t *create_volume_text(window_t *win);

text_t *create_volume_name(window_t *win);

text_t *create_se_text(window_t *win);

text_t *create_se_name(window_t *win);

button_t *create_menu_help(window_t *win);

void apply_menu_buttons_states(button_t *b_play, button_t *b_opt, \
    button_t *b_exit);

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
// Load save menu
int menu_loop_save(window_t *win, menu_t *menu);
//Save Events
int menu_event_save(window_t *win, menu_t *menu);
// Change the sound_effect status
void update_se(window_t *win, menu_t *menu);
// check mouse position for button state
void check_menu_mouse_position(window_t *win,
button_t *b_play, button_t *b_opt, button_t *b_exit);
int check_menu_mouse_position_2(window_t *win, button_t *custom_button);

// HITBOX FUNCS //

int mouse_hitbox_no_sprite(window_t *win, sfVector2f pos, sfIntRect rect);

int mouse_hitbox(window_t *win, sprite_t sprite);

int mouse_hitbox_view(window_t *win, sprite_t sprite, sfView *view);

#endif  /* MENU_H */
