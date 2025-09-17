/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** my_unsetenv
*/

#include "minishell.h"

void free_pointer(env_t *node)
{
    free(node->name);
    if (node->value != NULL) {
        free(node->value);
    }
    free(node);
}

void find_value(global_t *all, char *name)
{
    env_t *headcpy = all->head_env;
    env_t *previous = all->head_env;

    while (headcpy != NULL) {
        if (my_strcmp(headcpy->name, name) == 0) {
            previous->next = headcpy->next;
            free_pointer(headcpy);
            return;
        }
        previous = headcpy;
        headcpy = headcpy->next;
    }
}

void my_unsetenv(global_t *all, char **arguments)
{
    if (!arguments) {
        my_puterr("unsetenv: Too few arguments.\n");
        all->return_value = 1;
        return;
    }
    for (int i = 0; arguments[i] != NULL; i++) {
        find_value(all, arguments[i]);
    }
}
