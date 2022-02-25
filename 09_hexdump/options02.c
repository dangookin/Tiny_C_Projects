#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int r;
	int alfa,bravo,charlie;

	opterr = 0;
	alfa = 0;
	bravo = 0;
	charlie = 0;

	while( (r=getopt(argc,argv,"abc")) != -1 )
	{
		switch(r)
		{
			case 'a':
				alfa = 1;
				break;
			case 'b':
				bravo = 1;
				break;
			case 'c':
				charlie = 1;
				break;
			case '?':
				printf("Switch '%c' is invalid\n",optopt);
				break;
			default:
				puts("Unknown option");
		}
	}

	if( alfa ) puts("alfa option set");
	if( bravo ) puts("bravo option set");
	if( charlie ) puts("charlie option set");
	if( alfa+bravo+charlie==0 ) puts("No options set");

	return(0);
}
