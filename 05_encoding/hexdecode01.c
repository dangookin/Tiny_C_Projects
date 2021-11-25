#include <stdio.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

int main()
{
	char line[LENGTH];
	int x,ch;

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

			printf("%s\n",line);
			x = 0;
		}
	}

	return(0);
}
