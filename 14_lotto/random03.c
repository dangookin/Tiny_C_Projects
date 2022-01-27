#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int rows = 5;
	int x,y,r;

	srand( (unsigned)time(NULL) );

	for( x=0; x<rows; x++ )
	{
		for( y=0; y<rows; y++ )
		{
			r = rand() % 100 +1;
			printf("%3d ",r);
		}
		putchar('\n');
	}

	return(0);
}
