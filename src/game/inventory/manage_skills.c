/*
** EPITECH PROJECT, 2020
** manage_skill.c
** File description:
** manage skills
*/

#include "game.h"
#include "tools.h"
#include "my.h"

void draw_ico(sfRenderWindow *win, sprite_t *ico, int unlocked, int skill_val)
{
    if (!(unlocked & skill_val))
        sfSprite_setColor(ico->sprite, sfBlack);
    else
        sfSprite_setColor(ico->sprite, sfWhite);
    sfRenderWindow_drawSprite(win, ico->sprite, NULL);
}

void display_skill(sfRenderWindow *window, skill_t *skill)
{
    sfRenderWindow_drawVertexArray(window, skill->line, NULL);
    draw_ico(window, skill->ico_attack, skill->skill_unlock, ATTACK_BONUS);
    draw_ico(window, skill->ico_runner, skill->skill_unlock, SPEED_RUN);
    draw_ico(window, skill->ico_cry, skill->skill_unlock, WAR_CRY);
    draw_ico(window, skill->ico_money, skill->skill_unlock, MONEY_BONUS);
    draw_ico(window, skill->ico_ninja, skill->skill_unlock, NINJA);
    draw_ico(window, skill->ico_health, skill->skill_unlock, HEALTH);
    disp_text(window, skill->perk_text);
    display_sprite(window, skill->ico_perk);
}

void apply_skill(skill_t *skill, stats_t *stats, fight_t *fight)
{
    if (skill->skill_unlock & ATTACK_BONUS)
        stats->attack_bonus = 2;
    if (skill->skill_unlock & SPEED_RUN)
        stats->speed_bonus = 3;
    do_nothing();
    if (skill->skill_unlock & MONEY_BONUS)
        fight->bonus_gold = 2;
    if (skill->skill_unlock & HEALTH)
        stats->health_bonus = 10;
}

void check_passed(sprite_t *sprite, window_t *win, game_t *game, char *str)
{
    if (game->stats->state == SKILL &&
    sfFloatRect_contains(&sprite->hitbox, win->mouse.x, win->mouse.y)) {
        game->item_name->str = my_strdup(str);
        game->item_name->pos.x = win->mouse.x - my_strlen(str) * 30;
        game->item_name->pos.y = win->mouse.y + 5;
        disp_text(win->window, game->item_name);
    }
    return ;
}

void passed_mouse_skill(window_t *win, game_t *game, skill_t *skill)
{
    check_passed(skill->ico_attack, win, game, "Increase x2 attack");
    check_passed(skill->ico_runner, win, game, "Increase speed move");
    check_passed(skill->ico_health, win, game, "Increase 10 health points");
    check_passed(skill->ico_money, win, game, "Increase x2 money drop");
    check_passed(skill->ico_cry, win, game, "Unlock war cry skill");
    check_passed(skill->ico_ninja, win, game,
    "Get invisble from ennemies for 20 seconds");
}