#include "holiday_year.h"

int easter(struct holiday *hday)
{
	int Y,a,c,e,h,k,L;
	double b,d,f,g,i,m,month,day;

	Y = hday->year;
	a = Y%19;
	b = floor(Y/100);
	c = Y%100;
	d = floor(b/4);
	e = (int)b%4;
	f = floor((b+8)/25);
	g = floor((b-f+1)/3);
	h = (19*a+(int)b-(int)d-(int)g+15)%30;
	i = floor(c/4);
	k = c%4;
	L = (32+2*e+2*(int)i-h-k)%7;
	m = floor((a+11*h+22*L)/451);
	month = floor((h+L-7*m+114)/31)-1;
	day = ((h+L-7*(int)m+114)%31)+1;

	if( hday->month==month && hday->day==day )
		return(1);
	else
		return(0);
}

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
		"Christmas",
		"Easter"
	};
	int r;
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

	r = easter(h);
	if( r==1 )
	{
		h->name = n[11];
		return(r);
	}

	return(0);
}
