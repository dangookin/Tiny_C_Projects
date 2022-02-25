#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if( argc>1 )
	{
		return( strtol(argv[1],NULL,10) );
	}
	else
	{
		exit(0);
	}
}
