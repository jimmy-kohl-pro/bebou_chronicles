/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_text_fight
*/

#include "game.h"
#include "my.h"
#include "tools.h"

void create_text_fight_stats(window_t *win, fight_t *fight)
{
    sfVector2f pos = fight->fight_hud->pos;

    fight->ennemy_health = create_text_struct_fight(win);
    fight->ennemy_health->color = sfRed;
    fight->ennemy_health->pos = (sfVector2f) {pos.x + 1400, pos.y - 450};
    fight->player_health = create_text_struct_fight(win);
    fight->player_health->color = sfRed;
    fight->player_health->pos = (sfVector2f) {pos.x + 150, pos.y - 430};
    fight->infos = create_text_struct_fight(win);
    fight->infos->pos = (sfVector2f) {pos.x + 15, pos.y + 15};
    fight->other_stats = create_text_struct_fight(win);
    fight->other_stats->pos = (sfVector2f) {pos.x + 500, pos.y + 20};
    fight->ennemy_name = create_text_struct_fight(win);
    fight->ennemy_name->pos = (sfVector2f) {pos.x + 1400, pos.y - 480};
    fight->musachi_name = create_text_struct_fight(win);
    fight->musachi_name->pos = (sfVector2f) {pos.x + 150, pos.y - 460};
    fight->musachi_name->str = "Musachi";
}

void create_text_fight(window_t *win, fight_t *fight)
{
    sfVector2f pos = fight->fight_hud->pos;

    fight->attack_low = create_text_struct_fight(win);
    fight->attack_low->str = "attack (80%)";
    fight->attack_low->pos = (sfVector2f) {pos.x + 15, pos.y + 100};
    fight->attack_high = create_text_struct_fight(win);
    fight->attack_high->str = "strong attack (40%)";
    fight->attack_high->pos = (sfVector2f) {pos.x + 15, pos.y + 140};
    fight->heal = create_text_struct_fight(win);
    fight->heal->str = "heal (potion needed)";
    fight->heal->pos = (sfVector2f) {pos.x + 15, pos.y + 180};
    fight->escape = create_text_struct_fight(win);
    fight->escape->str = "try to escape (90%)";
    fight->escape->pos = (sfVector2f) {pos.x + 15, pos.y + 220};
}