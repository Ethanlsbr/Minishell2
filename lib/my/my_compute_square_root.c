/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday05-ethan.lesobre
** File description:
** my_compute_square_root
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int tmp = 0;

    for (int i = 1; i < nb; i++) {
        tmp = i * i;
        if (tmp == nb) {
            return i;
        }
    }
    return 0;
}
