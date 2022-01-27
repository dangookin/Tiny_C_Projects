#include <stdio.h>
#include <time.h>

int main()
{
	const char *months[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	time_t now;
	struct tm *date;
	int day,weekday,month,sunday,d;

	time(&now);
	date = localtime(&now);

	day = date->tm_mday;
	month = date->tm_mon;
	weekday = date->tm_wday;
	sunday = day - weekday;

	printf("  %s\n",months[month]);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for( d=sunday; d<sunday+7; d++ )
	{
		if( d==day )
			printf("[%2d]",d);
		else
			printf(" %2d ",d);
	}
	putchar('\n');

	return(0);
}
