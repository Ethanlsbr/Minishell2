/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell2-ethan.lesobre
** File description:
** parse_commands
*/

#include "minishell.h"

char **create_args_array(char **args, int nb)
{
    char **array = malloc(sizeof(char *) * (nb + 1));

    if (!array)
        return NULL;
    for (int i = 0; i < nb && args[i] != NULL; i++) {
        array[i] = my_strdup(args[i]);
    }
    array[nb] = NULL;
    return array;
}

astree_t *create_node_abst(char **args, int size)
{
    astree_t *newnode = malloc(sizeof(astree_t));

    if (size <= 0 || args == NULL || args[0] == NULL)
        return NULL;
    if (!newnode)
        return NULL;
    newnode->command = my_strdup(args[0]);
    newnode->arguments = malloc(sizeof(char *) * (size + 1));
    if (!newnode->arguments) {
        free(newnode);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        newnode->arguments[i] = my_strdup(args[i]);
    }
    newnode->arguments[size] = NULL;
    newnode->pipe = NULL;
    newnode->next = NULL;
    return newnode;
}

void add_to_root(global_t *all, astree_t *tmp)
{
    if (tmp) {
        tmp->next = all->tree_root;
        all->tree_root = tmp;
    }
}

void parse_commands(global_t *all, char **args)
{
    int i = 0;
    int last_pos = 0;
    astree_t *tmp;

    all->tree_root = NULL;
    for (; args[i] != NULL; i++) {
        if (my_strcmp(args[i], ";") == 0) {
            tmp = create_node_abst(args + last_pos, i - last_pos);
            add_to_root(all, tmp);
            last_pos = i + 1;
        }
    }
    if (i > last_pos) {
        tmp = create_node_abst(args + last_pos, i - last_pos);
        if (tmp) {
            tmp->next = all->tree_root;
            all->tree_root = tmp;
        }
    }
    check_command(all);
}
