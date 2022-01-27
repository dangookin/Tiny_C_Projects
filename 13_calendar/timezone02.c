#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t epoch = 0;

	putenv("TZ=GMT");
	tzset();
	printf("Time is %s",ctime(&epoch) );

	return(0);
}
