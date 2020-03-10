/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** error gestion
*/

#include "rush3.h"

int error1(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] != 'o' && str[x] != '-' && str[x] != '\n' && str[x] != ' '
            && str[x] != '|')
            return (-1);
        x++;
    }
    return (0);
}

int error2(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] != '/' && str[x] != 92 && str[x] != '*' && str[x] != '\n'
            && str[x] != ' ')
            return (-1);
        x++;
    }
    return (0);
}

int error3(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] != 'A' && str[x] != 'B' && str[x] != 'C' && str[x] != '\n'
            && str[x] != ' ')
            return (-1);
        x++;
    }
    return (0);
}
