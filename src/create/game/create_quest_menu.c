/*
** EPITECH PROJECT, 2020
** create_quest_menu.c
** File description:
** create quest menu
*/

#include "game.h"
#include "tools.h"
#include "my.h"

sprite_t *create_quest_bg(void)
{
    sprite_t *bg = my_calloc(sizeof(sprite_t));

    bg->clock = sfClock_create();
    bg->texture = sfTexture_createFromFile(
                            "assets/image/quest_hud.png", NULL);
    bg->sprite = sfSprite_create();
    bg->rect.left = 0;
    bg->rect.top = 0;
    bg->rect.width = 450;
    bg->rect.height = 300;
    bg->pos.x = -410;
    bg->pos.y = 400;
    if (!bg->texture || !bg->sprite)
        return NULL;
    bg->hitbox = sfSprite_getGlobalBounds(bg->sprite);
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    sfSprite_setTextureRect(bg->sprite, bg->rect);
    sfSprite_setPosition(bg->sprite, bg->pos);
    return bg;
}

quest_menu_t *create_quest_menu(window_t *win)
{
    quest_menu_t *quest_menu = my_calloc(sizeof(quest_menu_t));

    quest_menu->activated = 0;
    quest_menu->bg = create_quest_bg();
    quest_menu->main_quest = create_text_struct(win);
    quest_menu->main_quest->str = "Rendez vous dans votre maison";
    quest_menu->main_quest->size = 20;
    quest_menu->secondary_quest1 = create_text_struct(win);
    quest_menu->secondary_quest1->size = 20;
    quest_menu->secondary_quest2 = create_text_struct(win);
    quest_menu->secondary_quest2->size = 20;
    quest_menu->secondary_quest3 = create_text_struct(win);
    quest_menu->secondary_quest3->size = 20;
    return quest_menu;
}