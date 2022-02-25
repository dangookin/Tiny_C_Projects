#include <stdio.h>
#include <time.h>

int main()
{
	time_t now;
	struct tm *today;
	int month,day,year,weekday;

	now = time(NULL);
	today = localtime(&now);

	month = today->tm_mon+1;
	day = today->tm_mday;
	weekday = today->tm_wday;
	year = today->tm_year+1900;

	printf("Today is %d, %d %d, %d\n",
			weekday,
			month,
			day,
			year
		  );

	return(0);
}
