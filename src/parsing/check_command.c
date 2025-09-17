/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell2-ethan.lesobre
** File description:
** check_command
*/

#include "minishell.h"

void handle_redirection(global_t *all, char **cmd1, char **cmd2)
{
    int fd = open(cmd2[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int saved_stdout = dup(STDOUT_FILENO);

    if (fd == -1) {
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    handle_argument(all, cmd1);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
}

void handle_double_redirection(global_t *all, char **cmd1, char **cmd2)
{
    int fd = open(cmd2[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
    int saved_stdout = dup(STDOUT_FILENO);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    handle_argument(all, cmd1);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
}

char **get_command(char **commands, int limit)
{
    char **array = malloc(sizeof(char *) * limit + 1);

    for (int i = 0; i < limit; i++) {
        array[i] = my_strdup(commands[i]);
    }
    array[limit] = NULL;
    return array;
}

static bool check_type(global_t *all, char **args, int i, bool executed)
{
    if (my_strcmp(args[i], ">") == 0) {
        handle_redirection(all, get_command(args, i), args + i + 1);
        return true;
    }
    if (my_strcmp(args[i], ">>") == 0) {
        handle_double_redirection(all, get_command(args, i),
            args + i + 1);
            return true;
    }
    if (my_strcmp(args[i], "|") == 0) {
        execute_piped_command(all, get_command(args, i), args + i + 1);
        return true;
    }
    return executed;
}

void parse_command(global_t *all, char **args)
{
    bool executed = false;

    if (my_strcmp(args[0], ">") == 0 ||
        my_strcmp(args[0], ">>") == 0 ||
        my_strcmp(args[0], "|") == 0) {
            my_puterr("Invalid null command.\n");
            return;
    }
    for (int i = 0; args[i] != NULL; i++) {
        executed = check_type(all, args, i, executed);
    }
    if (executed == false) {
        handle_argument(all, args);
    }
}

void check_command(global_t *all)
{
    astree_t *headcpy = all->tree_root;

    if (!headcpy)
        return;
    while (headcpy != NULL) {
        if (!headcpy->arguments)
            break;
        parse_command(all, headcpy->arguments);
        headcpy = headcpy->next;
    }
}
