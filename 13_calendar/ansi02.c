#include <stdio.h>

int main()
{
	int b,f;


	for( b=0 ; b<8; b++ )
	{
		for( f=0; f<8; f++ )
		{
			printf("\x1b[%d;%dm %d:%d ",
					f+30,b+40,f+30,b+40
				  );
		}
		printf("\x1b[0m\n");
	}

	return(0);
}
