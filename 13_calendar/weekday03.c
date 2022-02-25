#include <stdio.h>
#include <stdlib.h>		/* needed for the strtol() and exit() functions */

int dow(int m,int d,int y)
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

int main(int argc, char *argv[])	/* include these arguments */
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

	/* if fewer than four arguments present, remind
	   the user of the command format */
	if( argc < 4 )
	{
		fprintf(stderr,"Format: weekday month day year\n");
		exit(1);
	}

	/* convert command line arguments into integers */
	m = strtol(argv[1],NULL,10);
	m--;			/* No human will type 0 for January */
					/* This is probably the statement you forgot */
	d = strtol(argv[2],NULL,10);
	y = strtol(argv[3],NULL,10);

	r = dow(m,d,y);

	printf("%s %d, %d is a %s\n",
			month[m],
			d,
			y,
			weekday[r]
		  );

	return(0);
}
