/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ennemies
*/

#include "my.h"
#include "game.h"

static sprite_t *create_sprite(ennemies_t *ennemies, int width, int height)
{
    sprite_t *sprite = my_calloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile(ennemies->path,
                NULL);
    sprite->clock = sfClock_create();
    sprite->sprite = sfSprite_create();
    sprite->pos = (sfVector2f) {1350, 300};
    sprite->rect = (sfIntRect) {0, 0, width, height};
    sfSprite_setTexture(sprite->sprite,
        sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite,
        sprite->rect);
    sprite->hitbox = sfSprite_getGlobalBounds(
        sprite->sprite);
    return sprite;
}

static void add_to_list(ennemies_t **list, char *line)
{
    ennemies_t *element = malloc(sizeof(items_list_t));
    char **line_double = my_str_to_word_array(line, ":*");

    element->id = my_getnbr(line_double[0]);
    element->name = my_strdup(line_double[1]);
    element->path = my_strdup(line_double[2]);
    element->attack = my_getnbr(line_double[5]);
    element->health = my_getnbr(line_double[6]);
    element->sprite = create_sprite(element, my_getnbr(line_double[3]),
                                    my_getnbr(line_double[4]));
    element->next = *list;
    *list = element;
    free(line_double);
}

ennemies_t *make_ennemies_list(void)
{
    ennemies_t *ennemies = NULL;
    char *line = NULL;
    int fd = open("ennemies/ennemies", O_RDONLY);

    if (fd < 0) {
        my_printf("Error while opening the inventory file\n");
        return NULL;
    }
    line = gnl_fight(fd);
    while (line != NULL) {
        add_to_list(&ennemies, line);
        line = gnl_fight(fd);
    }
    close(fd);
    return ennemies;
}