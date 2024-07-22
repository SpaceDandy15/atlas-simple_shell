#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 *getpid - gets the process id number
 *@void: no arguments
 *Return: void
**/
pid_t getpid(void)
{
	pid_t fpid;/**use for fork function**/
	pid_t pid;/**declare to use for getpid funct**/
	
	fpid = fork();/**fork function to split**/
	pid = getpid();/**initialize pid to grab id to print out**/

	if (fpid == -1)/**error handle for fork function**/
{
		perror("Error\n");/**prints error**/
}

	printf("PID: %u\n", pid_t);/**print pid to ensure its working also use echo$$**/

}
