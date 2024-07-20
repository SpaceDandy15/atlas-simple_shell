#ifndef _SHELL_H_
#define _SHELL_H_
#define BUFFER
#define

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**typedef struct{
	
	
};**/

int main (void);
int main (int ac, char **av);
int main (int ac, char **av, **env);
char *strtok(char *str, const char *delim);

#endif
