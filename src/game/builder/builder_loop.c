/*
** EPITECH PROJECT, 2020
** builder.c
** File description:
** builder
*/

#include "game.h"
#include "map.h"
#include "tools.h"
#include "build_map.h"

void display_hud_build(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    display_sprite(win->window, game->build->b_save->img);
    if (game->build->state == CATALOG)
        display_catalog(win, game);
}

void display_build(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->build->view);
    display_map(win, game);
    if (game->build->posing_objects)
        draw_posing_objects(win, game->build->posing_objects, game->build->view);
}

void build_update(window_t *win, game_t *game)
{
    manage_build_camera(win, game->build->view, game->time_elapsed);
}

int builder_loop(window_t *win, game_t *game)
{
    if (game->build->state == BUILD_MODE)
        builder_event(win, game);
    else if (game->build->state == CATALOG)
        builder_catalog_event(win, game);
    build_update(win, game);
    display_build(win, game);
    display_hud_build(win, game);
    return SUCCESS;
}