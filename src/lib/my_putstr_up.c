/*
** EPITECH PROJECT, 2024
** putstr
** File description:
** TASK 02
*/
#include "my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
