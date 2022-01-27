#include <stdio.h>
#include <time.h>
#include <string.h>			/* required for the strlen() function */

void center(char *text,int width)
{
	int s,length,indent;

	length = strlen(text);			/* obtain string length */
	if( length < width )			/* center the string within width */
	{
		indent = (width-length)/2;	/* calculate the setback */
		for(s=0;s<indent;s++)		/* pad spaces */
			putchar(' ');
		puts(text);					/* output text */
	}
	else							/* string is too long, so truncate */
	{
		for(s=0;s<width;s++)		/* output only width characters */
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
	int month,today,weekday,year,first,day,d;
	const int output_width = 27;		/* calendar width */
	char title[output_width];			/* string to store centered text */

	time(&now);
	date = localtime(&now);

	month = date->tm_mon;
	today = date->tm_mday;
	weekday = date->tm_wday;
	year = date->tm_year+1900;
	mdays[1] = february(year);
	first = thefirst(weekday,today);

	sprintf(title,"%s %d",months[month],year);	/* build string */
	center(title,output_width);					/* output string */
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
