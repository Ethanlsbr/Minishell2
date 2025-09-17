/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell2-ethan.lesobre
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

    #include "minishell.h"

typedef enum {
    COMMANDS,
    PIPE,
    REDIRECT,
    SEMICOLLON,
}node_type_t;

/* Struct for the abstract syntax tree. */
typedef struct astree_s {
    char *command;
    char **arguments;
    node_type_t type;
    char *file_name;
    struct astree_s *pipe;
    struct astree_s *next;
}astree_t;

/* Struct for the environement variable. */
typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
}env_t;

typedef struct global_s {
    int return_value;
    char **command;
    char *input;
    env_t *head_env;
    char **env;
    astree_t *tree_root;
}global_t;

#endif
