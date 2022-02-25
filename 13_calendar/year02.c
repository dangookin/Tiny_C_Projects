#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void center(char *text,int width)
{
	int s,length,indent;

	length = strlen(text);
	if( length < width )
	{
		indent = (width-length)/2;
		for(s=0;s<indent;s++)
			putchar(' ');
		puts(text);	
	}
	else
	{
		for(s=0;s<width;s++)
			putchar(*text++);
		putchar('\n');
	}
}

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

int main(int argc, char *argv[])
{
	const char *months[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	time_t now;				/* need this if no argument exists */
	struct tm date,*today;	/* add *today if no argument exists */
	int month,weekday,year,day,dow;
	const int output_width = 27;
	char title[output_width];

	if( argc<2 )			/* no year option typed */
	{
		time(&now);			/* use today's year */
		today = localtime(&now);
		date.tm_year = today->tm_year;
	}
	else			/* convert argv[1] to the year value */
	{
		date.tm_year = strtol(argv[1],NULL,10) - 1900;
	}

	/* fill the rest of the structure with January 1 data */
	date.tm_mon = 0;
	date.tm_mday = 1;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	putenv("TZ=GMT");
	tzset();	
	mktime(&date);

	/* setup January */
	weekday = date.tm_wday;
	year = date.tm_year + 1900;
	mdays[1] = february(year);

	dow = 0;
	for( month=0; month<12; month++ )
	{
		sprintf(title,"%s %d",months[month],year);
		center(title,output_width);
		printf("Sun Mon Tue Wed Thu Fri Sat\n");

		day = 1;
		while( day<=mdays[month] )
		{
			if( dow<weekday && day==1 )
			{
				printf("    ");
				dow++;
			}
			else
			{
				printf(" %2d ",day);
				dow++;
				if( dow > 6 )
				{
					dow = 0;
					putchar('\n');
				}
				day++;
				if( day>mdays[month] )
					break;
			}
		}
		weekday = dow;
		dow = 0;
		printf("\n\n");
	}

	return(0);
}
