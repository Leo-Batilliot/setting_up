/*
** EPITECH PROJECT, 2024
** count islands
** File description:
** main_count
*/
#include "lib/my.h"

static int square_bottom(char **world, int x, int y, int size)
{
    if (world[y + size] == NULL || world[y + size][x] == '\0')
        return size;
    for (int i = x; i <= x + size; i++) {
        if (world[y + size][i] != '.')
            return size;
    }
    return square_bottom(world, x, y, size + 1);
}

static int square_right(char **world, int x, int y, int size)
{
    if (world[y + size] == NULL || world[y][x + size] == '\0')
        return size;
    for (int i = y; i <= y + size; i++) {
        if (world[i][x + size] != '.')
            return size;
    }
    return square_right(world, x, y, size + 1);
}

static int compute_sizes(char **world, int x, int y)
{
    int size1 = square_right(world, x, y, 0);
    int size2 = square_bottom(world, x, y, 0);

    if (size1 < size2)
        return size1;
    return size2;
}

static int *compare_square_size(char **world, int y)
{
    int *res = malloc(sizeof(int) * 3);
    int current_size = 0;

    res[0] = 0;
    res[1] = 0;
    res[2] = 0;
    for (int x = 0; world[1][x] != '\0'; x++) {
        current_size = compute_sizes(world, x, y);
        if (current_size > res[0]) {
            res[0] = current_size;
            res[1] = y;
            res[2] = x;
        }
    }
    return res;
}

static int print_result(char **map, int x, int y, int size)
{
    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            map[i][j] = 'x';
    return my_show_word_array(map, 1);
}

int setting_up(char **world)
{
    int max_size = 0;
    int x = 0;
    int final_x = 0;
    int final_y = 0;
    int *current_res;

    for (int y = 1; world[y] != NULL; y++) {
        current_res = compare_square_size(world, y);
        if (current_res[0] > max_size) {
            max_size = current_res[0];
            final_x = current_res[2];
            final_y = current_res[1];
        }
        free(current_res);
    }
    print_result(world, final_x, final_y, max_size);
    return max_size;
}

char **is_valid_argv(char **map, char *av1, char *av2)
{
    if (str_is_num(av1) == 84)
        return NULL;
    if (av2 == NULL || av2[0] == '\0') {
        write(2, "The string you passed is empty", 30);
        return NULL;
    }
    if (valid_characters_string(av2) == 84)
        return NULL;
    return generate_map(av1, av2);
}

char **is_valid_file(char **map, char *file)
{
    struct stat file_stat;

    if (stat(file, &file_stat) != 0) {
        write(2, "Can't open the file, stat error\n", 31);
        return NULL;
    }
    if (!(file_stat.st_mode & S_IRUSR)) {
        write(2, "Can't open the file, permission denied", 38);
        return NULL;
    }
    if (file == NULL || file[0] == '\0') {
        write(2, "The path to your file is an empty string", 40);
        return NULL;
    }
    return load_map(map, file);
}

int main(int ac, char **av)
{
    char **map;

    if (ac != 3 && ac != 2) {
        write(2, "Invalid number of arguments", 27);
        return 84;
    }
    if (ac == 2)
        map = is_valid_file(map, av[1]);
    if (ac == 3)
        map = is_valid_argv(map, av[1], av[2]);
    if (map == NULL) {
        return 84;
    }
    setting_up(map);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}
