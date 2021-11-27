#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
	char ch;
	const int length = 10;

	srand( (unsigned)time(NULL) );

	for( x=0; x<length; x++ )
	{
		ch = rand() % ('~' - '!' + 1);
		putchar( ch+'!' );
	}
	putchar('\n');

	return(0);
}
