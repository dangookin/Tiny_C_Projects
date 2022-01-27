#include <stdio.h>
#include <time.h>

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
	int first;

	first = WEDNESDAY - ( 12 % 7 ) + 1;
	if( first < 0 )
		first += 7;

	printf("The first of this month was on a %s\n",
			weekday[first]
		  );

	return(0);
}
