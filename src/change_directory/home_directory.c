/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** home_directory
*/

#include "minishell.h"

void replace_old_path2(global_t *all, char *a_dir)
{
    env_t *headcpy = all->head_env;

    if (!a_dir) {
        return;
    }
    while (headcpy != NULL) {
        if (my_strcmp(headcpy->name, "OLDPWD") == 0) {
            free(headcpy->value);
            headcpy->value = my_strdup(a_dir);
            return;
        }
        headcpy = headcpy->next;
    }
}

char *get_home_path(char **env)
{
    if (env == NULL) {
        return NULL;
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME", 4) == 0) {
            return env[i] + 5;
        }
    }
    return NULL;
}

void home_directory(global_t *all, char **env)
{
    char *path = get_home_path(env);
    char buffer[BUFSIZ];
    char *actual_dir = getcwd(buffer, BUFSIZ);

    if (path == NULL) {
        my_puterr("No env variable: HOME");
        return;
    }
    if (chdir(path) != 0) {
        my_puterr(path);
        my_puterr(": No such file or directory.\n");
        return;
    }
    replace_old_path2(all, actual_dir);
}
