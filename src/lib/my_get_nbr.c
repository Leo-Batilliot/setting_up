/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-leo.batilliot
** File description:
** my_get_nbr
*/
#include "my.h"

long res(int count, int result, int minus)
{
    long reversed_result = 0;

    for (count; count > 0; count--) {
        if (reversed_result * 10 +(result % 10) > 2147483647 ||
            reversed_result * 10 +(result % 10) < -2147483648)
            return 0;
        reversed_result = reversed_result * 10 +(result % 10);
        result /= 10;
    }
    if (minus % 2 == 1) {
        reversed_result = - reversed_result;
    }
    return reversed_result;
}

int my_get_nbr(char *str)
{
    int result = 0;
    int minus = 0;
    int count = 0;
    int end = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            minus += 1;
        if (end == 1 && (str[i] < '0' || str[i] > '9')
            && str[i] != '+' && str[i] != '-')
            return 0;
        if (end > 1 && (str[i] < '0' || str[i] > '9'))
            return res(count, result, minus);
        if (str[i] <= '9' && str[i] >= '0') {
            result += (str[i] - '0') * end;
            end = end * 10;
            count += 1;
        }
    }
    return (int)res(count, result, minus);
}
