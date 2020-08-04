/*
** EPITECH PROJECT, 2020
** create_builder.c
** File description:
** create builder
*/

#include "game.h"
#include "my.h"
#include "build_map.h"
#include "tools.h"

static sprite_t *create_build_catalog(window_t *win)
{
    sprite_t *catalog = my_calloc(sizeof(sprite_t));

    catalog->clock = sfClock_create();
    catalog->texture = sfTexture_createFromFile(
                            "assets/image/inventory.png", NULL);
    catalog->sprite = sfSprite_create();
    catalog->rect.left = 0;
    catalog->rect.top = 0;
    catalog->rect.width = 960;
    catalog->rect.height = 783;
    catalog->pos.x = (float)win->mode.width / 4;
    catalog->pos.y = 100;
    if (!catalog->texture || !catalog->sprite)
        return NULL;
    sfSprite_setTexture(catalog->sprite, catalog->texture, sfTrue);
    sfSprite_setTextureRect(catalog->sprite, catalog->rect);
    sfSprite_setPosition(catalog->sprite, catalog->pos);
    catalog->hitbox = sfSprite_getGlobalBounds(catalog->sprite);
    return catalog;
}

sfView *create_build_camera(window_t *win)
{
    sfView *camera = my_calloc(sizeof(camera_t));

    camera = sfView_createFromRect((sfFloatRect){0, 0,
                (float)win->mode.width * 2, (float)win->mode.height * 2});
    sfView_setViewport(camera, (sfFloatRect){0, 0, 1, 1});
    return camera;
}

build_t *create_builder(window_t *win)
{
    build_t *build = my_calloc(sizeof(build_t));

    build->catalog = create_build_catalog(win);
    build->objects_list = create_objects_list();
    build->b_build = create_button_build(win);
    build->b_save = create_button_save_build(win);
    build->view = create_build_camera(win);
    return build;
}