/*
** EPITECH PROJECT, 2020
** map_read_props.c
** File description:
** map read props
*/

#include "map.h"
#include "my.h"
#include "tools.h"

int set_props_pos(props_t *temp, char *pos)
{
    char **pos_c = my_str_to_word_array(pos, "x");
    float x_props = 0;
    float y_props = 0;

    if (my_arraylen(pos_c) != 2)
        return FAIL;
    x_props = my_getfloat(pos_c[0], 2);
    y_props = my_getfloat(pos_c[1], 2);
    temp->pos = (sfVector2f){x_props, y_props};
    sfSprite_setPosition(temp->sprite, temp->pos);
    free_array(pos_c);
    return SUCCESS;
}

int set_props(props_t *temp, char *props_name)
{
    char **props_file = read_file(my_strcat("maps/props/", props_name));
    sfTexture *texture;
    char **hitbox_c = NULL;

    if (!props_file)
        return FAIL;
    hitbox_c = my_str_to_word_array(get_var("hitbox", props_file), "x");
    if (my_arraylen(hitbox_c) != 4)
        return FAIL;
    texture = sfTexture_createFromFile(get_var("sprite", props_file), NULL);
    temp->sprite = sfSprite_create();
    sfSprite_setTexture(temp->sprite, texture, sfTrue);
    temp->hitbox = (sfFloatRect){my_getfloat(hitbox_c[0], 2), my_getfloat(
    hitbox_c[1], 2), my_getfloat(hitbox_c[2], 2),
    my_getfloat(hitbox_c[3], 2)};
    temp->name = my_strdup(props_name);
    return SUCCESS;
}

void add_props(props_t **props_list, char *brut_props)
{
    props_t *temp = my_calloc(sizeof(props_t));
    char **props = my_str_to_word_array(brut_props, "=");

    if (my_arraylen(props) != 2)
        return ;
    if (!set_props(temp, props[0]))
        return ;
    if (!set_props_pos(temp, props[1]))
        return ;
    free_array(props);
    insert_sort_y(temp, props_list);
    return ;
}

props_t *read_props(char **map_brut)
{
    props_t *props = NULL;
    register int i = 0;

    for (i = 0; map_brut[i] && map_brut[i][0] != '#'; i++);
    for (; map_brut[i]; i++) {
        add_props(&props, map_brut[i]);
    }
    return props;
}
