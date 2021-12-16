#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void dir(const char *dirpath,const char *parentpath)
{
	DIR *dp;
	struct dirent *entry;
	struct stat fs;
	char subdirpath[BUFSIZ];

	dp = opendir(dirpath);
	if( dp==NULL )
	{
		fprintf(stderr,"Unable to read directory '%s'\n",
				dirpath
			   );
		exit(1);
	}

	printf("%s\n",dirpath);
	while( (entry=readdir(dp)) != NULL )
	{
		if( strncmp( entry->d_name,".",1)==0 )
			continue;

		stat(entry->d_name,&fs);
		if( S_ISDIR(fs.st_mode) )
		{
			if( chdir(entry->d_name)==-1 )
			{
				fprintf(stderr,"Unable to change to %s\n",
						entry->d_name
					   );
				exit(1);
			}

			getcwd(subdirpath,BUFSIZ);
			dir(subdirpath,dirpath);
		}
	}

	closedir(dp);

	if( chdir(parentpath)==-1 )
	{
		if( parentpath==NULL )
			return;
		fprintf(stderr,"Parent directory lost\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	char current[BUFSIZ];

	if( argc<2 )
	{
		getcwd(current,BUFSIZ);
	}
	else
	{
		strcpy(current,argv[1]);
		if( chdir(current)==-1 )
		{
			fprintf(stderr,"Unable to access directory %s\n",
					current
				   );
			exit(1);
		}
		getcwd(current,BUFSIZ);
	}

	dir(current,NULL);

	return(0);
}
