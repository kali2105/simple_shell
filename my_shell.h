#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int display_prompt(void);
char *read_input(void);
char *find_full_path(char **args, char *search_path, char *copy_path);
int check_builtin_commands(char **args, char *input_buffer, int exit_status);
int fork_and_execute(char **args, char *input_buffer, char *full_path);
char *duplicate_string(char *str);
int count_words(char *str);
int compare_strings(const char *s1, const char *s2);
char *string_concat(char *dest, char *src);
int string_length(char *s);
char **tokenize_input(char *input_buffer);
int split_path(char *path);
int compare_path_strings(const char *s1, const char *s2);
char *concatenate_strings(char *tmp, char **args, char *token);
char *get_environment_variable(const char *name);
int display_environment(void);
void print_string(char *str);
int print_character(char c);
char *fill_memory(char *s, char byte, unsigned int n);

#endif
