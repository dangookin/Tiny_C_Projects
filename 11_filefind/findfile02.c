#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <glob.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

int count;

void find(char *dirpath,char *parentpath,char *match)
{
	DIR *dp;
	struct dirent *entry;
	struct stat fs;
	char subdirpath[PATH_MAX];
	int g;
	glob_t gstruct;
	char **found;

	dp = opendir(dirpath);
	if( dp==NULL )
	{
		fprintf(stderr,"Unable to read directory '%s'\n",
				dirpath
			   );
		exit(1);
	}

	g = glob(match, GLOB_ERR, NULL, &gstruct);
	if( g==0 )
	{
		found = gstruct.gl_pathv;
		while(*found)
		{
			printf("%s/%s\n",dirpath,*found);
			found++;
			count++;
		}
	}

	while( (entry=readdir(dp)) != NULL )
	{
		stat(entry->d_name,&fs);
		if( S_ISDIR(fs.st_mode) )
		{
			if( strncmp( entry->d_name,".",1)==0 )
				continue;
			if( chdir(entry->d_name)==-1 )
			{
				fprintf(stderr,"Unable to change to %s\n",
						entry->d_name
					   );
				exit(1);
			}

			getcwd(subdirpath,BUFSIZ);
			find(subdirpath,dirpath,match);
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
	char current[PATH_MAX];
	char filename[PATH_MAX];
	char *r;

	printf("Filename or wildcard: ");
	r = fgets(filename,PATH_MAX,stdin);
	if( r==NULL )
		exit(1);
	while( *r!='\0' )
	{
		if( *r=='\n' )
		{
			*r = '\0';
			break;
		}
		r++;
	}

	getcwd(current,PATH_MAX);
	if( chdir(current)==-1 )
	{
		fprintf(stderr,"Unable to access directory %s\n",
				current
			   );
			exit(1);
	}

	count = 0;
	printf("Searching for '%s'\n",filename);
	find(current,NULL,filename);
	printf(" Found %d match",count);
	if( count!=1 )
		printf("es");
	putchar('\n');

	return(0);
}
