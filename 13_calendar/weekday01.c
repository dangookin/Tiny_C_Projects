#include <stdio.h>
#include <time.h>

int main()
{
	const char *weekday[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
	const char *month[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	time_t now;
	struct tm *date;

	time(&now);
	date = localtime(&now);

	printf("Today is %s %d, %d, a %s\n",
			month[ date->tm_mon ],
			date->tm_mday,
			date->tm_year+1900,
			weekday[ date->tm_wday ]
		  );

	return(0);
}
