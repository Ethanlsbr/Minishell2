/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday07-ethan.lesobre
** File description:
** my_putchar
*/

#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
