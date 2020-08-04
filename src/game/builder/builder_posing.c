/*
** EPITECH PROJECT, 2020
** builder_posing.c
** File description:
** builder pose
*/

#include "game.h"
#include "my.h"
#include "build_map.h"
#include "map.h"
#include "tools.h"

int find_objects(char *name, sfVector2f pos, char **array)
{
    register int i = 0;
    register int v = 0;
    register int res = -1;
    char **temp_pos = NULL;

    if (!name)
        return -1;
    for (v = 0; array[v] != NULL; v++) {
        res = browse_var_line(name, array, v, i);
        if (res == -1)
            continue;
        temp_pos = my_str_to_word_array(array[res], "=x");
        if (res != -1 && my_arraylen(temp_pos) == 3
        && my_getnbr(temp_pos[1]) == (int)pos.x
        && my_getnbr(temp_pos[2]) == (int)pos.y) {
            free_array(temp_pos);
            return res;
        }
        free_array(temp_pos);
        i = 0;
    }
    return (-1);
}

void delete_posing_objects(map_t **map, objects_to_del_t to_del)
{
    char *filename = my_strcat("maps/", (*map)->name);
    char **map_array = read_file(filename);
    FILE *map_file;
    register int i = 0;
    int objects_selected = -1;
    char *name_objects = NULL;

    if (!my_strcmp(to_del.name, "null"))
        return;
    name_objects = my_strdup(to_del.name);
    objects_selected = find_objects(name_objects, to_del.pos, map_array);
    if (objects_selected == -1)
        return;
    map_file = fopen(filename, "w+");
    delete_var(objects_selected, &map_array);
    for (i = 0; map_array[i]; i++) {
        if (fwrite(map_array[i], my_strlen(map_array[i]), 1, map_file)
        == (size_t)-1)
            my_printf("error writing\n");
        fwrite("\n", 1, 1, map_file);
    }
    fclose(map_file);
    free(name_objects);
    (*map) = map_load((*map)->name);
}

void add_posing_objects(map_t **map, char *name_objects, sfVector2f pos_objects)
{
    char *filename = my_strcat("maps/", (*map)->name);
    char **map_array = read_file(filename);
    FILE *map_file = fopen(filename, "w+");
    register int i = 0;

    new_var(name_objects, my_strthreecat(
            float_str(pos_objects.x, 2), "x",
            float_str(pos_objects.y, 2)), &map_array);
    for (i = 0; map_array[i]; i++) {
        if (fwrite(map_array[i], my_strlen(map_array[i]), 1, map_file)
        == (size_t)-1)
            my_printf("error writing\n");
        fwrite("\n", 1, 1, map_file);
    }
    fclose(map_file);
    *map = map_load((*map)->name);
}

void draw_posing_objects(window_t *win, objects_list_t *posing_objects,
                                                    sfView *free_cam)
{
    posing_objects->sprite->pos = sfRenderWindow_mapPixelToCoords(win->window,
                                                        win->mouse, free_cam);
    display_sprite(win->window, posing_objects->sprite);
}