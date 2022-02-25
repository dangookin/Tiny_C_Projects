#include <stdio.h>

#define BYTES_PER_LINE 18

int main()
{
	int ch,bytes;

	bytes = 0;
	printf("HEX ENCODE v1.0\n");
	while( (ch=getchar()) != EOF )
	{
		printf(" %02X",ch);
		bytes++;
		if( bytes == BYTES_PER_LINE)
		{
			putchar('\n');
			bytes = 0;
		}
	}
	printf("\nHEX ENCODE END\n");

	return(0);
}
