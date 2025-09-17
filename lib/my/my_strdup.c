/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** My_strdup
*/

#include "../../include/my.h"

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);

    my_strcpy(new_str, str);
    return new_str;
}
