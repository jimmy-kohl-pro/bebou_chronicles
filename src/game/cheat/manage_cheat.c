/*
** EPITECH PROJECT, 2020
** manage_cheat.c
** File description:
** manage cheat
*/

#include "game.h"
#include "particle_engine.h"
#include "inventory.h"

void manage_cheat(window_t *win, game_t *game)
{
    if (!game->cheat_mode)
        return;
    game->god->pos = game->player->sprite->pos;
    game->god->pos.x += 100;
    game->god->pos.y += 420;
    if (sfKeyboard_isKeyPressed(sfKeyX))
        add_xp(game->stats, 10);
    if (sfKeyboard_isKeyPressed(sfKeyC))
        update_life(game->stats, 5);
    if (sfKeyboard_isKeyPressed(sfKeyW))
        update_inventory(game->items_list, 5, 1);
    manage_particle(win, game->god, game->time_elapsed);
}