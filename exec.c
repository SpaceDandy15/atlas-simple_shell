#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> /** for waitpid*/

/**
 * _exec - function that executes in the main shell
 * @status: the status of the path, whether the file found is executable or not
 * @args: the parsed arguments
 * @ext_st: the exit status
 * @tal: tally of commands or attempted commands that were run
 * Return: void
*/
void _my_exec(int status, char **args, int *ex_st, int *tal)
{
	pid_t pid = fork();/**initiate pid at beginning - Ariel**/

	if (status == 2) /** will indicate that the file exists but may not be executable.*/
	{
		if (access(args[0], X_OK) == 0) /** outer if block that checks if the file pointed to by args [0], 
		access function makes this executable, X_OK tests for the files executability.*/
		{
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
		else if (access(args[0], F_OK) != 0) /** if the file does not exits (F_OK test fails), this block executes. F_OK checks for the existence of the file.*/
		{
			print_str("sh: ");
			print_int(*tal); /** pass the dereferencec value of tal to print_int*/
			print_str(": ");
			perror(args[0]);
			*ex_st = 127;
		} /** prints an error message indicating the file was not found, the ex_st 127 is the exit status.*/
		else if (access(args [0], F_OK) == 0 && access(args[0], X_OK) != 0) /** if the file exists but is not executable, this block executes. 
		It will combine checks for file existence (F_OK) and non-executablitly (X_0K)*/
		
		{
			print_str("sh: ");
			print_int(*tal);
			print_str(": ");
			perror(args[0]);
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
	if (pid == 0) /** child proccess*/
	{
		if (execvp(command, args) == -1)
		{
			perror("Failed to execute custom command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /**fork failed*/
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else /** parent process*/
	{
		int status;
		waitpid(pid, &status, 0);
		*exit_status = WEXITSTATUS(status);
	}
}
