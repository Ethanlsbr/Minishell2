/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-ethan.lesobre
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
