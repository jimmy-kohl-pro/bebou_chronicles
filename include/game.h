/*
** EPITECH PROJECT, 2020
** game.h
** File description:
** game header
*/

#ifndef GAME_H_
#define GAME_H_

#include "basic.h"

typedef struct camera_s
{
    sfView *view;
    sfVector2f dim;
    sfVector2f pos;
} camera_t;

typedef struct hud_s
{
    sfView *view;
} hud_t;

typedef enum state_n
{
    MENU_PAUSE,
    IN_OPTIONS,
    IN_HELP,
    IN_GAME,
    IN_FIGHT,
} state_e;

typedef enum direction_n
{
    NONE,
    DOWN,
    UP,
    LEFT,
    RIGHT
} direction_e;

typedef struct player_s
{
    sprite_t *sprite;
    int direction;
    int speed_move;
    int speed_anim;
} player_t;

typedef struct map_s
{
    sprite_t *sprite;
} map_t;

typedef struct game_s
{
    sfClock *clock_loop;
    float time_elapsed;
    state_e state;
    camera_t *camera;
    hud_t *hud;
    map_t *map;
    player_t *player;
} game_t;

// INIT GAME //

game_t *create_game(window_t *win);

map_t *create_game_map(window_t *win);

camera_t *create_game_camera(window_t *win);

hud_t *create_game_hud(window_t *win);

player_t *create_game_player(window_t *win);

//STATES//

int pause_loop(window_t *win, game_t *game);

int game_loop(window_t *win, game_t *game);

int option_loop(window_t *win, game_t *game);

int help_loop(window_t *win, game_t *game);

int fight_loop(window_t *win, game_t *game);

//STATES//

// GAME //

int launch_game(window_t *win);

int game_state(window_t *win, game_t *game);

int pause_event(window_t *win, game_t *game);

int game_event(window_t *win, game_t *game);

void display_game(window_t *win, game_t *game);

void display_hud(window_t *win, game_t *game);

void update_game(window_t *win, game_t *game);

int check_player_move(player_t *player, float elapsed_time);

void update_camera(camera_t *camera, player_t *player, sprite_t *map);

#endif /* !GAME_H_ */
