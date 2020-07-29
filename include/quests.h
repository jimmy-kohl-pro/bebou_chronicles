/*
** EPITECH PROJECT, 2020
** quests.h
** File description:
** my_rpg
*/

#ifndef QUESTS_H_
#define QUESTS_H_

#include "basic.h"

typedef struct dialogue_s
{
    sprite_t *sprite;
    sprite_t *end_image;
    sprite_t *cat;
    sprite_t *bandit;
    sprite_t *baby;
    text_t *text;
    int activated;
    int check_pass;
    int first_dial;
    int prietress_dial;
    int ok_dial;
    int emperor_dead;
    int cat_quest_launched;
    int cat_quest;
    int bandit_quest_launched;
    int bandit_killed;
    int baby_quest_launched;
    int baby_quest;
    int bandit_quest;
} dialogue_t;

typedef struct letter_s
{
    sprite_t *sprite;
    int activated;
} letter_t;

typedef struct pnj_s
{
    sprite_t *ronin;
    sprite_t *woman;
    sprite_t *man;
    sprite_t *noble;
    sprite_t *priestess;
    sprite_t *samurai;
} pnj_t;

#endif