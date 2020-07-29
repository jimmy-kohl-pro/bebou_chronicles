/*
** EPITECH PROJECT, 2020
** custom_commands.c
** File description:
** contains custom command handling functions
*/

#include "game.h"
#include "menu_h.h"
#include "tools.h"

int custom_command_hair(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ)
            game->player->custom->hair_id -= 1;
    if (event.key.code == sfKeyD)
        game->player->custom->hair_id += 1;
    if (game->player->custom->hair_id < 0)
        game->player->custom->hair_id = 0;
    if (game->player->custom->hair_id > game->player->custom->hair_nb)
        game->player->custom->hair_id = game->player->custom->hair_nb;
    return SUCCESS;
}

int custom_command_face(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ)
            game->player->custom->face_id -= 1;
    if (event.key.code == sfKeyD)
        game->player->custom->face_id += 1;
    if (game->player->custom->face_id < 0)
        game->player->custom->face_id = 0;
    if (game->player->custom->face_id > game->player->custom->face_nb)
        game->player->custom->face_id = game->player->custom->face_nb;
    return SUCCESS;
}

int custom_command_shirt(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ)
            game->player->custom->shirt_id -= 1;
    if (event.key.code == sfKeyD)
        game->player->custom->shirt_id += 1;
    if (game->player->custom->shirt_id < 0)
        game->player->custom->shirt_id = 0;
    if (game->player->custom->shirt_id > game->player->custom->shirt_nb)
        game->player->custom->shirt_id = game->player->custom->shirt_nb;
    return SUCCESS;
}

int custom_command_pants(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ)
            game->player->custom->pants_id -= 1;
    if (event.key.code == sfKeyD)
        game->player->custom->pants_id += 1;
    if (game->player->custom->pants_id < 0)
        game->player->custom->pants_id = 0;
    if (game->player->custom->pants_id > game->player->custom->pants_nb)
        game->player->custom->pants_id = game->player->custom->pants_nb;
    return SUCCESS;
}

int custom_command_shoes(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ)
            game->player->custom->shoes_id -= 1;
    if (event.key.code == sfKeyD)
        game->player->custom->shoes_id += 1;
    if (game->player->custom->shoes_id < 0)
        game->player->custom->shoes_id = 0;
    if (game->player->custom->shoes_id > game->player->custom->shoes_nb)
        game->player->custom->shoes_id = game->player->custom->shoes_nb;
    return SUCCESS;
}