#include <stdio.h>
#include <time.h>

int thefirst(int wday, int mday)
{
	int first;

	first = wday - ( mday % 7 ) + 1;
	if( first < 0 )
		first += 7;

	return(first);
}

int main()
{
	enum {
		SUNDAY, MONDAY, TUESDAY, WEDNESDAY,
		THURSDAY, FRIDAY, SATURDAY
	};
	const char *weekday[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};

	printf("If day %d is a %s, the first is on a %s\n",
			25,
			weekday[SATURDAY],
			weekday[ thefirst(SATURDAY,25) ]
		  );

	return(0);
}
