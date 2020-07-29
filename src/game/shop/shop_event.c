/*
** EPITECH PROJECT, 2020
** escape_event.c
** File description:
** escape event
*/

#include "game.h"
#include "menu_h.h"
#include "tools.h"
#include "my.h"

static int play_moula_sound(shop_t *shop)
{
    sfMusic_stop(shop->money_sound);
    sfMusic_play(shop->money_sound);
    return 1;
}

static void pressed_key(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEscape || event.key.code == sfKeyM) {
        game->state = IN_GAME;
        game->player->direction = 0;
    }
}

static void pressed_mouse(window_t *win, game_t *game)
{
    if (mouse_hitbox(win, *(game->shop->potion_sprite))
    && how_many_item(game->items_list, 5) >= 5
    && play_moula_sound(game->shop)) {
        update_inventory(game->items_list, 5, -5);
        update_inventory(game->items_list, 2, 1);
    }
    if (mouse_hitbox(win, *(game->shop->katana_sprite))
    && how_many_item(game->items_list, 5) >= 30
    && how_many_item(game->items_list, 1) == 0
    && play_moula_sound(game->shop)) {
        update_inventory(game->items_list, 5, -30);
        update_inventory(game->items_list, 1, 1);
    }
}

static void passed_mouse(window_t *win, game_t *game)
{
    if (mouse_hitbox(win, *(game->shop->potion_sprite)))
        game->shop->object_description->str =
        "Potion : Gives 15 HP when\ndrinked\nCost : 5";
    else if (mouse_hitbox(win, *(game->shop->katana_sprite))
            && how_many_item(game->items_list, 1) == 0)
        game->shop->object_description->str =
        "Stone Katana : Gives a \nattack bonus of x2\nCost : 30";
    else
        game->shop->object_description->str = NULL;
}

int shop_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(game, win->event);
        if (win->event.type == sfEvtMouseButtonPressed)
            pressed_mouse(win, game);
    }
    passed_mouse(win, game);
    return SUCCESS;
}