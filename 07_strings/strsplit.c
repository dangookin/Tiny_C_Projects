#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsplit(char *org,int offset,char **s1,char **s2)
{
	int len;

	len = strlen(org);
	if(offset > len)
		return(0);
	*s1 = malloc(sizeof(char) * offset+1);
	*s2 = malloc(sizeof(char) * len-offset+1);
	if( s1==NULL || s2==NULL )
		return(0);
	strncpy(*s1,org,offset);
	strncpy(*s2,org+offset,len-offset);
	return(1);
}

int main()
{
	char string[] = "When this baby hits 88 miles per hour";
	char *first,*second;
	int r;

	r = strsplit(string,15,&first,&second);
	if(r==1)
	{
		printf("Split successful\n");
		printf("'%s' split into:\n",string);
		printf("'%s'\n",first);
		printf("'%s'\n",second);
	}
	else
	{
		puts("The function was unable to split the string");
	}

	return(0);
}
