#include <stdio.h>
#include <time.h>

int isholiday(struct tm *d)
{
	if( d->tm_mon==0 && d->tm_mday==1)
		return(1);

	if( d->tm_mon==5 && d->tm_mday==19)
		return(1);

	if( d->tm_mon==6 && d->tm_mday==4)
		return(1);

	if( d->tm_mon==10 && d->tm_mday==11)
		return(1);

	if( d->tm_mon == 11 && d->tm_mday == 25)
		return(1);

	return(0);
}

int main()
{
	time_t now;
	struct tm *today;
	int r;

	now = time(NULL);
	today = localtime(&now);

	printf("Today is %d/%02d/%d, ",
			today->tm_mon+1,
			today->tm_mday,
			today->tm_year+1900
		  );

	r = isholiday(today);
	if(r)
		puts("a holiday");
	else
		puts("not a holiday");

	return(r);
}
