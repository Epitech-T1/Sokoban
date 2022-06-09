/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** sokoban
*/

#include "../include/sokoban.h"

void print_map(sokoban_t *map)
{
    int i = 0;

    for (; map->tab[i] != NULL; i++)
        mvprintw(i, map->row, map->tab[i]);
    refresh();
}

int move_cursor_next(sokoban_t *map)
{
    if (map->ch == KEY_DOWN)
        move_down(map);
}

int move_cursor(sokoban_t *map)
{
    if (map->ch == KEY_LEFT)
        move_left(map);
    else if (map->ch == KEY_RIGHT)
        move_right(map);
    else if (map->ch == KEY_UP)
        move_up(map);
    move_cursor_next(map);
}

void find_p(sokoban_t *map)
{
    int x = 0;

    for (int y = 0; map->tab[y] != NULL; y++) {
        for (x = 0; map->tab[y][x] != '\0'; x++) {
            if (map->tab[y][x] == 'P') {
                map->y_pos = y;
                map->x_pos = x;
                break;
            }
        }
    }
}

void init_ncurses(sokoban_t *map)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    print_map(map);
    curs_set(0);
    while (map->ch != 32) {
        map->ch = getch();
        move_cursor(map);
        print_map(map);
    }
    refresh();
    endwin();
}
