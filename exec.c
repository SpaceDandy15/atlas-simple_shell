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
    pid_t pid = fork();

    if (pid == 0) { /**Child process*/
        if (execvp(command, args) == -1) {
            perror("Failed to execute command");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) { /** Parent process*/
        wait(NULL); /** Wait for the child process to finish*/
        *exit_status = WEXITSTATUS(errno); // Set the exit status
    } else { /** Fork failed*/
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
}
