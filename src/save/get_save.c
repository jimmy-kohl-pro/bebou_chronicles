/*
** EPITECH PROJECT, 2020
** get_save.c
** File description:
** get save
*/

#include "basic.h"
#include "my.h"
#include "get_next_line.h"

char **read_file(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    char *buffer = NULL;
    char **file = my_calloc(sizeof(char *) * 200);
    register int i = 0;

    if (fd == -1)
        return NULL;
    buffer = get_next_line_titou(fd);
    for (i = 0; buffer; i++) {
        if (!buffer)
            return NULL;
        file[i] = my_strdup(buffer);
        free(buffer);
        buffer = get_next_line_titou(fd);
    }
    file[i] = NULL;
    close(fd);
    return file;
}

int browse_var_line(char *var, char **save, int v, int i)
{
    while (save[v][i] != 61) {
        if (save[v][i] == var[i])
            i++;
        else if (save[v][i] != var[i] && save[v][i] != 61)
            break;
        if (save[v][i] == 61)
            return (v);
    }
    return -1;
}

int find_var(char *var, char **save)
{
    int i = 0;
    int v = 0;
    int res = -1;

    while (save[v] != NULL) {
        res = browse_var_line(var, save, v, i);
        if (res != -1)
            return res;
        i = 0;
        v++;
    }
    return (-1);
}

char *get_var(char *var, char **save)
{
    int v = find_var(var, save);
    int c = 0;
    int c_var = 0;
    char *var_val = NULL;

    if (v == -1)
        return (NULL);
    var_val = my_calloc(sizeof(char) * my_strlen(save[v]) + 1);
    if (var_val == NULL)
        return (NULL);
    while (save[v][c++] != 61);
    while (save[v][c] != '\0')
        var_val[c_var++] = save[v][c++];
    return (var_val);
}