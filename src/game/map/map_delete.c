/*
** EPITECH PROJECT, 2020
** map_delete.c
** File description:
** map delete
*/

#include "map.h"
#include <stdlib.h>

void destroy_pattern(pattern_t **pattern)
{
    pattern_t *node_delete = NULL;
    pattern_t *save_pattern = *pattern;

    while ((*pattern)->next) {
        node_delete = (*pattern);
        save_pattern = (*pattern)->next;
        node_delete->next = NULL;
        sfSprite_destroy(node_delete->sprite);
        free(node_delete);
        *pattern = save_pattern;
    }
}

void destroy_map(map_t **map)
{
    destroy_pattern(&(*map)->pattern);
    free((*map)->name);
    free((*map));
}