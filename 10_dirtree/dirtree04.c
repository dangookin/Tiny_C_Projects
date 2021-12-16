#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct dentry {
	char *name;
	char path[BUFSIZ];
	char parent[BUFSIZ];
	int depth;
	int last;
};

char *extract(char *path)
{
	char *p;
	int len;

	len = strlen(path);
	if( len==0 )
		return(NULL);
	if( len==1 & *(path+0)=='/' )
		return(path);

	p = path+len;
	while( *p != '/' )
	{
		p--;
		if( p==path )
			return(NULL);
	}
	p++;

	if( *p == '\0' )
		return(NULL);
	else
		return(p);
}

void dir(struct dentry *d,int i)	
{
	DIR *dp;
	struct dirent *entry;
	struct stat fs;
	int indent;

	(d+i)->last = FALSE;

	dp = opendir((d+i)->path);
	if( dp==NULL )
	{
		fprintf(stderr,"Unable to read directory '%s'\n",
				(d+i)->path
			   );
		exit(1);
	}

	for( indent=0; indent<(d+i)->depth; indent++ )
	{
		if( indent==((d+i)->depth)-1 )
			printf("+--");
		else
			printf("|  ");
	}

	(d+i)->name = extract((d+i)->path);
	printf("%s\n",(d+i)->name);
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

			/* check for size limit */
			getcwd((d+i+1)->path,BUFSIZ);
			strcpy( (d+i+1)->parent, (d+i)->path );
			(d+i+1)->depth = (d+i)->depth+1;
			dir(d,i+1);
		}
	}

	closedir(dp);

	/* last i item is the last directory */
	(d+i)->last = TRUE;
	if( chdir((d+i)->parent)==-1 )
		return;
}

int main(int argc, char *argv[])
{
	struct dentry *d;
	int i = 0;

	d = (struct dentry *)malloc(sizeof(struct dentry)*100);
	if( d==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	if( argc<2 )
	{
		getcwd((d+i)->path,BUFSIZ);
	}
	else
	{
		strcpy((d+i)->path,argv[1]);
		if( chdir((d+i)->path)==-1 )
		{
			fprintf(stderr,"Unable to access directory %s\n",
					(d+i)->path
				   );
			exit(1);
		}
		getcwd((d+i)->path,BUFSIZ);
	}

	dir(d+i,0);

	return(0);
}
