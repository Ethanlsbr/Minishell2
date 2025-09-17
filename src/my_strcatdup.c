/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** my_strcatdup
*/

#include "minishell.h"

char *my_strcatdup(char *dest, char const *src)
{
    int l = my_strlen(dest);
    int i = 0;
    char *cpy = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (int i = 0; dest[i] != '\0'; i++) {
        cpy[i] = dest[i];
    }
    for (; src[i] != '\0'; i++) {
        cpy[l] = src[i];
        l++;
    }
    cpy[l] = '\0';
    free(dest);
    return cpy;
}
