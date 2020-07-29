/*
** EPITECH PROJECT, 2020
** game_event.c
** File description:
** game event
*/

#include "game.h"
#include "tools.h"
#include "save.h"
#include "build_map.h"
#include "map.h"
#include "my.h"

static void pressed_direction_key(player_t *player, sfEvent event)
{
    if (event.key.code == sfKeyZ || event.key.code == sfKeyUp)
        player->direction |= UP;
    if (event.key.code == sfKeyQ || event.key.code == sfKeyLeft)
        player->direction |= LEFT;
    if (event.key.code == sfKeyS || event.key.code == sfKeyDown)
        player->direction |= DOWN;
    if (event.key.code == sfKeyD || event.key.code == sfKeyRight)
        player->direction |= RIGHT;
    if (event.key.code == sfKeyLShift)
        player->is_sprint = 1;
}

static void pressed_key_2(game_t *game, sfEvent evt)
{
    if (evt.key.code == sfKeyF3)
        game->hitbox_activated = (game->hitbox_activated + 1) % 2;
    if (evt.key.code == sfKeyC && game->stats->skill->skill_unlock & WAR_CRY)
        sfSound_play(game->player->war_cry);
    if (evt.key.code == sfKeyN && game->stats->skill->skill_unlock & NINJA
    && !game->player->ninja_cooldown) {
        sfClock_restart(game->player->ninja_clock);
        game->player->ninja_activated = 1;
        game->fight->game_launched = 1;
    }
    if (evt.key.code == sfKeyF1)
        game->cheat_mode = (game->cheat_mode + 1) % 2;
}

static void pressed_key(window_t *win, game_t *game, sfEvent evt)
{
    pressed_direction_key(game->player, evt);
    if (evt.key.code == sfKeyF)
        win->fps->activated = (win->fps->activated + 1) % 2;
    if (evt.key.code == sfKeyF11)
        take_screenshot(win);
    if (evt.key.code == sfKeyF9)
        game->state = BUILD;
    if (evt.key.code == sfKeyEscape) {
        game->state = IN_ESCAPE;
        game->saves = load_slot(game->esc_menu->b_slot1,
        game->esc_menu->b_slot2, game->esc_menu->b_slot3);
    }
    if (evt.key.code == sfKeyE) {
        game->state = IN_INVENTORY;
        game->stats->state = STATS;
    }
    if (evt.key.code == sfKeySpace) {
        game->letter->activated = 0;
    }
    pressed_key_2(game, evt);
}

static void released_key(window_t *win, game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyZ || event.key.code == sfKeyUp)
        game->player->direction ^= UP;
    if (event.key.code == sfKeyQ || event.key.code == sfKeyLeft)
        game->player->direction ^= LEFT;
    if (event.key.code == sfKeyS || event.key.code == sfKeyDown)
        game->player->direction ^= DOWN;
    if (event.key.code == sfKeyD || event.key.code == sfKeyRight)
        game->player->direction ^= RIGHT;
    if (event.key.code == sfKeyLShift) {
        game->player->is_sprint = 0;
        game->player->speed_move = 6 + game->stats->speed_bonus;
    }
    if (event.key.code == sfKeyEnter && game->dialogue->activated
    && but_se(win)) {
        game->dialogue->check_pass++;
    }
    if (event.key.code == sfKeyT && how_many_item(game->items_list, 10) >= 1)
        game->player->torch_active = (game->player->torch_active + 1) % 2;
}

int game_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(win, game, win->event);
        if (win->event.type == sfEvtKeyReleased)
            released_key(win, game, win->event);
        if (win->event.type == sfEvtMouseButtonReleased &&
        !my_strcmp(game->map->name, "my_house") &&
        sfFloatRect_contains(&game->build->b_build->img->hitbox, win->mouse.x,
        win->mouse.y) && but_se(win))
            game->state = BUILD;
        if (game->stats->health == 0) {
            game->saves = load_slot(game->esc_menu->b_slot1,
            game->esc_menu->b_slot2, game->esc_menu->b_slot3);
            game->state = IN_ESCAPE;
        }
    }
    return SUCCESS;
}