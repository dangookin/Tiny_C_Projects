#include <stdio.h>

#define BYTES_PER_LINE 18

int main()
{
	int ch,bytes,checksum;

	bytes = checksum = 0;
	printf("HEX ENCODE v2.0\n");
	while( (ch=getchar()) != EOF )
	{
		printf(" %02X",ch);
		checksum += ch;
		bytes++;
		if( bytes == BYTES_PER_LINE)
		{
			printf(" %02X\n",checksum%0x100);
			bytes = checksum = 0;
		}
	}
	if( bytes>0 )
		printf(" %02X",checksum%0x100);
	printf("\nHEX ENCODE END\n");

	return(0);
}
