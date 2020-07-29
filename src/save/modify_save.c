/*
** EPITECH PROJECT, 2020
** modify_save.c
** File description:
** modfiy save file
*/

#include "save.h"
#include "my.h"

int save_dup(char ***save, char **original_save)
{
    int i = -1;

    (*save) = my_calloc(sizeof(char *) * (my_arraylen(original_save) + 1));
    if ((*save) == NULL)
        return FAIL;
    while (original_save[++i])
        (*save)[i] = my_strdup(original_save[i]);
    (*save)[i] = NULL;
    return SUCCESS;
}

int modify_var(char *var, char *new_var, char ***save)
{
    int v = find_var(var, (*save));
    char *temp_save = NULL;

    temp_save = get_var(var, (*save));
    if (!temp_save)
        return (-1);
    free((*save)[v]);
    (*save)[v] = my_calloc(sizeof(char) * (my_strlen(new_var) + 1));
    if ((*save)[v] == NULL)
        return (0);
    (*save)[v] = my_strthreecat(var, "=", new_var);
    return (1);
}

int delete_var(int var, char ***save)
{
    int save_len = my_arraylen((*save));
    char **temp_save = NULL;
    int i = -1;
    int j = -1;

    save_dup(&temp_save, (*save));
    free_array((*save));
    (*save) = my_calloc(sizeof(char *) * (save_len));
    if (!(*save))
        return (84);
    while (temp_save[++i]) {
        if (i != var) {
            ++j;
            (*save)[j] = my_strdup(temp_save[i]);
        }
    }
    j++;
    (*save)[j] = NULL;
    free_array(temp_save);
    return SUCCESS;
}

int new_var(char *var, char *content, char ***save)
{
    int i = -1;
    int save_len = my_arraylen((*save));
    char **temp_save = NULL;
    char *new_var = my_strthreecat(var, "=", content);

    save_dup(&temp_save, (*save));
    free_array((*save));
    (*save) = malloc(sizeof(char *) * (save_len + 2));
    if ((*save) == NULL)
        return (84);
    while (temp_save[++i])
        (*save)[i] = my_strdup(temp_save[i]);
    (*save)[i] = new_var;
    i++;
    (*save)[i] = NULL;
    free_array(temp_save);
    return SUCCESS;
}