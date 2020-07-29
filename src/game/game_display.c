/*
** EPITECH PROJECT, 2020
** game_display.c
** File description:
** game display
*/

#include "game.h"
#include "tools.h"
#include "map.h"
#include "my.h"

static void display_particle(window_t *win, game_t *game)
{
    if (!my_strcmp(game->map->name, "north_map"))
        manage_particle(win, game->snow, game->time_elapsed);
    if (!my_strcmp(game->map->name, "village_map"))
        manage_particle(win, game->sakura, game->time_elapsed);
    display_torch(win, game);
}

void display_game(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->camera->view);
    display_map(win, game);
    if (!game->dialogue->cat_quest && game->dialogue->cat_quest_launched
        && !my_strcmp(game->map->name, "temple_map")
        && how_many_item(game->items_list, 3) == 0)
        display_sprite(win->window, game->dialogue->cat);
    if (!my_strcmp(game->map->name, "village_map")) {
        display_sprite(win->window, game->pnj->ronin);
        display_sprite(win->window, game->pnj->woman);
        display_sprite(win->window, game->pnj->man);
    } if (!my_strcmp(game->map->name, "temple_map"))
        display_sprite(win->window, game->pnj->priestess);
    if (!my_strcmp(game->map->name, "palace_map")) {
        display_sprite(win->window, game->pnj->samurai);
        display_sprite(win->window, game->pnj->noble);
    }
    display_particle(win, game);
    if (game->hitbox_activated)
        display_hitbox(win, game->map->props, game->player);
    manage_cheat(win, game);
}