/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pnjs_dialogues
*/

#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "quests.h"
#include "my.h"

static void pnj1_dial(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageois : Bonjour Musashi, es-tu\n"\
        "alle tester la nouvelle potion du marchand ?\n"\
        "Elle fait des miracles parait-il !";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str = "Musashi : Merci de ton conseil,\n"\
        "je vais aller voir ca !";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->check_pass = 0;
        game->dialogue->activated = 0;
        game->player->sprite->pos.x = game->player->sprite->pos.x - 120;
    }
}

static void pnj2_dial(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Villageoise : Oh Musashi ! Je ne"\
        " supporte\nplus ma femme, tu as bien raison de rester seul.";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str = "Musachi : Ce n'est pas par choix "\
        "Nobuaki...\nPrend soin d'elle.";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->check_pass = 0;
        game->dialogue->activated = 0;
        game->player->sprite->pos.x = game->player->sprite->pos.x - 100;
    }
}

static void pnj3_dial(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str = "Enfant : J'adore me promener dans les"\
        " plaines\nenneiges au dessus du village. Elles sont\ntellement "\
        "apaisantes.";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str = "Enfant : Par contre, tout a l'heure,"\
        " j'ai\nentendues des pleurs de bebe la-bas. Ca m'a fait\npeur alors"\
        " je suis vite parti.";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->check_pass = 0;
        game->dialogue->activated = 0;
        game->player->sprite->pos.y = game->player->sprite->pos.y + 100;
    }
}

void check_dialogues(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    if (game->player->sprite->pos.x > 2700
    && game->player->sprite->pos.x < 2818 && game->player->sprite->pos.y > 1257
    && game->player->sprite->pos.y < 1428) {
        game->dialogue->activated = 1;
        pnj1_dial(game);
        display_dialogue(win, game);
    } if (game->player->sprite->pos.x > 17869
    && game->player->sprite->pos.x < 17896 && game->player->sprite->pos.y > 703
    && game->player->sprite->pos.y < 900) {
        game->dialogue->activated = 1;
        pnj2_dial(game);
        display_dialogue(win, game);
    } if (game->player->sprite->pos.x > 6821
    && game->player->sprite->pos.x < 7200 && game->player->sprite->pos.y > 148
    && game->player->sprite->pos.y < 200) {
        game->dialogue->activated = 1;
        pnj3_dial(game);
        display_dialogue(win, game);
    } sfRenderWindow_setView(win->window, game->camera->view);
}