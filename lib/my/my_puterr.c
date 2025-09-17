/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday10-ethan.lesobre
** File description:
** my_puterr
*/

#include "../../include/my.h"

int my_puterr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
    return i;
}
