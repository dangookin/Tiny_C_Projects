#include <stdio.h>
#include <time.h>

int main()
{
	time_t epoch = 0;

	printf("Time is %s",ctime(&epoch) );

	return(0);
}
