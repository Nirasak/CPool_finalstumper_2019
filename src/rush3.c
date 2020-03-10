/*
** EPITECH PROJECT, 2019
** rush3.c
** File description:
** rush3
*/

#include <unistd.h>
#include "rush3.h"

void my_print(char *str, int x, int y, int z)
{
    my_putstr(str);
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    if (z == 0)
        my_putchar('\n');
}

int count_width(char *str)
{
    int x;

    while (str[x] != '\n' && str[x] != '\0')
        x++;
    return (x);
}

int count_height(char *str)
{
    int x;
    int count;

    while (str[x] != '\0') {
        if (str[x] == '\n')
            count++;
        x++;
    }
    return (count);
}

int check_rush(char *str, int x, int y)
{
    if ((x == 1 || y == 1) && error3(str) == 0) {
        my_print("[rush1-3] ", x, y, 1);
        my_print(" || [rush1-4] ", x, y, 1);
        my_print(" || [rush1-5] ", x, y, 0);
        return (0);
    }
    if (str[x - 1] == 'A' && error3(str) == 0) {
        my_print("[rush1-3] ", x, y, 0);
        return (0);
    }
    if (str[(y - 1) * (x + 1)] == 'A' && error3(str) == 0) {
        my_print("[rush1-4] ", x, y, 0);
        return (0);
    }
    if (str[y * (x + 1) - 2] == 'A' && error3(str) == 0) {
        my_print("[rush1-5] ", x, y, 0);
        return (0);
    }
    my_putstr("none\n");
    return (-1);
}

int rush3(char *str)
{
    int x = count_width(str);
    int y = count_height(str);

    if (x <= 0 || y <= 0) {
        my_putstr("none\n");
        return (-1);
    }
    if (str[0] == 'o' && error1(str) == 0) {
        my_print("[rush1-1] ", x, y, 0);
        return (0);
    }
    if ((str[0] == '*' || str[0] == '/') && error2(str) == 0) {
        my_print("[rush1-2] ", x, y, 0);
        return (0);
    }
    if (check_rush(str, x, y) == -1)
        return (-1);
    return (0);
}
