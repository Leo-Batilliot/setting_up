/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-leo.batilliot
** File description:
** my_strlen
*/
#include "my.h"

long my_strlen(char *str)
{
    long i = 0;

    for (i; str[i] != '\0'; i++);
    return i;
}
