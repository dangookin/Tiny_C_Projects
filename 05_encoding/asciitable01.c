#include <stdio.h>

int main()
{
	int x;

	/* output the header row, all columns or "sticks" */
	printf("Dec  Oct  Hex  C  \
 Dec  Oct  Hex  C  \
 Dec  Oct  Hex  C  \
 Dec  Oct  Hex  C\n");
	/* only need to process one stick, but use offsets
	   to output the other three sticks */
	for( x=0; x<32; x++ )
	{
		/* first stick, don't output character values */
		printf("%3d  %3o  %3x  - | ",
				x, x, x
			  );
		/* each other stick in a 32, 63, 96 offset */
		printf("%3d  %3o  %3x  %c | ",
				x+32, x+32, x+32, x+32
			  );
		printf("%3d  %3o  %3x  %c | ",
				x+64, x+64, x+64, x+64
			  );
		printf("%3d  %3o  %3x  %c \n",
				x+96, x+96, x+96, x+96
			  );
	}

	return(0);
}
