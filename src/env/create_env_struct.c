/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** create_env_struct
*/

#include "minishell.h"

env_t *create_newnode(char *env_var)
{
    int name_size = 0;
    env_t *newnode = malloc(sizeof(env_t));

    for (; env_var[name_size] != '\0'; name_size++) {
        if (env_var[name_size] == '=') {
            break;
        }
    }
    newnode->name = my_strndup(env_var, name_size);
    newnode->value = my_strdup(env_var + name_size + 1);
    return newnode;
}

env_t *reverse_list(env_t *head)
{
    env_t *prev = NULL;
    env_t *current = head;
    env_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void create_env_struct(global_t *all, char **env)
{
    env_t *tmp;

    if (!env) {
        return;
    }
    for (int i = 0; env[i] != NULL; i++) {
        tmp = create_newnode(env[i]);
        tmp->next = all->head_env;
        all->head_env = tmp;
    }
    all->head_env = reverse_list(all->head_env);
}
