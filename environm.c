#include "shell.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
/**
 *execve - pass existing through new terminal
 *@pathname: path
 *@argv: array including file name
 *Return:-1 if an error
**/
int execve(const char *pathname, char *const argv[], char *const env[])
{
	const char *path = "/bin/sh";
	char *const argv[] = {"/bin/sh", NULL};
	char *const env[] = {NULL};
	pid_t pid;

	pid = fork();

	if (execve(cmd, argv[0], argv) == -1)/**handling errors**/
{
		printf("Error\n");
		return (-1);/**returns error**/
}
	fork();
	if (pid == )
{
		wait();
		getpid();
}
	isatty(int fd);/**will recurse and handle and fork**/
	printf("");/**prints if execve funct is successful**/
	return (execve(pathname, argv, env));
}
/**
 *isatty - checks if program is a terminal
 *@fd: file descriptor
 *Return: 1 if terminal, 0 if not
**/
int isatty(int fd);/**don't need this will look into working it into code wednesday**/
{
	if (fd == 1)/**checks if terminal**/
{
		getline();/**will recurse prompt */
		fork();/**will call create second path for execve to follow**/
		printf("Terminal acquired, Major.\n");/**GiTS reference**/
		return (1);/**returns terminal**/
}
	else
{
		printf("Failed to acquire terminal, Major!\n");/**is not a terminal**/
}
	return (isatty(fd));
}