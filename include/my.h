/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains prototypes of all functions of libmy
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
int my_putnbr_base(long, char const *);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
char *my_strdup(char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char const *, char const *);
char *my_strncat(char *, char const *, int);
int my_intlen(int);
int my_printf(const char *, ...);
int dflag(va_list);
int oflag(va_list);
int xflag(va_list);
int big_xflag(va_list);
int uflag(va_list);
int cflag(va_list);
int sflag(va_list);
int big_sflag(va_list);
int pflag(va_list);
int perflag(va_list);
int bflag(va_list);
int my_putzero(char);
void *my_memset(char *, int, int);
void *my_calloc(size_t);
void nfree(void **);
char *open_path(char *);
int *my_lenline(char *);
int my_linenbr(char *);
int my_maxline(char *);
char **my_str_to_word_array(char *, char *);
char *my_strthreecat(char const *, char const *, char const *);
int my_arraylen(char **);
int my_print_array(char **);
int free_array(char **);
char *str_until_last(char *, char);
int str_begin_last(char **, char);
int where_last_char(char *, char);
int count_ascii(char *str, char c);
char *int_str(int);

#endif