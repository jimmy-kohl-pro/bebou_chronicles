/*
** EPITECH PROJECT, 2020
** create_custom_items.c
** File description:
** deals with custom items creation
*/

#include "game.h"
#include "tools.h"
#include "my.h"

sprite_t *create_custom_obj(float scale, char *filepath, int width, int height)
{
    sprite_t *obj = my_calloc(sizeof(sprite_t));

    obj->clock = sfClock_create();
    obj->texture = sfTexture_createFromFile(filepath, NULL);
    obj->sprite = sfSprite_create();
    obj->pos.x = 0;
    obj->pos.y = 0;
    obj->rect.left = 0;
    obj->rect.top = 0;
    obj->rect.width = width;
    obj->rect.height = height;
    if (!obj->texture || !obj->sprite)
        return FAIL;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setScale(obj->sprite, fvec(scale, scale));
    sfSprite_setPosition(obj->sprite, obj->pos);
    return obj;
}

void malloc_custom_arrays(custom_t *custom)
{
    custom->face = my_calloc(sizeof(sprite_t *) * 5);
    custom->hair = my_calloc(sizeof(sprite_t *) * 3);
    custom->shirt = my_calloc(sizeof(sprite_t *) * 4);
    custom->pants = my_calloc(sizeof(sprite_t *) * 4);
    custom->shoes = my_calloc(sizeof(sprite_t *) * 3);
}

void create_custom_head(custom_t *custom, float scale)
{
    custom->face[0] = create_custom_obj(scale, \
        "assets/custom/bebar.png", 155, 324);
    custom->face[1] = create_custom_obj(scale, \
        "assets/custom/bebar.png", 155, 324);
    custom->face[2] = create_custom_obj(scale, \
        "assets/custom/stache.png", 155, 324);
    custom->face[3] = create_custom_obj(scale, \
        "assets/custom/mask.png", 155, 324);
    custom->face[4] = NULL;
    custom->hair[0] = create_custom_obj(scale, \
        "assets/custom/veuches.png", 155, 324);
    custom->hair[1] = create_custom_obj(scale, \
        "assets/custom/veuches.png", 155, 324);
    custom->hair[2] = NULL;
}

void create_custom_body(custom_t *custom, float scale)
{
    custom->shirt[0] = create_custom_obj(scale, \
        "assets/custom/wb.png", 155, 324);
    custom->shirt[1] = create_custom_obj(scale, \
        "assets/custom/wb.png", 155, 324);
    custom->shirt[2] = create_custom_obj(scale, \
        "assets/custom/kimono.png", 155, 324);
    custom->shirt[3] = NULL;
    custom->pants[0] = create_custom_obj(scale, \
        "assets/custom/red_pants.png", 155, 324);
    custom->pants[1] = create_custom_obj(scale, \
        "assets/custom/red_pants.png", 155, 324);
    custom->pants[2] = create_custom_obj(scale, \
        "assets/custom/k_pants.png", 155, 324);
    custom->pants[3] = NULL;
    custom->shoes[0] = create_custom_obj(scale, \
        "assets/custom/klakettes.png", 155, 324);
    custom->shoes[1] = create_custom_obj(scale, \
        "assets/custom/klakettes.png", 155, 324);
    custom->shoes[2] = NULL;
}

custom_t *init_custom_struct(float scale, window_t *win)
{
    custom_t *custom = my_calloc(sizeof(custom_t));

    custom->which_part = 0;
    malloc_custom_arrays(custom);
    create_custom_head(custom, scale);
    create_custom_body(custom, scale);
    custom->bg_chara = create_chara_bg();
    custom->custom_bg = create_custom_bg();
    init_custom_basics(custom);
    custom->c_buttons = create_all_custom_buttons(win);
    return (custom);
}
