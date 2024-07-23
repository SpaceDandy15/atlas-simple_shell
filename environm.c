#include "shell.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
/**
 *execve - pass existing through new terminal
 *@pathname: path
 *@argv: array including file name
 *Return: 
**/
int execve(const char *pathname, char *const argv[])
{
	if (execve(cmd, argv[0], argv) == -1)
{
		printf("Error\n");
}
	printf();
	return ();
/**
 *isatty - checks if program is a terminal
 *@fd: file descriptor
 *Return: 1 if terminal, 0 if not
**/
int isatty(int fd);
{
	if (isatty() == 1)
{
		getline();
		return ();
}
		else
{
			printf("");
}
	return ();
}
