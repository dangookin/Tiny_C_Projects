#include <stdio.h>

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

int main()
{
	int y;

	for( y=1584; y<=2101; y++ )
	{
		if( february(y)==29 )
			printf("%d\n",y);
	}

	return(0);
}
