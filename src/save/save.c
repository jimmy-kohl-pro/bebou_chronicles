/*
** EPITECH PROJECT, 2020
** save.c
** File description:
** save
*/

#include "save.h"
#include "my.h"
#include "map.h"

void save(game_t *game, int n_slot)
{
    char *file_name = my_strcat("saves/slot", int_str(n_slot));
    FILE *slot = fopen(file_name, "w+");
    char **save = my_calloc(sizeof(char *) * 2);
    register int i = 0;
    register int array_len = 0;

    add_all_var(game, &save);
    array_len = my_arraylen(save);
    for (i = 0; i < array_len; i++) {
        if (fwrite(save[i], my_strlen(save[i]), 1, slot) == (size_t)-1)
            my_printf("error writing\n");
        fwrite("\n", 1, 1, slot);
    }
    free_array(save);
    free(file_name);
    fclose(slot);
}

int load_save(game_t *game, int n_slot)
{
    char *file_name = my_strcat("saves/slot", int_str(n_slot));
    char **save = read_file(file_name);

    if (!load_player_pos(game->player, &game->map, get_var("pos", save),
    get_var("map", save)) || !load_player_custom(game->player, get_var("custom",
    save)) || !load_player_stats(game, save) || !load_skill(game->stats, save)
    || !load_quest(game->dialogue, save) || !load_items(&game->items_list,
    save))
        return FAIL;
    free_array(save);
    free(file_name);
    return SUCCESS;
}