/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stats_changer
*/

#include "game.h"
#include "tools.h"
#include "my.h"

void stat_message_handler(window_t *win, stats_t *stats, player_t *player)
{
    stats->text_change->pos = player->sprite->pos;
    stats->text_change->pos.x = stats->text_change->pos.x - 10;
    stats->text_change->pos.y = stats->text_change->pos.y - 10;
    disp_text(win->window, stats->text_change);
    stats->elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(
    stats->clock));
    if (stats->elapsed_time > 2.000000) {
        stats->text_change->str = NULL;
        sfClock_restart(stats->clock);
    }
}

static void set_message_level(stats_t *stats)
{
    stats->text_change->color = sfYellow;
    stats->text_change->str = "LEVEL UP";
    sfClock_restart(stats->clock);
    sfMusic_stop(stats->level_sound);
    sfMusic_play(stats->level_sound);
}

static void set_message_xp(stats_t *stats, int earned_xp)
{
    stats->text_change->color = sfGreen;
    stats->text_change->str = my_strthreecat("+ ", int_str(earned_xp),
                                                " XP");
    sfClock_restart(stats->clock);
    sfMusic_stop(stats->xp_sound);
    sfMusic_play(stats->xp_sound);
}

void add_xp(stats_t *stats, int earned_xp)
{
    stats->xp = stats->xp + earned_xp * stats->xp_bonus;
    set_message_xp(stats, earned_xp);
    while (stats->xp >= stats->xp_max) {
        stats->xp = stats->xp - stats->xp_max;
        stats->level++;
        if (stats->level % 2 == 0)
            stats->perk_points++;
        set_message_level(stats);
        stats->xp_max = 40 + 10 * stats->level;
        stats->health_max = 25 + 5 * stats->level + stats->health_bonus;
        stats->health = stats->health_max;
    }
}

void update_life(stats_t *stats, int life)
{
    stats->health = stats->health + life;
    if (stats->health > stats->health_max)
        stats->health = stats->health_max;
    if (stats->health < 0)
        stats->health = 0;
}