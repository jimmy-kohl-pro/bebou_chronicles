/*
** EPITECH PROJECT, 2020
** builder_catalog.c
** File description:
** builder catalog
*/

#include "build_map.h"
#include "game.h"
#include "tools.h"
#include "my.h"

void update_objects_coords(int *item_x, int *item_y, objects_list_t *element,
                            sfVector2f invent_pos)
{
    element->sprite_ico->pos.x = invent_pos.x + 183 * *item_x + 45;
    element->sprite_ico->pos.y = invent_pos.y + 186 * *item_y + 42;
    element->stack.pos.x = element->sprite_ico->pos.x + 135;
    element->stack.pos.y = element->sprite_ico->pos.y + 120;
    element->stack.str = int_str(element->nb);
    (*item_x)++;
    if (*item_x == 5) {
        *item_x = 0;
        (*item_y)++;
    }
}

void display_all_objects(window_t *win, objects_list_t *items_list,
                        sfVector2f invent_pos)
{
    objects_list_t *element = items_list;
    int item_x = 0;
    int item_y = 0;

    while (element && item_y < 4) {
        if (element->nb) {
            update_objects_coords(&item_x, &item_y, element,
                                invent_pos);
            display_sprite(win->window, element->sprite_ico);
            if (element->nb > 1)
                disp_text(win->window, &element->stack);
        }
        element = element->next;
    }
}

void display_catalog(window_t *win, game_t *game)
{
    display_sprite(win->window, game->build->catalog);
    display_all_objects(win, game->build->objects_list, game->build->catalog->pos);
}