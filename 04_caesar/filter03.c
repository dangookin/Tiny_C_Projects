#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int ch,r;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	while( (ch = getchar()) != EOF)
	{
		/* generate a random value, 0 or 1 */
		r = rand() % 2;
		if( r )				/* if r==1, make the character uppercase */
			putchar(toupper(ch));
		else				/* otherwise, it's converted to lowercase */
			putchar(tolower(ch));
		/* toupper() and tolower() affect only letters */
	}

	return(0);
}
