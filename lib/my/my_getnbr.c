/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday04-ethan.lesobre
** File description:
** my_getnbr
*/

#include "../../include/my.h"

int check_char(char const *str, int i)
{
    if (str[i + 1] < '0' || str[i + 1] > '9') {
        if (str[i + 1] != '-' && str[i + 1] != '+') {
            return 0;
        }
    }
    return 1;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int is_neg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            is_neg *= -1;
        }
        if (str[i] <= '9' && str[i] >= '0') {
            nb = nb * 10 + (str[i] - 48);
        }
        if (check_char(str, i) == 0) {
            nb *= is_neg;
            return nb;
        }
    }
    nb *= is_neg;
    return nb;
}
