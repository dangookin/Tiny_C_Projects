#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;

	while( (ch = getchar()) != EOF)
	{
		if( islower(ch) )			/* weed out only lowercase letters */
			putchar( toupper(ch) );	/* output uppercase */
		else
			putchar(ch);
	}

	return(0);
}
/*
   You can modify this filter to output only lowercase letters or
   to switch case (u/c to l/c and vice-versa). Use the proper
   ctype function to perform the conversions
*/
