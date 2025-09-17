/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** My_print_array
*/

#include "../../include/my.h"
#include <time.h>

int my_print_array(char const **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; i++) {
        count += my_putstr(array[i]);
        my_putchar('\n');
        count++;
    }
    return count;
}
