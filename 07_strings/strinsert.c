#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strinsert(char *org, char *ins, int offset)
{
	char *new;
	int size,index,append;

	size = strlen(org)+strlen(ins);
	if( offset<0 )
		return(NULL);

	new = malloc(sizeof(char) * size+1);
	if( new==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}
	
	offset -= 1;
	index = 0;
	append = 0;
	while( *org )
	{
		if( index==offset )
		{
			while( *ins )
			{
				*(new+index) = *ins;
				index++;
				ins++;
			}
			append = 1;
		}
		*(new+index) = *org;
		index++;
		org++;
	}
	if( !append )
	{
		while( *ins )
		{
			*(new+index) = *ins;
			index++;
			ins++;
		}
	}
	*(new+index) = '\0';

	return(new);
}

int main()
{
	char s1[] = "Well, this is another mess!";
	char s2[] = "fine ";

	printf("Before: %s\n",s1);
	printf("After: %s\n",strinsert(s1,s2,23));

	return(0);
}
