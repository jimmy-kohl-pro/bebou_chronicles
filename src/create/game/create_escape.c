/*
** EPITECH PROJECT, 2020
** create_escape.c
** File description:
** create escape menu
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static sprite_t *create_escape_bg(void)
{
    sprite_t *bg = my_calloc(sizeof(sprite_t));

    bg->clock = sfClock_create();
    bg->texture = sfTexture_createFromFile("assets/image/bg_esc_menu.png",
                NULL);
    bg->sprite = sfSprite_create();
    bg->pos = ORIGIN;
    bg->rect.left = 0;
    bg->rect.top = 0;
    bg->rect.width = 500;
    bg->rect.height = 268;
    if (!bg->texture || !bg->sprite)
        return FAIL;
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    sfSprite_setTextureRect(bg->sprite, bg->rect);
    return (bg);
}

escape_t *create_game_escape_menu(window_t *win)
{
    escape_t *esc = my_calloc(sizeof(escape_t));

    esc->bg = create_escape_bg();
    esc->b_continue = create_esc_continue(win);
    esc->b_opt = create_esc_opt(win);
    esc->b_quit = create_esc_quit(win);
    esc->b_save = create_esc_save(win);
    esc->b_slot1 = create_b_slot1(win);
    esc->b_slot2 = create_b_slot2(win);
    esc->b_slot3 = create_b_slot3(win);
    esc->b_ret = create_b_ret(win);
    esc->state = ESC;
    return esc;
}