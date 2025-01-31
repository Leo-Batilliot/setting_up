/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-leo.batilliot
** File description:
** map
*/

#include "lib/my.h"

static int contains_nondigits(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '0')
            return 84;
    return 0;
}

static char *my_strdup(char *str)
{
    int i = 0;
    char *res;

    for (; str[i] != '\0'; i++);
    res = malloc(sizeof(char) * i + 1);
    for (int y = 0; y < i; y++)
        res[y] = str[y];
    res[i] = '\0';
    return res;
}

static char *first(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    char buffer[30];
    int size = 30;
    int i = 0;

    read(fd, buffer, size);
    for (; buffer[i] != '\n'; i++) {
    }
    buffer[i] = '\0';
    close(fd);
    return my_strdup(buffer);
}

int valid_characters_string(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != 'o') {
            write(2, "The string/map contains invalid characters\n", 43);
            return 84;
        }
    }
}

int str_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            write(2, "First argument has to be a positive number", 42);
            return 84;
        }
    }
    return 0;
}

static int check_str_content(char **str, int size)
{
    int i;
    int len;

    for (i = 1; str[i] != NULL; i++);
    if (i - 1 != size) {
        write(2, "The number is not equal to the number of lines\n", 46);
        return 84;
    }
    for (i = 1; str[i] != NULL; i++)
        if (valid_characters_string(str[i]) == 84)
            return 84;
    len = my_strlen(str[1]);
    for (i = 1; str[i] != NULL; i++) {
        if (my_strlen(str[i]) != len) {
            write(2, "The lines of the map aren't of equal lenght\n", 45);
            return 84;
        }
    }
    return 0;
}

char **error_handling(char **str, char *file_name)
{
    int number;
    char *first_line = first(file_name);

    if (first_line == NULL || contains_nondigits(first_line) == 84 ||
        first_line[0] == '\0') {
        write(2, "The first line of the file has to be a number\n", 46);
        return NULL;
    }
    number = my_get_nbr(first_line);
    if (number < 1) {
        write(2, "The number has to be strictly positive\n", 39);
        return NULL;
    }
    if (check_str_content(str, number) == 84)
        return NULL;
    return str;
}

char **load_map(char **map, char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    int size;
    struct stat file_stat;
    char *buffer;
    int bytes;

    if (stat(file_name, &file_stat) == -1) {
        close(fd);
        write(2, "Encountered an error while trying to open the file\n", 51);
        return NULL;
    }
    size = file_stat.st_size;
    buffer = (char *)malloc((size + 1) * sizeof(char));
    bytes = read(fd, buffer, size);
    if (buffer[bytes - 1] != '\n')
        return NULL;
    buffer[bytes] = '\0';
    close(fd);
    map = my_str_to_word_array(buffer);
    return error_handling(map, file_name);
}

char **generate_map(char *size_str, char *pattern)
{
    int size = my_get_nbr(size_str);
    int pattern_len = my_strlen(pattern);
    int start_index = 0;
    char **map = malloc((size + 2)* sizeof(char *));

    map[0] = NULL;
    for (int i = 1; i < size + 1; i++) {
        map[i] = malloc(size + 1);
        for (int j = 0; j < size; j++) {
            map[i][j] = pattern[(start_index + j) % pattern_len];
        }
        map[i][size] = '\0';
        start_index = (start_index + size) % pattern_len;
    }
    map[size + 1] = NULL;
    if (check_str_content(map, size) == 84)
        return NULL;
    return map;
}
