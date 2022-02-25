#include <stdio.h>

int main()
{
	unsigned char data[256];
	int b;

	/* fill the array */
	for( b=0; b<256; b++ )
		data[b] = b;

	/* dump the data */
	for( b=0; b<256; b++ )
	{
		if( b%16==0 )				/* the start of every line */
			printf("%05X ",b);		/* output the offset */
		printf(" %02X",data[b]);
		if( (b+1)%8==0 )			/* after the 8th column */
			putchar(' ');			/* add a space */
		if( (b+1)%16==0 )			/* newline after 16 bytes */
			putchar('\n');
	}

	return(0);
}
