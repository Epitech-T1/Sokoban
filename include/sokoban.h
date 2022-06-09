/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct sokoban {
    int x_pos;
    int y_pos;
    int ch;
    int row;
    int col;
    char **tab;
    char *buffer;
    char *nbr_o;
} sokoban_t;

// src/error_handling_map.c
int check_win(sokoban_t *map);
int manage_res(sokoban_t *map);
int error_handling_map(sokoban_t *map);

// src/move_next.c
void move_right_snd(sokoban_t *map, int x, int y);
void move_left_snd(sokoban_t *map, int x, int y);
void move_up_snd(sokoban_t *map, int x, int y);
void move_down_snd(sokoban_t *map, int x, int y);

// src/move.c
void move_right(sokoban_t *map);
void move_left(sokoban_t *map);
void move_up(sokoban_t *map);
void move_down(sokoban_t *map);

// src/sokoban.c
void find_p(sokoban_t *map);
int move_cursor(sokoban_t *map);
void init_ncurses(sokoban_t *map);

// src/usage.c
void usage(char *str);

#endif /* !SOKOBAN_H_ */
