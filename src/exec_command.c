/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** exec_command
*/

#include "minishell.h"

static void free_array(char **array)
{
    if (!array) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i] != NULL) {
            free(array[i]);
        }
    }
    free(array);
}

int check_binary(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        return 1;
    } else {
        close(fd);
        return 0;
    }
}

void segfault_handling(global_t *all, int status)
{
    int signal_num;

    if (WIFEXITED(status)) {
        all->return_value = WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status)) {
        signal_num = WTERMSIG(status);
        if (signal_num == SIGSEGV) {
            my_puterr("Segmentation fault");
        }
        if (WCOREDUMP(status)) {
            my_puterr(" (core dumped)");
        }
        my_puterr("\n");
        if (signal_num == SIGFPE) {
            my_puterr("Floating point exception\n");
        }
    }
}

int execute_binary(global_t *all, char **command, char *path)
{
    pid_t pid;
    int status = 0;

    if (check_binary(path) != 0)
    return 1;
    pid = fork();
    if (pid == 0) {
        execve(path, command, all->env);
        perror("execve");
        write(STDERR_FILENO, "Command execution failed\n", 25);
        exit(127);
    } else {
        wait(&status);
        segfault_handling(all, status);
    }
    return 0;
}

char **search_path(char **env)
{
    char **tab;
    char *path = NULL;
    char *tmp = NULL;

    if (env == NULL)
    return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            path = my_strdup(env[i] + 5);
            tmp = my_strdup(env[i] + 5);
            tab = my_str_to_array(tmp, ':');
            free(path);
            free(tmp);
            return tab;
        }
    }
    return NULL;
}

static int is_directory(const char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) != 0) {
        return 0;
    }
    return S_ISDIR(path_stat.st_mode);
}

static void handle_absolute_path(global_t *all, char **command, char **tab)
{
    if (is_directory(command[0])) {
        mini_printf("%s: Permission denied.\n", command[0]);
        all->return_value = 1;
        return;
    }
    if (execute_binary(all, command, command[0]) == 0) {
        free_array(tab);
        return;
    }
    mini_printf("%s: Command not found.\n", command[0]);
    all->return_value = 1;
    free_array(tab);
}

void exec_command(global_t *all, char **command)
{
    char **tab = search_path(all->env);
    char *path = NULL;

    if (tab == NULL) {
        mini_printf("No path variable set\n");
        return;
    }
    for (int i = 0; tab[i]; i++) {
        path = my_strdup(tab[i]);
        path = my_strcatdup(path, "/");
        path = my_strcatdup(path, command[0]);
        if (execute_binary(all, command, path) == 0) {
            free(path);
            free_array(tab);
            return;
        }
        free(path);
    }
    handle_absolute_path(all, command, tab);
}
