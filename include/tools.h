/*
** EPITECH PROJECT, 2020
** tools.h
** File description:
** tools header
*/

#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.h>

#define ORIGIN (fvec(0, 0))

// 2D Vector, x and y //

// 2D x and y in float
sfVector2f fvec(float x, float y);
// 2D x and y in int
sfVector2i ivec(int x, int y);
// 2D x and y in unsigned int
sfVector2u uvec(unsigned int x, unsigned int y);

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

// Update animation on several column
void update_animclock_column(int intervl, sprite_t *elem, int max, int column);

#endif /* !TOOLS_H */