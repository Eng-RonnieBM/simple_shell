#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFF_MAX 1024 /* max buffer size*/
#define MAXLIST 100 /* max number of commands to be supported.*/
#define STDOUT STDOUT_FILENO /* abbreviating this variable.*/
#define STDIN STDIN_FILENO /*abbreviating this variable.*/
#define CLEAR_SCREEN write(STDOUT, "\033[H\033[J", 6) /*a macro*/
#define NEW_LINE write(STDOUT, "\n", 1) /*a macro*/

/* env_handle.c */
char **fetch_paths(char **envp);
char *_getenv(char **envp, char *name);

/* string_functions.c */
char **separate_string(char *string, char *sep);

/* 0b-prompt.c */
void prompt(void);
void handle_prompt(int *keep_prompt, char **paths);
char **fill_params(char *buffer);

/* 3-executor.c */
void execute_comand(char **params, char **paths, int *keep_prompt);
void attach_path(char *comand, char **paths);

/* 0c-read_line.c */
char *takeInput(int *keep_prompt);

/*NEEDED STRING FUNCTIONS*/
int _strlen(char *s);
int empty_line(char *buff);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
void strClear(char *string, int len);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);

/*PRINT CURRENT DIRECTORY --- sin usar aun*/
void printDir(void);


#endif
