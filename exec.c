#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

/**
 * _path - function that handles path-related operations
 * @input: Tokenized input arguments
 * @env: Environment variables
 * @ex_st: Exit status
 * @status: Status indicator (e.g., file exists but may not be executable)
 * @args: Command and its arguments
 * @tal: An integer value used for printing
 * Return: 0 if successful
 **/
int _path(char **input, char **env, int *ex_st, int *status, char ***args, int *tal) {
    pid_t pid;

    /**Example initialization of status based on some condition*/
    *status = determineStatus(input, env); /** You need to define this function*/

    if (*status == 2) {
        if (access((*args)[0], X_OK) == 0) {
            pid = fork();
            if (pid == 0) {
                _custom_exec((*args)[0], *args, ex_st);
            } else {
                wait(NULL);
                *ex_st = 0;
            }
        } else if (access((*args)[0], F_OK) != 0) {
            print_str("sh: ");
            print_int(*tal);
            print_str(": ");
            perror((*args)[0]);
            *ex_st = 127;
        } else if (access((*args)[0], F_OK) == 0 && access((*args)[0], X_OK) != 0) {
            print_str("sh: ");
            print_int(*tal);
            print_str(": ");
            perror((*args)[0]);
            *ex_st = 126;
        }
    }

    return 0;
}

/**
 * _custom_exec - custom execution function
 * @command: The command to execute
 * @args: Arguments for the command
 * @exit_status: Pointer to store the exit status of the executed command
 * Return: void
 */
void _custom_exec(const char *command, char *const args[], int *exit_status) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(command, args) == -1) {
            perror("Failed to execute command");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        wait(NULL);
        *exit_status = WEXITSTATUS(errno);
    } else {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
}
