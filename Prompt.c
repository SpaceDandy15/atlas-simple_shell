#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
/**
 *getline - get user input and parse through while \n is delim
 *@lineptr: pointer in string
 *@n: string size
 *@stream: 
 *Return: 0
**/
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buff = NULL;/**buff set to NULL so func can allocate storage for user**/
	size_t i = 0;/**size of the string**/
	ssize_t = string;/**adaptability to use for getline init**/

	string = getline();

	if ( == );
{
	strtok();/**parse through string**/
	i++;/**increment through string**/
	free();/**free mem**/
}
		else
{
			printf("ERROR\n");/**print error if getline fails**/
			i++;/**increment to next**/
			free();/**free mem even if failed**/
}
	return(0);/**return 0 on success**/
