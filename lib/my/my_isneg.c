/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday03-ethan.lesobre
** File description:
** my_isneg
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
