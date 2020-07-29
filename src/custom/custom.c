/*
** EPITECH PROJECT, 2020
** custom.c
** File description:
** contains customization handling functions
*/

#include "game.h"
#include "menu_h.h"
#include "tools.h"

static void custom_menu_display(window_t *win, player_t *player, game_t *game)
{
    display_sprite_scl(win->window, player->custom->custom_bg, fvec( \
        (float)win->mode.width / (float)player->custom->custom_bg->rect.width,
        (float)win->mode.height / \
        (float)player->custom->custom_bg->rect.height));
    display_sprite(win->window, player->custom->bg_chara);
    player->sprite->pos.x = (float)win->mode.width / 2 - 100;
    player->sprite->pos.y = (float)win->mode.height / 2 - 200;
    display_player(win, player, game);
    update_buttons(player->custom, player->custom->which_part);
    display_custom_buttons(win, player->custom);
}

int custom_loop(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    custom_event(win, game);
    custom_menu_display(win, game->player, game);
    return SUCCESS;
}

void update_custom_hair_and_face(player_t *player, int hair, int face)
{
    player->custom->face[face]->pos.x = player->sprite->pos.x;
    player->custom->face[face]->pos.y = player->sprite->pos.y;
    player->custom->face[face]->rect.left = player->sprite->rect.left;
    player->custom->face[face]->rect.top = player->sprite->rect.top;
    sfSprite_setTexture(player->custom->face[face]->sprite, \
        player->custom->face[face]->texture, sfTrue);
    sfSprite_setTextureRect(player->custom->face[face]->sprite, \
        player->custom->face[face]->rect);
    sfSprite_setPosition(player->custom->face[face]->sprite, \
        player->custom->face[face]->pos);
    player->custom->hair[hair]->pos.x = player->sprite->pos.x;
    player->custom->hair[hair]->pos.y = player->sprite->pos.y;
    player->custom->hair[hair]->rect.left = player->sprite->rect.left;
    player->custom->hair[hair]->rect.top = player->sprite->rect.top;
    sfSprite_setTexture(player->custom->hair[hair]->sprite, \
        player->custom->hair[hair]->texture, sfTrue);
    sfSprite_setTextureRect(player->custom->hair[hair]->sprite, \
        player->custom->hair[hair]->rect);
    sfSprite_setPosition(player->custom->hair[hair]->sprite, \
        player->custom->hair[hair]->pos);
}

void update_custom_shirt_and_pants(player_t *player, int shirt, int pants)
{
    player->custom->shirt[shirt]->pos.x = player->sprite->pos.x;
    player->custom->shirt[shirt]->pos.y = player->sprite->pos.y;
    player->custom->shirt[shirt]->rect.left = player->sprite->rect.left;
    player->custom->shirt[shirt]->rect.top = player->sprite->rect.top;
    sfSprite_setTexture(player->custom->shirt[shirt]->sprite, \
        player->custom->shirt[shirt]->texture, sfTrue);
    sfSprite_setTextureRect(player->custom->shirt[shirt]->sprite, \
        player->custom->shirt[shirt]->rect);
    sfSprite_setPosition(player->custom->shirt[shirt]->sprite, \
        player->custom->shirt[shirt]->pos);
    player->custom->pants[pants]->pos.x = player->sprite->pos.x;
    player->custom->pants[pants]->pos.y = player->sprite->pos.y;
    player->custom->pants[pants]->rect.left = player->sprite->rect.left;
    player->custom->pants[pants]->rect.top = player->sprite->rect.top;
    sfSprite_setTexture(player->custom->pants[pants]->sprite, \
        player->custom->pants[pants]->texture, sfTrue);
    sfSprite_setTextureRect(player->custom->pants[pants]->sprite, \
        player->custom->pants[pants]->rect);
    sfSprite_setPosition(player->custom->pants[pants]->sprite, \
        player->custom->pants[pants]->pos);
}

void update_custom_shoes(player_t *player, int shoes)
{
    player->custom->shoes[shoes]->pos.x = player->sprite->pos.x;
    player->custom->shoes[shoes]->pos.y = player->sprite->pos.y;
    player->custom->shoes[shoes]->rect.left = player->sprite->rect.left;
    player->custom->shoes[shoes]->rect.top = player->sprite->rect.top;
    sfSprite_setTexture(player->custom->shoes[shoes]->sprite, \
        player->custom->shoes[shoes]->texture, sfTrue);
    sfSprite_setTextureRect(player->custom->shoes[shoes]->sprite, \
        player->custom->shoes[shoes]->rect);
    sfSprite_setPosition(player->custom->shoes[shoes]->sprite, \
        player->custom->shoes[shoes]->pos);
}