/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday05-ethan.lesobre
** File description:
** my_compute_power_rec
*/

#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    int tmp;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    nb = nb * my_compute_power_rec(nb, p - 1);
    return nb;
}
