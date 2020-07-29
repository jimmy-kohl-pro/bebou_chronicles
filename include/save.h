/*
** EPITECH PROJECT, 2020
** save.h
** File description:
** save header
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "game.h"

// From map.h
struct map_s;

typedef struct slot_s
{
    text_t *location;
    text_t *percent_game;
    text_t *life;
    text_t *empty;
} slot_t;

typedef struct file_save_s
{
    slot_t *slot1;
    slot_t *slot2;
    slot_t *slot3;
} file_save_t;

int check_save_folder(void);

void save(game_t *game, int n_slot);
int load_save(game_t *game, int n_slot);

// ***** Save variables ******* //

void add_all_var(game_t *game, char ***save);

// ***** Load save variable ****** //

int load_player_pos(player_t *player, struct map_s **map, char *var_pos,
                                                char *var_map);

int load_player_custom(player_t *player, char *custom_brut);

int load_player_stats(game_t  *game, char **save);

int load_skill(stats_t *stats, char **save);

int load_quest(dialogue_t *dial, char **save);

int load_items(items_list_t **items_list, char **save);

// ***** Tool function to manage save variables ****** //

file_save_t *load_slot(button_t *b_1, button_t *b_2, button_t *b_3);

int check_save_file(int n_slot);

void delete_save(int n_slot);

#endif /* !SAVE_H_ */
