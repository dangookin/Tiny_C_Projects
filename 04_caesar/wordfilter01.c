#include <stdio.h>
#include <ctype.h>

#define WORDSIZE 64

int main()
{
	char word[WORDSIZE];
	int ch,offset;

	offset = 0;
	while( (ch = getchar()) != EOF)
	{
		if( isspace(ch) )
		{
			word[offset] = '\0';
			if( offset>0 )
				printf("%s\n",word);
			offset = 0;
		}
		else
		{
			word[offset] = ch;
			offset++;
			if( offset==WORDSIZE-1 )
			{
				word[offset] = '\0';
				printf("%s\n",word);
				offset = 0;
			}
		}
	}

	return(0);
}
