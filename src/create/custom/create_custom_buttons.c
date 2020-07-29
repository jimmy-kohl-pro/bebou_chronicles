/*
** EPITECH PROJECT, 2020
** create_custom_buttons.c
** File description:
** create buttons of custom menu
*/

#include "menu_h.h"
#include "tools.h"
#include "my.h"

void init_custom_basics(custom_t *custom)
{
    custom->face_id = 0;
    custom->hair_id = 0;
    custom->shirt_id = 0;
    custom->pants_id = 0;
    custom->pants_id = 0;
    custom->face_nb = 3;
    custom->hair_nb = 1;
    custom->shirt_nb = 2;
    custom->pants_nb = 2;
    custom->shoes_nb = 1;
    sfSprite_setColor(custom->face[0]->sprite, (sfColor){0, 0, 0, 0});
    sfSprite_setColor(custom->hair[0]->sprite, (sfColor){0, 0, 0, 0});
    sfSprite_setColor(custom->shirt[0]->sprite, (sfColor){0, 0, 0, 0});
    sfSprite_setColor(custom->pants[0]->sprite, (sfColor){0, 0, 0, 0});
    sfSprite_setColor(custom->shoes[0]->sprite, (sfColor){0, 0, 0, 0});
}

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

button_t *create_custom_button(window_t *win, int y, int top)
{
    button_t *button = my_calloc(sizeof(button_t));

    button->img = malloc(sizeof(sprite_t));
    button->img->texture = sfTexture_createFromFile(
                                    "assets/custom/custom_buttons.png", NULL);
    button->img->sprite = sfSprite_create();
    button->img->rect.left = 0;
    button->img->rect.top = top;
    button->img->rect.width = 216;
    button->img->rect.height = 90;
    button->img->pos.x = (float)win->mode.width / 1.40;
    button->img->pos.y = (float)win->mode.height / 3.0 + y;
    if (!button->img->texture || !button->img->sprite)
        return NULL;
    set_button(button->img);
    button->img->hitbox = sfSprite_getGlobalBounds(button->img->sprite);
    return button;
}

button_t *create_custom_cursor(char *filepath, int x)
{
    button_t *button = my_calloc(sizeof(button_t));

    button->img = malloc(sizeof(sprite_t));
    button->img->texture = sfTexture_createFromFile(filepath, NULL);
    button->img->sprite = sfSprite_create();
    button->img->rect.left = 0;
    button->img->rect.top = 0;
    button->img->rect.width = 26;
    button->img->rect.height = 33;
    button->img->pos.x = 837 + x;
    button->img->pos.y = 250;
    if (!button->img->texture || !button->img->sprite)
        return NULL;
    set_button(button->img);
    button->img->hitbox = sfSprite_getGlobalBounds(button->img->sprite);
    return button;
}

c_button_t *create_all_custom_buttons(window_t *win)
{
    c_button_t *all_buttons = my_calloc(sizeof(c_button_t));

    all_buttons->b_head = create_custom_button(win, 0, 0);
    all_buttons->b_face = create_custom_button(win, 90, 90);
    all_buttons->b_shirt = create_custom_button(win, 180, 180);
    all_buttons->b_pants = create_custom_button(win, 270, 270);
    all_buttons->b_shoes = create_custom_button(win, 360, 360);
    all_buttons->c_left = create_custom_cursor(
        "assets/custom/cursor_left.png", 0);
    all_buttons->c_right = create_custom_cursor(
        "assets/custom/cursor_right.png", 150);
    return all_buttons;
}
