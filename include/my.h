/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** my
*/

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#ifndef MY_H_
    #define MY_H_
int my_putstr(char const *str);
int main (int argc, char **argv, char **env);
char *my_strstr(char *src, char const *to_find);
char *get_env(char **env, char *find);
char **arg_to_str(char *arg);
int get_nb_arr(char **arg);
void print_arg(char **arg);
char *my_strcpy(char *dest, char const *src);
char *check_path(char **path, char *exec, char **arr);
char **parse_path(char *path, char *delim, char **old);
char *move_pointer(char *pointer);
bool file_exists (char *filename);
int make_exec(char **arg, char **env, char *path, int val);
char **my_arrcpy(char **src);
int make_built(char **arg, char **env);
char *my_strcat (char *dest, char const *src);
int exec(char **arg, char **env, char *path);
int my_setenv(char **env, char **arg);
char *parse_env_var(char **env, char *arg);
char *get_words_nb(char *str);
char *get_words_nb_2(char *str);
char *remove_trailing_spaces(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int check_errors(int status, pid_t p);
char *my_strcat (char *dest, char const *src);
int exec_tty(int argc, char **argv, char **env, char *line);
int run_tty(char **env, char *line);
int my_strncmp(char const *s1, char const *s2, int n);
bool folder_exists(char *path);
int change_directory(char **arg, char **env);
int get_words(char *arg);
void manage_exit(int size, int tty_val, int val);
int env_checker(char **env, char *find);
char **get_var_env(char **env, char *delim);
int env_err(char *arg, int pos, char **env);
int handling_folder_files(char *path, char **arg, char **env);
void parse_env(char **arg, char **env);
int check_env(char **env, char *arg);
void update_pwd(char **env, char *new);
int my_get_nbr(char *str);
int exit_values(char **arg);
int check_exit_utils(char val);
void manage_ctrl_c(int my_signal);
bool file_exists(char *filename);
int check_exit_val(char *val);
char *get_path(char **env, char *find, char *path);
int replace_env(char **env, char *var, char *val);
int make_built_sec(char **arg, char **env);
int my_unsetenv(char **env, char **arg);
void print_prompt(char **env);
void hide_ctrl(char **env, int tty_val);
int exec_shell(int ac, char **av, char **env);
int check_dir_utils(char **arg, char **env, char **env_cp);
int return_value(int sign);
int my_arr_len(char **arr);
void write_error_message(char *path);
void write_error_cd(char *path);
int check_slash(char *arg);
int check_special_cases(char **env, char **arg);
int my_arrlen(char **arr);
char **malloc_arr(int words);
int skip_words(int i, char *str);
char **parse_arr(char *line);
#endif/* !MY_H_ */
