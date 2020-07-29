/*
** EPITECH PROJECT, 2020
** map_read_ground.c
** File description:
** read map ground
*/

#include "map.h"
#include "my.h"
#include "tools.h"

void add_pattern(pattern_t **pattern_list, char b, int height, int width)
{
    pattern_t *temp = my_calloc(sizeof(pattern_t));
    char **pattern = read_file(my_strcat("maps/pattern/",
        (char [2]){b, '\0'}));
    sfTexture *texture;
    char *var = NULL;

    if (!pattern)
        return;
    var = get_var("sprite", pattern);
    if (!var)
        return;
    texture = sfTexture_createFromFile(var, NULL);
    temp->sprite = sfSprite_create();
    sfSprite_setTexture(temp->sprite, texture, sfTrue);
    sfSprite_setPosition(temp->sprite, fvec(width * 200, height * 200));
    temp->next = *pattern_list;
    *pattern_list = temp;
    free_array(pattern);
    free(var);
}

pattern_t *read_pattern(char **map_brut, sfVector2f *size)
{
    pattern_t *pattern = NULL;
    register int i = 0;
    register int c = 0;
    register int max_line = 0;

    for (i = 0; map_brut[i] && map_brut[i][0] != '#'; i++) {
        for (c = 0; map_brut[i][c]; c++) {
            add_pattern(&pattern, map_brut[i][c], i, c);
            if (c > max_line)
                max_line = c;
        }
    }
    *size = fvec((max_line) * 200, (i - 1) * 200);
    return pattern;
}