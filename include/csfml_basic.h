/*
** EPITECH PROJECT, 2019
** csmfl_basic.h
** File description:
** contains prototypes and structure for basic use of csfml lib
*/

#ifndef BASIC_CSFML_H_
#define BASIC_CSFML_H_

#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <unistd.h>
#include "my.h"
#include "colors.h"

#define ORIGIN (fpos(0, 0))
#define FAIL (0)
#define SUCCESS (1)

typedef struct comp_s
{
    int nbr;
    float fnbr;
    sfVector2i v2i;
    sfVector2f v2f;
    sfText *text;
    sfColor color;
    sfRectangleShape *rect;
    sfImage *image;
    sfClock *clock;
} comp_t;

typedef struct elem_s
{
    struct elem_s *next;
    struct elem_s *prev;
    comp_t **comp;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect i_rect;
    sfFloatRect hitbox;
} elem_t;

typedef struct window
{
    sfFont *font;
    sfVector2i mouse;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} window_t;

window_t *init_window(int, float, char *, int);
sfVector2i mouse_setpos(window_t *);
// Position x and y in float
sfVector2f fpos(float x, float y);
// Position x and y in int
sfVector2i ipos(int, int);
// Position x and y in unsigned int
sfVector2u upos(unsigned int x, unsigned int y);
// int update_clock(int, sprite_t **, int, double);
int update_animclock(int intervl, elem_t *element, int max);
int update_animclock_column(int intervl, elem_t *element, int max, int column);
sfVector2f get_scale(float);
sfIntRect int_area(int, int, int, int);
int check_alloc(void **, int);
int error_alloc(void);
void clear_window(window_t *);
void put_sprite(sfRenderWindow *window, sfSprite *sprite, sfVector2f pos);
void put_sprite_scale(sfRenderWindow *window, sfSprite *sprite,
sfVector2f pos, sfVector2f resize);
sfText *init_text(char *text_content, sfFont *font, sfColor color);
void print_text(sfText *text, sfVector2f, window_t *, unsigned int size);
// sprite_t *create_sprite(char *);
// sprite_t *create_spritear(char *, sfIntRect);
void free_win(window_t *);
// void free_sprite(sprite_t *sprite);
// void free_spritebyone(sprite_t **sprite);
void free_audio(sfMusic **);
sfFloatRect f_rec(float, float, float, float);
sfVertex newvertex(sfVector2f, sfColor, sfVector2f);


int fcomp(elem_t *elem, char *comp);
void update_position(elem_t *elem, sfVector2f new_pos);

#endif