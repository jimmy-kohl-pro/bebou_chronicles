/*
** EPITECH PROJECT, 2020
** map_read_objects.c
** File description:
** map read objects
*/

#include "map.h"
#include "my.h"
#include "tools.h"

int set_objects_pos(objects_t *temp, char *pos)
{
    char **pos_c = my_str_to_word_array(pos, "x");
    float x_objects = 0;
    float y_objects = 0;

    if (my_arraylen(pos_c) != 2)
        return FAIL;
    x_objects = my_getfloat(pos_c[0], 2);
    y_objects = my_getfloat(pos_c[1], 2);
    temp->pos = (sfVector2f){x_objects, y_objects};
    sfSprite_setPosition(temp->sprite, temp->pos);
    free_array(pos_c);
    return SUCCESS;
}

int set_objects(objects_t *temp, char *objects_name)
{
    char **objects_file = read_file(my_strcat("maps/objects/", objects_name));
    sfTexture *texture;
    char **hitbox_c = NULL;

    if (!objects_file)
        return FAIL;
    hitbox_c = my_str_to_word_array(get_var("hitbox", objects_file), "x");
    if (my_arraylen(hitbox_c) != 4)
        return FAIL;
    texture = sfTexture_createFromFile(get_var("sprite", objects_file), NULL);
    temp->sprite = sfSprite_create();
    sfSprite_setTexture(temp->sprite, texture, sfTrue);
    temp->hitbox = (sfFloatRect){my_getfloat(hitbox_c[0], 2), my_getfloat(
    hitbox_c[1], 2), my_getfloat(hitbox_c[2], 2),
    my_getfloat(hitbox_c[3], 2)};
    temp->name = my_strdup(objects_name);
    temp->type = my_getnbr(get_var("type", objects_file));
    return SUCCESS;
}

void add_objects(objects_t **objects_list, char *brut_objects)
{
    objects_t *temp = my_calloc(sizeof(objects_t));
    char **objects = my_str_to_word_array(brut_objects, "=");

    if (my_arraylen(objects) != 2)
        return ;
    if (!set_objects(temp, objects[0]))
        return ;
    if (!set_objects_pos(temp, objects[1]))
        return ;
    free_array(objects);
    insert_sort_y(temp, objects_list);
    return ;
}

objects_t *read_objects(char **map_brut)
{
    objects_t *objects = NULL;
    register int i = 0;

    for (i = 0; map_brut[i] && map_brut[i][0] != '#'; i++);
    for (; map_brut[i]; i++) {
        add_objects(&objects, map_brut[i]);
    }
    return objects;
}
