#include <stdio.h>
#include <time.h>

int moon_phase(int year,int month,int day)
{
    int d,g,e;

	d = day;
    if(month == 2)
		d += 31;
    else if(month > 2)
		d += 59+(month-3)*30.6+0.5;
    g = (year-1900)%19;
    e = (11*g + 29) % 30;
    if(e == 25 || e == 24)
		++e;
	return ((((e + d)*6+5)%177)/22 & 7);
}

int main(int argc, char *argv[])
{
	time_t now;
	struct tm *clock;
	char time_string[64];
	char *phase[8] = {
			"waxing crescent", "at first quarter",
			"waxing gibbous", "full", "waning gibbous",
			"at last quarter", "waning crescent", "new"
	};
	int mp;

	time(&now);
	clock = localtime(&now);
	
	strftime(time_string,64,"Today is %A, %B %d, %Y%nIt is %r%n",clock);

	printf("Greetings");
	if( argc>1 )
		printf(", %s",argv[1]);
	printf("!\n%s",time_string);
	mp = moon_phase(clock->tm_year+1900,clock->tm_mon,clock->tm_mday);
	printf("The moon is %s\n",phase[mp]);

	return(0);
}
