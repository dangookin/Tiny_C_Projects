#include <stdio.h>
#include <time.h>

#define FRIDAY 5
#define MONDAY 1

struct holiday {
	int month;
	int day;
	int wday;
	char *name;
};

int isholiday(struct holiday *h)
{
	char *n[] = {
		"New Years Day",
		"Juneteenth",
		"Independence Day",
		"Veterans Day",
		"Christmas"
	};

	if( h->month==11 && h->day==31 && h->wday==FRIDAY )
	{
		h->name = n[0];
		return(2);
	}
	if( h->month==0 && h->day==1 )
	{
		h->name = n[0];
		return(1);
	}
	if( h->month==0 && h->day==2 && h->wday==MONDAY )
	{
		h->name = n[0];
		return(2);
	}

	if( h->month==5 )
	{
		if( h->day>17 && h->day<21 )
		{
			if( h->day==18 && h->wday==FRIDAY )
			{
				h->name = n[1];
				return(2);
			}
			if( h->day==20 && h->wday==MONDAY )
			{
				h->name = n[1];
				return(2);
			}
			if( h->day==19 )
			{
				h->name = n[1];
				return(1);
			}
		}
	}

	if( h->month==6 )
	{
		if( h->day>2 && h->day<6 )
		{
			if( h->day==3 && h->wday==FRIDAY )
			{
				h->name = n[2];
				return(2);
			}
			if( h->day==5 && h->wday==MONDAY )
			{
				h->name = n[2];
				return(2);
			}
			if( h->day==4 )
			{
				h->name = n[2];
				return(1);
			}
		}
	}

	if( h->month==10 )
	{
		if( h->day>9 && h->day<13 )
		{
			if( h->day==10 && h->wday==FRIDAY )
			{
				h->name = n[3];
				return(2);
			}
			if( h->day==12 && h->wday==MONDAY )
			{
				h->name = n[3];
				return(2);
			}
			if( h->day==11 )
			{
				h->name = n[3];
				return(1);
			}
		}
	}

	if( h->month==11 )
	{
		if( h->day>23 && h->day<27 )
		{
			if( h->day==24 && h->wday==FRIDAY )
			{
				h->name = n[4];
				return(2);
			}
			if( h->day==26 && h->wday==MONDAY )
			{
				h->name = n[4];
				return(2);
			}
			if( h->day==25 )
			{
				h->name = n[4];
				return(1);
			}
		}
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

	h.month = today->tm_mon;
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
