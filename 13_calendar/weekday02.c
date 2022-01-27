#include <stdio.h>

int dayoftheweek(int m,int d,int y)
{
	int t[] = {
		0, 3, 2, 5, 0, 3,
		5, 1, 4, 6, 2, 4
	};
	int r;

	y -= m<2;
	r = ( y + y/4 - y/100 + y/400 + t[m] + d) % 7;
	return(r);
}

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
	int m,d,y,r;

	m = 1;
	d = 3;
	y = 1993;

	r = dayoftheweek(m,d,y);

	printf("%s %d, %d is a %s\n",
			month[m],
			d,
			y,
			weekday[r]
		  );

	return(0);
}
