#include <stdio.h>

void line_out(int offset, int length, unsigned char *data)
{
	int a;

	printf("%05X ",offset);

	for( a=0; a<length; a++ )
	{
		printf(" %02X",*(data+a));
		if( (a+1)%8==0 )
			putchar(' ');
	}

	putchar(' ');
	for( a=0; a<length; a++ )
	{
		if( *(data+a)>=' ' && *(data+a)<='~' )
			putchar( *(data+a) );
		else
			putchar(' ');
	}

	putchar('\n');
}

int main()
{
	unsigned char data[256];
	int b;
	const int length = 16;

	for( b=0; b<256; b++ )
		data[b] = b;

	for( b=0; b<256; b+=length )
	{
		line_out(b,length,data+b);
	}

	return(0);
}
