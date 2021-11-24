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
	int items;

	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open file %s\n",filename);
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
		printf("%d: %s",items,entry);
		items++;
	}

	fclose(fp);
		
	return(0);
}
