#include <stdio.h>
#include <ctype.h>

int strwords(char *s)
{
	enum { FALSE, TRUE };
	int inword = FALSE;	
	int count;

	count = 0;
	while(*s)
	{
		if( isalpha(*s) )
		{
			if( !inword )
			{
				count++;
				inword = TRUE;
			}
		}
		else
		{
			inword = FALSE;
		}
		s++;
	}

	return(count);
}

int main()
{
	char string[] = "This is a sample string";

	printf("The string '%s' contains %d words\n",
			string,
			strwords(string)
		  );

	return(0);
}
