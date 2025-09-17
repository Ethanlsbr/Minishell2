/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** handle_argument
*/

#include "minishell.h"

void check_return_value(global_t *all, char **command)
{
    if (command[1] != NULL) {
        all->return_value = my_getnbr(command[1]);
    } else {
        all->return_value = 0;
    }
}

void handle_argument(global_t *all, char **command)
{
    int size = 0;

    for (; command[size] != NULL; size++);
    if (my_strcmp(command[0], "cd") == 0) {
        return change_directory(all, command + 1);
    }
    if (my_strcmp(command[0], "env") == 0 && size == 1) {
        return print_env(all);
    }
    if (my_strcmp(command[0], "setenv") == 0) {
        return my_setenv(all, command + 1);
    }
    if (my_strcmp(command[0], "unsetenv") == 0) {
        return my_unsetenv(all, command + 1);
    }
    if (my_strcmp(command[0], "exit") == 0) {
        check_return_value(all, command);
        do_exit(all);
    }
    exec_command(all, command);
}
