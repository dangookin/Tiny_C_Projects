#include <stdio.h>

char *binString(char a)
{
	static char b[9];
	int i;

	i = 0;
	while( i<8 )
	{
		b[i] = a&0x80 ? '1' : '0';
		a <<= 1;
		i++;
	}
	b[i] = '\0';

	return(b);
}

int main()
{
	int a;

	for( a=0; a<32; a++ )
	{
		printf("%2d %02X %s - | ",a,a,binString(a));
		printf("%2d %02X %s %c | ",a+32,a+32,binString(a+32),a+32);
		printf("%2d %02X %s %c | ",a+64,a+64,binString(a+64),a+64);
		printf("%3d %02X %s %c |\n",a+96,a+96,binString(a+96),a+96);
	}

	return(0);
}
