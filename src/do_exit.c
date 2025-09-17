/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** do_exit
*/

#include "minishell.h"

void free_env(env_t *head_env)
{
    env_t *cpy;

    if (!head_env) {
        return;
    }
    while (head_env != NULL) {
        if (head_env->name != NULL) {
            free(head_env->name);
        }
        if (head_env->value != NULL) {
            free(head_env->value);
        }
        cpy = head_env;
        head_env = head_env->next;
        if (cpy != NULL) {
            free(cpy);
        }
    }
}

void do_exit(global_t *all)
{
    int value = all->return_value;

    if (all->input != NULL) {
        free(all->input);
    }
    free_env(all->head_env);
    free(all);
    exit(value);
}
