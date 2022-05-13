/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** exec
*/

#include "include/my.h"

int get_words(char *arg)
{
    int words = 1;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == ' ')
            words++;
    }
    return words;
}

char **arg_to_str(char *arg)
{
    int words = get_words(arg), nb = 0, y = 0, z = 0;
    char **arr = malloc_arr(words);
    for (int i = 0; arg[i] != '\0';) {
        if (i > 1 && arg[i - 1] == 32 && arg[i] != 32) {
            arr[y][z] = '\0';
            y++;
            z = 0;
        }
        if (arg[i] == 32)
            i++;
        else {
            arr[y][z] = arg[i];
            z++;
            i++;
        }
    }
    return arr;
}

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
    }
}

int exec(char **arg, char **env, char *path)
{
    pid_t p, w;
    int status;
    p = fork();
    int waitstatus;
    int i = 1;
    if (p != 0) {
        w = waitpid(p, &status, WUNTRACED | WCONTINUED);
        return (check_errors(status, p));
    } else {
        if (handling_folder_files(path, arg, env) == 0 &&
        execve(path, arg, env) == -1) {
            write(1, arg[0], my_strlen(arg[0]));
            my_putstr(": Command not found.\n");
            exit(1);
        }
    }
}
