/*
** EPITECH PROJECT, 2020
** build_map.h
** File description:
** build map
*/

#ifndef BUILD_MAP_H_
#define BUILD_MAP_H_

#include "game.h"
#include "map.h"

// From map.h
struct map_s;

typedef struct props_list
{
    int id;
    char *name;
    char *path;
    int nb;
    sprite_t *sprite_ico;
    sprite_t *sprite;
    text_t stack;
    struct props_list *next;
} props_list_t;

typedef struct props_to_del_s
{
    char *name;
    sfVector2f pos;
} props_to_del_t;

typedef enum state_build_n
{
    BUILD_MODE,
    CATALOG
} state_build_e;

typedef struct build_s
{
    sfView *view;
    props_list_t *props_list;
    props_list_t *posing_props;
    sprite_t *catalog;
    button_t *b_build;
    button_t *b_save;
    state_build_e state;
} build_t;

// ****** Create Builder ****** //

build_t *create_builder(window_t *win);

button_t *create_button_build(window_t *win);
button_t *create_button_save_build(window_t *win);

props_list_t *create_props_list(void);

// ****** Event ****** //

void builder_catalog_event(window_t *win, game_t *game);
void builder_event(window_t *win, game_t *game);
void manage_build_camera(window_t *win, sfView *view, float elapsed_time);

// ****** Catalog ****** //

void display_catalog(window_t *win, game_t *game);

// ****** Posing props ****** //

void draw_posing_props(window_t *win, props_list_t *posing_props,
                                                    sfView *free_cam);
void add_posing_props(map_t **map, char *name_props, sfVector2f pos_props);

void delete_posing_props(map_t **map, props_to_del_t to_del);

props_to_del_t find_click_props(sfVector2f mouse, struct props_s *props);

#endif /* !BUILD_MAP_H_ */
