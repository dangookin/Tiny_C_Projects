#include <stdio.h>
#include <math.h>

void easter(int year)
{
	int Y,a,c,e,h,k,L;
	double b,d,f,g,i,m,month,day;

	Y = year;
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
	month = floor((h+L-7*m+114)/31);
	day = ((h+L-7*(int)m+114)%31)+1;

	printf("In %d, Easter is ",Y);
	if(month == 3)
		printf("March %d\n",(int)day);
	else
		printf("April %d\n",(int)day);
}

int main()
{
	int x;

	for(x=2018;x<2036;x++)
		easter(x);

	return(0);
}

