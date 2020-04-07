// /*
// ** EPITECH PROJECT, 2020
// ** create_opt_button.c
// ** File description:
// ** create options buttons
// */

// #include "menu_h.h"

// static void set_button(sprite_t *sprite_button)
// {
//     sfSprite_setTexture(sprite_button->sprite, sprite_button->texture, sfTrue);
//     sfSprite_setTextureRect(sprite_button->sprite, sprite_button->rect);
//     sfSprite_setOrigin(sprite_button->sprite,
//                         fvec((float)sprite_button->rect.width / 2,
//                         (float)sprite_button->rect.height / 2));
//     sfSprite_setPosition(sprite_button->sprite, sprite_button->pos);
// }

// button_t *create_menu_play(window_t *win)
// {
//     button_t *play = my_calloc(sizeof(button_t));

//     play->img = malloc(sizeof(sprite_t));
//     play->img->texture = sfTexture_createFromFile(
//                                     "assets/image/button_play.png", NULL);
//     play->img->sprite = sfSprite_create();
//     play->img->rect.left = 0;
//     play->img->rect.top = 0;
//     play->img->rect.width = 286;
//     play->img->rect.height = 123;
//     play->img->pos.x = (float)win->mode.width / 1.25;
//     play->img->pos.y = (float)win->mode.height / 1.9;
//     if (!play->img->texture || !play->img->sprite)
//         return NULL;
//     set_button(play->img);
//     play->img->hitbox = sfSprite_getGlobalBounds(play->img->sprite);
//     return play;
// }

// button_t *create_opt_(window_t *win)
// {
//     button_t *exit = my_calloc(sizeof(button_t));

//     exit->img = my_calloc(sizeof(sprite_t));
//     exit->img->texture = sfTexture_createFromFile(
//                             "assets/image/button_exit.png", NULL);
//     exit->img->sprite = sfSprite_create();
//     exit->img->rect.left = 0;
//     exit->img->rect.top = 0;
//     exit->img->rect.width = 286;
//     exit->img->rect.height = 123;
//     exit->img->pos.x = (float)win->mode.width / 1.25;
//     exit->img->pos.y = (float)win->mode.height / 1.9 + 123 * 2;
//     if (!exit->img->texture || !exit->img->sprite)
//         return NULL;
//     set_button(exit->img);
//     exit->img->hitbox = sfSprite_getGlobalBounds(exit->img->sprite);
//     return exit;
// }

// button_t *create_opt_volume(window_t *win)
// {
//     button_t *options = my_calloc(sizeof(button_t));

//     options->img = my_calloc(sizeof(sprite_t));
//     options->img->texture = sfTexture_createFromFile(
//                             "assets/image/button_options.png", NULL);
//     options->img->sprite = sfSprite_create();
//     options->img->rect.left = 0;
//     options->img->rect.top = 0;
//     options->img->rect.width = 286;
//     options->img->rect.height = 123;
//     options->img->pos.x = (float)win->mode.width / 1.25;
//     options->img->pos.y = (float)win->mode.height / 1.9 + 123;
//     if (!options->img->texture || !options->img->sprite)
//         return NULL;
//     set_button(options->img);
//     options->img->hitbox = sfSprite_getGlobalBounds(options->img->sprite);
//     return options;
// }