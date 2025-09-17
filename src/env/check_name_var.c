/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** check_name_var
*/

#include "minishell.h"

int is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_alphanumeric_or_underscore(char c)
{
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == '_');
}

int check_existing(global_t *all, char *name, char *value)
{
    env_t *headcpy = all->head_env;

    while (headcpy != NULL) {
        if (my_strcmp(headcpy->name, name) == 0) {
            free(headcpy->value);
            headcpy->value = my_strdup(value);
            return 0;
        }
        headcpy = headcpy->next;
    }
    return 1;
}

int check_name_var(global_t *all, char *name, char *value)
{
    if (!is_letter(name[0])) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        all->return_value = 1;
        return 1;
    }
    for (int i = 1; name[i] != '\0'; i++) {
        if (!is_alphanumeric_or_underscore(name[i])) {
            my_puterr("setenv: Variable name must contain");
            my_puterr(" alphanumeric characters.\n");
            all->return_value = 1;
            return 1;
        }
    }
    if (check_existing(all, name, value) == 0) {
        all->return_value = 1;
        return 1;
    }
    return 0;
}
