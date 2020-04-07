/*
** EPITECH PROJECT, 2020
** create_player.c
** File description:
** camera player
*/

#include "game.h"
#include "my.h"
#include "tools.h"

static sprite_t *create_player_sprite(window_t *win)
{
    sprite_t *player_sprite = my_calloc(sizeof(sprite_t));

    player_sprite->clock = sfClock_create();
    player_sprite->texture = sfTexture_createFromFile(
                        "assets/image/player.png", NULL);
    player_sprite->sprite = sfSprite_create();
    player_sprite->pos = ORIGIN;
    player_sprite->rect.left = 0;
    player_sprite->rect.top = 0;
    player_sprite->rect.width = 24;
    player_sprite->rect.height = 32;
    if (!player_sprite->texture || !player_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(player_sprite->sprite, player_sprite->texture, sfTrue);
    sfSprite_setTextureRect(player_sprite->sprite, player_sprite->rect);
    sfSprite_setPosition(player_sprite->sprite, player_sprite->pos);
    player_sprite->hitbox = sfSprite_getGlobalBounds(player_sprite->sprite);
    return player_sprite;
}

player_t *create_game_player(window_t *win)
{
    player_t *player = my_calloc(sizeof(player_t));

    player->direction = NONE;
    player->sprite = create_player_sprite(win);
    player->speed_move = 1;
    player->speed_anim = 70;
    return player;
}