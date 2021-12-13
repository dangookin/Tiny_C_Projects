#include <stdio.h>

int main()
{
	unsigned char data[256];
	int b;

	for( b=0; b<256; b++ )
		data[b] = b;

	for( b=0; b<256; b++ )
		printf("%d\n",data[b]);

	return(0);
}
