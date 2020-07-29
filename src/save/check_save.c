/*
** EPITECH PROJECT, 2020
** check_save.c
** File description:
** check_save.c
*/

#include "basic.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "save.h"

int check_save_folder(void)
{
    DIR *save_dir = opendir("./saves");

    if (!save_dir) {
        my_printf("\"saves\" folder not found, create it please\n");
        return FAIL;
    }
    closedir(save_dir);
    return SUCCESS;
}

int check_save_file(int n_slot)
{
    char *file_name = my_strcat("saves/slot", int_str(n_slot));
    char **save = read_file(file_name);

    if (!save || my_arraylen(save) == 0)
        return -1;
    free(file_name);
    free(save);
    return n_slot;
}