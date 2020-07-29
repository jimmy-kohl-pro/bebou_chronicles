/*
** EPITECH PROJECT, 2020
** escape_event.c
** File description:
** escape event
*/

#include "game.h"
#include "menu_h.h"
#include "tools.h"
#include "my.h"

static void pressed_key(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEscape || event.key.code == sfKeyE) {
        game->state = IN_GAME;
        game->player->direction = 0;
    }
}

static void passed_mouse(window_t *win, game_t *game)
{
    items_list_t *element = game->items_list;
    sfVector2i mouse_view = sfMouse_getPositionRenderWindow(win->window);

    while (element) {
        if (mouse_hitbox(win, *(element->sprite))) {
            game->item_name->pos.x = mouse_view.x + 5;
            game->item_name->pos.y = mouse_view.y + 5;
            game->item_name->str = my_strdup(element->name);
            disp_text(win->window, game->item_name);
            return;
        }
        element = element->next;
    }
}

void released_mouse(window_t *win, sfVector2i mouse, game_t *game)
{
    items_list_t *element = game->items_list;

    while (element) {
        if (mouse_hitbox(win, *(element->sprite)) && element->id == 2
        && but_se(win)) {
            update_inventory(game->items_list, 2, -1);
            update_life(game->stats, 15);
        }
        element = element->next;
    }
    if (game->stats->state == STATS &&
    sfFloatRect_contains(&(game->stats->b_skill->hitbox),
                            (float)mouse.x, (float)mouse.y) && but_se(win))
        game->stats->state = SKILL;
    else if (game->stats->state == SKILL &&
    sfFloatRect_contains(&(game->stats->b_skill->hitbox),
                            (float)mouse.x, (float)mouse.y) && but_se(win))
        game->stats->state = STATS;
    if (game->stats->state == SKILL)
        click_skill(mouse, game, game->stats->skill);
}

int inventory_event(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtMouseButtonReleased)
            released_mouse(win, win->mouse, game);
        if (win->event.type == sfEvtKeyPressed)
            pressed_key(game, win->event);
    }
    passed_mouse(win, game);
    passed_mouse_skill(win, game, game->stats->skill);
    return SUCCESS;
}