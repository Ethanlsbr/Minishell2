/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** move_directory
*/

#include "minishell.h"
#include <stdbool.h>

void replace_old_path(global_t *all, char *a_dir, char **command, bool old_dir)
{
    env_t *headcpy = all->head_env;

    if (old_dir == false) {
        if (chdir(command[0]) != 0) {
            error_gestion(all, command);
            return;
        }
    }
    if (!a_dir) {
        return;
    }
    while (headcpy != NULL) {
        if (my_strcmp(headcpy->name, "OLDPWD") == 0) {
            free(headcpy->value);
            headcpy->value = my_strdup(a_dir);
            return;
        }
        headcpy = headcpy->next;
    }
}

char *get_old_path(global_t *all)
{
    env_t *headcpy = all->head_env;

    while (headcpy != NULL) {
        if (my_strcmp(headcpy->name, "OLDPWD") == 0) {
            return my_strdup(headcpy->value);
        }
        headcpy = headcpy->next;
    }
    return NULL;
}

void move_directory(global_t *all, char **command, int nb_args)
{
    char *old_path = get_old_path(all);
    char buffer[BUFSIZ];
    char *actual_dir = getcwd(buffer, BUFSIZ);
    bool old_dir = false;

    if (my_strcmp(command[0], "-") == 0 && nb_args == 1) {
        old_dir = true;
        if (old_path == NULL) {
            my_puterr(": No such file or directory.\n");
            all->return_value = 1;
            return;
        }
        if (chdir(old_path) != 0) {
            error_gestion(all, command);
            return;
        }
    }
    replace_old_path(all, actual_dir, command, old_dir);
    free(old_path);
}
