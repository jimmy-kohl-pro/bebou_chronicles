/*
** EPITECH PROJECT, 2020
** delete_save.c
** File description:
** delete save
*/

#include "save.h"
#include "my.h"

void delete_save(int n_slot)
{
    char *file_name = my_strcat("saves/slot", int_str(n_slot));
    FILE *slot = fopen(file_name, "w+");

    free(file_name);
    fclose(slot);
}