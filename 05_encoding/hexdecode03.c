#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

int main()
{
	char line[LENGTH];
	int x,ch,hex;
	char *r;

	r = fgets(line,LENGTH,stdin);
	if( r==NULL || strncmp(line,"HEX ENCODE",10)!=0 )
	{
		fprintf(stderr,"Invalid HEX ENCODE data\n");
		exit(1);
	}

	x = 0;
	while( (ch=getchar()) != EOF )
	{
		line[x] = ch;
		x++;
		if( ch=='\n' || x==LENGTH)
		{
			if( line[x-1]=='\n')
				line[x-1] = '\0';
			else
				line[x] = '\0';

			if( strncmp(line,"HEX ENCODE END",13)==0 )
				break;

			r = strtok(line," ");
			while(r)
			{
				sscanf(r,"%02X",&hex);
				printf("%c",hex);
				r = strtok(NULL," ");
			}
			x = 0;
		}
	}

	return(0);
}
