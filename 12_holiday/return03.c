#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int r;

	srand( (unsigned)time(NULL) );

	r = rand() % 2;
	if(r)
	{
		fprintf(stderr,"Welp, this program screwed up!\n");
		return(EXIT_FAILURE);
	}
	else
	{
		printf("Everything went ducky!\n");
		return(EXIT_SUCCESS);
	}
}
