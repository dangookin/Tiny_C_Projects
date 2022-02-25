#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
	return( *(int *)a - *(int *)b);
}

int main()
{
	const int balls = 69, draw = 5;
	int x,y;
	int winners[draw];

	srand( (unsigned)time(NULL) );

	printf("Drawing %d numbers from %d balls:\n",
			draw,
			balls
		  );

	for( x=0; x<draw; x++ )
	{
		winners[x] = rand()%balls+1;
	}

	for( x=0; x<draw-1; x++ )
		for( y=x+1; y<draw ; y++ )
			if( winners[x]==winners[y] )
			{
				winners[y] = rand()%balls + 1;
				y = draw;
				x = -1;
			}

	/* add the quicksort */
	qsort(winners,draw,sizeof(int),compare);

	/* output the results */
	for( x=0; x<draw; x++ )
	{
		printf(" %d",winners[x]);	/* prefix each number with a space */
									/* no padding, no %2d */
		if( x<draw-1 )				/* before the last number is output */
			printf(" -");			/* add a dash between the numbers */
	}
	putchar('\n');

	return(0);
}
