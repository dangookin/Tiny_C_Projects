#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int balls = 69, draw = 5;
	int x,r,count;
	int numbers[balls];

	srand( (unsigned)time(NULL) );

	printf("Drawing %d numbers from %d balls:\n",
			draw,
			balls
		  );

	for( x=0; x<balls; x++ )
	{
		numbers[x] = 0;
	}

	for( x=0; x<draw; x++ )
	{
		do
			r=rand()%balls;
		while( numbers[r]==1 );
		numbers[r] = 1;
	}

	count = 0;
	for( x=0; x<balls; x++ )
	{
		if( numbers[x] )
		{
			printf(" %d",x+1);
			count++;
			if( count<draw )
				printf(" -");
		}
	}
	putchar('\n');

	return(0);
}
