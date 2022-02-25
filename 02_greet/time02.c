#include <stdio.h>
#include <time.h>

int main()
{
	time_t now;
	struct tm *clock;

	time(&now);
	clock = localtime(&now);
	puts("Time details:");
	printf(" Day of the year: %d\n",clock->tm_yday);
	printf(" Day of the week: %d\n",clock->tm_wday);
	printf("            Year: %d\n",clock->tm_year+1900);
	printf("           Month: %d\n",clock->tm_mon+1);
	printf("Day of the month: %d\n",clock->tm_mday);
	printf("            Hour: %d\n",clock->tm_hour);
	printf("          Minute: %d\n",clock->tm_min);
	printf("          Second: %d\n",clock->tm_sec);

	return(0);
}
