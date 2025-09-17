/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday07-ethan.lesobre
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H

    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stddef.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_array(char *str, char sep);
int my_puterr(char *str);
char *my_strdup(char *str);
char *my_strndup(char *str, int n);
int my_print_array(char const **array);
int mini_printf(const char *format, ...);
int my_strncmp(char *s1, char *s2, int n);

#endif
