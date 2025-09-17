/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** Mini_printf
*/

#include "../../include/my.h"

void switch_cases(const char *format, va_list parameter, int i)
{
    if (format[i] == 'd' || format[i] == 'i') {
        my_put_nbr(va_arg(parameter, int));
    }
    if (format[i] == 's') {
        my_putstr(va_arg(parameter, char *));
    }
    if (format[i] == 'c') {
        my_putchar(va_arg(parameter, int));
    }
    if (format[i] == '%') {
        my_putchar('%');
    }
}

int mini_printf(const char *format, ...)
{
    va_list parameter;

    va_start(parameter, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else {
            i++;
            switch_cases(format, parameter, i);
        }
    }
    va_end(parameter);
    return 0;
}
