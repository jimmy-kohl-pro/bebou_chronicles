/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "my.h"
#include "inventory.h"

static sprite_t *create_sprite(items_list_t *items_list)
{
    sprite_t *sprite = my_calloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile(items_list->path,
                NULL);
    sprite->clock = sfClock_create();
    sprite->sprite = sfSprite_create();
    sprite->pos = (sfVector2f) {-100, 0};
    sprite->rect = (sfIntRect) {0, 0, 141, 141};
    sfSprite_setTexture(sprite->sprite,
        sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite,
        sprite->rect);
    sprite->hitbox = sfSprite_getGlobalBounds(
        sprite->sprite);
    items_list->stack = (text_t) {sfText_create(), sfFont_createFromFile(
        "assets/fonts/upheavtt.ttf"), NULL, 40, sfWhite, (sfVector2f) {0, 0}};
    return sprite;
}

static void add_to_list(items_list_t **list, char *line)
{
    items_list_t *element = malloc(sizeof(items_list_t));
    int i = -1;
    int first_sep = 0;
    int second_sep = 0;
    char *char_id = my_strdup(line);

    while (line[++i] != '\0') {
        if (line[i] == ':' && first_sep == 0)
            first_sep = i;
        else if (line[i] == ':')
            second_sep = i;
    }
    char_id[first_sep] = '\0';
    element->id = my_getnbr(char_id);
    free(char_id);
    element->name = my_strdup(line + first_sep + 1);
    element->name[second_sep - first_sep - 1] = '\0';
    element->path = my_strdup(line + second_sep + 1);
    element->next = *list;
    *list = element;
}

items_list_t *make_inventory_list(void)
{
    items_list_t *items_list = NULL;
    char *line = NULL;
    int fd = open("inventory/inventory_list", O_RDONLY);

    if (fd < 0) {
        my_printf("Error while opening the inventory file\n");
        return NULL;
    }
    line = get_next_line_titou(fd);
    while (line != NULL) {
        add_to_list(&items_list, line);
        items_list->nb = 0;
        items_list->sprite = create_sprite(items_list);
        line = get_next_line_titou(fd);
    }
    close(fd);
    set_in_inventory(items_list, 10, 1);
    set_in_inventory(items_list, 0, 1);
    set_in_inventory(items_list, 2, 3);
    return items_list;
}