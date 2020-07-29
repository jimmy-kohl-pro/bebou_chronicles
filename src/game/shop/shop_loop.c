/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** displays inventory
*/

#include "game.h"
#include "tools.h"
#include "my.h"
#include "map.h"

static void display_shop(window_t *win, game_t *game)
{
    display_game(win, game);
    sfRenderWindow_setView(win->window, game->hud->view);
    display_sprite(win->window, game->shop->shop_hud);
    display_sprite(win->window, game->shop->potion_sprite);
    if (how_many_item(game->items_list, 1) == 0)
        display_sprite(win->window, game->shop->katana_sprite);
    display_sprite_scl(win->window, game->shop->coin_sprite,
                                            (sfVector2f) {0.5, 0.5});
    disp_text(win->window, game->shop->shop_name);
    disp_text(win->window, game->shop->object_description);
    game->shop->money->str = int_str(how_many_item(game->items_list, 5));
    disp_text(win->window, game->shop->money);
}

int shop_loop(window_t *win, game_t *game)
{
    game->player->direction = NONE;
    game->player->speed_move = 6;
    sfRenderWindow_clear(win->window, sfBlack);
    display_shop(win, game);
    shop_event(win, game);
    manage_fps(win, win->fps);
    sfRenderWindow_setView(win->window, game->camera->view);
    return SUCCESS;
}