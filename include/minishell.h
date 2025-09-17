/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** minishell
*/

#ifndef INCLUDED_MINISHELL_H
    #define INCLUDED_MINISHELL_H

    #include "my.h"
    #include "struct.h"
    #include <signal.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <stdbool.h>
    #define ARGS 100

void signal_handler(void);
void exec_command(global_t *all, char **command);
void handle_argument(global_t *all, char **command);
void change_directory(global_t *all, char **command);
void move_directory(global_t *all, char **command, int nb_args);
void home_directory(global_t *all, char **env);
void print_env(global_t *all);
void do_exit(global_t *all);
void create_env_struct(global_t *all, char **env);
void my_setenv(global_t *all, char **command);
void my_unsetenv(global_t *all, char **arguments);
char *my_strcatdup(char *dest, char const *src);
char **get_argument(char *input);
int check_name_var(global_t *all, char *name, char *value);
void error_gestion(global_t *all, char **command);
void parse_commands(global_t *all, char **args);
void execute_piped_command(global_t *all, char **cmd1, char **cmd2);
void check_command(global_t *all);

#endif
