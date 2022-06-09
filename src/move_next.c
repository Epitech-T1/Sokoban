/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** cursor
*/

#include "../include/sokoban.h"

void move_right_snd(sokoban_t *map, int x, int y)
{
    if (map->tab[y][x + 1] == 'X' && map->tab[y][x + 2] == 'O' ||
        map->tab[y][x + 1] == 'X' && map->tab[y][x + 2] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y][x + 1] = 'P';
        map->tab[y][x + 2] = 'X';
        map->x_pos += 1;
    }
}

void move_left_snd(sokoban_t *map, int x, int y)
{
    if (map->tab[y][x - 1] == 'X' && map->tab[y][x - 2] == 'O' ||
        map->tab[y][x - 1] == 'X' && map->tab[y][x - 2] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y][x - 1] = 'P';
        map->tab[y][x - 2] = 'X';
        map->x_pos -= 1;
    }
}

void move_up_snd(sokoban_t *map, int x, int y)
{
    if (map->tab[y - 1][x] == 'X' && map->tab[y - 2][x] == 'O' ||
        map->tab[y - 1][x] == 'X' && map->tab[y - 2][x] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y - 1][x] = 'P';
        map->tab[y - 2][x] = 'X';
        map->y_pos -= 1;
    }
}

void move_down_snd(sokoban_t *map, int x, int y)
{
    if (map->tab[y + 1][x] == 'X' && map->tab[y + 2][x] == 'O' ||
        map->tab[y + 1][x] == 'X' && map->tab[y + 2][x] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y + 1][x] = 'P';
        map->tab[y + 2][x] = 'X';
        map->y_pos += 1;
    }
}
