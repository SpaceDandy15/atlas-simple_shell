#ifndef _SHELL_H_
#define _SHELL_H_
#define BUFFER
#define

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

struct stat{
	
	
};

int main (void);
int main (int ac, char **av);
int main (int ac, char **av, **env);
char *strtok(char *str, const char *delim);
pid_t getppid(void);/**reference in man page**/
ppid_t getppid(void);/**same as above**/
pid_t fork(void);/**fork man page**/
int stat(const char *restrict pathname, struct stat *restrict statbuf);
pid_t wait(int *_Nullable wstatus);
pid_t waitpid(pid_t pid, int *_Nullable wstatus, int options);
int execve(const char *pathname, char *const _Nullable argv[], char *const _Nullable envp[]);
int isatty(int fd);
ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
char *_getenv(info_t *, const char *);/**prototypes for envrionment**/
int _setenv(info_t *);
int _unsetenv(info_t *);
int _currentenv(info_t *);


#endif
