/*
** EPITECH PROJECT, 2020
** display_custom_buttons.c
** File description:
** deals with display and states of custom buttons
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static void set_button(sprite_t *sprite_button)
{
    sfSprite_setTexture(sprite_button->sprite, sprite_button->texture,
        sfTrue);
    sfSprite_setTextureRect(sprite_button->sprite, sprite_button->rect);
    sfSprite_setOrigin(sprite_button->sprite,
                        fvec((float)sprite_button->rect.width / 2,
                        (float)sprite_button->rect.height / 2));
    sfSprite_setPosition(sprite_button->sprite, sprite_button->pos);
}

void display_custom_buttons(window_t *win, custom_t *custom)
{
    set_button(custom->c_buttons->b_head->img);
    set_button(custom->c_buttons->b_face->img);
    set_button(custom->c_buttons->b_shirt->img);
    set_button(custom->c_buttons->b_pants->img);
    set_button(custom->c_buttons->b_shoes->img);
    display_sprite(win->window, custom->c_buttons->b_head->img);
    display_sprite(win->window, custom->c_buttons->b_face->img);
    display_sprite(win->window, custom->c_buttons->b_shirt->img);
    display_sprite(win->window, custom->c_buttons->b_pants->img);
    display_sprite(win->window, custom->c_buttons->b_shoes->img);
    display_sprite(win->window, custom->c_buttons->c_left->img);
    display_sprite(win->window, custom->c_buttons->c_right->img);
}

static void update_custom_button_state(c_button_t *allbuttons)
{
    allbuttons->b_head->img->rect.left = 215 * allbuttons->b_head->state;
    allbuttons->b_face->img->rect.left = 215 * allbuttons->b_face->state;
    allbuttons->b_shirt->img->rect.left = 215 * allbuttons->b_shirt->state;
    allbuttons->b_pants->img->rect.left = 215 * allbuttons->b_pants->state;
    allbuttons->b_shoes->img->rect.left = 215 * allbuttons->b_shoes->state;
}

int update_buttons(custom_t *custom, int which_part)
{
    if (which_part == 0)
        custom->c_buttons->b_head->state = CLICKED;
    if (which_part == 1)
        custom->c_buttons->b_face->state = CLICKED;
    if (which_part == 2)
        custom->c_buttons->b_shirt->state = CLICKED;
    if (which_part == 3)
        custom->c_buttons->b_pants->state = CLICKED;
    if (which_part == 4)
        custom->c_buttons->b_shoes->state = CLICKED;
    update_custom_button_state(custom->c_buttons);
    return SUCCESS;
}
