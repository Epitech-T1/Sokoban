/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** move
*/

#include "../include/sokoban.h"

void move_right(sokoban_t *map)
{
    int y = map->y_pos;
    int x = map->x_pos;

    if (map->tab[y][x + 1] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y][x + 1] = 'P';
        map->x_pos += 1;
        if (map->nbr_o == "O") {
            map->tab[y][x] = 'O';
            map->nbr_o = '\0';
        }
    }
    if (map->tab[y][x + 1] == 'O') {
        map->tab[y][x] = ' ';
        map->tab[y][x + 1] = 'P';
        map->x_pos += 1;
        map->nbr_o = "O";
    }
    move_right_snd(map, x, y);
}

void move_left(sokoban_t *map)
{
    int y = map->y_pos;
    int x = map->x_pos;

    if (map->tab[y][x - 1] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y][x - 1] = 'P';
        map->x_pos -= 1;
        if (map->nbr_o == "O") {
            map->tab[y][x] = 'O';
            map->nbr_o = '\0';
        }
    }
    if (map->tab[y][x - 1] == 'O') {
        map->tab[y][x] = ' ';
        map->tab[y][x - 1] = 'P';
        map->x_pos -= 1;
        map->nbr_o = "O";
    }
    move_left_snd(map, x, y);
}

void move_up(sokoban_t *map)
{
    int y = map->y_pos;
    int x = map->x_pos;

    if (map->tab[y - 1][x] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y - 1][x] = 'P';
        map->y_pos -= 1;
        if (map->nbr_o == "O") {
            map->tab[y][x] = 'O';
            map->nbr_o = '\0';
        }
    }
    if (map->tab[y - 1][x] == 'O') {
        map->tab[y][x] = ' ';
        map->tab[y - 1][x] = 'P';
        map->y_pos -= 1;
        map->nbr_o = "O";
    }
    move_up_snd(map, x, y);
}

void move_down(sokoban_t *map)
{
    int y = map->y_pos;
    int x = map->x_pos;

    if (map->tab[y + 1][x] == ' ') {
        map->tab[y][x] = ' ';
        map->tab[y + 1][x] = 'P';
        map->y_pos += 1;
        if (map->nbr_o == "O") {
            map->tab[y][x] = 'O';
            map->nbr_o = '\0';
        }
    }
    if (map->tab[y + 1][x] == 'O') {
        map->tab[y][x] = ' ';
        map->tab[y + 1][x] = 'P';
        map->y_pos += 1;
        map->nbr_o = "O";
    }
    move_down_snd(map, x, y);
}
