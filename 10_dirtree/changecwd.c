#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char cwd[BUFSIZ];
	int r;

	r = chdir("..");
	if( r==-1 )
	{
		fprintf(stderr,"Unable to change directories\n");
		exit(1);
	}

	getcwd(cwd,BUFSIZ);
	printf("The current working directory is %s\n",cwd);

	return(0);
}
