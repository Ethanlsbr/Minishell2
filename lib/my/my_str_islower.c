/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-ethan.lesobre
** File description:
** my_str_islower
*/

#include "../../include/my.h"

int my_str_islower(char const *str)
{
    if (str == NULL) {
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            return 0;
        }
    }
    return 1;
}
