#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h> /** defines data types used in system source code*/


int main (void);/**basic entry point, unsure if we'll need it**/
char *_getenv(ino_t *, const char *);
char *trtok(char *str, const char *delim);
int _strcmp(const char *a, const char *b);
char *pathstr(char *path);
int prompt(void); /**prompt declaration*/
char *_strdup(const char *s); /** declaration for path.c*/
/**funciton declartions from exec.c*/
void _my_exec(int status, char **args, int *ex_st, int *tal);
void _custom_exec(const char *command, char *const args[], int *exit_status);
/**custom function declarations*/
void print_str(const char *str);
void print_int(int num);
void perror_custom(const char *message, const char *filename);
int _path(char **input, char **env, int *ex_st, int *status, char ***args, int *tal);
#endif
