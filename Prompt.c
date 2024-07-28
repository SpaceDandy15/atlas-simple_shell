#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int prompt(void)
{
	char *line = NULL; /**NULL initiiated for getline to allocate mem**/
	ssize_t read;/**variable storing sizes and counts in system calls**/
	char *args[64]; /**max num of arg**/
	int status = -1; /** initializes status to indicate an error initially*/
	int ex_st = 0; /**Initialize ex_st to 0, assuming it holds an exit status*/
	int tal = 0; /**Initialize tal to 0, assuming it tracks some count or flag*/
	size_t len = 0; /** declare and intializes len for geltin*/

	char *token; /** moved declarations outside of loop*/
	int i = 0;
	while (1) /** starts an infinite loop which will run until broken out of*/
	{
		printf("Ghost> "); /** Displays prompt*/
		read = getline(&line, &len, stdin); /** reads a line from sta1ndard input (stdin). However, len not being defined will cause comp error*/

		if (read == -1)
		{
			perror("Error reading line");
			break; /** checks if the get line call failed, prints an error message and breaks out of loop.*/
		}
		/** Parse the input into arguments*/
		token = strtok(line, " \t\r\n\a");
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\r\n\a"); /** parses the input line into tokens (arguments) and stores them in the args array. loop continues until there are no more tokens.*/
		}
		args[i] = NULL; /** Null terminate the arguments array*/

		/** Execute the commmand (look at this later)*/
		_exec(status, args, &ex_st, &tal);

		/**cleanup*/
		free(line); /**frees the memory allocated to line by getline*/
		/**line = NULL; reset line to Null - Ariel*/
		for (i = 0; args[i]; i++) 
		{
			free(args[i]); /** frees each argument stored in the args array.*/
		}
	}
	return 0;
}