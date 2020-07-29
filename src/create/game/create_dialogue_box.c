/*
** EPITECH PROJECT, 2020
** create_dialogue_box.c
** File description:
** my_rpg
*/

#include "game.h"
#include "tools.h"
#include "my.h"
#include "quests.h"

static sprite_t *create_end_image(void)
{
    sprite_t *sprite = my_calloc(sizeof(sprite_t));

    sprite->clock = sfClock_create();
    sprite->texture = sfTexture_createFromFile(
                        "assets/image/final_scene.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->pos = ORIGIN;
    sprite->rect.left = 0;
    sprite->rect.top = 0;
    sprite->rect.width = 714;
    sprite->rect.height = 402;
    if (!sprite->texture || !sprite->sprite)
        return FAIL;
    sfSprite_setTexture(sprite->sprite,
        sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite,
        sprite->rect);
    sfSprite_setPosition(sprite->sprite,
        sprite->pos);
    return sprite;
}

static sprite_t *create_dialogue_box_sprite(void)
{
    sprite_t *dialogue_box_sprite = my_calloc(sizeof(sprite_t));

    dialogue_box_sprite->clock = sfClock_create();
    dialogue_box_sprite->texture = sfTexture_createFromFile(
                        "assets/image/dialoguebox.png", NULL);
    dialogue_box_sprite->sprite = sfSprite_create();
    dialogue_box_sprite->pos = (sfVector2f) {0, 500};
    dialogue_box_sprite->rect.left = 0;
    dialogue_box_sprite->rect.top = 0;
    dialogue_box_sprite->rect.width = 2000;
    dialogue_box_sprite->rect.height = 500;
    if (!dialogue_box_sprite->texture || !dialogue_box_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(dialogue_box_sprite->sprite,
        dialogue_box_sprite->texture, sfTrue);
    sfSprite_setTextureRect(dialogue_box_sprite->sprite,
        dialogue_box_sprite->rect);
    sfSprite_setPosition(dialogue_box_sprite->sprite,
        dialogue_box_sprite->pos);
    return dialogue_box_sprite;
}

dialogue_t *create_dialogue_box(window_t *win)
{
    dialogue_t *dialogue_box = my_calloc(sizeof(dialogue_t));

    dialogue_box->sprite = create_dialogue_box_sprite();
    dialogue_box->text = create_text_struct_fight(win);
    dialogue_box->end_image = create_end_image();
    dialogue_box->cat = create_cat_sprite();
    dialogue_box->bandit = create_bandit_sprite();
    dialogue_box->baby = create_baby_sprite();
    dialogue_box->text->pos = (sfVector2f) {70, 560};
    dialogue_box->text->size = 60;
    dialogue_box->check_pass = 0;
    dialogue_box->first_dial = 0;
    dialogue_box->prietress_dial = 0;
    dialogue_box->ok_dial = 0;
    dialogue_box->emperor_dead = 0;
    dialogue_box->cat_quest_launched = 0;
    dialogue_box->cat_quest = 0;
    dialogue_box->bandit_quest_launched = 0;
    dialogue_box->bandit_quest = 0;
    dialogue_box->bandit_killed = 0;
    dialogue_box->baby_quest_launched = 0;
    dialogue_box->baby_quest = 0;
    return dialogue_box;
}

static sprite_t *create_letter_sprite(void)
{
    sprite_t *letter_sprite = my_calloc(sizeof(sprite_t));

    letter_sprite->clock = sfClock_create();
    letter_sprite->texture = sfTexture_createFromFile
        ("assets/image/letter.png", NULL);
    letter_sprite->sprite = sfSprite_create();
    letter_sprite->pos = ORIGIN;
    letter_sprite->rect.left = -420;
    letter_sprite->rect.top = -250;
    letter_sprite->rect.width = 1420;
    letter_sprite->rect.height = 813;
    if (!letter_sprite->texture || !letter_sprite->sprite)
        return FAIL;
    sfSprite_setTexture(letter_sprite->sprite,
        letter_sprite->texture, sfTrue);
    sfSprite_setTextureRect(letter_sprite->sprite,
        letter_sprite->rect);
    sfSprite_setPosition(letter_sprite->sprite,
        letter_sprite->pos);
    return letter_sprite;
}

letter_t *create_letter(void)
{
    letter_t *letter = my_calloc(sizeof(letter_t));

    letter->activated = 0;
    letter->sprite = create_letter_sprite();
    return letter;
}