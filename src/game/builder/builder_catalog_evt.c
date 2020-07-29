/*
** EPITECH PROJECT, 2020
** builder_catalog_evt.c
** File description:
** builder catalog event
*/

#include "build_map.h"
#include "game.h"
#include "tools.h"
#include "my.h"

static void released_key(game_t *game, sfEvent evt)
{
    if (evt.key.code == sfKeyEscape)
        game->state = BUILD_MODE;
    if (evt.key.code == sfKeyE)
        game->build->state = BUILD_MODE;
}

static void released_mouse(window_t *win, game_t *game)
{
    if (sfFloatRect_contains(&game->build->b_save->img->hitbox, win->mouse.x,
                            win->mouse.y) && but_se(win))
        game->state = BUILD_MODE;
}

static void passed_mouse(window_t *win, game_t *game, sfEvent event)
{
    props_list_t *element = game->build->props_list;

    while (element) {
        element->sprite_ico->hitbox = sfSprite_getGlobalBounds(
                                                element->sprite_ico->sprite);
        if (sfFloatRect_contains(&element->sprite_ico->hitbox,
                                    win->mouse.x, win->mouse.y)) {
            game->item_name->pos.x = win->mouse.x + 5;
            game->item_name->pos.y = win->mouse.y + 5;
            game->item_name->str = my_strdup(element->name);
            disp_text(win->window, game->item_name);
            event.type == sfEvtMouseButtonPressed ?
            game->build->posing_props = element : 0;
            return;
        }
        element = element->next;
    }
}

void builder_catalog_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyReleased)
            released_key(game, win->event);
        if (win->event.type == sfEvtMouseButtonReleased)
            released_mouse(win, game);
        passed_mouse(win, game, win->event);
    }
}