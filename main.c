#include "shell.h"
#include <unistd.h>
/**maybe recurse everything in here**/
int main(void)
{
	if (isatty(STDIN_FILENO))/**checks if terminal**/
	{
	printf("Terminal acquired, Major.\n");/**GiTS reference**/
	return 1;/**returns terminal**/
}
else
{
	printf("failed to acquire terminal, Major!\n");
}
prompt(); /** calls after checking for a terminal*/
return 0;
}
