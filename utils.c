/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** utils
*/

#include "my.h"

char **malloc_arr(int words)
{
    int nb = 0;
    char **arr = malloc(sizeof(char *) * words + 1);
    for (int tmp = words; tmp != 0; tmp--) {
        arr[nb] = malloc(sizeof(char) * 1000);
        nb++;
    }
    return arr;
}

int skip_words(int i, char *str)
{
    for (; str[i] != '\0' && str[i] == ' ' || str[i] == '\n'
    || str[i] != '\0' && str[i] == 9 || str[i] != '\0' && str[i] == 10;)
        i++;
    return i;
}
