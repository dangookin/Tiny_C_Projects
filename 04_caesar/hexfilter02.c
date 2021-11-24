#include <stdio.h>

int main()
{
	int ch,wrap;

	wrap = 0;			/* initialize the wrap to zero */
	while( (ch=getchar()) != EOF )
	{
		printf("%02X ",ch);
		wrap+=3;		/* each printf() output is 3 characters wide */
						/* assume that the terminal column width is 80 */
		if( wrap>77 || ch=='\n' )	/* I chose 77 because 77+3=80 */
		{
			putchar('\n');		/* output a newline - wrap */
			wrap=0;				/* reset the wrap value */
		}
	}

	return(0);
}
