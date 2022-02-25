#include <stdio.h>

int main()
{
	int ch;

	while( (ch=getchar()) != EOF )
	{
		printf("%02X ",ch);
	}

	return(0);
}
