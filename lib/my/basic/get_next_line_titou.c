/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my.h"

static char *read_file_and_check_back_n(int fd, char *str, int choose)
{
    char *buff;
    int len;
    switch (choose) {
        case 1:
            buff = my_calloc(sizeof(char *) * (READ_SIZE + 1));
            if (buff == NULL)
                return NULL;
            len = read(fd, buff, READ_SIZE);
            if (fd < 0 || len <= 0)
                return NULL;
            buff[len] = '\0';
            return buff;
        case 2:
            for (int i = 0; str[i] != '\0'; i = i + 1) {
                if (str[i] == '\n')
                    return " ";
            }
            return NULL;
        }
    return NULL;
}

static char *str_mix(char *str1, char *str2, int *nb)
{
    int i = 0;
    int j = 0;
    char *str = my_calloc(sizeof(char) * (READ_SIZE + *nb * READ_SIZE + 1));

    if (str2 == 0) {
        *nb = -2;
        return str1;
    }
    while (str1[i] != '\0') {
        str[i] = str1[i];
        i = i + 1;
    }
    while (str2[j] != '\0' && str2 != 0)
        str[i++] = str2[j++];
    str[i] = '\0';
    free(str1);
    free(str2);
    return str;
}

static char *take_what_remains(char *left, char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        i = i + 1;
    }
    i = i + 1;
    if (str[i - 1] != '\0') {
        while (str[i] != '\0') {
            left[j] = str[i];
            i = i + 1;
            j = j + 1;
        }
    }
    left[j] = '\0';
    return left;
}

static char *take_the_line(char *str)
{
    int i = 0;
    char *res;

    while (str[i] != '\n' && str[i] != '\0')
        i = i + 1;
    res = my_calloc(sizeof(char) * (i + 1));
    i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        res[i] = str[i];
        i = i + 1;
    }
    res[i] = '\0';
    free(str);
    return res;
}

char *get_next_line_titou(int fd)
{
    static int i = 2;
    static char *left = NULL;
    char *text;

    if (fd < 0 || READ_SIZE < 1)
        return NULL;
    text = read_file_and_check_back_n(fd, text, 1);
    if (text == NULL && (left == NULL || left[0] == '\0'))
        return NULL;
    if (left != NULL)
        text = str_mix(left, text, &i);
    i = 2;
    while (read_file_and_check_back_n(fd, text, 2) == NULL && i != -1) {
        text = str_mix(text, read_file_and_check_back_n(fd, text, 1), &i);
        i = i + 1;
    }
    left = my_calloc(sizeof(char) * (READ_SIZE + i * READ_SIZE + 1));
    left = take_what_remains(left, text);
    text = take_the_line(text);
    return text;
}