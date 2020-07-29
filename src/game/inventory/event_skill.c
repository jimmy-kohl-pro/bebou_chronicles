/*
** EPITECH PROJECT, 2020
** event_skill.c
** File description:
** envent_skill
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static void click_passive(sfVector2i mouse, int *perk_point, skill_t *skill)
{
    if (sfFloatRect_contains(&skill->ico_attack->hitbox, mouse.x, mouse.y)
    && *perk_point >= 1 && !(skill->skill_unlock & ATTACK_BONUS)) {
        skill->skill_unlock |= ATTACK_BONUS;
        (*perk_point) -= 1;
    }
    if (sfFloatRect_contains(&skill->ico_runner->hitbox, mouse.x, mouse.y)
    && skill->skill_unlock & ATTACK_BONUS && *perk_point >= 1
    && !(skill->skill_unlock & SPEED_RUN)) {
        skill->skill_unlock |= SPEED_RUN;
        (*perk_point) -= 1;
    }
    if (sfFloatRect_contains(&skill->ico_health->hitbox, mouse.x, mouse.y)
    && skill->skill_unlock & SPEED_RUN && *perk_point >= 1
    && !(skill->skill_unlock & HEALTH)) {
        skill->skill_unlock |= HEALTH;
        (*perk_point) -= 1;
    }
}

static void click_active(sfVector2i mouse, int *perk_point, skill_t *skill)
{
    if (sfFloatRect_contains(&skill->ico_money->hitbox, mouse.x, mouse.y)
    && skill->skill_unlock & SPEED_RUN && *perk_point >= 1
    && !(skill->skill_unlock & MONEY_BONUS)) {
        skill->skill_unlock |= MONEY_BONUS;
        (*perk_point) -= 1;
    }
    if (sfFloatRect_contains(&skill->ico_cry->hitbox, mouse.x, mouse.y)
    && skill->skill_unlock & ATTACK_BONUS && *perk_point >= 1
    && !(skill->skill_unlock & WAR_CRY)) {
        skill->skill_unlock |= WAR_CRY;
        (*perk_point) -= 1;
    }
    if (sfFloatRect_contains(&skill->ico_ninja->hitbox, mouse.x, mouse.y)
    && skill->skill_unlock & WAR_CRY && *perk_point >= 1
    && !(skill->skill_unlock & NINJA)) {
        skill->skill_unlock |= NINJA;
        (*perk_point) -= 1;
    }
}

void click_skill(sfVector2i mouse, game_t *game, skill_t *skill)
{
    click_passive(mouse, &game->stats->perk_points, skill);
    click_active(mouse, &game->stats->perk_points, skill);
}