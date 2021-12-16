#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
	DIR *dp;

	dp = opendir(".");
	if(dp == NULL)
	{
		puts("Unable to read directory");
		exit(1);
	}

	puts("Directory is opened!");
	
	closedir(dp);
	puts("Directory is closed!");

	return(0);
}
