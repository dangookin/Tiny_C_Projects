#include <stdio.h>
#include <unistd.h>

int main()
{
	char cwd[BUFSIZ];

	getcwd(cwd,BUFSIZ);
	printf("The current working directory is %s\n",cwd);

	return(0);
}
