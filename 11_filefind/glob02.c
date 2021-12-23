#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

int main()
{
	char filename[PATH_MAX];
	char *r;
	int g;
	glob_t gstruct;
	char **found;

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

	g = glob(filename, GLOB_ERR , NULL, &gstruct);
	if( g!=0 )
	{
		if( g==GLOB_NOMATCH )
			fprintf(stderr,"No matches for '%s'\n",filename);
		else
			fprintf(stderr,"Some kinda glob error\n");
		exit(1);
	}
	
	printf("Found %zu filename matches\n",gstruct.gl_pathc);
	found = gstruct.gl_pathv;
	while(*found)
	{
		printf("%s\n",*found);
		found++;
	}

	return(0);
}
