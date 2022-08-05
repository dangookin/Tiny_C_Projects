#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *left(char *s,int len)
{
	char *buf;
	int x;

	buf = malloc(sizeof(char)*len+1);
	if( buf==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	for(x=0;x<len;x++)
	{
		if( *(s+x)=='\0' )
			break;
		*(buf+x) = *(s+x);
	}
	*(buf+x) = '\0';

	return(buf);
}

char *right(char *s,int len)
{
	char *buf;
	char *start;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	start = s;
	while(*start!='\0')
	   start++;
	start -= len;
	if( start < s )
		exit(1);

	for(x=0;x<len;x++)
		*(buf+x) = *(start+x);
	*(buf+x) = '\0';

	return(buf);
}

char *mid(char *s, int offset, int len)
{
	char *buf;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	for(x=0;x<len;x++)
	{
		*(buf+x) = *(s+offset-1+x);
		if( *(buf+x)=='\0')	
			break;
	}
	*(buf+x) = '\0';

	return(buf);
}

int main()
{
	char string[] = "Slice me, dice me, make Julienne fries!";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",8,left(string,8));
	printf("Middle %d characters: %s\n",7,mid(string,11,7));
	printf("Right %d characters: %s\n",20,right(string,20));

	return(0);
}
