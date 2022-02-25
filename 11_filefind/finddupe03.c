#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

struct finfo {
	int index;
	int repeat;
	char name[BUFSIZ];
	char path[PATH_MAX];
	struct finfo *next;
};

struct finfo *find( char *dirpath, char *parentpath, struct finfo *f)
{
	DIR *dp;
	struct dirent *entry;
	struct stat fs;
	char subdirpath[PATH_MAX];
	int i;

	dp = opendir(dirpath);
	if( dp==NULL )
	{
		fprintf(stderr,"Unable to read directory '%s'\n",
				dirpath
			   );
		exit(1);
		/* will free memory as it exits */
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
			f = find(subdirpath,dirpath,f);
		}
		else
		{
			f->next = malloc( sizeof(struct finfo) * 1);
			if( f->next == NULL )
			{
				fprintf(stderr,
						"Unable to allocate new structure\n");
				exit(1);
			}

			i = f->index;
			f = f->next;
			f->index = i+1;
			f->repeat = 1;
			strcpy(f->name,entry->d_name);
			strcpy(f->path,dirpath);
			f->next = NULL;
		}
	}

	closedir(dp);

	if( chdir(parentpath)==-1 )
	{
		if( parentpath==NULL )
			return(f);
		fprintf(stderr,"Parent directory lost\n");
		exit(1);
	}
	return(f);
}

int main()
{
	char startdir[PATH_MAX];
	struct finfo *first,*current,*scan;

	first = malloc( sizeof(struct finfo) * 1 );
	if( first==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	first->index = 0;
	strcpy(first->name,"");
	strcpy(first->path,"");
	first->next = NULL;

	getcwd(startdir,PATH_MAX);
	if( chdir(startdir)==-1 )
	{
		fprintf(stderr,"Unable to access directory %s\n",
				startdir
			   );
			exit(1);
	}

	find(startdir,NULL,first);

	current = first;
	while( current )
	{
		if( current->index > 0 )
		{
			scan = current->next;
			while( scan )
			{
				if( strcmp(current->name,scan->name)==0 )
				{
					current->repeat++;
				}
				scan = scan->next;
			}
		}
		current = current->next;
	}

	current = first;
	while( current )
	{
		if( current->index > 0 )
		{
			printf("%d:%s/%s (%d)\n",
					current->index,
					current->path,
					current->name,
					current->repeat
				  );
		}
		current = current->next;
	}

	return(0);
}
