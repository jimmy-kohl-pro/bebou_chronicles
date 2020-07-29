/*
** EPITECH PROJECT, 2020
** create_player.c
** File description:
** camera player
*/

#include "game.h"
#include "my.h"
#include "tools.h"

static void set_rect(sprite_t *player_sprite)
{
    player_sprite->rect.left = 0;
    player_sprite->rect.top = 0;
    player_sprite->rect.width = 155;
    player_sprite->rect.height = 324;
}

static sprite_t *create_player_sprite(void)
{
    sprite_t *player_sprite = my_calloc(sizeof(sprite_t));

    player_sprite->clock = sfClock_create();
    player_sprite->texture = sfTexture_createFromFile(
                        "assets/custom/player.png", NULL);
    player_sprite->sprite = sfSprite_create();
    player_sprite->pos = ORIGIN;
    set_rect(player_sprite);
    if (!player_sprite->texture || !player_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(player_sprite->sprite, player_sprite->texture,
        sfTrue);
    sfSprite_setTextureRect(player_sprite->sprite, player_sprite->rect);
    sfSprite_setPosition(player_sprite->sprite, player_sprite->pos);
    sfSprite_setScale(player_sprite->sprite, fvec((float)450 /
    (float)player_sprite->rect.height, (float)450 /
    (float)player_sprite->rect.height));
    player_sprite->hitbox = (sfFloatRect){30, 390, 150, 50};
    return player_sprite;
}

player_t *create_game_player(window_t *win)
{
    player_t *player = my_calloc(sizeof(player_t));
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(
                                            "assets/sound/warcry.ogg");

    player->direction = NONE;
    player->sprite = create_player_sprite();
    player->speed_move = 6;
    player->speed_anim = 600;
    player->ninja_clock = sfClock_create();
    player->ninja_activated = 0;
    player->ninja_cooldown = 0;
    player->is_sprint = 0;
    player->torch_active = 0;
    player->war_cry = sfSound_create();
    sfSound_setBuffer(player->war_cry, buffer);
    player->custom = init_custom_struct(
    (float)450 / (float)player->sprite->rect.height, win);
    return player;
}