/*
** EPITECH PROJECT, 2020
** custom_commands_mouse.c
** File description:
** contains custom command handling functions
*/


#include "game.h"
#include "menu_h.h"
#include "tools.h"

int custom_command_mouse_hair(custom_t *custom, int check)
{
    if (check == 0)
        return 0;
    custom->hair_id += (check == 1) ? -1 : 1;
    if (custom->hair_id < 0)
        custom->hair_id = 0;
    if (custom->hair_id > custom->hair_nb)
        custom->hair_id = custom->hair_nb;
    return SUCCESS;
}

int custom_command_mouse_face(custom_t *custom, int check)
{
    if (check == 0)
        return 0;
    custom->face_id += (check == 1) ? -1 : 1;
    if (custom->face_id < 0)
        custom->face_id = 0;
    if (custom->face_id > custom->face_nb)
        custom->face_id = custom->face_nb;
    return SUCCESS;
}

int custom_command_mouse_shirt(custom_t *custom, int check)
{
    if (check == 0)
        return 0;
    custom->shirt_id += (check == 1) ? -1 : 1;
    if (custom->shirt_id < 0)
        custom->shirt_id = 0;
    if (custom->shirt_id > custom->shirt_nb)
        custom->shirt_id = custom->shirt_nb;
    return SUCCESS;
}

int custom_command_mouse_pants(custom_t *custom, int check)
{
    if (check == 0)
        return 0;
    custom->pants_id += (check == 1) ? -1 : 1;
    if (custom->pants_id < 0)
        custom->pants_id = 0;
    if (custom->pants_id > custom->pants_nb)
        custom->pants_id = custom->pants_nb;
    return SUCCESS;
}

int custom_command_mouse_shoes(custom_t *custom, int check)
{
    if (check == 0)
        return 0;
    custom->shoes_id += (check == 1) ? -1 : 1;
    if (custom->shoes_id < 0)
        custom->shoes_id = 0;
    if (custom->shoes_id > custom->shoes_nb)
        custom->shoes_id = custom->shoes_nb;
    return SUCCESS;
}