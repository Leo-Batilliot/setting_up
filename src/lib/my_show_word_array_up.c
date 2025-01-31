/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-leo.batilliot
** File description:
** my_show_word_array_UP
*/
#include "my.h"

int my_show_word_array(char **array, int start)
{
    if (array == NULL)
        return 0;
    for (int i = start; array[i] != NULL; i++) {
        my_putstr(array[i]);
        write(1, "\n", 1);
    }
    return 0;
}
