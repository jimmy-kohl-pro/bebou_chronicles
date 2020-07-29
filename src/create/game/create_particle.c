/*
** EPITECH PROJECT, 2020
** create_particle.c
** File description:
** create particle
*/

#include "particle_engine.h"
#include "game.h"
#include "tools.h"

particle_engine_t *create_rain(window_t *win)
{
    particle_engine_t *rain = create_particle_system();
    sfColor blob_color = sfColor_fromRGBA(0, 0, 255, 100);
    sfImage *blob = sfImage_createFromColor(6, 24, blob_color);
    sfTexture *blob_texture = sfTexture_createFromImage(blob, NULL);
    sfSprite *blob_sprite = sfSprite_create();

    sfSprite_setTexture(blob_sprite, blob_texture, sfTrue);
    particle_set_origin(rain,
    fvec(win->mode.width / 2, 0), LINEAR, 0);
    particle_set_range(rain, win->mode.width, -6, win->mode.height);
    particle_set_move(rain, 13, 1000, 0);
    particle_set_sizerange(rain, 2, 6, RANDOM);
    particle_add_sprite(rain, blob_sprite);
    return rain;
}

particle_engine_t *create_snow(void)
{
    particle_engine_t *snow = create_particle_system();
    sfTexture *snow_texture = sfTexture_createFromFile(
                                            "assets/image/snow.png", NULL);
    sfSprite *snow_sprite = sfSprite_create();

    sfSprite_setTexture(snow_sprite, snow_texture, sfTrue);
    particle_set_origin(snow, fvec(2900, 0), LINEAR, 0);
    particle_set_range(snow, 5800, -20, 3200);
    particle_set_move(snow, 2, 100000, 2);
    particle_set_sizerange(snow, 10, 20, RANDOM);
    particle_add_sprite(snow, snow_sprite);
    return snow;
}

particle_engine_t *create_god(void)
{
    particle_engine_t *god = create_particle_system();
    sfColor aura_color = sfColor_fromRGBA(255, 255, 255, 200);
    sfImage *aura = sfImage_createFromColor(6, 24, aura_color);
    sfTexture *aura_texture = sfTexture_createFromImage(aura, NULL);
    sfSprite *aura_sprite = sfSprite_create();

    sfSprite_setTexture(aura_sprite, aura_texture, sfTrue);
    particle_set_origin(god, ORIGIN, LINEAR, 3.2);
    particle_set_range(god, 200, 0, 400);
    particle_set_move(god, 13, 1000, 0);
    particle_set_sizerange(god, 2, 6, FADE_IN_TIME);
    particle_set_color_variation(god, RANDOM);
    particle_add_color(god, sfBlue);
    particle_add_color(god, sfYellow);
    particle_add_sprite(god, aura_sprite);
    particle_set_disappear(god, FADE);
    return god;
}

particle_engine_t *create_run_particle(void)
{
    particle_engine_t *run = create_particle_system();
    sfColor aura_color = sfColor_fromRGBA(102, 61, 21, 255);
    sfImage *aura = sfImage_createFromColor(10, 10, aura_color);
    sfTexture *aura_texture = sfTexture_createFromImage(aura, NULL);
    sfSprite *aura_sprite = sfSprite_create();

    sfSprite_setTexture(aura_sprite, aura_texture, sfTrue);
    particle_set_origin(run, ORIGIN, DIVERGENT, 3.2);
    particle_set_range(run, 100, 0, 100);
    particle_set_move(run, 5, 1000, 0);
    particle_set_sizerange(run, 4, 10, RANDOM);
    particle_add_sprite(run, aura_sprite);
    particle_set_disappear(run, FADE);
    return run;
}