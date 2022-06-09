/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** usage
*/

#include "../include/sokoban.h"

void usage(char *str)
{
    if (strcmp(str, "-h") == 0) {
        printf("USAGE\n");
        printf("     ./my_sokoban map\n");
        printf("DESCRIPTION\n");
        printf("     map  file representing the warehouse map");
        printf(", containing ‘#’ for walls,\n");
        printf("          ‘P’ for the player, ‘X’ for boxes ");
        printf("and ‘O’ for storage locations.\n");
    }
}
