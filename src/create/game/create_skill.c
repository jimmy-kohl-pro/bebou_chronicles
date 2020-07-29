/*
** EPITECH PROJECT, 2020
** create_skill.c
** File description:
** create skill
*/

#include "game.h"
#include "tools.h"
#include "my.h"

static sprite_t *create_icone(char *path, sfVector2f pos)
{
    sprite_t *icone = my_calloc(sizeof(sprite_t));
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    icone->sprite = sfSprite_create();
    icone->pos = pos;
    sfSprite_setTexture(icone->sprite, texture, sfTrue);
    icone->hitbox = sfSprite_getGlobalBounds(icone->sprite);
    sfSprite_setOrigin(icone->sprite,
    fvec(icone->hitbox.width / 2, icone->hitbox.height / 2));
    sfSprite_setPosition(icone->sprite, icone->pos);
    icone->hitbox = sfSprite_getGlobalBounds(icone->sprite);
    return icone;
}

void create_tree_line(skill_t *skill)
{
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_attack->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_runner->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_runner->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_health->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_runner->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_money->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_attack->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_cry->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_cry->pos, sfWhite, ORIGIN});
    sfVertexArray_append(skill->line,
    (sfVertex){skill->ico_ninja->pos, sfWhite, ORIGIN});
}

text_t *create_perk_text(void)
{
    text_t *texts = my_calloc(sizeof(text_t));

    texts->text = sfText_create();
    sfText_setOutlineColor(texts->text, sfWhite);
    texts->color = sfYellow;
    texts->font = sfFont_createFromFile("assets/fonts/upheavtt.ttf");
    sfText_setFont(texts->text, texts->font);
    texts->pos = fvec(1350, 150);
    texts->size = 50;
    texts->str = my_strdup("0");
    return texts;
}

skill_t *create_struct_skill(void)
{
    skill_t *skill = my_calloc(sizeof(skill_t));

    skill->skill_unlock = 0;
    skill->line = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(skill->line, sfLines);
    skill->ico_attack = create_icone("assets/ico/attack.png", fvec(1510, 610));
    skill->ico_runner = create_icone("assets/ico/runner.png", fvec(1440, 450));
    skill->ico_money = create_icone("assets/ico/money.png", fvec(1350, 270));
    skill->ico_health = create_icone("assets/ico/health.png", fvec(1500, 270));
    skill->ico_cry = create_icone("assets/ico/cry.png", fvec(1630, 450));
    skill->ico_ninja = create_icone("assets/ico/ninja.png", fvec(1630, 270));
    skill->ico_perk = create_icone("assets/ico/medal.png", fvec(1315, 185));
    skill->perk_text = create_perk_text();
    create_tree_line(skill);
    return skill;
}

sprite_t *create_button_skill(void)
{
    sprite_t *button = my_calloc(sizeof(sprite_t));
    sfTexture *texture = sfTexture_createFromFile(
        "assets/image/button_skill.png", NULL);

    button->sprite = sfSprite_create();
    button->pos = fvec(1375, 700);
    sfSprite_setTexture(button->sprite, texture, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    button->hitbox = sfSprite_getGlobalBounds(button->sprite);
    return button;
}