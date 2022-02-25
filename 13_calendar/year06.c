#include "holiday_year.h"

void color_holiday(int d)
{
	printf("\x1b[%d;%dm%2d",
			FG+WHITE,
			BG+RED,
			d
		  );
}

void color_today(int d)
{
	printf("\x1b[%d;%dm%2d",
			FG+RED,
			BG+BLACK,
			d
		  );
}

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
	struct holiday h;

	time(&now);	
	today = localtime(&now);
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
			h.month = month+c;
			h.year = year;
			h.name = NULL;
			day = 1;
			for( dow=0; dow<7; dow++ )
			{
				if( dow<dotm[month+c] )
				{
					printf("  ");
				}
				else
				{
					h.day = day;
					h.wday = dow;
					if( isholiday(&h)==1 )
						color_holiday(day);
					else if( today->tm_year+1900==year &&
						today->tm_mon==month+c &&
						today->tm_mday==day
					  )
						color_today(day);
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
				h.month = month+c;
				h.year = year;
				h.name = NULL;
				day = dotm[month+c];
				for( dow=0; dow<7; dow++ )
				{
					h.day = day;
					h.wday = dow;
					if( isholiday(&h)==1 )
						color_holiday(day);
					else if( today->tm_year+1900==year &&
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
