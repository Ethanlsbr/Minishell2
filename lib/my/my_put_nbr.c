/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday03-ethan.lesobre
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb -= (nb + nb);
    }
    if (nb / 10 >= 1) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return 0;
}
