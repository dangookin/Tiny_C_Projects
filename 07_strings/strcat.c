#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char *src)
{
	return( strcat(dest,src) );
}

int main()
{
	char s1[32] = "This is another ";
	char s2[] = "fine mess!";
	char *s3;

	s3 = strappend(s1,s2);
	printf("%s\n",s3);

	return(0);
}
