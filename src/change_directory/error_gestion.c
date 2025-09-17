/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** error_gestion
*/

#include "minishell.h"

void error_gestion(global_t *all, char **command)
{
    struct stat path_stat;

    if (!command) {
        all->return_value = 1;
        return;
    }
    if (stat(command[0], &path_stat) != 0) {
        my_puterr(command[0]);
        my_puterr(": No such file or directory.\n");
        all->return_value = 1;
        return;
    }
    if (!S_ISDIR(path_stat.st_mode)) {
        my_puterr(command[0]);
        my_puterr(": Not a directory.\n");
        all->return_value = 1;
        return;
    }
}
