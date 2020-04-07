/*
** EPITECH PROJECT, 2020
** create_intro.c
** File description:
** create intro animation
*/

#include "menu_h.h"
#include "tools.h"
#include "my.h"

static sprite_t *init_bg(void)
{
    sprite_t *bg = my_calloc(sizeof(sprite_t));

    bg->clock = sfClock_create();
    bg->texture = sfTexture_createFromFile("assets/image/intro.png", NULL);
    bg->sprite = sfSprite_create();
    bg->pos = ORIGIN;
    bg->rect.left = 0;
    bg->rect.top = 0;
    bg->rect.width = 500;
    bg->rect.height = 288;
    if (!bg->texture || !bg->sprite)
        return FAIL;
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    sfSprite_setTextureRect(bg->sprite, bg->rect);
    return (bg);
}

static text_t *init_intro_text(window_t *win)
{
    text_t *name = my_calloc(sizeof(text_t));

    name->text = sfText_create();
    name->size = 140;
    name->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    name->str = "STUDIO BEBOU";
    name->pos = fvec((float)win->mode.width / 10,
    (float)win->mode.height / 2);
    name->color = sfWhite;
    sfText_setFillColor(name->text, sfWhite);
    sfText_setOutlineColor(name->text, sfBlack);
    sfText_setOutlineThickness(name->text, (float)5);
    return (name);
}

intro_t *create_intro(window_t *win)
{
    intro_t *intro = my_calloc(sizeof(intro_t));

    intro->activated = sfTrue;
    intro->bg = init_bg();
    intro->fade = sfRectangleShape_create();
    intro->color = sfColor_fromRGBA(0, 0, 0, 255);
    intro->fade_clock = sfClock_create();
    intro->name = init_intro_text(win);
    sfRectangleShape_setSize(intro->fade,
    fvec((float)win->mode.width, (float)win->mode.height));
    sfRectangleShape_setFillColor(intro->fade, intro->color);
    return (intro);
}