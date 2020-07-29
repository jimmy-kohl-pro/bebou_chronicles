/*
** EPITECH PROJECT, 2020
** load_slot.c
** File description:
** load slot
*/

#include "save.h"
#include "my.h"
#include "tools.h"

text_t *create_text_slot(char *text_string, int size, sfVector2f pos)
{
    text_t *word = my_calloc(sizeof(text_t));
    sfFloatRect b;

    word->color = sfWhite;
    word->font = sfFont_createFromFile("assets/fonts/hiroshima.otf");
    word->pos = pos;
    word->size = size;
    word->str = text_string;
    word->text = sfText_create();
    sfText_setColor(word->text, word->color);
    sfText_setPosition(word->text, word->pos);
    sfText_setCharacterSize(word->text, size);
    sfText_setFont(word->text, word->font);
    sfText_setString(word->text, word->str);
    b = sfText_getGlobalBounds(word->text);
    sfText_setOrigin(word->text, fvec(b.width / 2, b.height / 2));
    return word;
}

void fill_slot_save(slot_t *slot, char **save, sfVector2f b_pos)
{
    if (!save || my_arraylen(save) == 0) {
        slot->empty = create_text_slot("Empty.", 60, fvec(b_pos.x,
                                                            b_pos.y));
        return ;
    }
    slot->empty = create_text_slot("Not empty", 60, fvec(b_pos.x,
                                                        b_pos.y));
}

file_save_t *load_slot(button_t *b_1, button_t *b_2, button_t *b_3)
{
    char **save1 = read_file("saves/slot1");
    char **save2 = read_file("saves/slot2");
    char **save3 = read_file("saves/slot3");
    file_save_t *saves = my_calloc(sizeof(file_save_t));

    saves->slot1 = my_calloc(sizeof(slot_t));
    saves->slot2 = my_calloc(sizeof(slot_t));
    saves->slot3 = my_calloc(sizeof(slot_t));
    fill_slot_save(saves->slot1, save1, b_1->img->pos);
    fill_slot_save(saves->slot2, save2, b_2->img->pos);
    fill_slot_save(saves->slot3, save3, b_3->img->pos);
    free_array(save1);
    free_array(save2);
    free_array(save3);
    return saves;
}