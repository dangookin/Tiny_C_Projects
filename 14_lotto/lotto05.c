#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 69
#define DRAW 5

void lotto(int *a)
{
	int numbers[BALLS];
	int x,y,r;

	for( x=0; x<BALLS; x++ )
	{
		numbers[x] = 0;
	}

	for( x=0; x<DRAW; x++ )
	{
		do
			r=rand()%BALLS;
		while( numbers[r]==1 );
		numbers[r] = 1;
	}

	y = 0;
	for( x=0; x<BALLS; x++ )
	{
		if( numbers[x] )
		{
			*(a+y) = x;
			y++;
		}
		if( y==DRAW )
			break;
	}
}

int main()
{
	int x;
	int match[DRAW];

	srand( (unsigned)time(NULL) );

	printf("Trying to match:");
	lotto(match);
	for( x=0; x<DRAW; x++ )
	{
		printf(" %d",match[x]+1);
		if( x<DRAW-1 )
			printf(" -");
	}
	putchar('\n');

	return(0);
}
