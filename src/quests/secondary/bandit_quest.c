/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** bandit_quest
*/

#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "quests.h"
#include "my.h"

void attack_bandit(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    if (game->player->sprite->pos.x > 8960
    && game->player->sprite->pos.x < 9100 && game->player->sprite->pos.y > 100
    && game->player->sprite->pos.y < 200) {
        game->dialogue->activated = 1;
        if (game->dialogue->check_pass == 0) {
            game->dialogue->text->str = "Bandit : Tu veux que je te rende"\
            " les sushis de\nTakeda ? Jamais de mon vivant !";
        } if (game->dialogue->check_pass == 1) {
            game->dialogue->check_pass = 0;
            launch_fight(game, 5);
            game->dialogue->bandit_killed = 1;
            game->dialogue->activated = 0;
        }
        display_sprite(win->window, game->dialogue->sprite);
        disp_text(win->window, game->dialogue->text);
    }
    sfRenderWindow_setView(win->window, game->camera->view);
    display_sprite_scl(win->window, game->dialogue->bandit,
                        (sfVector2f) {3, 3});
}

static void finish_bandit_quest(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageois : Oh merci ! Tu as"\
        " retrouve ma\nnourriture ! Voila 30 pieces pour te remercier.";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->check_pass = 0;
        game->dialogue->bandit_quest = 1;
        update_inventory(game->items_list, 5, 30);
        update_inventory(game->items_list, 6, -1);
        add_xp(game->stats, 30);
        game->dialogue->activated = 0;
    }
}

static void launch_bandit_quest(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageois : Un bandit m'a vole ma"\
        " nourriture,\npeux-tu le tuer et me la rendre ?";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str = "Villageois : Il doit tres probablement"\
        " se situer\nsur la route entre le village et le temple.";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->check_pass = 0;
        game->dialogue->bandit_quest_launched = 1;
        game->dialogue->activated = 0;
    }
}

void bandit_quest(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    if (game->player->sprite->pos.x > 2172
    && game->player->sprite->pos.x < 2408 && game->player->sprite->pos.y > 1632
    && game->player->sprite->pos.y < 2100
    && !game->dialogue->bandit_quest_launched) {
        game->dialogue->activated = 1;
        launch_bandit_quest(game);
        display_dialogue(win, game);
    } else if (game->player->sprite->pos.x > 2171
    && game->player->sprite->pos.x < 2408 && game->player->sprite->pos.y > 1632
    && game->player->sprite->pos.y < 2100 && !game->dialogue->bandit_quest
    && how_many_item(game->items_list, 6) >= 1) {
        game->dialogue->activated = 1;
        finish_bandit_quest(game);
        display_dialogue(win, game);
    } sfRenderWindow_setView(win->window, game->camera->view);
}