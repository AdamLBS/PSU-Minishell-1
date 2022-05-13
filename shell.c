/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** shell
*/

#include "my.h"

int exec_shell(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t size = 0;
    int tty_val = isatty(STDIN_FILENO), val = 0;
    hide_ctrl(env, tty_val);
    while (1) {
        if (tty_val != 0)
            print_prompt(env);
        size = getline(&line, &len, stdin);
        line[my_strlen(line) - 1] = '\0';
        char **env_cp = my_arrcpy(env);
        char *path = get_path(env_cp, "PATH=", path);
        char **parsed = parse_path(path, ":", parsed);
        char **arr = parse_arr(line);
        char *tmp = check_path(parsed, arr[0], arr);
        manage_exit(size, tty_val, val);
        val = make_exec(arr, env, tmp, val);
    }
    my_putstr("exit\n");
}

char **parse_arr(char *line)
{
    char *test = remove_trailing_spaces(line);
    char **arr = arg_to_str(test);
    return arr;
}
