/*
** EPITECH PROJECT, 2020
** basic.h
** File description:
** basic structure (sprite)
*/

#ifndef BASIC_H_
#define BASIC_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define SUCCESS (1)
#define FAIL (0)

// From build_map.h
struct particle_engine_s;

typedef struct camera_s
{
    sfView *view;
    sfVector2f dim;
    sfVector2f pos;
} camera_t;

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
    int volume;
    sfMusic *button_se;
    sfSprite *cursor;
    struct particle_engine_s *mouse_particle;
    int se_status;
} window_t;

typedef enum button_state_n
{
    NORMAL,
    POINTED,
    CLICKED
} button_state_e;

typedef struct button_s
{
    sprite_t *img;
    text_t *text;
    button_state_e state;
} button_t;

void delete_sprite(sprite_t *sprite);
void manage_fps(window_t *win, fps_t *fps);
fps_t *create_fps(void);

// Play the button sound_effect help
int but_se(window_t *menu);

char **read_file(char *file_name);

int find_var(char *var, char **save);
char *get_var(char *var, char **save);

int modify_var(char *var, char *new_var, char ***array);
int delete_var(int var, char ***array);
int new_var(char *var, char *content, char ***array);
int browse_var_line(char *var, char **save, int v, int i);

void do_nothing(void);

#endif /* !BASIC_H_ */
