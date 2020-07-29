/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** game loop
*/

#include "game.h"
#include "map.h"
#include "tools.h"

static void stop_all_musics(game_t *game)
{
    sfMusic_stop(game->bg_music);
    sfMusic_stop(game->bg_pause);
    sfMusic_stop(game->stats->xp_sound);
    sfMusic_stop(game->stats->level_sound);
    sfMusic_stop(game->fight->battle_music);
    sfMusic_stop(game->shop->money_sound);
    sfSound_stop(game->player->war_cry);
    sfMusic_destroy(game->bg_music);
    sfMusic_destroy(game->bg_pause);
    sfMusic_destroy(game->stats->xp_sound);
    sfMusic_destroy(game->stats->level_sound);
    sfMusic_destroy(game->fight->battle_music);
    sfMusic_destroy(game->shop->money_sound);
    sfSound_destroy(game->player->war_cry);
}

static void choose_music_to_play(game_t *game)
{
    if ((game->state == IN_GAME || game->state == IN_INVENTORY
        || game->state == IN_SHOP)
        && sfMusic_getStatus(game->bg_music) != sfPlaying)
        sfMusic_play(game->bg_music);
    if (game->state == IN_ESCAPE
        && sfMusic_getStatus(game->bg_pause) != sfPlaying)
        sfMusic_play(game->bg_pause);
    if (game->state == IN_FIGHT
        && sfMusic_getStatus(game->fight->battle_music) != sfPlaying)
        sfMusic_play(game->fight->battle_music);
}

static void choose_music_to_pause(game_t *game)
{
    if (game->state != IN_GAME && game->state != IN_INVENTORY
        && game->state != IN_SHOP
        && sfMusic_getStatus(game->bg_music) != sfPaused)
        sfMusic_pause(game->bg_music);
    if (game->state != IN_ESCAPE
        && sfMusic_getStatus(game->bg_pause) != sfStopped)
        sfMusic_stop(game->bg_pause);
    if (game->state != IN_FIGHT
        && sfMusic_getStatus(game->fight->battle_music) != sfStopped)
        sfMusic_stop(game->fight->battle_music);
}

int game_state(window_t *win, game_t *game)
{
    int (*choose_state[])(window_t *win, game_t *game) = {
        &escape_loop, &game_loop, &fight_loop, &inventory_loop,
        &shop_loop, &custom_loop, &builder_loop, NULL};

    while (sfRenderWindow_isOpen(win->window) && !game->end) {
        win->mouse = sfMouse_getPositionRenderWindow(win->window);
        choose_music_to_play(game);
        choose_music_to_pause(game);
        get_elapsed_time(&game->time_elapsed, game->clock_loop);
        choose_state[game->state](win, game);
        sfRenderWindow_setView(win->window, game->hud->view);
        display_cursor(win, game->time_elapsed);
        sfRenderWindow_setView(win->window, game->camera->view);
        sfRenderWindow_display(win->window);
        sfRenderWindow_clear(win->window, sfBlack);
    }
    stop_all_musics(game);
    return SUCCESS;
}