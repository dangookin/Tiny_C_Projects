#include <stdio.h>

int main(int argc, char *argv[])
{
	int x;

	if( argc>1 )
	{
		for( x=1; x<argc; x++ )
			printf("%s\n",argv[x]);
	}

	return(0);
}
