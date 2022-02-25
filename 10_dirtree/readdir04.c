#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

int main()
{
	DIR *dp;
	struct dirent *entry;
	struct stat fs;
	int r;
	char *filename;

	dp = opendir(".");
	if(dp == NULL)
	{
		puts("Unable to read directory");
		exit(1);
	}

	while( (entry = readdir(dp)) != NULL )
	{
		filename = entry->d_name;
		r = stat( filename,&fs );
		if( r==-1 )
		{
			fprintf(stderr,"Error reading '%s'\n",filename);
			exit(1);
		}
		
		if( S_ISDIR(fs.st_mode) )
			printf(" Dir %-16s ",filename);
		else
			printf("File %-16s ",filename);

		printf("%8lu bytes ",fs.st_size);

		printf("%s",ctime(&fs.st_atime));
	}

	closedir(dp);

	return(0);
}
