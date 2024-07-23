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
	if (execve(cmd, argv[0], argv) == -1)/**handling errors**/
{
		printf("Error\n");
}
	printf();/**prints if execve funct is successful**/
	return ();
/**
 *isatty - checks if program is a terminal
 *@fd: file descriptor
 *Return: 1 if terminal, 0 if not
**/
int isatty(int fd);
{
	if (isatty() == 1)/**checks if terminal**/
{
		getline();/**uses getline to get information**/
		return ();/**returns terminal**/
}
		else
{
			printf("");/**is not a terminal**/
}
	return ();
}
