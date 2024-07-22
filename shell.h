#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFFER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h> /**Does not hang if no status is available; return immediately.*/
#include <sys/types.h> /** defines data types used in system source code*/

struct status
{
	statbuf;	
};/**use for stat function**/

typedef struct pid_s 
{
	int wstatus;
	int options;
	pid;
	ppid;
}pid_t;/**type that pid, ppid, fork and wait func use**/

typedef struct ssize_s
{
	char *lineptr;
	n;
	FILE stream

}ssize_t;/**td used for getline function**/

int main (void);/**basic entry point, unsure if we'll need it**/
char *strtok(char *str, const char *delim);/*** to user input and a delim**/
pid_t getppid(void);/**returns pid_t**/
pid_t getppid(void);/**same as above**/
pid_t fork(void);/**also ret type**/
int stat(const char *pathname, struct stat *statbuf);/**need more research**/
pid_t wait(int *wstatus);/**not sure yet for wait func, here for options**/
pid_t waitpid(pid_t pid, int *wstatus, int options);/**same as above**/
int execve(const char *pathname, char *const argv[], char *const envp[]);
/**uses arg for file name and details, and pathname for printing everything**/
int isatty(int fd);/**returns a file descriptor**/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);/**uses td to use F op and data**/
char *_getenv(info_t *, const char *);//**gcc uses ino_t similar stat uses
/**comp thinks youre trying to use that, if type add to header**/
/**functions for path.c**/
char *_stdrup(const char *s);
char *trtok(char *str, const char *delim);
int _strcmp(const char *a, const char *b);
char *pathstr(char *path, char *first);
int access(const char *pathname, int mode);
int exec(const char *path, char *const argv[], char *const envp[]);
void wait(int *status);

/**environment shortend code proto type to handle the simplicity of the project while the
 * other approach was more dynamic and would handle more precise errors but
 * would take too much time writing all that code for all the files.**/
int printenv(char **env, int *ex_st);

/**funciton declartions form exec.c*/
void _exc(int status, char **args, int *ex_st, int *tal);

// custom function declarations
void print_str(const char *str);
void print_int(int num);
void perror_custom(const char *message, const char *filename);

/**
 * I am thinking we dont need these functions**/

#endif
