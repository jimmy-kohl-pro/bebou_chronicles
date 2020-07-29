/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_shop
*/

#include "game.h"
#include "my.h"
#include "tools.h"

static sprite_t *create_potion_sprite(void)
{
    sprite_t *shop = my_calloc(sizeof(sprite_t));

    shop->clock = sfClock_create();
    shop->texture =
        sfTexture_createFromFile("assets/items/healing_potion.png", NULL);
    shop->sprite = sfSprite_create();
    shop->pos = (sfVector2f) {635, 490};
    shop->rect.left = 0;
    shop->rect.top = 0;
    shop->rect.width = 141;
    shop->rect.height = 141;
    if (!shop->texture || !shop->sprite)
        return FAIL;
    sfSprite_setTexture(shop->sprite, shop->texture, sfTrue);
    sfSprite_setTextureRect(shop->sprite, shop->rect);
    shop->hitbox = sfSprite_getGlobalBounds(shop->sprite);
    return shop;
}

static sprite_t *create_katana_sprite(void)
{
    sprite_t *shop = my_calloc(sizeof(sprite_t));

    shop->clock = sfClock_create();
    shop->texture = sfTexture_createFromFile("assets/items/stone_katana.png",
                NULL);
    shop->sprite = sfSprite_create();
    shop->pos = (sfVector2f) {1060, 490};
    shop->rect.left = 0;
    shop->rect.top = 0;
    shop->rect.width = 141;
    shop->rect.height = 141;
    if (!shop->texture || !shop->sprite)
        return FAIL;
    sfSprite_setTexture(shop->sprite, shop->texture, sfTrue);
    sfSprite_setTextureRect(shop->sprite, shop->rect);
    shop->hitbox = sfSprite_getGlobalBounds(shop->sprite);
    return shop;
}

static sprite_t *create_coin_sprite(void)
{
    sprite_t *shop = my_calloc(sizeof(sprite_t));

    shop->clock = sfClock_create();
    shop->texture = sfTexture_createFromFile("assets/items/coin.png",
                NULL);
    shop->sprite = sfSprite_create();
    shop->pos = (sfVector2f) {1275, 265};
    shop->rect.left = 0;
    shop->rect.top = 0;
    shop->rect.width = 141;
    shop->rect.height = 141;
    if (!shop->texture || !shop->sprite)
        return FAIL;
    sfSprite_setTexture(shop->sprite, shop->texture, sfTrue);
    sfSprite_setTextureRect(shop->sprite, shop->rect);
    return shop;
}

static sprite_t *create_shop_hud(void)
{
    sprite_t *shop = my_calloc(sizeof(sprite_t));

    shop->clock = sfClock_create();
    shop->texture = sfTexture_createFromFile("assets/image/shop_hud.png",
                NULL);
    shop->sprite = sfSprite_create();
    shop->pos = (sfVector2f) {450, 250};
    shop->rect.left = 0;
    shop->rect.top = 0;
    shop->rect.width = 900;
    shop->rect.height = 600;
    if (!shop->texture || !shop->sprite)
        return FAIL;
    sfSprite_setTexture(shop->sprite, shop->texture, sfTrue);
    sfSprite_setTextureRect(shop->sprite, shop->rect);
    return shop;
}

shop_t *create_shop(window_t *win)
{
    shop_t *shop = my_calloc(sizeof(shop_t));

    shop->shop_hud = create_shop_hud();
    shop->shop_name = create_text_struct(win);
    shop->shop_name->pos = (sfVector2f) {785, 280};
    shop->shop_name->str = "SHOP";
    shop->shop_name->size = 100;
    shop->object_description = create_text_struct(win);
    shop->object_description->pos = (sfVector2f) {560, 660};
    shop->object_description->str = NULL;
    shop->money = create_text_struct(win);
    shop->money->pos = (sfVector2f) {1210, 265};
    shop->money->str = NULL;
    shop->coin_sprite = create_coin_sprite();
    shop->katana_sprite = create_katana_sprite();
    shop->potion_sprite = create_potion_sprite();
    shop->money_sound = sfMusic_createFromFile("assets/sound/money.ogg");
    sfMusic_setVolume(shop->money_sound, win->volume);
    return shop;
}