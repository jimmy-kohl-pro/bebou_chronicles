/*
** EPITECH PROJECT, 2020
** map_load.c
** File description:
** map load
*/

#include "map.h"
#include "game.h"
#include "my.h"

map_t *map_load(char *map_name)
{
    char *file_name = my_strcat("maps/", map_name);
    char **map_brut = read_file(file_name);
    map_t *map = map_brut ? my_calloc(sizeof(map_t)) : NULL;

    if (!map_brut || !map)
        return NULL;
    map->name = map_name;
    map->pattern = read_pattern(map_brut, &map->size);
    map->objects = read_objects(map_brut);
    return map;
}

