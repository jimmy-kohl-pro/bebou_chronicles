/*
** EPITECH PROJECT, 2020
** create_particle.c
** File description:
** create particle
*/

#include "particle_engine.h"
#include "game.h"
#include "tools.h"

sfSprite *create_petal(sfTexture *texture, int nb)
{
    sfSprite *sakura_sprite = sfSprite_create();

    sfSprite_setTexture(sakura_sprite, texture, sfTrue);
    sfSprite_setTextureRect(sakura_sprite, (sfIntRect){193 * nb, 0, 193, 200});
    return sakura_sprite;
}

particle_engine_t *create_sakura(void)
{
    particle_engine_t *sakura = create_particle_system();
    sfTexture *sakura_texture = sfTexture_createFromFile(
                                            "assets/image/sakura.png", NULL);
    sfSprite *sakura_sprite = create_petal(sakura_texture, 0);
    sfSprite *sakura1_sprite = create_petal(sakura_texture, 1);
    sfSprite *sakura2_sprite = create_petal(sakura_texture, 2);
    sfSprite *sakura3_sprite = create_petal(sakura_texture, 3);

    particle_set_origin(sakura, fvec(2900 + 100, 0), LINEAR, 0);
    particle_set_range(sakura, 5800 + 2000, -2000, 3200);
    particle_set_move(sakura, 3, 500000, 2);
    particle_set_sizerange(sakura, 40, 60, RANDOM);
    particle_add_sprite(sakura, sakura_sprite);
    particle_add_sprite(sakura, sakura1_sprite);
    particle_add_sprite(sakura, sakura2_sprite);
    particle_add_sprite(sakura, sakura3_sprite);
    return sakura;
}

particle_engine_t *create_fire_particle(void)
{
    particle_engine_t *fire = create_particle_system();
    sfColor aura_color = sfColor_fromRGBA(255, 255, 255, 255);
    sfImage *aura = sfImage_createFromColor(10, 10, aura_color);
    sfTexture *aura_texture = sfTexture_createFromImage(aura, NULL);
    sfSprite *aura_sprite = sfSprite_create();

    sfSprite_setTexture(aura_sprite, aura_texture, sfTrue);
    particle_set_origin(fire, ORIGIN, DIVERGENT, 3.2);
    particle_set_range(fire, 100, 0, 120);
    particle_set_move(fire, 2, 2000, 0);
    particle_set_sizerange(fire, 4, 10, RANDOM);
    particle_add_sprite(fire, aura_sprite);
    particle_set_color_variation(fire, RANDOM);
    particle_add_color(fire, sfColor_fromRGB(255, 165, 0));
    particle_add_color(fire, sfColor_fromRGB(255, 69, 0));
    particle_add_color(fire, sfColor_fromRGB(255, 140, 0));
    particle_set_disappear(fire, FADE);
    return fire;
}
