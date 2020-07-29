/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** baby_quest
*/

#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "quests.h"
#include "my.h"

static void finish_baby_quest(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageois : Mon bebe ! Je ne te\n"\
            "remercierai jamais assez... Je n'ai que 30\npieces, elles sont"\
            " a toi.";
    } if (game->dialogue->check_pass == 1) {
        update_inventory(game->items_list, 5, 20);
        update_inventory(game->items_list, 7, -1);
        add_xp(game->stats, 30);
        game->dialogue->check_pass = 0;
        game->dialogue->baby_quest = 1;
        game->dialogue->activated = 0;
    }
}

static void launch_baby_quest(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageois : Au secours, j'ai perdu"\
        " mon\nbebe ! Que quelqu'un m'aide !";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str = "Musachi : Ne t'inquiete pas, je vais"\
        " le\nretrouver.";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->check_pass = 0;
        game->dialogue->baby_quest_launched = 1;
        game->dialogue->activated = 0;
    }
}

void take_baby(window_t *win, game_t *game)
{
    if (game->player->sprite->pos.x > 0
    && game->player->sprite->pos.x < 200
    && game->player->sprite->pos.y > 0
    && game->player->sprite->pos.y < 200
    && but_se(win))
        update_inventory(game->items_list, 7, 1);
    sfRenderWindow_setView(win->window, game->camera->view);
    display_sprite(win->window, game->dialogue->baby);
}

void baby_quest(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    if (game->player->sprite->pos.x > 3936
    && game->player->sprite->pos.x < 4145
    && game->player->sprite->pos.y > 1541 && game->player->sprite->pos.y < 1884
    && !game->dialogue->baby_quest_launched) {
        game->dialogue->activated = 1;
        launch_baby_quest(game);
        display_dialogue(win, game);
    } else if (game->player->sprite->pos.x > 3936
    && game->player->sprite->pos.x < 4145 && game->player->sprite->pos.y > 1541
    && game->player->sprite->pos.y < 1884
    && !game->dialogue->baby_quest && how_many_item(game->items_list, 7) >= 1) {
        game->dialogue->activated = 1;
        finish_baby_quest(game);
        display_dialogue(win, game);
    } sfRenderWindow_setView(win->window, game->camera->view);
}