#ifndef START_H
#define START_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
extern int status;
extern int errno;
int isExit(char *c);
int countwords(char *str, char *d);
char **spilt_string(char *delim, char *str);
char *make_path_arr(char **str);
int check_the_slash(char *str);
char *compare_and_set_env(char **env, char **argv);
void free_grid(char **grid);
int excute_function(char **argv, char *str);
void print_env(char **envp);
void display_dollar_sign(void);
void display_prompet(char **env, char **envp, char **arg, int count);
void non_interactive_mode(char **env, char **arg, char **envp, int count);
void check_if_true(char *pathname, char **argv, int count, char *filename);
int _getline(char **line_ptr, size_t *n, FILE *stream);
char *_strtok(char *str, char *delim);
int check_the_spaces(char *buff);
void free_fun(char **tmp, int i, char *tmp2);
void check_state(int is_cmplte, char **argv, int cnt, char *file, char **env);
int exit_case(int count, char *filename, char *val);
#endif /* START_H */
