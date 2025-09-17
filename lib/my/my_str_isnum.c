/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-ethan.lesobre
** File description:
** my_str_isnum
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}
