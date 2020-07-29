/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** displays inventory
*/

#include "game.h"
#include "tools.h"
#include "my.h"
#include "map.h"

static void set_stats(stats_t *stats)
{
    char *on_health = NULL;
    char *on_xp = NULL;

    stats->health_txt->pos = stats->stats_bg->pos;
    stats->health_txt->pos.x = stats->health_txt->pos.x + 30;
    stats->health_txt->pos.y = stats->health_txt->pos.y + 30;
    stats->xp_txt->pos = stats->health_txt->pos;
    stats->level_txt->pos = stats->health_txt->pos;
    stats->level_txt->pos.y = stats->level_txt->pos.y + 90;
    stats->xp_txt->pos.y = stats->xp_txt->pos.y + 180;
    on_health = my_strcat(" / ", int_str(stats->health_max));
    on_xp = my_strcat(" / ", int_str(stats->xp_max));
    free(stats->health_txt->str);
    free(stats->xp_txt->str);
    free(stats->level_txt->str);
    stats->health_txt->str = my_strthreecat("Health = \n     ",
        int_str(stats->health), on_health);
    stats->xp_txt->str = my_strthreecat("XP =\n     ",
        int_str(stats->xp), on_xp);
    stats->level_txt->str = my_strcat("Level =\n     ", int_str(stats->level));
}

void update_item_coords(int *item_x, int *item_y, items_list_t *element,
                            sfVector2f invent_pos)
{
    element->sprite->pos.x = invent_pos.x + 183 * *item_x + 45;
    element->sprite->pos.y = invent_pos.y + 186 * *item_y + 42;
    element->stack.pos.x = element->sprite->pos.x + 135;
    element->stack.pos.y = element->sprite->pos.y + 120;
    element->stack.str = int_str(element->nb);
    (*item_x)++;
    if (*item_x == 5) {
        *item_x = 0;
        (*item_y)++;
    }
}

void display_all_items(window_t *win, items_list_t *items_list,
                        sfVector2f invent_pos)
{
    items_list_t *element = items_list;
    int item_x = 0;
    int item_y = 0;

    while (element && item_y < 4) {
        if (element->nb) {
            update_item_coords(&item_x, &item_y, element,
                                invent_pos);
            display_sprite(win->window, element->sprite);
            if (element->nb > 1)
                disp_text(win->window, &element->stack);
        }
        element = element->next;
    }
}

static void display_inv(window_t *win, game_t *game)
{
    display_game(win, game);
    sfRenderWindow_setView(win->window, game->hud->view);
    game->inventory->pos = (sfVector2f) {200, 100};
    game->stats->stats_bg->pos.x = game->inventory->pos.x + 1080;
    game->stats->stats_bg->pos.y = game->inventory->pos.y;
    display_sprite(win->window, game->inventory);
    display_sprite(win->window, game->stats->stats_bg);
    set_stats(game->stats);
    game->stats->health_max = 25 + 5 * game->stats->level +\
    game->stats->health_bonus;
    apply_skill(game->stats->skill, game->stats, game->fight);
    if (game->stats->state == STATS) {
        disp_text(win->window, game->stats->health_txt);
        disp_text(win->window, game->stats->xp_txt);
        disp_text(win->window, game->stats->level_txt);
    } else if (game->stats->state == SKILL)
        display_skill(win->window, game->stats->skill);
    display_sprite(win->window, game->stats->b_skill);
    display_all_items(win, game->items_list, game->inventory->pos);
}

int inventory_loop(window_t *win, game_t *game)
{
    game->player->direction = NONE;
    game->player->speed_move = 6;
    sfRenderWindow_clear(win->window, sfBlack);
    game->stats->skill->perk_text->str = int_str(game->stats->perk_points);
    display_inv(win, game);
    inventory_event(win, game);
    manage_fps(win, win->fps);
    sfRenderWindow_setView(win->window, game->camera->view);
    return SUCCESS;
}