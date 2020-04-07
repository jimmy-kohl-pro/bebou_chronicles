/*
** EPITECH PROJECT, 2019
** getnextline.c
** File description:
** Get the nextline of file descriptor
*/

#include "get_next_line.h"
#include "my.h"

char *get_next_line(int fd)
{
    static char *buff;
    char *line = my_calloc(sizeof(char) * (READ_SIZE + 1));
    int rd = 0;
    int i = 0;

    if (fd == -1 || READ_SIZE == 0 || line == NULL)
        return (NULL);
    if (buff == NULL || *buff == '\0') {
        buff = my_calloc(sizeof(char) * (READ_SIZE + 1));
        rd = read(fd, buff, READ_SIZE);
        if (buff == NULL || rd == -1 || rd == 0) {
            free(buff);
            return (NULL);
        }
    }
    while (*buff != '\0' && (i == 0 || *(buff - 1) != '\n'))
        line[i++] = *buff++;
    line[i - 1] = '\0';
    return (line);
}