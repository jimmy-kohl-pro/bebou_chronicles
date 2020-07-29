/*
** EPITECH PROJECT, 2020
** create_game.c
** File description:
** create game objects
*/

#include "game.h"
#include "my.h"
#include "particle_engine.h"
#include "map.h"
#include "build_map.h"

static void create_sound(window_t *win, game_t *game)
{
    game->bg_music = sfMusic_createFromFile("assets/sound/village.ogg");
    game->bg_pause = sfMusic_createFromFile("assets/sound/rain.ogg");
    game->stats->xp_sound = sfMusic_createFromFile("assets/sound/XP.ogg");
    game->stats->level_sound = sfMusic_createFromFile(
                                            "assets/sound/level_up.ogg");
    game->fight->battle_music = sfMusic_createFromFile(
                                            "assets/sound/battle.ogg");
    sfMusic_setVolume(game->bg_music, win->volume);
    sfMusic_setVolume(game->bg_pause, win->volume);
    sfMusic_setVolume(game->stats->xp_sound, win->volume);
    sfMusic_setVolume(game->stats->level_sound, win->volume);
    sfMusic_setVolume(game->fight->battle_music, win->volume);
    sfMusic_setLoop(game->bg_music, sfTrue);
    sfMusic_setLoop(game->bg_pause, sfTrue);
    sfMusic_setLoop(game->fight->battle_music, sfTrue);
}

static void set_value(stats_t *stats)
{
    stats->attack_bonus = 1;
    stats->level = 1;
    stats->xp = 0;
    stats->health = 30;
    stats->xp_max = 50;
    stats->health_max = 30;
    stats->xp_bonus = 1;
    stats->health_bonus = 0;
}

static stats_t *create_struct_stats(window_t *win)
{
    stats_t *stats = my_calloc(sizeof(stats_t));

    stats->stats_bg = create_stats_bg(win);
    stats->health_txt = create_text_struct(win);
    stats->xp_txt = create_text_struct(win);
    stats->level_txt = create_text_struct(win);
    stats->text_change = create_text_struct(win);
    stats->state = STATS;
    stats->skill = create_struct_skill();
    stats->b_skill = create_button_skill();
    stats->health_txt->color = sfRed;
    stats->xp_txt->color = sfGreen;
    stats->level_txt->color = sfYellow;
    stats->attack = 0;
    stats->attack_bonus = 1;
    set_value(stats);
    stats->clock = sfClock_create();
    stats->perk_points = 0;
    return stats;
}

static void create_game_2(window_t *win, game_t *game)
{
    game->pnj = create_pnj();
    game->state = IN_GAME;
    game->end = sfFalse;
    game->clock_loop = sfClock_create();
    game->stats = create_struct_stats(win);
    game->fight = create_fight(win);
    game->shop = create_shop(win);
    game->fight->bonus_gold = 1;
    game->hitbox_activated = 0;
    game->build = create_builder(win);
    game->sakura = create_sakura();
    game->god = create_god();
    game->fire = create_fire_particle();
    game->quest_menu = create_quest_menu(win);
    game->cheat_mode = 0;
}

game_t *create_game(window_t *win)
{
    game_t *game = my_calloc(sizeof(game_t));

    game->map = map_load("village_map");
    game->player = create_game_player(win);
    game->camera = create_game_camera(win);
    game->hud = create_game_hud(win);
    game->esc_menu = create_game_escape_menu(win);
    game->items_list = make_inventory_list();
    game->inventory = create_inventory(win);
    game->item_name = create_text_struct(win);
    game->dialogue = create_dialogue_box(win);
    game->rain = create_rain(win);
    game->snow = create_snow();
    game->run_particle = create_run_particle();
    game->letter = create_letter();
    create_game_2(win, game);
    create_sound(win, game);
    game->build = create_builder(win);
    return game;
}