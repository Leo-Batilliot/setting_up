/*
** EPITECH PROJECT, 2024
** myh
** File description:
** task 02
*/
#ifndef TEST_H
    #define TEST_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>

void my_putstr(char *);
int my_show_word_array(char **, int);
int my_get_nbr(char *);
long my_strlen(char *);
char **generate_map(char *, char *);
char **load_map(char **, char *);
char **my_str_to_word_array(char *);
int str_is_num(char *);
int valid_characters_string(char *);

#endif /* TEST_H */
