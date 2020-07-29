/*
** EPITECH PROJECT, 2020
** create_window.c
** File description:
** create window
*/

#include "basic.h"
#include "colors.h"
#include "my.h"
#include "tools.h"
#include "particle_engine.h"

static void create_sound_and_fps(window_t *win)
{
    win->fps = create_fps();
    win->button_se = sfMusic_createFromFile("assets/sound/button.ogg");
    win->volume = 50;
    win->se_status = 1;
}

struct particle_engine_s *create_mouse_particle(void)
{
    struct particle_engine_s *particle = create_particle_system();
    sfColor aura_color = sfColor_fromRGBA(255, 98, 137, 255);
    sfImage *aura = sfImage_createFromColor(10, 10, aura_color);
    sfTexture *aura_texture = sfTexture_createFromImage(aura, NULL);
    sfSprite *aura_sprite = sfSprite_create();

    sfSprite_setTexture(aura_sprite, aura_texture, sfTrue);
    particle_set_origin(particle, ORIGIN, DIVERGENT, 5.5);
    particle_set_range(particle, 100, 0, 100);
    particle_set_move(particle, 2, 10000, 0);
    particle_set_sizerange(particle, 1, 4, RANDOM);
    particle_add_sprite(particle, aura_sprite);
    particle_set_disappear(particle, FADE);
    return particle;
}

window_t *create_window(int height, float ratio, char *name, int bar)
{
    window_t *win = my_calloc(sizeof(window_t));
    if (!win)
        return (NULL);
    if (bar == -1)
        bar = sfClose | sfResize | sfTitlebar;
    win->mode.bitsPerPixel = 32;
    win->mode.height = height;
    win->mode.width = height * ratio;
    win->window = sfRenderWindow_create(win->mode, name, bar, NULL);
    create_sound_and_fps(win);
    if (!win->window) {
        my_printf("%s[ERR]%s Cannot create window.%s\n",
        BOLDRED, YELLOW, RESET);
        return (NULL);
    } win->cursor = sfSprite_create();
    sfSprite_setTexture(win->cursor,
        sfTexture_createFromFile("assets/image/cursor.png", NULL), sfTrue);
    win->mouse_particle = create_mouse_particle();
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    sfRenderWindow_setFramerateLimit(win->window, 90);
    return (win);
}