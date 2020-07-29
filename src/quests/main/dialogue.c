/*
** EPITECH PROJECT, 2020
** rpg_bis
** File description:
** dialogue
*/

#include "quests.h"
#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"

static void palace_2(game_t *game)
{
    if (game->dialogue->check_pass == 2) {
        game->dialogue->text->str =
        "Musashi : Rends moi ma fille et tu auras\nla vie sauve.";
    } if (game->dialogue->check_pass == 3) {
        game->dialogue->text->str =
        "Empereur : Jamais. Elle mourra pour ta desertion.";
    } if (game->dialogue->check_pass == 4) {
        game->dialogue->text->str = "Musashi : Tu l'auras voulu.";
    }
}

void palace(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str =
        "Musashi : Aujourd'hui est le jour de ta mort\n"\
        "maudit Empereur. Sakura, sauve-toi avec moi.";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str =
        "Empereur : Tu ne peux rien contre moi, sale\ntraitre. Tu vas payer"\
        " pour ta lachete,\net jamais tu n'auras la main de Sakura.";
    }
    palace_2(game);
    if (game->dialogue->check_pass == 5) {
        game->dialogue->check_pass = 0;
        game->dialogue->activated = 0;
        launch_fight(game, 4);
        if (game->stats->health > 0)
            game->dialogue->emperor_dead = 1;
    }
}

void temple_1(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str =
        "Pretresse : Musashi, que me vaut l'honneur de\n"\
        "ta visite ?";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str =
        "Musashi : Ma fille a ete kidnappee par\n"\
        "l'empereur, j'ai besoin de votre aide.";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->text->str =
        "Pretresse : Pour 100 pieces, je peux te donner\n"\
        "le legendaire sabre du samourai dechu.\n"\
        "Ce katana fait 3 fois plus mal que celui en bois.\n"\
        "Pour trouver cet argent, tu peux essayer\nd'aider un villageois !\n";
    } if (game->dialogue->check_pass == 3) {
        game->dialogue->check_pass = 0;
        game->dialogue->prietress_dial = 1;
        game->dialogue->activated = 0;
    }
}

void temple_2(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str =
        "Musashi : Voici les 100 pieces. Je te remercie\npretresse.";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str =
        "Pretresse : Merci, Musachi. le legendaire\n"\
        "sabre du samourai dechu est a toi.";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->text->str =
        "Musashi : Il faut desormais que j'aille au\n"\
        "palais pour vaincre l'Empereur et sauver ma fille.\n"\
        "Si mes souvenirs sont exacts, il doit se \nsituer au nord d'ici.";
    } if (game->dialogue->check_pass == 3) {
        update_inventory(game->items_list, 8, 1);
        update_inventory(game->items_list, 5, -100);
        add_xp(game->stats, 50);
        game->dialogue->check_pass = 0;
        game->dialogue->ok_dial = 1;
        game->dialogue->activated = 0;
    }
}

void display_dialogue(window_t *win, game_t *game)
{
    display_sprite(win->window, game->dialogue->sprite);
    disp_text(win->window, game->dialogue->text);
}