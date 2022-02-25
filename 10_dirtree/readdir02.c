#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
	DIR *dp;
	struct dirent *entry;

	dp = opendir(".");
	if(dp == NULL)
	{
		puts("Unable to read directory");
		exit(1);
	}

	entry = readdir(dp);

	printf("File %s\n",entry->d_name);

	closedir(dp);

	return(0);
}
