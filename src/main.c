/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** main
*/

#include "minishell.h"

static void free_args(global_t *all)
{
    if (all->command != NULL) {
        free(all->command);
    }
    return;
}

void free_struct(global_t *all)
{
    free(all->input);
    for (int i = 0; all->command[i] != NULL; i++) {
        free(all->command[i]);
    }
    free(all->command);
    free(all);
}

void remove_char(global_t *all)
{
    int i = 0;

    for (; all->input[i] != '\0'; i++);
    all->input[i - 1] = '\0';
}

void echo_used(global_t *all)
{
    if (!isatty(STDIN_FILENO)) {
        do_exit(all);
    }
}

int shell_loop(global_t *all)
{
    size_t len = 0;

    while (1) {
        if (all->input != NULL)
            free(all->input);
        all->input = NULL;
        if (isatty(STDIN_FILENO))
            my_putstr("$> ");
        if (getline(&all->input, &len, stdin) == -1) {
            echo_used(all);
            my_putstr("exit\n");
            do_exit(all);
        }
        remove_char(all);
        all->command = get_argument(all->input);
        if (all->command != NULL)
            parse_commands(all, all->command);
        free_args(all);
    }
}

int main(int ac, __attribute__((unused))char **av, char **env)
{
    global_t *all = malloc(sizeof(global_t));

    if (!all) {
        perror("malloc");
        exit(84);
    }
    all->command = NULL;
    all->input = NULL;
    all->return_value = 0;
    all->head_env = NULL;
    all->env = env;
    if (ac != 1) {
        my_puterr("No argument expected\n");
        do_exit(all);
    }
    create_env_struct(all, env);
    signal_handler();
    return shell_loop(all);
}
