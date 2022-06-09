/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** error_handling_map
*/

#include "../include/sokoban.h"

int check_win(sokoban_t *map)
{
    int x = 0;

    for (int y = 0; map->tab[y] != NULL; y++) {
        for (x = 0; map->tab[y][x] != '\0'; x++) {
            if (map->tab[y][x] == 'O')
                return (1);
        }
    }
    return (0);
}

int manage_res(sokoban_t *map)
{
    if (check_win(map) == 0) {
        clear();
        curs_set(0);
        printw("You win.\nPress any key to exit.\n");
        map->ch = getch();
        refresh();
        endwin();
    }
    if (check_win(map) == 1) {
        clear();
        curs_set(0);
        printw("You loss.\nPress any key to exit.\n");
        map->ch = getch();
        refresh();
        endwin();
        return (1);
    }
    return (0);
}

int error_handling_map(sokoban_t *map)
{
    int x = 0;
    int o = 0;
    int p = 0;

    for (int i = 0; map->buffer[i] != '\0'; i++) {
        if (map->buffer[i] != '#' && map->buffer[i] != 'X' &&
            map->buffer[i] != 'O' && map->buffer[i] != 'P' &&
            map->buffer[i] != ' ' && map->buffer[i] != '\n') {
            return (84);
        }
        map->buffer[i] == 'O' ? o++ : 0;
        map->buffer[i] == 'P' ? p++ : 0;
        map->buffer[i] == 'X' ? x++ : 0;
    }
    if (o != x || x == 0 || p != 1)
        return (84);
    return (0);
}