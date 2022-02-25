#include <stdio.h>

int main()
{
	int hexbytes[] = {
		0x41, 0x42, 0x43, 0x44, 0x45,
		0x46, 0x47, 0x48, 0x49, 0x4A
	};
	int x,checksum;

	checksum = 0;
	for( x=0; x<10; x++ )
	{
		checksum += hexbytes[x];
		printf(" %02X",hexbytes[x]);
	}
	printf("\nChecksum = %02X\n",checksum%0x100);

	return(0);
}
