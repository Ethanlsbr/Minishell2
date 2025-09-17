/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday07-ethan.lesobre
** File description:
** my_strncat
*/

#include "../../include//my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int l = my_strlen(dest);
    int i = 0;

    for (; i < nb; i++) {
        dest[l] = src[i];
        l++;
    }
    dest[l] = '\0';
    return dest;
}
