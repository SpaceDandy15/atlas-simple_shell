#include "shell.h"

/**
 * _path - function that prints environment PATH
 * @env: environment
 * @first: the first tokenized keyword (user inputted argument)
 * @input: the tokenized arguemnets
 * @ex_st: the exit status
 * Return: 0 if successful
*/
int _path(char *first, char **input, char **env, int *ex_st) /** this function takes four parameters
char *first: a pointer to the first tokenized keyword (user inputted argument).
char **input: a pointer to an array of tokenzied arguments
char **env: a pointer to an array representing the environment variables
int *ex_st: a pointer to an integer variable used to store the exit status.**/
{ /** variable declarations*/
	int i; /** integer used as loop counter*/
	char *temp, *left, *right; /** pointer used for string manipulation*/
	char *new = NULL, *envcopy = NULL; /** temporary storage for manipulated paths , envcopy is a copy fo the current environment variable being processed.*/

	for (i = 0; env[i] != '\0'; i++) /** loop iterates over each environment variable until it encounters a null terminator ('\0'),
	indicates the end of the environment variables array.*/
	{
		envcopy = _strdup(env[i]);
		left = strtok(envcopy, "= \t");
		temp = trtok(NULL, "=\t"); /** environment is duplicated using _stdup, the split into tokens based on spaces,
		equals signs, and tabs. First token is stored in left and second token is in temp*/

		if (_strcmp(left, "PATH")== 0) /** checks if left token matches the string "PATH", if it does it will proceed to tokenized temp again, this time splitting
		on colons, spaces, and tabs to get individual paths.*/
		{
			right = strtok(temp, ": \t");
			while (right)
			{
				new = pathstr(right, first);

				if (access(new, X_OK) == 0)
				{
					if (fork() == 0)
					exec(new,input, NULL);

					else
					wait (NULL);
					*ex_st = 0;
					free(new);
					free(envcopy);
					return (0);
				}
				right = strtok(NULL, ": \t");
				free(new); /** for each path that is found, pathstr will manipulate it. This also checks
				if the modified path is executable using access and if it is FORKS a new process to execute 
				the command using exec. After execution child process finishes and sets the exit status to 0.*/
			}
		}
		free(envcopy);
	}
	return (2); /** after processing all paths, the function frees memory alocated for envcopy and returns 2,
	 indicating failure to find a valid executable path*/
}
