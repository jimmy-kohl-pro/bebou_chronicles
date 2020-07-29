/*
** EPITECH PROJECT, 2020
** display_hud.c
** File description:
** display hud
*/

#include "game.h"
#include "particle_engine.h"
#include "tools.h"
#include "map.h"
#include "build_map.h"
#include "my.h"

static void new_secondary_quest(game_t *game, char *str)
{
    if (game->quest_menu->secondary_quest1->str == NULL)
        game->quest_menu->secondary_quest1->str = str;
    else if (game->quest_menu->secondary_quest2->str == NULL)
        game->quest_menu->secondary_quest2->str = str;
    else if (game->quest_menu->secondary_quest3->str == NULL)
        game->quest_menu->secondary_quest3->str = str;
}

static void update_quests_text(game_t *game)
{
    game->quest_menu->main_quest->pos.x = game->quest_menu->bg->pos.x + 23;
    game->quest_menu->main_quest->pos.y = game->quest_menu->bg->pos.y + 100;
    game->quest_menu->secondary_quest1->pos.x = game->quest_menu->bg->pos.x + 23;
    game->quest_menu->secondary_quest1->pos.y = game->quest_menu->bg->pos.y + 180;
    game->quest_menu->secondary_quest1->str = NULL;
    game->quest_menu->secondary_quest2->pos.x = game->quest_menu->bg->pos.x + 23;
    game->quest_menu->secondary_quest2->pos.y = game->quest_menu->bg->pos.y + 220;
    game->quest_menu->secondary_quest2->str = NULL;
    game->quest_menu->secondary_quest3->pos.x = game->quest_menu->bg->pos.x + 23;
    game->quest_menu->secondary_quest3->pos.y = game->quest_menu->bg->pos.y + 260;
    game->quest_menu->secondary_quest3->str = NULL;
    if (game->dialogue->first_dial)
        game->quest_menu->main_quest->str = "Allez voir la pretresse a l'est";
    if (game->dialogue->prietress_dial)
        game->quest_menu->main_quest->str = "Recoltez 100 pieces pour\nla pretresse";
    if (game->dialogue->ok_dial)
        game->quest_menu->main_quest->str = "Allez au palais au nord.";
    if (game->dialogue->cat_quest_launched && !game->dialogue->cat_quest)
        new_secondary_quest(game, "Retrouve Sasuke le chat");
    if (game->dialogue->bandit_quest_launched && !game->dialogue->bandit_killed)
        new_secondary_quest(game, "Va tuer le bandit");
    if (game->dialogue->bandit_killed && !game->dialogue->bandit_quest)
        new_secondary_quest(game, "Rapporte ses sushis à Takeda");
    if (game->dialogue->baby_quest_launched && !game->dialogue->baby_quest)
        new_secondary_quest(game, "Retrouve le bebe");
}

static void display_quest(window_t *win, game_t *game)
{
    update_quests_text(game);
    if (!game->quest_menu->activated && game->quest_menu->bg->pos.x > -410) {
        game->quest_menu->bg->pos.x = game->quest_menu->bg->pos.x - 10;
    } if (win->mouse.x < 120 && win->mouse.y > 330 && win->mouse.y < 700
        && game->quest_menu->bg->pos.x < 0) {
        game->quest_menu->bg->pos.x = game->quest_menu->bg->pos.x + 10;
        game->quest_menu->activated = 1;
    } if (win->mouse.x > 500 || win->mouse.y < 330 || win->mouse.y > 700)
        game->quest_menu->activated = 0;
    display_sprite(win->window, game->quest_menu->bg);
    disp_text(win->window, game->quest_menu->main_quest);
    disp_text(win->window, game->quest_menu->secondary_quest1);
    disp_text(win->window, game->quest_menu->secondary_quest2);
    disp_text(win->window, game->quest_menu->secondary_quest3);
}

void display_hud(window_t *win, game_t *game)
{
    stat_message_handler(win, game->stats, game->player);
    sfRenderWindow_setView(win->window, game->hud->view);
    display_quest(win, game);
    manage_fps(win, win->fps);
    if (game->letter->activated == 1)
        display_sprite(win->window, game->letter->sprite);
    if (!my_strcmp(game->map->name, "my_house"))
        display_sprite(win->window, game->build->b_build->img);
    sfRenderWindow_setView(win->window, game->camera->view);
}