#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
/**
 * _path - function that prints environment PATH
 *@env: environment
 *@first: the first tokenized keyword (user inputted argument)
 *@input: the tokenized arguemnets
 *@ex_st: the exit status
 *Return: 0 if successful
**/
int _path(char **input, char **env, int *ex_st)
{
<<<<<<< HEAD
	pid_t pid; /**declaring pid here for future init*/
	
	if (status == 2) /** will indicate that the file exists but may not be executable.*/
	{
		if (access(args[0], X_OK) == 0) /** outer if block that checks if the file pointed to by args [0], 
		access function makes this executable, X_OK tests for the files executability.*/
		{
			pid = fork();/**init pid to fork function */
			if (pid == 0) /** if fork returns 0, it means we are in the child process. command is executed here*/
			{
				_custom_exec(args[0], args, NULL); /** executes the command located at args [0] with arguments*/
			}
			else
			{
				wait(NULL); /**(the parent waits for the child process to finish executing*/
				*ex_st = 0; /** successful execution*/
			}
		}
		else if (access(args[0], F_OK) != 0) /** if the file exists */
		{
			print_str("sh: ");
			print_int(*tal); /** pass the dereferencec value of tal to print_int*/
			print_str(": ");
			perror(args[0]);
			*ex_st = 127;
		} /** prints an error message indicating the file was not found, the ex_st 127 is the exit status.*/
		else if (access(args [0], F_OK) == 0 && access(args[0], X_OK) != 0) /** if the file exists but is not executable**/
		
		{
			print_str("sh: ");/**prints sh: */
			print_int(*tal);
			print_str(": ");/** prints :  */
			perror(args[0]);/**/
			*ex_st = 126;
		} /** sets the exit status to  126 which is a permission issue.*/
	}
}

/**
 * _custom_exec - custom execution function
 * @command: The command to execute
 * @args: Arguments for the command
 * @exit_status: Pointer to store the exit stauts of the executed command
 * Return: void
*/

void _custom_exec(const char *command, char *const args[], int *exit_status)
{

=======
	int i; /** integer used as loop counter*/
	char *temp, *left, *right; /** pointer used for string manipulation*/
	char *new = NULL, *envcopy = NULL; /** temporary storage for manipulated paths , envcopy is a copy fo the current environment variable being processed.*/
>>>>>>> refs/remotes/origin/main
	pid_t pid = fork();

	for (i = 0; env[i] != NULL; i++) /** loop iterates over each environment variable until it encounters a null terminator ('\0'),
	indicates the end of the environment variables array.*/
	{
		envcopy = _strdup(env[i]);
		left = strtok(envcopy, "= \t");
		temp = trtok(NULL, "=\t"); /** environment is duplicated using _stdup, the split into tokens based on spaces,
		equals signs, and tabs. First token is stored in left and second token is in temp*/

		if (_strcmp(left, "PATH") == 0) /** checks if left token matches the string "PATH", if it does it will proceed to tokenized temp again, this time splitting
		on colons, spaces, and tabs to get individual paths.*/
		{
			right = strtok(temp, ": \t");
			while (right)
			{
				new = pathstr(right);

				if (access(new, X_OK) == 0)
				{
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
<<<<<<< HEAD
	else if (pid < 0) /**fork failed*/
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else /** parent process waits for child*/
	{
		int status;
		waitpid(pid, &status, 0);
		*exit_status = WEXITSTATUS(status);/**wait for child to terminate */
	}
}
=======
	return (2); /** after processing all paths, the function frees memory alocated for envcopy and returns 2,
	 indicating failure to find a valid executable path*/
}
>>>>>>> refs/remotes/origin/main
