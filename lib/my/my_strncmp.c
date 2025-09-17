/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int my_strncmp(char *s1, char *s2, int n)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i]) {
            return 1;
        }
    }
    return 0;
}
