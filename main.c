#include "shell.h"
#include "Prompt.c"
/**maybe recurse everything in here**/
int main(void)
{
	if (isatty(fd) == 1)/**checks if terminal**/
{
		printf("Terminal acquired, Major.\n");/**GiTS reference**/
		return (1);/**returns terminal**/
}
	else
{
		printf("Failed to acquire terminal, Major!\n");/**is not a terminal**/
}
	return (0);

	{
		prompt();
	}

	return 0;
}
