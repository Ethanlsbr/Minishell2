/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-ethan.lesobre
** File description:
** signal_handler
*/

#include "minishell.h"

void sig_handler(int sig)
{
    (void)sig;
    if (isatty(STDIN_FILENO)) {
        mini_printf("\n$> ");
    } else {
        mini_printf("\n");
    }
}

void signal_handler(void)
{
    signal(SIGINT, sig_handler);
}
