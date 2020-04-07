/*
** EPITECH PROJECT, 2019
** getnextline.h
** File description:
** header file of getnextline, with read_size
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


#ifndef READ_SIZE
#define READ_SIZE (2048)
#endif

char *get_next_line(int);

#endif /* !GET_NEXT_LINE_H_ */