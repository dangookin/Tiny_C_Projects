#include <stdio.h>

/* This function rolls over the 'digits' in the array from 'a'
   to 'z'. When 'z' is encountered, the column shift back to 'a', but
   the function is recursively called to the next position left,
   which is -1 element in the array.
   A check is made to ensure that the function doesn't attempt to
   modify array elements < 0.
   Argument 'c' is the char array.
   Argument pos is the element position, highest first
 */  
int flip(char *c,int pos)
{
	*(c+pos) = *(c+pos)+1;			/* increment the letter */
	if( *(c+pos) > 'z' )			/* check for overflow */
	{
		*(c+pos) = 'a';				/* reset back to a */
		if( pos!=0 )				/* watch for overflow */
		{
			if( !flip(c,pos-1) )	/* flip the next column's digit */
				return(0);			/* echo down the FALSE return */
		}
		else
			return(0);				/* last column, FALSE return */
	}
	return(1);						/* keep looping */
}

int main()
{
	char password[] = "password";	/* password to guess */
	char guess[] = "aaaaaaaa";		/* initalized to make it easier */
	char *p,*g;

	printf("Password cracking...\n");
	/* I use a do-while loop so that the first iteration of
	   guess[] isn't skipped */
	do
	{
		/* perform the comparison and exit if true */
		/* This is my own string comparison routine as
		   strcmp() is slow */
		p = password;
		g = guess;
		while(*p)
		{
			if( *p==*g )		/* compare each letter */
			{
				p++;
				g++;
			}
			else
				break;			/* break when they don't match */
		}
		/* if both characters are null here, the strings match */
		if( *p=='\0' && *g=='\0' )
		{
			printf("Found password '%s'\n",guess);
			break;		/* stop the loop */
		}
	}
	while( flip(guess,7) );

	return(0);
}
