/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** my_setenv
*/

#include "minishell.h"

env_t *create_node(char **command)
{
    env_t *newnode = malloc(sizeof(env_t));

    if (!newnode) {
        return NULL;
    }
    newnode->name = my_strdup(command[0]);
    if (command[1] != NULL) {
        newnode->value = my_strdup(command[1]);
    } else {
        newnode->value = NULL;
    }
    newnode->next = NULL;
    return newnode;
}

void my_setenv(global_t *all, char **command)
{
    env_t *headcpy = all->head_env;
    int nb_args = 0;

    for (; command[nb_args] != NULL; nb_args++);
    if (nb_args == 0 || nb_args > 2) {
        print_env(all);
        return;
    }
    if (check_name_var(all, command[0], command[1]) != 0)
        return;
    while (headcpy != NULL) {
        if (headcpy->next == NULL) {
            break;
        }
        headcpy = headcpy->next;
    }
    headcpy->next = create_node(command);
}
