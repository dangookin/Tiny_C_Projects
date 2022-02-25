#include <stdio.h>
#include <ctype.h>

/* instead of counting where words start, this
   function counts whitespace */
int strwords(char *s)
{
	enum { FALSE, TRUE };
	int inword = FALSE;	
	int count;

	count = 0;					/* word count */
	while(*s)					/* loop through the string */
	{
		if( isspace(*s) )		/* whitespace encountered */
		{
			if( inword )		/* were we inside a word? */
			{
				count++;		/* tick off another word */
				inword = FALSE;	/* we're not inside a word */
			}
		}
		else
		{
			inword = TRUE;		/* inside a word */
		}
		s++;					/* next character */
	}

	if( inword==TRUE )			/* if we end inside a word... */
		count++;				/* ...count it */

	return(count);
}

int main()
{
	char string[] = "This isn't a sample string";

	printf("The string '%s' contains %d words\n",
			string,
			strwords(string)
		  );

	return(0);
}
