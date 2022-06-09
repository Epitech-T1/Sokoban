/*
** EPITECH PROJECT, 2022
** Tek1
** File description:
** utilities
*/

#include "../include/sokoban.h"

char **my_str_tab(char *str)
{
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * nbr_line(str) + 1);
    int k = 0;;

    if (tab == NULL)
        return (NULL);
    while (str[k] != '\0') {
        j = 0;
        tab[i] = malloc(sizeof(char) * len_line(str) + 1);
        while (str[k] != '\n') {
            tab[i][j] = str[k];
            j++;
            k++;
        }
        i++;
        k++;
    }
    return (tab);
}