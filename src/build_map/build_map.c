/*
** EPITECH PROJECT, 2020
** map_creation.c
** File description:
** map creation
*/

#include "game.h"
#include "build_map.h"
#include "my.h"
#include "fcntl.h"
#include "sys/stat.h"
#include "sys/types.h"

void initiate_list(char *temp, map_gen **head)
{
    (*head) = malloc(sizeof(map_gen));
    (*head)->line = temp;
    (*head)->next = NULL;
}

void create_new_node(char *temp, map_gen **head)
{
    map_gen *new = malloc(sizeof(map_gen));
    map_gen *inter = (*head);

    while (inter->next != NULL)
        inter = inter->next;
    inter->next = new;
    new->line = temp;
    new->next = NULL;
}

map_gen *create_list(map_gen **head, char *temp)
{
    if ((*head) == NULL)
        initiate_list(temp, head);
    else {
        create_new_node(temp, head);
    }
}

map_gen *build_map(char *filepath)
{
    int check = 0;
    int index = 0;
    int fd = open(filepath, O_RDONLY);
    char *temp;
    map_gen *head = NULL;

    if (fd == -1) {
        return NULL;
    }
    while (check != -1) {
        temp = get_next_line_titou(fd);
        create_list(&head, temp);
        check = (temp == NULL) ? -1 : 0;
    }
    return head;
}