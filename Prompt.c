#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void)
{
	char *line = NULL; //used to store users input line
	ssize_t read; // declares a variable read of type ssize for storing sizes and counts in system calls.
	char *args[64]; //maximum number of arguments
	int status = 0; //declars int status intialized to 0
	int ex_st = 0; // delcares int ex_st intitialied to 0
	int tal = 0; // declares another int tal

	while (1) // starts an infinite loop which will run until broken out of
	{
		printf("> "); //Displays prompt
		read = getline(&line, &len, stdin); // reads a line from standard input (stdin). However, len not being defined will cause comp error
		if (read == -1)
		{
			perror("Error reading line");
			break; // checks if the get line call failed, prints an error message and breaks out of loop.
		}
		// Parse the input into arguments
		char *token = strtok(line, " \t\r\n\a"); // initializes a tokenization process on the input line using space, tab, carriage return, newline and alert as delimiters
		int i = 0; // declares an int i initialized to 0 this will be used as an index for args array
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\r\n\a"); // parses the input line into tokens (arguments) and stores them in the args array. loop continues until there are no more tokens. 
		}
		args[i] = NULL; //Null terminate the arguments array

		// Execute the commmand
		_exec(status, args, &ex_st, &tal);

		// cleanup
		free(line); //frees the memory allocated to line by getline
		for (i = 0; args [i]; i++) 
		{
			free(args[i]); // frees each argument stored in the args array.
		}
		free (args); // frees the args array itself.
	}
	return 0;
}
