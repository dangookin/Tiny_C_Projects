#include <stdio.h>

int main()
{
	unsigned char a;

	a = 0;
	while( 1 )
	{
		printf("%d\n",a);
		if( a==255 )
			break;
		a++;
	}

	return(0);
}
