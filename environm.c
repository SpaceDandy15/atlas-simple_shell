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
int execve(const char *pathname, char *const argv[])
{
	const char *path;
	char *const argv [] = {"/usr/bin/ls", "ls", "NULL"};

	if (execve(cmd, argv[0], argv) == -1)/**handling errors**/
{
		printf("Error\n");
		return (-1);/**returns error**/
}
	isatty();/**will recurse and handle and fork**/
	printf("");/**prints if execve funct is successful**/
}
/**
 *isatty - checks if program is a terminal
 *@fd: file descriptor
 *Return: 1 if terminal, 0 if not
**/
int isatty(int fd);/**don't need this will look into working it into code wednesday**/
{
	if (isatty() == 1)/**checks if terminal**/
{
		fork();/**will call create second pathe for execve to follow**/
		printf("Terminal acquired, Major.\n");/**GiTS reference**/
		return ();/**returns terminal**/
}
	else
{
		printf("Failed to acquire terminal, Major!\n");/**is not a terminal**/
}
	return ();
}
