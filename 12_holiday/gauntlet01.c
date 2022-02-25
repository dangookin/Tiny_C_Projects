#include <stdio.h>

int main()
{
	const char *month[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	const char *weekday[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
	int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31,
		30, 31, 30, 31 };
	enum { SU, MO, TU, WE, TH, FR, SA };
	int start_day,dom,doy,year,m;

	start_day = SA;
	doy = 1;
	year = 2022;
	for( m=0; m<12; m++ )
	{
		for( dom=1; dom<=mdays[m]; dom++ )
		{
			printf("%s, %s %d, %d\n",
					weekday[ (doy+start_day-1) % 7],
					month[m],
					dom,
					year
				  );
			doy++;
		}
	}

	return(0);
}
