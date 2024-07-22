#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 *getppid - gets the parent pid
 *@void: no arguments
 *Return: parent process id number
**/
pid_t getppid(void)
{
        pid_t fppid;/**declare struct of ppid to use for fork**/
	pid_t ppid/**declare type for parent pid**/

	fppid = fork();/**initialize to fork function**/
	ppid = getppid();/**init to getppid function**/
	
	if (ppid == -1)
{
		perror("Error\n");
		return (1);
}

        printf("PPID: %u\n", getppid());/**print ppid**/

        return (ppid);/**return parent process identification number**/
}
