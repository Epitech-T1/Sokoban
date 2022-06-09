/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/

#include "../include/sokoban.h"

int get_file_size(const char *filename)
{
    int size = 0;
    struct stat st;

    stat(filename, &st);
    size = st.st_size;
    return (size);
}

sokoban_t *init_struct(void)
{
    sokoban_t *map = malloc(sizeof(sokoban_t));

    if (map == NULL)
        return (84);
    map->x_pos = 0;
    map->y_pos = 0;
    map->ch = 0;
    map->row = LINES / 2;
    map->col = COLS / 2;
    return (map);
}

int read_map(sokoban_t *map, char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (84);
    map->buffer = malloc(sizeof(char) * get_file_size(filename) + 1);
    read(fd, map->buffer, get_file_size(filename));
    map->tab = my_str_tab(map->buffer);
    if (map->buffer == NULL || error_handling_map(map) == 84)
        return (84);
    find_p(map);
    init_ncurses(map);
    if (manage_res(map) == 1)
        return (1);
    close(fd);
    return (0);
}

int check(char **argv)
{
    sokoban_t *map = NULL;

    if (argv[1][0] == '-')
        usage(argv[1]);
    map = init_struct();
    return (read_map(map, argv[1]));
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (check(av));
}
