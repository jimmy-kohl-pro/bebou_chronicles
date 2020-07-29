/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_fight
*/

#include "game.h"
#include "my.h"
#include "tools.h"

sprite_t *create_attack_anim(void)
{
    sprite_t *sprite = my_calloc(sizeof(sprite_t));

    sprite->clock = sfClock_create();
    sprite->texture = sfTexture_createFromFile(
                                "assets/image/attack_sprite.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->pos = ORIGIN;
    sprite->rect.left = 0;
    sprite->rect.top = 0;
    sprite->rect.width = 192;
    sprite->rect.height = 192;
    if (!sprite->texture || !sprite->sprite)
        return FAIL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return (sprite);
}

sprite_t *create_battlg_bg(void)
{
    sprite_t *map = my_calloc(sizeof(sprite_t));

    map->clock = sfClock_create();
    map->texture = sfTexture_createFromFile("assets/image/battleback.png",
                NULL);
    map->sprite = sfSprite_create();
    map->pos = ORIGIN;
    map->rect.left = 0;
    map->rect.top = 0;
    map->rect.width = 1821;
    map->rect.height = 1024;
    if (!map->texture || !map->sprite)
        return FAIL;
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setTextureRect(map->sprite, map->rect);
    return map;
}

sprite_t *create_battle_player(void)
{
    sprite_t *map = my_calloc(sizeof(sprite_t));

    map->clock = sfClock_create();
    map->texture = sfTexture_createFromFile("assets/image/battle_player.png",
                NULL);
    map->sprite = sfSprite_create();
    map->pos = (sfVector2f) {50, 330};
    map->rect.left = 0;
    map->rect.top = 0;
    map->rect.width = 313;
    map->rect.height = 390;
    if (!map->texture || !map->sprite)
        return FAIL;
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setTextureRect(map->sprite, map->rect);
    return map;
}

sprite_t *create_battle_hud(void)
{
    sprite_t *map = my_calloc(sizeof(sprite_t));

    map->clock = sfClock_create();
    map->texture = sfTexture_createFromFile("assets/image/fight_hud.png",
                NULL);
    map->sprite = sfSprite_create();
    map->pos = (sfVector2f) {10, 715};
    map->rect.left = 0;
    map->rect.top = 0;
    map->rect.width = 800;
    map->rect.height = 300;
    if (!map->texture || !map->sprite)
        return FAIL;
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setTextureRect(map->sprite, map->rect);
    return map;
}

fight_t *create_fight(window_t *win)
{
    fight_t *fight = my_calloc(sizeof(fight_t));

    fight->ennemies = make_ennemies_list();
    fight->bg = create_battlg_bg();
    fight->fight_hud = create_battle_hud();
    fight->player = create_battle_player();
    fight->attack_anim = create_attack_anim();
    fight->id = 0;
    fight->cursor = ATTACK_LOW;
    fight->turn = PLAYER_TURN;
    create_text_fight(win, fight);
    create_text_fight_stats(win, fight);
    fight->nb_ennemies = 1;
    fight->init_fight = 0;
    fight->ennemy_health_int = 1;
    fight->clock_infos = sfClock_create();
    fight->pass_text = 0;
    fight->ennemy_played = 0;
    fight->end_message = 0;
    return fight;
}