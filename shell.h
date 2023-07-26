#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

#define MAX 1024
#define INIT 128

extern char  **environ;

int str_len(char *str);
void str_cpy(char *dest, char *src);
char **str_tok(char *str, const char *delim, int *num);
void free_arr(char **vector, int len);
int str_cmp(char *str1, char *str2, int n);
bool file_stat(char *path, struct stat *f_stat);
char *con_cat(int len, ...);
char *file_path(char *filename, struct stat *f_stat);
int at_oi(char *str);
void en_v(char **argv, int i);
void ex_it(char *buf, char **argv, int i);
bool built_in(char *buf, char **argv, int i);
void exe_cve(char **argv, int i);
char *get_env(char *env_key);
void write_str(char *str);
void exe(char **argv, int i);
char *get_line(int fd);
int put_char(char ch);
void _path(char **argv, char *buffer, char **args, int i, int a);
void bu_ffer(char *buffer);
void get_one(char *buffer, char *t_buffer, int i);
char *tokenise(char *buffer, const char *delim);
int pr_f(int fd, const char *format, ...);
int it_oa(int num, char *str);


#endif
