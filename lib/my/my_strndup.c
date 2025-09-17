/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** My_strndup
*/

#include "../../include/my.h"

char *my_strndup(char *str, int n)
{
    char *new_str = malloc(sizeof(char) * (n + 1));

    if (!new_str) {
        return NULL;
    }
    my_strncpy(new_str, str, n);
    new_str[n] = '\0';
    return new_str;
}
