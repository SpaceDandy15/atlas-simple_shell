#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h> /** defines data types used in system source code*/


int main (void);/**basic entry point, unsure if we'll need it**/
pid_t wait(int *wstatus);/**not sure yet for wait func, here for options**/
pid_t waitpid(pid_t pid, int *wstatus, int options);/**same as above**/
int exec(const char *pathname, char *const argv[], char *const envp[]);
/**uses arg for file name and details, and pathname for printing everything**/
int isatty(int fd);/**returns a file descriptor**/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);/**uses td to use F op and data**/
char *_getenv(ino_t *, const char *);
char *trtok(char *str, const char *delim);
int _strcmp(const char *a, const char *b);
char *pathstr(char *path);
void waiting(int *status); /**changing this to waiting. Having it be wait conflicts with standard library functions*/
int prompt(void); /**prompt declaration*/
char *_strdup(const char *s); /** declaration for path.c*/
/**funciton declartions from exec.c*/
void _my_exec(int status, char **args, int *ex_st, int *tal);
void _custom_exec(const char *command, char *const args[], int *exit_status);
/**custom function declarations*/
void print_str(const char *str);
void print_int(int num);
void perror_custom(const char *message, const char *filename);

#endif