/*
** EPITECH PROJECT, 2020
** main_quest.c
** File description:
** my_rpg
*/

#include "quests.h"
#include "inventory.h"
#include "game.h"
#include "map.h"
#include "tools.h"
#include "my.h"

void home_letter(game_t *game)
{
    if (game->dialogue->check_pass == 0) {
        game->dialogue->text->str =
        "Tiens, une lettre. Voyons ce qu'elle contient.";
    } if (game->dialogue->check_pass == 1) {
        game->dialogue->text->str =
        "'Traitre, l'heure de la vengeance a sonne.\n"\
        "Des l'aube, ta fille sera executee sur\nla place du village.\n\n"\
        "Signe : L'Empereur'";
    } if (game->dialogue->check_pass == 2) {
        game->dialogue->text->str =
        "Non... Ce n'est pas possible... Il faut que\n"\
        "j'aille parler a la pretresse, au temple..";
    } if (game->dialogue->check_pass == 3) {
        game->dialogue->check_pass = 0;
        game->dialogue->first_dial = 1;
        game->dialogue->activated = 0;
        add_xp(game->stats, 30);
    }
}

void first_check(window_t *win, game_t *game)
{
    if (!my_strcmp("my_house", game->map->name)
    && !game->dialogue->first_dial) {
        game->dialogue->activated = 1;
        sfRenderWindow_setView(win->window, game->hud->view);
        home_letter(game);
        display_dialogue(win, game);
        sfRenderWindow_setView(win->window, game->camera->view);
    }
}

void prietress_check(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->hud->view);
    if (game->player->sprite->pos.x > 1495
    && game->player->sprite->pos.x < 2400
    && game->player->sprite->pos.y > 2595
    && game->player->sprite->pos.y < 2650
    && !game->dialogue->prietress_dial) {
        game->dialogue->activated = 1;
        temple_1(game);
        display_dialogue(win, game);
    } else if (game->player->sprite->pos.x > 1495
    && game->player->sprite->pos.x < 2400
    && game->player->sprite->pos.y > 2595
    && game->player->sprite->pos.y < 2650
    && !game->dialogue->ok_dial && how_many_item(game->items_list, 5) >= 100) {
        game->dialogue->activated = 1;
        temple_2(game);
        display_dialogue(win, game);
    } sfRenderWindow_setView(win->window, game->camera->view);
}

void palace_check(window_t *win, game_t *game)
{
    if (!my_strcmp(game->map->name, "palace_map")
    && game->player->sprite->pos.x > 2359
    && game->player->sprite->pos.x < 3065
    && game->player->sprite->pos.y < 1518) {
        game->dialogue->activated = 1;
        sfRenderWindow_setView(win->window, game->hud->view);
        palace(game);
        display_dialogue(win, game);
        sfRenderWindow_setView(win->window, game->camera->view);
    }
}

void main_quest(window_t *win, game_t *game)
{
    tp(game);
    first_check(win, game);
    if (!my_strcmp(game->map->name, "road_1"))
        check_dialogues(win, game);
    if (!my_strcmp(game->map->name, "temple_map"))
        prietress_check(win, game);
    if (!game->dialogue->emperor_dead)
        palace_check(win, game);
    else {
        sfRenderWindow_setView(win->window, game->hud->view);
        display_sprite_scl(win->window, game->dialogue->end_image,
                            (sfVector2f) {3, 3});
        sfRenderWindow_setView(win->window, game->camera->view);
    }
}