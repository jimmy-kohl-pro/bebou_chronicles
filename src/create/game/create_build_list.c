/*
** EPITECH PROJECT, 2020
** create_build_list.c
** File description:
** create_build_list
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "build_map.h"
#include "tools.h"

static float larger_side(sfFloatRect hitbox)
{
    float max = 0;

    if (hitbox.height > max)
        max = hitbox.height;
    if (hitbox.width > max)
        max = hitbox.width;
    return max;
}

static sprite_t *create_sprite(props_list_t *items_list, char **props)
{
    sprite_t *sprite = my_calloc(sizeof(sprite_t));
    char **hitbox_brut = my_str_to_word_array(get_var("hitbox", props), "x");
    sfFloatRect temp_hitbox;

    sprite->texture = sfTexture_createFromFile(items_list->path, NULL);
    sprite->pos = ORIGIN;
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->hitbox = (sfFloatRect){my_getnbr(hitbox_brut[0]),
        my_getnbr(hitbox_brut[1]), my_getnbr(hitbox_brut[2]),
        my_getnbr(hitbox_brut[3])};
    temp_hitbox = sfSprite_getGlobalBounds(sprite->sprite);
    sfSprite_setOrigin(sprite->sprite, fvec(temp_hitbox.width / 2,
                                            temp_hitbox.height / 2));
    return sprite;
}

static sprite_t *create_sprite_ico(props_list_t *items_list)
{
    sprite_t *sprite = my_calloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile(items_list->path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->pos = (sfVector2f) {-100, 0};
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->hitbox = sfSprite_getGlobalBounds(sprite->sprite);
    items_list->stack = (text_t) {sfText_create(), sfFont_createFromFile(
        "assets/fonts/upheavtt.ttf"), NULL, 40, sfWhite, (sfVector2f) {0, 0}};
    sfSprite_setScale(sprite->sprite, fvec(147 / larger_side(sprite->hitbox),
                                147 / larger_side(sprite->hitbox)));
    sprite->hitbox = sfSprite_getGlobalBounds(sprite->sprite);
    return sprite;
}

static void add_to_list(props_list_t **list, char **props, char *name)
{
    props_list_t *element = my_calloc(sizeof(props_list_t));

    element->id = my_getnbr(get_var("id", props));
    element->name = my_strdup(name);
    element->path = get_var("sprite", props);
    element->sprite_ico = create_sprite_ico(element);
    element->sprite = create_sprite(element, props);
    element->nb = 1;
    element->next = *list;
    *list = element;
}

props_list_t *create_props_list(void)
{
    props_list_t *props_list = NULL;
    char **props = NULL;
    DIR *dir = opendir("maps/props");
    struct dirent *dirent;

    if (!dir)
        return NULL;
    dirent = readdir(dir);
    for (; dirent != 0; dirent = readdir(dir)) {
        if ((dirent->d_name[0] == '.'))
            continue;
        props = read_file(my_strcat("maps/props/", dirent->d_name));
        add_to_list(&props_list, props, dirent->d_name);
        free_array(props);
    }
    closedir(dir);
    return props_list;
}