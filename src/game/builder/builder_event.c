/*
** EPITECH PROJECT, 2020
** builder_event.c
** File description:
** builder event
*/

#include "game.h"
#include "build_map.h"
#include "tools.h"

void manage_build_camera(window_t *win, sfView *view, float elapsed_time)
{
    sfVector2f orig_size = sfView_getSize(view);

    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
        sfView_move(view,
        fvec(0, -4 * elapsed_time / ((float)win->mode.width / orig_size.x)));
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
        sfView_move(view,
        fvec(0, 4 * elapsed_time / ((float)win->mode.width / orig_size.x)));
    if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
        sfView_move(view,
        fvec(-4 * elapsed_time / ((float)win->mode.width / orig_size.x), 0));
    if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
        sfView_move(view,
        fvec(4 * elapsed_time / ((float)win->mode.width / orig_size.x), 0));
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        sfView_zoom(view, (float)0.99);
    if (sfKeyboard_isKeyPressed(sfKeyLControl))
        sfView_zoom(view, (float)1.01);
}

static void released_key(window_t *win, game_t *game,
                        sfEvent evt, props_list_t **posing_props)
{
    sfFloatRect rect;
    props_to_del_t temp;

    if (evt.mouseButton.button == sfMouseRight && !(*posing_props)) {
        temp = find_click_props(
        sfRenderWindow_mapPixelToCoords(win->window, win->mouse,
        game->build->view), game->map->props);
        delete_posing_props(&game->map, temp);
    }
    if ((evt.key.code == sfKeyEscape || evt.mouseButton.button == sfMouseRight)
    && posing_props)
        (*posing_props) = NULL;
    else if (evt.key.code == sfKeyEscape) {
        game->state = IN_GAME;
        game->player->direction = 0;
    }
    if (evt.mouseButton.button == sfMouseLeft && (*posing_props)) {
        rect = sfSprite_getGlobalBounds((*posing_props)->sprite->sprite);
        add_posing_props(&game->map, (*posing_props)->name,
        (sfVector2f){(*posing_props)->sprite->pos.x - rect.width / 2,
        (*posing_props)->sprite->pos.y - rect.height / 2});
    }
    if (evt.key.code == sfKeyE)
        game->build->state = CATALOG;
}

static void released_mouse(window_t *win, game_t *game)
{
    if (sfFloatRect_contains(&game->build->b_save->img->hitbox, win->mouse.x,
                            win->mouse.y) && but_se(win)) {
        game->state = IN_GAME;
        game->player->direction = 0;
    }
}

void builder_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyReleased
        || win->event.type == sfEvtMouseButtonPressed)
            released_key(win, game, win->event, &game->build->posing_props);
        if (win->event.type == sfEvtMouseButtonReleased)
            released_mouse(win, game);
    }
}