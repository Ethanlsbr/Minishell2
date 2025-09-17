/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-ethan.lesobre
** File description:
** my_str_isalpha
*/

#include "../../include/my.h"

int check_uppercase(char const *str)
{
    if (str[0] < 'A' || str[0] > 'Z') {
        return 1;
    }
    return 0;
}

int my_str_isalpha(char const *str)
{
    int nb = 0;

    if (str == NULL) {
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            nb += check_uppercase(str + i);
        }
    }
    if (nb > 0) {
        return 1;
    } else {
        return 0;
    }
}
