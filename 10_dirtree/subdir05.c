#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void dir(const char *dirname)
{
	DIR *dp;
	struct dirent *entry;
	struct stat fs;
	char *filename;
	char directory[BUFSIZ];

	if( chdir(dirname)==-1 )
	{
		fprintf(stderr,"Unable to change to %s\n",dirname);
		exit(1);
	}

	getcwd(directory,BUFSIZ);

	dp = opendir(directory);
	if( dp==NULL )
	{
		fprintf(stderr,"Unable to read directory '%s'\n",
				directory
			   );
		exit(1);
	}

	printf("%s\n",directory);
	while( (entry=readdir(dp)) != NULL )
	{
		filename = entry->d_name;
		if( strncmp( filename,".",1)==0 )
			continue;

		stat(filename,&fs);
		if( S_ISDIR(fs.st_mode) )
			dir(filename);
	}

	closedir(dp);

	if( chdir("..")==-1 )
	{
		fprintf(stderr,"Parent directory lost\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	if( argc<2 )
	{
		dir(".");
	}
	else
		dir(argv[1]);

	return(0);
}
