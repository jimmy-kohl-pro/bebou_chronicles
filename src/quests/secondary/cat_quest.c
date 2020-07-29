/*
** EPITECH PROJECT, 2020
** rpg_bis
** File description:
** secondary_quest
*/

#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "quests.h"
#include "my.h"

static void finish_cat_quest(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageois : Oh merci ! Tu as\n"\
            "retrouve Sasuke ! Voila tes 20 pieces.";
    } if (game->dialogue->check_pass == 1) {
        update_inventory(game->items_list, 5, 20);
        update_inventory(game->items_list, 3, -1);
        add_xp(game->stats, 20);
        game->dialogue->check_pass = 0;
        game->dialogue->cat_quest = 1;
        game->dialogue->activated = 0;
    }
}

static void launch_cat_quest(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageoise : Aide moi a retrouver mon"\
        " chat et je\nt'offrirai 20 pieces en gage de gratitude !";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->check_pass = 0;
        game->dialogue->cat_quest_launched = 1;
        game->dialogue->activated = 0;
    }
}

void take_cat(window_t *win, game_t *game)
{
    if (game->player->sprite->pos.x > 5108
    && game->player->sprite->pos.x < 5282
    && game->player->sprite->pos.y > 2170
    && game->player->sprite->pos.y < 2312
    && but_se(win))
        update_inventory(game->items_list, 3, 1);
}

void cat_quest(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    if (game->player->sprite->pos.x > 303
    && game->player->sprite->pos.x < 746
    && game->player->sprite->pos.y > 2130
    && game->player->sprite->pos.y < 2480
    && !game->dialogue->cat_quest_launched) {
        game->dialogue->activated = 1;
        launch_cat_quest(game);
        display_dialogue(win, game);
    } else if (game->player->sprite->pos.x > 303
    && game->player->sprite->pos.x < 746
    && game->player->sprite->pos.y > 2130
    && game->player->sprite->pos.y < 2480
    && !game->dialogue->cat_quest && how_many_item(game->items_list, 3) >= 1) {
        game->dialogue->activated = 1;
        finish_cat_quest(game);
        display_dialogue(win, game);
    } sfRenderWindow_setView(win->window, game->camera->view);
}