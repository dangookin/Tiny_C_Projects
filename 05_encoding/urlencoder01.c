#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;

	while( (ch=getchar()) != EOF )
	{
		if( ch=='-' || ch=='.' || ch=='_' || ch=='*' )
			putchar(ch);
		else if( ch==' ')
			putchar('+');
		else if( isalnum(ch) )
			putchar(ch);
		else
			printf("%%%02X",ch);
	}

	return(0);
}
