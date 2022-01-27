#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int rows = 5;
	int x,y,r;

	for( x=0; x<rows; x++ )
	{
		for( y=0; y<rows; y++ )
		{
			r = rand();
			printf("%d ",r);
		}
		putchar('\n');
	}

	return(0);
}
