#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char *src)
{
	char *s;
	char *index;

	/* allocate storage for the new string */
		/* you can't use sizeof here as it returns the
		   size of a char pointer, not the string's storage */
	s = malloc( strlen(dest)+strlen(src)+1 );	/* +1 for the \0 */
		/* always test allocated storage */
	if( s==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	/* copy the first string */
	index = s;			/* initialize offset */
	while( *dest )		/* loop until \0 found */
	{
		*index = *dest;	/* copy the character */
		index++;		/* indrement offset */
		dest++;			/* increment string */
	}

	/* copy the second string */
	while( *src )
	{
		*index = *src;
		index++;
		src++;
	}
	*index = '\0';		/* properly terminate the new string */

	return(s);
}

int main()
{
	char s1[] = "This is another ";	/* no need for 32 characters here */
	char s2[] = "fine mess!";
	char *s3;

	s3 = strappend(s1,s2);
	printf("%s\n",s3);

	return(0);
}
