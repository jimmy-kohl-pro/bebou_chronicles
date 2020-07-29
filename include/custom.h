/*
** EPITECH PROJECT, 2020
** custom.h
** File description:
** include of custom structs
*/

#ifndef CUSTOM_H
#define CUSTOM_H

typedef struct custom_buttons_s
{
    button_t *b_head;
    button_t *b_face;
    button_t *b_shirt;
    button_t *b_pants;
    button_t *b_shoes;
    button_t *c_right;
    button_t *c_left;

}c_button_t;

typedef struct custom_s
{
    int hair_id;
    int face_id;
    int shirt_id;
    int pants_id;
    int shoes_id;
    sprite_t **face;
    sprite_t **hair;
    sprite_t **shirt;
    sprite_t **pants;
    sprite_t **shoes;
    int hair_nb;
    int face_nb;
    int shirt_nb;
    int pants_nb;
    int shoes_nb;
    sprite_t *bg_chara;
    sprite_t *custom_bg;
    c_button_t *c_buttons;
    int which_part;
} custom_t;

sprite_t *create_chara_bg(void);
sprite_t *create_custom_bg(void);

#endif /* !CUSTOM_H */
