/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** function that copies n char of a string into another
*/

#include "my.h"

char *open_path(char *path)
{
    struct stat fileStat;
    int statopen = stat(path, &fileStat);
    char *buff = malloc(sizeof(char) * (fileStat.st_size + 1));
    int fd = open(path, O_RDONLY);
    int rd = read(fd, buff, fileStat.st_size);

    if (fileStat.st_size == 0)
        return (NULL);
    buff[rd] = '\0';
    return (buff);
}