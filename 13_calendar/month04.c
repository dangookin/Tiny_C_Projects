#include <stdio.h>
#include <stdlib.h>			/* required for strtol() function */
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

int thefirst(int wday, int mday)
{
	int first;

	first = wday - (mday % 7) + 1;
	if( first < 0 )
		first += 7;

	return(first);
}

int main(int argc, char *argv[])
{
	const char *months[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	time_t now;
	struct tm *date;
	int month,today,weekday,year,first,day,d;
	int a_month,a_year;				/* arguments from the command line */
	const int output_width = 27;
	char title[output_width];

	/* obtain these values first */
	time(&now);
	date = localtime(&now);

	/* check for arguments */
	if( argc==3 )
	{
		a_month = strtol(argv[1],NULL,10);
		a_year = strtol(argv[2],NULL,10);
		if( a_month>0 && a_month<13 )		/* check month range */
		{
			date->tm_mon = a_month-1;		/* January is zero */
			date->tm_year = a_year - 1900;	/* account for 1900 */
			date->tm_mday = 1;				/* start on the first */
			mktime(date);					/* update the date structure */
		}
	}

	month = date->tm_mon;
	today = date->tm_mday;
	weekday = date->tm_wday;
	year = date->tm_year+1900;
	mdays[1] = february(year);
	first = thefirst(weekday,today);

	sprintf(title,"%s %d",months[month],year);
	center(title,output_width);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");

	day = 1;
	while( day<=mdays[month] )
   	{
		for( d = 0; d < 7; d++)
		{
			if( d<first && day==1 )
			{
				printf("    ");
			}
			else
			{
				if( day == today )
					printf("[%2d]",day);
				else
					printf(" %2d ",day);
				day++;
				if( day>mdays[month] )
					break;
			}
		}
		putchar('\n');
	}

	return(0);
}
