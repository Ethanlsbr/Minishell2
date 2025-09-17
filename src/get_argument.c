/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** get_argument
*/

#include "minishell.h"

char **get_argument(char *input)
{
    char **args = malloc(sizeof(char *) * ARGS);
    char *token;
    int i = 0;

    token = strtok(input, " \t");
    while (token != NULL && i < ARGS - 1) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t");
    }
    args[i] = NULL;
    if (args[0] == NULL)
        return NULL;
    return args;
}
