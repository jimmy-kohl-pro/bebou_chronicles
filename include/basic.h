/*
** EPITECH PROJECT, 2020
** basic.h
** File description:
** basic structure (sprite)
*/

#ifndef BASIC_H_
#define BASIC_H_

#include <SFML/Graphics.h>

#define SUCCESS (1)
#define FAIL (0)

typedef struct text_s {
    sfText *text;
    sfFont *font;
    char *str;
    unsigned int size;
    sfColor color;
    sfVector2f pos;
} text_t;

typedef struct sprite_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect hitbox;
    sfClock *clock;
} sprite_t;

typedef struct fps_s
{
    sfText *text;
    int activated;
    sfClock *clock;
    int nbr;
} fps_t;

typedef struct window
{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfVector2i mouse;
    fps_t *fps;
} window_t;

void delete_sprite(sprite_t *sprite);
void manage_fps(window_t *win, fps_t *fps);
fps_t *create_fps(void);

#endif /* !BASIC_H_ */
