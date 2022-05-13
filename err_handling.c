/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** err_handling
*/

#include "my.h"

int handling_folder_files(char *path, char **arg, char **env)
{
    if (access(path, F_OK) == -1 && path[0] == '/') {
        my_putstr(path);
        my_putstr(": Command not found.\n");
        exit(1);
    }
    if (path[0] == '.'  ||  path[0] == '/' && file_exists(path)
    || check_slash(path)) {
        if (execve(path, arg, env) == -1) {
            write_error_message(path);
            exit(1);
        }
    }
    if (my_strncmp(path, arg[0], my_strlen(path)) == 0 &&
        check_slash(path) == 0) {
        my_putstr(path);
        my_putstr(": Command not found.\n");
        exit(1);
    }
    return 0;
}

void write_error_message(char *path)
{
    if (errno == 8) {
        write(1, path, my_strlen(path));
        write(1, ": Exec format error. Wrong Architecture.\n", 41);
    } else {
        write(1, path, my_strlen(path));
        write(1, ": ", 2);
        write(1, strerror(errno), my_strlen(strerror(errno)));
        write(1, ".\n", 2);
    }
}

int check_slash(char *arg)
{
    int i = 0;
    while (arg[i] != '\0') {
        if (arg[i] == '/')
            return 1;
        i++;
    }
    return 0;
}
