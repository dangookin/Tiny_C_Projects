#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int balls = 69, draw = 5;
	int x,r;

	srand( (unsigned)time(NULL) );

	printf("Drawing %d numbers from %d balls:\n",
			draw,
			balls
		  );

	for( x=0; x<draw; x++ )
	{
		r = rand() % balls+1;
		printf("%2d\n",r);
	}

	return(0);
}
