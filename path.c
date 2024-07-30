#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * _path - function that prints environment PATH
 *@env: environment
 *@first: the first tokenized keyword (user inputted argument)
 *@input: the tokenized arguements
 *@ex_st: the exit status
 *Return: 0 if successful
**/
int _path(char **input, char **env, int *ex_st)
{
	int i; /** integer used as loop counter*/
	char *temp, *left, *right; /** pointer used for string manipulation*/
	char *new = NULL, *envcopy = NULL; /** temporary storage for manipulated paths , envcopy is a copy fo the current environment variable being processed.*/
	
	pid_t pid;

	for (i = 0; env[i] != NULL; i++) /** loop iterates over each environment variable until it encounters a null terminator ('\0'),
	indicates the end of the environment variables array.*/
	{
		envcopy = strdup(env[i]);
		if (!envcopy)
		{
			perror("malloc fail");
			return (2);
		}

		left = strtok(envcopy, "= \t");
		temp = strdup(NULL, "=\t"); /** environment is duplicated using _stdup, the split into tokens based on spaces,
		equals signs, and tabs. First token is stored in left and second token is in temp*/

		if (strcmp(left, "PATH") == 0) /** checks if left token matches the string "PATH", if it does it will proceed to tokenized temp again, this time splitting
		on colons, spaces, and tabs to get individual paths.*/
		{
			right = strtok(temp, ": \t");
			while (right)
			{
				new = pathstr(right);
				if (!new)
				{
					perror("memalloc failed");
					free(envcopy);
					return (2);
				}
				if (access(new, X_OK) == 0)
				{
					pid = fork();
					if (pid == 0)
					_custom_exec(new,input, NULL);

					else if (pid > 0)
					{
					wait (NULL);
					*ex_st = 0;
					}
					else
					{
						perror("fork");
					}
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