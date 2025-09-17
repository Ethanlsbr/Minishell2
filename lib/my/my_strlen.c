/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday04-ethan.lesobre
** File description:
** my_strlen
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
