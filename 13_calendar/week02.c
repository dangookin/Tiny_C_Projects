#include <stdio.h>
#include <time.h>

int february(int year)
{
    if( year%400==0 )
        return(29);

    if( year%100==0 )
        return(28);

    if( year%4!=0 )
        return(28);

    return(29);
}

int main()
{
	const char *months[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	time_t now;
	struct tm *date;
	int day,weekday,month,sunday,d;

	time(&now);
	date = localtime(&now);
	mdays[1] = february(date->tm_year+1900);

	month = date->tm_mon;
	day = date->tm_mday;
	weekday = date->tm_wday;
	sunday = day - weekday;

	printf("  %s\n",months[month]);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for( d=sunday; d<sunday+7; d++ )
	{
		if( d<1 || d>mdays[month] )
			printf("    ");
		else
		{
			if( d==day )
				printf("[%2d]",d);
			else
				printf(" %2d ",d);
		}
	}
	putchar('\n');

	return(0);
}
