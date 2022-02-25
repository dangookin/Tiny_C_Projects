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

int winner(int *m, int *g)
{
	int x,y,c;

	c = 0;
	for( x=0; x<DRAW; x++ )
		for( y=0; y<DRAW; y++ )
		{
			if( *(m+x) == *(g+y) )
				c++;
		}
	return(c);
}

int main()
{
	const int tomatch = 2;
	int x,c,count;
	int match[DRAW],guess[DRAW];

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

	count = 0;
	do
	{
		lotto(guess);
		c = winner(match,guess);
		count++;
	} while( c<tomatch );

	printf("It took %d times to match %d balls:\n",
			count,
			c
		  );
	for( x=0; x<DRAW; x++ )
	{
		printf(" %d",guess[x]+1);
		if( x<DRAW-1 )
			printf(" -");
	}
	putchar('\n');

	return(0);
}
