/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** print_env
*/

#include "minishell.h"

void print_env(global_t *all)
{
    env_t *headcpy = all->head_env;

    while (headcpy != NULL) {
        if (headcpy->value != NULL) {
            mini_printf("%s=%s\n", headcpy->name, headcpy->value);
        } else {
            mini_printf("%s=\n", headcpy->name);
        }
        headcpy = headcpy->next;
    }
}
