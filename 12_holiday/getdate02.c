#include <stdio.h>
#include <time.h>

int main()
{
	time_t now;
	struct tm *today;
	int month,day,year,weekday;
	/* if you use the *months[] type of declaration for an
	   array of strings, remember to make it 'const' as
	   modifying the strings can get you into trouble */
	const char *months[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December"
	};
	/* value 0 is Sunday for the tm_wday structure member */
	const char *days[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday"
	};

	now = time(NULL);
	today = localtime(&now);

	month = today->tm_mon;		/* oops! Did you forget to modify
								   this statement? tm_mon starts
								   with 0 for January */
	day = today->tm_mday;
	weekday = today->tm_wday;
	year = today->tm_year+1900;

	/* replace the first two conversion characters with
	   %s for the new string values */
	printf("Today is %s, %s %d, %d\n",
			days[weekday],
			months[month],
			day,
			year
		  );

	return(0);
}
