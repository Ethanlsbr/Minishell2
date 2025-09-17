/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell2-ethan.lesobre
** File description:
** execute_piped_command
*/

#include "minishell.h"

static int create_pipe(int *pipe_fd)
{
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return -1;
    }
    return 0;
}

static int create_child_process(pid_t *pid)
{
    *pid = fork();
    if (*pid == -1) {
        perror("fork");
        return -1;
    }
    return 0;
}

static void setup_child_process(int *pipe_fd, int is_child_1)
{
    if (is_child_1) {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
    } else {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], STDIN_FILENO);
    }
    close(pipe_fd[is_child_1 ? 1 : 0]);
}

static void handle_piped_child(global_t *all, char **cmd)
{
    handle_argument(all, cmd);
    exit(EXIT_SUCCESS);
}

void close_buffer(int *pipe_fd, pid_t pid1, pid_t pid2)
{
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void execute_piped_command(global_t *all, char **cmd1, char **cmd2)
{
    int pipe_fd[2];
    pid_t pid1;
    pid_t pid2;

    if (create_pipe(pipe_fd) == -1)
        return;
    if (create_child_process(&pid1) == -1)
        return;
    if (pid1 == 0) {
        setup_child_process(pipe_fd, 1);
        handle_piped_child(all, cmd1);
    }
    if (create_child_process(&pid2) == -1)
        return;
    if (pid2 == 0) {
        setup_child_process(pipe_fd, 0);
        handle_piped_child(all, cmd2);
    }
    close_buffer(pipe_fd, pid1, pid2);
}
