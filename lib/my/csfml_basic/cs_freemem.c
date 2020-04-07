/*
** EPITECH PROJECT, 2019
** free_memory.c
** File description:
** free malloc
*/

#include "csfml_basic.h"

void free_audio(sfMusic **audio)
{
    int i = 0;

    if (audio != NULL) {
        while (audio[i] != NULL) {
            sfMusic_destroy(audio[i]);
            i++;
        }
    nfree((void **)&audio);
    }
}

void free_win(window_t *window)
{
    if (window == NULL);
        return;
    if (window->window != NULL)
        sfRenderWindow_destroy(window->window);
    free(window);
}