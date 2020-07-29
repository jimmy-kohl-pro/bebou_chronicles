/*
** EPITECH PROJECT, 2020
** map.h
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include "basic.h"

// From game.h
struct player_s;
struct game_s;

// Pattern, like grass, etc..., but may be replace by sfSprite *ground
typedef struct pattern_s
{
    sfSprite *sprite;
    struct pattern_s *next;
} pattern_t;

// Object on the map
typedef struct props_s
{
    sfSprite *sprite;
    sfFloatRect hitbox;
    sfVector2f pos;
    char *name;
    struct props_s *next;
} props_t;

typedef struct map_s
{
    pattern_t *pattern;
    sfSprite *ground;
    props_t *props;
    char *name;
    sfVector2f size;
} map_t;

// ****** Read ****** //

map_t *map_load(char *map_name);

pattern_t *read_pattern(char **map_brut, sfVector2f *size);
void add_pattern(pattern_t **pattern_list, char b, int height, int width);
void add_props(props_t **props_list, char *brut_props);

props_t *read_props(char **map_brut);
void insert_sort_y(props_t *new, props_t **head);

// ****** Display ****** //

void display_map(window_t *win, struct game_s *game);

// ****** Delete ****** //

void destroy_map(map_t **map);


#endif /* !MAP_H_ */
