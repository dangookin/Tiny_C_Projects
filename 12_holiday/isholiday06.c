#include <stdio.h>
#include <time.h>

#define FRIDAY 5
#define MONDAY 1
#define THURSDAY 4
#define FIRST_WEEK h->day<8 
#define SECOND_WEEK h->day>7&&h->day<15
#define THIRD_WEEK h->day>14&&h->day<22
#define FOURTH_WEEK h->day>21&&h->day<29
#define LAST_WEEK h->day>24&&h->day<32

struct holiday {
	int month;
	int day;
	int wday;
	char *name;
};

int weekend(int holiday, int mday, int wday)
{
	if( mday>holiday-2 && mday<holiday+2 )
	{
		if( mday==holiday-1 && wday==FRIDAY )
			return(2);
		if( mday==holiday+1 && wday==MONDAY )
			return(2);
		if( mday==holiday )
			return(1);
	}
	return(0);
}

int isholiday(struct holiday *h)
{
	char *n[] = {
		"New Years Day",
		"Martin Luther King Day",
		"Presidents Day",
		"Memorial Day",
		"Juneteenth",
		"Independence Day",
		"Labor Day",
		"Columbus Day",
		"Veterans Day",
		"Thanksgiving",
		"Christmas"
	};
	int r;
	/* create enumerated constants for 0 through 11 */
	enum { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
		JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER,
		DECEMBER };

	if( h->month==DECEMBER && h->day==31 && h->wday==FRIDAY )
	{
		h->name = n[0];
		return(2);
	}
	if( h->month==JANUARY && h->day==1 )
	{
		h->name = n[0];
		return(1);
	}
	if( h->month==JANUARY && h->day==2 && h->wday==MONDAY )
	{
		h->name = n[0];
		return(2);
	}

	if( h->month==JANUARY && h->wday==MONDAY )
	{
		if( THIRD_WEEK )
		{
			h->name = n[1];
			return(1);
		}
	}

	if( h->month==FEBRUARY && h->wday==MONDAY )
	{
		if( THIRD_WEEK )
		{
			h->name = n[2];
			return(1);
		}
	}

	if( h->month==MAY && h->wday==MONDAY )
	{
		if( LAST_WEEK )
		{
			h->name = n[3];
			return(1);
		}
	}

	if( h->month==JUNE )
	{
		r = weekend(19,h->day,h->wday);
		h->name = n[4];
		return(r);
	}

	if( h->month==JULY )
	{
		r = weekend(4,h->day,h->wday);
		h->name = n[5];
		return(r);
	}

	if( h->month==SEPTEMBER && h->wday==MONDAY )
	{
		if( FIRST_WEEK )
		{
			h->name = n[6];
			return(1);
		}
	}

	if( h->month==OCTOBER && h->wday==MONDAY)
	{
		if( SECOND_WEEK )
		{
			h->name = n[7];
			return(1);
		}
	}

	if( h->month==NOVEMBER )
	{
		if( h->wday==THURSDAY && FOURTH_WEEK )
		{
			h->name = n[9];
			return(1);
		}
		r = weekend(11,h->day,h->wday);
		h->name = n[8];
		return(r);
	}

	if( h->month==DECEMBER )
	{
		r = weekend(25,h->day,h->wday);
		h->name = n[10];
		return(r);
	}

	return(0);
}

int main()
{
	time_t now;
	struct tm *today;
	struct holiday h;
	int r;

	now = time(NULL);
	today = localtime(&now);

	h.month = today->tm_mon;		/* this item must be sent as-is */
	h.day = today->tm_mday;
	h.wday = today->tm_wday;
	h.name = NULL;

	printf("Today is %d/%02d/%d, ",
			today->tm_mon+1,
			today->tm_mday,
			today->tm_year+1900
		  );

	r = isholiday(&h);
	if(r==1)
		puts(h.name);
	else if(r==2)
		printf("%s observed\n",h.name);
	else
		puts("not a holiday");

	return(r);
}
