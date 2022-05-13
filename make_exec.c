/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** make_exec
*/

#include "my.h"

int make_built(char **arg, char **env)
{
    if (my_strncmp(arg[0], "exit", my_strlen(arg[0])) == 0) {
        exit_values(arg);
        return 1;
    }
    if (my_strncmp(arg[0], "env", my_strlen(arg[0])) == 0) {
        print_arg(env);
        return 1;
    }
    if (my_strncmp(arg[0], "unsetenv", my_strlen(arg[0])) == 0)
        return my_unsetenv(env, arg);
    return make_built_sec(arg, env);
}

int make_built_sec(char **arg, char **env)
{
    if (my_strncmp(arg[0], "setenv", my_strlen(arg[0])) == 0) {
        return (my_setenv(env, arg));
    }
    if (my_strncmp(arg[0], "cd", my_strlen(arg[0])) == 0) {
        return change_directory(arg, env);
    }
    return -1;
}

int make_exec(char **arg, char **env, char *path, int val)
{
    int j = 0;
    if (arg[0][0] == '\0') {
        return (val);
    }
    j = make_built(arg, env);
    if (j >= 0) {
        return j;
    }
    else
        return (exec(arg, env, path));
}
