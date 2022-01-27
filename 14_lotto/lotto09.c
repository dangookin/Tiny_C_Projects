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
	const int tomatch = 5;
	const int tally = 100;
	int x,c,count;
	int match[DRAW],guess[DRAW];
	/* new variables here */
	int q,results[tally];
	long total;
	float average;

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

	/* new loop to preform the operation 100 times */
	q = 0;					/* loop counter */
	while( q<tally )		/* loop 'tally' times */
	{
		count = 0;
		do
		{
			lotto(guess);
			c = winner(match,guess);
			count++;
		} while( c<tomatch );
		results[q] = count;		/* retain the repeat count */
		q++;				/* increment the loop counter */
	}

	/* obtain the total and the average */
	total = 0;
	for( x=0; x<tally; x++ )
		total += results[x];		/* add up all the values */
	average = (float)total/(float)tally;	/* divide to get the average */

	/* reporting statements */
	printf("For %d times, the average count ",tally);
	printf("to match %d balls is %.0f\n",tomatch,average);

	return(0);
}
