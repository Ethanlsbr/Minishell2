/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** My_str_to_array
*/

#include "../../include/my.h"

int get_word_len(char *str, char sep)
{
    int i = 0;

    while (str[i] && str[i] != sep)
        i++;
    return i;
}

int get_nb_word(char *str, char sep)
{
    int nb_word = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] != sep) {
            nb_word++;
            i += get_word_len(str + i, sep);
        } else {
            i++;
        }
    }
    return nb_word;
}

char **my_str_to_array(char *str, char sep)
{
    int word_len = 0;
    int word_idx = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (get_nb_word(str, sep) + 1));
    if (!tab)
        return NULL;
    for (int i = 0; str[i] != '\0';) {
        if (str[i] != sep) {
            word_len = get_word_len(str + i, sep);
            tab[word_idx] = my_strndup(str + i, word_len);
            i += word_len;
            word_idx++;
        } else {
            i++;
        }
    }
    tab[word_idx] = NULL;
    return tab;
}
