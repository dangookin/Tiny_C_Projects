#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COLUMNS 4
#define BOLD 1
#define RED	1			/* added for today's highlight */
#define BLACK 0
#define CYAN 6
#define WHITE 7
#define FG 30
#define BG 40

/* this function outputs today's date in red on black */
void color_today(int d)
{
	printf("\x1b[%d;%dm%2d",
			FG+RED,
			BG+BLACK,
			d
		  );
}

/* a single color output function can be written to output any
   text or value in a single function. The text string must be
   passed, along with the foreground and background colors */

void color_output(int d)
{
	if( d%2 )
		printf("\x1b[%d;%dm%2d",
				FG+BLACK,
				BG+WHITE,
				d
			  );
	else
		printf("\x1b[%d;%dm%2d",
				FG+WHITE,
				BG+CYAN,
				d
			  );
}

void center(char *text,int width)
{
	int s,length,indent;

	length = strlen(text);
	if( length < width )
	{
		indent = (width-length)/2;
		for(s=0;s<indent;s++)
			putchar(' ');
		while( *text )
		{
			putchar(*text);
			text++;
			s++;
		}
		for(;s<width;s++)
			putchar(' ');
	}
	else
	{
		for(s=0;s<width;s++)
			putchar(*text++);
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
		"Jan", "Feb", "March", "April",
		"May", "June", "July", "Aug",
		"Sep", "Oct", "Nov", "Dec"
	};
	int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dotm[12];
	time_t now;	
	struct tm date,*today;
	int month,weekday,year,day,dow,c,week;
	const int output_width = 14;
	char title[output_width];

	time(&now);						/* these two statements are moved */
	today = localtime(&now);		/* outside of the if decision */
									/* it's necessary to always know
									   the current date, even when
									   another year is specified at
									   the command prompt */
	if( argc<2 )
	{
		date.tm_year = today->tm_year;
	}
	else
	{
		date.tm_year = strtol(argv[1],NULL,10) - 1900;
	}

	date.tm_mon = 0;
	date.tm_mday = 1;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	putenv("TZ=GMT");
	tzset();	
	mktime(&date);

	weekday = date.tm_wday;
	year = date.tm_year + 1900;
	mdays[1] = february(year);
	dotm[0] = weekday;

	for( month=1; month<12; month++ )
	{
		dotm[month] = (mdays[month-1]+dotm[month-1]) % 7;
	}

	for( month=0; month<12; month+=COLUMNS )
	{
		for( c=0; c<COLUMNS; c++ )
		{
			sprintf(title,"%s %d",months[month+c],year);
			center(title,output_width);
			printf("  ");
		}
		putchar('\n');

		for( c=0; c<COLUMNS; c++ )
		{
			printf("\x1b[%dm%s",BOLD,"Su");
			printf("\x1b[0m%s","Mo");
			printf("\x1b[%dm%s",BOLD,"Tu");
			printf("\x1b[0m%s","We");
			printf("\x1b[%dm%s",BOLD,"Th");
			printf("\x1b[0m%s","Fr");
			printf("\x1b[%dm%s",BOLD,"Sa");
			printf("\x1b[0m  ");
		}
		putchar('\n');

		for( c=0; c<COLUMNS; c++ )
		{
			day = 1;
			for( dow=0; dow<7; dow++ )
			{
				if( dow<dotm[month+c] )
				{
					printf("  ");
				}
				else
				{
					/* a decision is made here when today happens
					   in the first week of the month. First check
					   the date */
					if( today->tm_year+1900==year &&
						today->tm_mon==month+c &&
						today->tm_mday==day
					  )
							color_today(day);
					/* otherwise, output the normal color day */
					else
						color_output(day);
					day++;
				}
			}
			printf("\x1b[0m  ");
			dotm[month+c] = day;
		} 
		printf("\x1b[0m\n");

		for( week=1; week<6; week++ )
		{
			for( c=0; c<COLUMNS; c++ )
			{
				day = dotm[month+c];
				for( dow=0; dow<7; dow++ )
				{
					/* test for today every day of the month */
					if( today->tm_year+1900==year &&
						today->tm_mon==month+c &&
						today->tm_mday==day
					  )
							color_today(day);
					else
					{
						if( day <= mdays[month+c] )
							color_output(day);
						else
							printf("\x1b[0m  ");
					}
					day++;
				}
				printf("\x1b[0m  ");
				dotm[month+c] = day;
			}
			printf("\x1b[0m\n");
		}
		putchar('\n');
	}

	return(0);
}
