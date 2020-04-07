/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function program
*/

#include "my.h"
#include "basic.h"
#include "menu_h.h"

static int launch(void) {
    window_t *win = NULL;
    char *seed;

    srand((size_t)&seed);
    win = create_window(1024, 16.0 / 9.0, "BEBOU CHRONICLES", -1);
    if (!win || !menu(win))
        return FAIL;
    return SUCCESS;
}

static int display_h(void)
{
    my_printf("\tUSAGE\n./my_rpg\n");
    my_printf("\tDESCRIPTION\nYou play romans and defend your empire !\n");
    return SUCCESS;
}

static int find_env_var(char *restrict var, char **restrict env)
{
    register int i = 0;
    register int v = 0;

    while (env[v] != NULL) {
        while (env[v][i] != 61) {
            if (env[v][i] == var[i])
                i++;
            else if (env[v][i] != var[i] && env[v][i] != 61)
                break;
            if (env[v][i] == 61)
                return (v);
        }
        i = 0;
        v++;
    }
    return FAIL;
}

int main(int ac, char **av, char **env)
{
    if (ac == 2 && !my_strcmp("-h", av[1]))
        display_h();
    else if (!env || !find_env_var("DISPLAY", env) ||
    !find_env_var("XAUTHORITY", env) || ac != 1)
        return 84;
    else if (!launch())
        return 84;
    return 0;
}