#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main()
{
	const char filename[] = "pithy.txt";
	FILE *fp;
	char buffer[BSIZE];
	char *r,*entry;
	int items,x;
	char **list_base;

	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open file %s\n",filename);
		exit(1);
	}

	list_base = malloc(sizeof(char *) * 100);
	if( list_base==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	items = 0;
	while( !feof(fp) )
	{
		r = fgets(buffer,BSIZE,fp);
		if( r==NULL )
			break;
		entry = malloc(sizeof(char) * strlen(buffer)+1);
		if( entry==NULL )
		{
			fprintf(stderr,"Unable to allocate memory\n");
			exit(1);
		}
		strcpy(entry,buffer);
		*(list_base+items) = entry;
		items++;
		if( items%100==0 )
		{
			list_base = realloc(list_base,sizeof(char *)*(items+100));
			if( list_base==NULL )
			{
				fprintf(stderr,"Unable to reallocate memory\n");
				exit(1);
			}
		}
	}

	fclose(fp);

	for( x=0; x<items; x++ )
		printf("%s",*(list_base+x));
		
	return(0);
}
