#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void)
{
	char *line = NULL; /**NULL initiiated for getline to allocate mem**/
	ssize_t read;/**variable storing sizes and counts in system calls**/
	char *args[64]; /**max num of arg**/
	int status, ex_st, tal = 0;

	while (1) // starts an infinite loop which will run until broken out of
	{
		printf("> "); //Displays prompt
		read = getline(&line, &len, stdin); // reads a line from sta1ndard input (stdin). However, len not being defined will cause comp error
		/**why do we need len if size is already being allocated?--ARIEL**/

		if (read == -1)
		{
			perror("Error reading line");
			break; // checks if the get line call failed, prints an error message and breaks out of loop.
		}
		// Parse the input into arguments
		char *token = strtok(line, " \t\r\n\a"); // initializes a tokenization process on the input line using space, tab, carriage return, newline and alert as delimiters
		int i = 0; // declares an int i initialized to 0 this will be used as an index for args array
			   // declaring here may cause problems with compiling -ARIEL//
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\r\n\a"); // parses the input line into tokens (arguments) and stores them in the args array. loop continues until there are no more tokens. 
		}
		args[i] = NULL; //Null terminate the arguments array

		// Execute the commmand (look at this later)
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
