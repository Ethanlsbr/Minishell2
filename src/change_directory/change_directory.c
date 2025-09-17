/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** change_directory
*/

#include "minishell.h"

void change_directory(global_t *all, char **command)
{
    int i = 0;

    for (; command[i] != NULL; i++);
    if (i == 0) {
        return home_directory(all, all->env);
    } else {
        return move_directory(all, command, i);
    }
}
