#include <stdio.h>
#include <time.h>

struct holiday {
	int month;
	int day;
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

	if( h->month==0 && h->day==1)
	{
		h->name = n[0];
		return(1);
	}

	if( h->month==5 && h->day==19)
	{
		h->name = n[1];
		return(1);
	}

	if( h->month==6 && h->day==4)
	{
		h->name = n[2];
		return(1);
	}

	if( h->month==10 && h->day==11)
	{
		h->name = n[3];
		return(1);
	}

	if( h->month== 11 && h->day == 25)
	{
		h->name = n[4];
		return(1);
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
	h.name = NULL;

	printf("Today is %d/%02d/%d, ",
			today->tm_mon+1,
			today->tm_mday,
			today->tm_year+1900
		  );

	r = isholiday(&h);
	if(r)
		puts(h.name);
	else
		puts("not a holiday");

	return(r);
}
