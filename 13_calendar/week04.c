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
	int day,weekday,month,sunday,d,pmonth,weekno; 

	time(&now);
	date = localtime(&now);

	mdays[1] = february(date->tm_year+1900);
	month = date->tm_mon;
	pmonth = month-1;
	if( pmonth<0 )
		pmonth=11;
	day = date->tm_mday;
	weekday = date->tm_wday;
	sunday = day - weekday;

	if( sunday<1 )
		printf("  %s / %s",months[pmonth],months[month]);
	else if( sunday+6 > mdays[month] )
	{
		if( month==11 )
			printf("  %s / %s",months[month],months[0]);
		else
			printf("  %s / %s",months[month],months[month+1]);
	}
	else
		printf("  %s",months[month]);

	weekno = (9 + date->tm_yday-weekday)/7;
	if( weekno==0 )
		weekno = 52;
	printf(" - Week %d\n",weekno);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for( d=sunday; d<sunday+7; d++ )
	{
		if( d<1 )
			printf(" %2d ",mdays[pmonth]+d);
		else if( d>mdays[month] )
			printf(" %2d ",d-mdays[month]);
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
