#include <stdio.h>
#include <ctype.h>

/* I chose to use ctype functions as opposed to writing my own */

/* capitalize the first character of each word in the string */
void strcaps(char *s)
{
	enum { FALSE, TRUE };	/* create TRUE/FALSE constants, 0 and 1 */
	int inword = FALSE;		/* assume not in a word to start */

	/* loop through the string until *s=='\0' */
	while(*s)
	{
		if( isalpha(*s) )	/* look for alphabetic characters */
		{
			if( !inword )		/* is a word being processed? If not, */
			{					/* a new word has started */
				*s = toupper(*s);	/* convert first letter to u/c */
				inword = TRUE;		/* currently inside a word */
			}
		}
		else				/* non-alphabet characters here */
		{
			inword = FALSE;		/* not in a word */
		}
		s++;				/* continue processing the string */
	}
}

int main()
{
	char string[] = "This is a sample string";

	printf("Original string: %s\n",string);
	strcaps(string);
	printf("Uppercase string: %s\n",string);

	return(0);
}
