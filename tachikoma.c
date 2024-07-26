#include "shell.h"
/**
 *getpid - get pid process 
 *@: no parameters
 *Return: void, pid 
 */
pid_t getpid(void)
{
    pid_t pid;

    pid = fork();

    if (pid)
    {
        perror("");
    }
    if (pid == 0)
    {
        wait(pid);
        printf("", pid);
    }
    
    wait(pid);
    printf("", pid);
    return (pid);
}