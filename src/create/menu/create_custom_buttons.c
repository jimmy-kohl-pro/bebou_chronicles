/*
** EPITECH PROJECT, 2020
** create_custom_buttons.c
** File description:
** deals with custom buttons
*/

#include "menu_h.h"
#include "tools.h"
#include "my.h"

static void set_button_custom(sprite_t *sprite_button)
{
    sfSprite_setTexture(sprite_button->sprite, sprite_button->texture,
        sfTrue);
    sfSprite_setTextureRect(sprite_button->sprite, sprite_button->rect);
    sfSprite_setOrigin(sprite_button->sprite,
                        fvec((float)sprite_button->rect.width / 2,
                        (float)sprite_button->rect.height / 2));
    sfSprite_setPosition(sprite_button->sprite, sprite_button->pos);
}

button_t *create_menu_custom(window_t *win)
{
    button_t *custom = my_calloc(sizeof(button_t));

    custom->img = malloc(sizeof(sprite_t));
    custom->img->texture = sfTexture_createFromFile(
                                    "assets/image/custom_button.png", NULL);
    custom->img->sprite = sfSprite_create();
    custom->img->rect.left = 0;
    custom->img->rect.top = 0;
    custom->img->rect.width = 290;
    custom->img->rect.height = 120;
    custom->img->pos.x = (float)win->mode.width / 1.25;
    custom->img->pos.y = (float)win->mode.height / 1.9;
    if (!custom->img->texture || !custom->img->sprite)
        return NULL;
    set_button_custom(custom->img);
    custom->img->hitbox = sfSprite_getGlobalBounds(custom->img->sprite);
    return custom;
}

sprite_t *create_help_sprite(void)
{
    sprite_t *help_sprite = my_calloc(sizeof(sprite_t));

    help_sprite->clock = sfClock_create();
    help_sprite->texture = sfTexture_createFromFile(
                        "assets/image/help.png", NULL);
    help_sprite->sprite = sfSprite_create();
    help_sprite->pos = ORIGIN;
    help_sprite->rect.left = 0;
    help_sprite->rect.top = 0;
    help_sprite->rect.width = 1920;
    help_sprite->rect.height = 1080;
    sfSprite_getGlobalBounds(help_sprite->sprite);
    if (!help_sprite->texture || !help_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(help_sprite->sprite,
        help_sprite->texture, sfTrue);
    sfSprite_setTextureRect(help_sprite->sprite, help_sprite->rect);
    sfSprite_setPosition(help_sprite->sprite, help_sprite->pos);
    return help_sprite;
}

help_t *create_help(void)
{
    help_t *help = my_calloc(sizeof(help_t));

    help->activated = 0;
    help->sprite = create_help_sprite();
    return help;
}

button_t *create_menu_help(window_t *win)
{
    button_t *help = my_calloc(sizeof(button_t));

    help->img = malloc(sizeof(sprite_t));
    help->img->texture = sfTexture_createFromFile(
                                    "assets/image/interrogation.png", NULL);
    help->img->sprite = sfSprite_create();
    help->img->rect.left = 0;
    help->img->rect.top = 0;
    help->img->rect.width = 36;
    help->img->rect.height = 61;
    help->img->pos.x = (float)win->mode.width - 40;
    help->img->pos.y = (float)win->mode.height - 70;
    if (!help->img->texture || !help->img->sprite)
        return NULL;
    set_button_custom(help->img);
    help->img->hitbox = sfSprite_getGlobalBounds(help->img->sprite);
    return help;
}