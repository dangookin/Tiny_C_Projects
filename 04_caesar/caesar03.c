#include <stdio.h>
#include <ctype.h>

int main()
{
	int shift,ch;

	shift = 'A' - 'D';

	while( (ch = getchar()) != EOF)
	{
		if( isalpha(ch))
		{
			ch+= shift;
			if( ch<'A' || (ch>'Z' && ch<'a'))
				ch+= 26;
		}
		putchar(ch);
	}

	return(0);
}
