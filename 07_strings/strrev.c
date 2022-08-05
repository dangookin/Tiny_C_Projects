#include <stdio.h>
#include <stdlib.h>

char *strrev(char *s)
{
	int len,i;
	char *reversed;

	len = 0;
	while( *s )
	{
		len++;
		s++;
	}

	reversed = malloc( sizeof(char) * len );
	if( reversed==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	s--;
	i = 0;
	while(len)
	{
		*(reversed+i) = *s;
		i++;
		len--;
		s--;
	}
	*(reversed+i) = '\0';

	return(reversed);
}

int main()
{
	char s[] = "A string dwelling in memory";

	printf("Before: %s\n",s);
	printf("After: %s\n",strrev(s));

	return(0);
}
