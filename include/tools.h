/*
** EPITECH PROJECT, 2020
** tools.h
** File description:
** tools header
*/

#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.h>
#include "basic.h"

// From map.h
struct objects_s;

// From game.h
struct player_s;

#define ORIGIN (fvec(0, 0))

// 2D Vector, x and y //

// 2D x and y in float
sfVector2f fvec(float x, float y);
// 2D x and y in int
sfVector2i ivec(int x, int y);
// 2D x and y in unsigned int
sfVector2u uvec(unsigned int x, unsigned int y);

float dist_vec(sfVector2f a, sfVector2f b);

// Hitbox

// Sprite //

// Display a sprite
void display_sprite(sfRenderWindow *win, sprite_t *sprite);
// Display a sprite with a personnalized scale
void display_sprite_scl(sfRenderWindow *win, sprite_t *sprite,
sfVector2f scale);

// Text //

// Display text
void disp_text(sfRenderWindow *win, text_t *text);

// Clock //

// Update animation
void update_animclock(int intervl, sprite_t *elem, int max);
void update_animclock_pers(int intervl, sprite_t *elem, int max);

// Update animation on several column
void update_animclock_column(int intervl, sprite_t *elem, int max, int column);

void get_elapsed_time(float *time_elapsed, sfClock *clock);

// ****** SCREENSHOT ****** //

void take_screenshot(window_t *win);
sprite_t *window_to_sprite(window_t *win);

// ****** MATH ****** //

// it takes the current position of the entity, the position of its
// destination, the speed, and the time elapsed since the last frame
// (to be framerate independent).
// And it returns the new position of the entity towards its destination.
sfVector2f move_towards(sfVector2f pos, sfVector2f next_pos,
                            int speed, float elapsed_time);

int random_range(int lower, int upper);

// ****** TRANSFORM ****** //

sfSprite *sprite_turn_horizontally(sfSprite *original);

// ****** Debug ******* //

void display_hitbox(window_t *win, struct objects_s *objects,
struct player_s *player);

// ****** Cursor ****** //

void display_cursor(window_t *win, float elapsed_time);

#endif /* !TOOLS_H */